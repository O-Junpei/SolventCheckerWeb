#include <WiFi.h>
#include <time.h>
#include <SD.h>
#include <RCS620S.h>
#include <HX711.h>

//SD関係
#define LOG_FILE_NAME "/log.txt"
#define SD_CS 5
static File s_myFile;

//Wifi関係
#define JST     3600* -9
const char* ssid = "2balf";
const char* password = "phenolammonia";

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

void setup() { 

  Serial.begin(115200);      // for RC-S620/S
  Serial.println("Initing");

  // 音を鳴らす準備
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);
  //callMaryHadLittleLampSound();

  //SDの初期化
  //初期化に失敗するとメリーさんの羊が再生される。
  if (!SD_init()){
    callMaryHadLittleLampSound(); 
  }

  //wifi
  //wifiConnect();
  //Serial.println(getTimeString());

  

  //felica
  int ret;
  ret = rcs620s.initDevice();
  while (!ret) {
      ret = rcs620s.initDevice();
      Serial.println(" blooking ");
      delay(1000);
  }
}

void loop() {
  int ret, i;
 
  // Polling
  rcs620s.timeout = COMMAND_TIMEOUT;
  ret = rcs620s.polling();
  
  if(ret) {

    String felicaID = "";
    for(i = 0; i < 8; i++)
    {
      if(rcs620s.idm[i] / 0x10 == 0) felicaID += "0";
      //Serial.print(rcs620s.idm[i], HEX);
      felicaID += String(rcs620s.idm[i], HEX);
    }

    callZeldaSound();

    String weight = String(getAverageWeight());
    String date = String(getTimeString());

    SD_write(date, felicaID, weight);
    
    delay(5000);
    
  } else {
    Serial.println("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}

