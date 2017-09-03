#include <RCS620S.h>

//フェリカ
#define COMMAND_TIMEOUT 400
#define POLLING_INTERVAL 500

RCS620S rcs620s;

//ブザー関連
#define BUZZER_PIN 22      // ブザーを鳴らすためのピン
#define LEDC_CHANNEL 0      // チャンネル
#define LEDC_TIMER_BIT 14
#define LEDC_BASE_FREQ 5000

//
/*
const char* wifi_ssid = "2balf";
const char* wifi_pass = "phenolammonia";
const char* smtp_username = "fuji.lab.tech";
const char* smtp_password = "Yag1064Wave";
const char* smtp_from_address = "fuji.lab.tech@gmail.com";
const int smtp_port = 465;
const char* smtp_hostname = "smtp.gmail.com";

const char* to_address = "snorlax.chemist.and.jazz@gmail.com";
const char* subject = "From ESP32";
const char* content = "Hello, this is ESP32.";

*/
void setup() { 

  int ret;
  Serial.begin(115200);      // for RC-S620/S
 
  // initialize RC-S620/S
  ret = rcs620s.initDevice();

  
    // 音を鳴らす準備
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);

  callZeldaSound();

    while (!ret) {
      ret = rcs620s.initDevice();
             Serial.println(" blooking ");
               delay(1000);
               // blocking
  }
}

void sendMail(){
  
  
  
  
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
    /*
    tone(9,1318,80);
    delay(100);
    tone(9,1318,80);
    */
    
    delay(5000);
    
  } else {
    Serial.println("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
