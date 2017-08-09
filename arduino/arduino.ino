#include <LiquidCrystal.h>
#include <RCS620S.h>
#include <HX711.h>
 
#define COMMAND_TIMEOUT 400
#define POLLING_INTERVAL 500
 
RCS620S rcs620s;
HX711 scale(A2, A3);
 
void setup() { 
  int ret;
  Serial.begin(115200);      // for RC-S620/S
 
  // initialize RC-S620/S
  ret = rcs620s.initDevice();

  while (!ret) {
      ret = rcs620s.initDevice();
             Serial.println(" blooking ");
               delay(1000);
               // blocking
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
    
    tone(9,1318,80);
    delay(100);
    tone(9,1318,80);

    float average = 0;
    for (int j=0;j<10;j++){
      average += scale.read();
      delay(50);
    }
    String wheight = String(average);
    Serial.print(wheight);
    Serial.print(" ");
    
    Serial.println();
    delay(5000);
    
  } else {
    Serial.println("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
