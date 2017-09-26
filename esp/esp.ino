#include <SD.h>
#include <RCS620S.h>
#include <HX711.h>

//フェリカ関係
#define COMMAND_TIMEOUT 400
#define POLLING_INTERVAL 500

RCS620S rcs620s;

//ブザー関連
#define BUZZER_PIN 22      // ブザーを鳴らすためのピン
#define LEDC_CHANNEL 0      // チャンネル
#define LEDC_TIMER_BIT 14
#define LEDC_BASE_FREQ 5000

//ロードセル関係
HX711 scale(14, 15);

//SD関係
#define LOG_FILE_NAME "/log.txt"
const uint8_t SD_CS = 5; // GPIO5=CS
static File s_myFile;


void setup() { 

  int ret;
  Serial.begin(115200);      // for RC-S620/S

  // initialize RC-S620/S
  ret = rcs620s.initDevice();

  // 音を鳴らす準備
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);

  callZeldaSound();
  Serial.println("kokokara");

  SD_init();
  SD_write();
  Serial.println(SD_read());

  while (!ret) {
      ret = rcs620s.initDevice();
      Serial.println(" blooking ");
      Serial.println(scale.read());
      delay(1000);
  }
}


void SD_init()
{
    Serial.print("Initializing SD card...");

    if (!SD.begin(SD_CS)) {
      Serial.println("initialization failed!");
      return;
    }
    Serial.println("initialization done.");        
}

String SD_read() {

    String str;

    File file = SD.open(LOG_FILE_NAME, FILE_READ);

    if(file){
        //---1byteずつ読み込んだ文字を結合
        while (file.available()) {
            str += char(file.read());
        }
    } else{
        Serial.println(" error...");
    }
    //---ファイルを閉じる
    file.close();
    
    return str;
}

void SD_write()
{
    String backLog = SD_read();

    s_myFile = SD.open(LOG_FILE_NAME, FILE_WRITE);
    if (s_myFile) {
        Serial.print("Writing to test.txt...");
        s_myFile.print(backLog);
        s_myFile.println("testing 1, 2, 3.");
        s_myFile.close();
        Serial.println("done.");
    } else {
        Serial.println("error opening test.txt");
    }
}


void loop() {
  int ret, i;
 
  // Polling
  rcs620s.timeout = COMMAND_TIMEOUT;
  ret = rcs620s.polling();
  
  if(ret) {
    Serial.print(" ");
    for(i = 0; i < 8; i++)
    {
      if(rcs620s.idm[i] / 0x10 == 0) Serial.print(0);
      Serial.print(rcs620s.idm[i], HEX);
    }
    Serial.print(" ");
    Serial.println();

    callZeldaSound();
    
    delay(5000);
    
  } else {
    Serial.println("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}

