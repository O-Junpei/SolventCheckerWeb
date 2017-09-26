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
#define SD_CS 5
static File s_myFile;

void setup() { 

  Serial.begin(115200);      // for RC-S620/S

  //felica
  int ret;
  ret = rcs620s.initDevice();

  // 音を鳴らす準備
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);
  //callZeldaSound();

  //SDの確認
  SD_init();
  //SD_write("17/09/32","idididid", "32567");
  //Serial.println(SD_read());

  while (!ret) {
      ret = rcs620s.initDevice();
      Serial.println(" blooking ");
      Serial.println(scale.read());
      delay(1000);
  }
}

void loop() {
  int ret, i;
 
  // Polling
  rcs620s.timeout = COMMAND_TIMEOUT;
  ret = rcs620s.polling();
  
  if(ret) {
    for(i = 0; i < 8; i++)
    {
      if(rcs620s.idm[i] / 0x10 == 0) Serial.print(0);
      Serial.print(rcs620s.idm[i], HEX);
    }
    Serial.println();

    callZeldaSound();
    
    delay(5000);
    
  } else {
    Serial.println("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}

