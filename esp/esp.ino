#include <LiquidCrystal.h>
#include <RCS620S.h>

#define COMMAND_TIMEOUT 400
#define POLLING_INTERVAL 500
 
RCS620S rcs620s;

#define BUZZER_PIN 23       // ブザーを鳴らすためのピン
#define BEAT 150            // 一つの音を鳴らす時間
#define LEDC_CHANNEL 0      // チャンネル
#define LEDC_TIMER_BIT 13
#define LEDC_BASE_FREQ 5000

 
void setup() { 
  int ret;
  Serial.begin(115200);      // for RC-S620/S
 
  // initialize RC-S620/S
  ret = rcs620s.initDevice();


    // 音を鳴らす準備
  ledcSetup(LEDC_CHANNEL, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);


  while (!ret) {
      ret = rcs620s.initDevice();
             Serial.println(" blooking ");
               delay(1000);
               // blocking
  }
}

/**
 * ゼルダの謎解き音
 */
void callZeldaSound() {
  ledcWriteTone(LEDC_CHANNEL, 3136); // ソ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 2960); // ♯ファ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 2489); // ♯レ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 1760); // ラ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 1661); // ♯ソ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 2637); // ミ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 3322); // ♯ソ
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 4186); // ド
  delay(BEAT);
  ledcWriteTone(LEDC_CHANNEL, 0);    // 音を止める
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
