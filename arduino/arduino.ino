#include <LiquidCrystal.h>
#include <RCS620S.h>
 
#define COMMAND_TIMEOUT 400
#define POLLING_INTERVAL 500
 
RCS620S rcs620s;
 
void setup() { 
  int ret;
  Serial.begin(115200);      // for RC-S620/S
 
  // initialize RC-S620/S
  ret = rcs620s.initDevice();

  while (!ret) {
      ret = rcs620s.initDevice();
             Serial.println("blooking");
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
    Serial.print("IDm:");
    for(i = 0; i < 8; i++)
    {
      if(rcs620s.idm[i] / 0x10 == 0) Serial.print(0);
      Serial.print(rcs620s.idm[i], HEX);
    }

            tone(9,1318,80);
  delay(100);
  tone(9,1318,80);
  delay(5000);
  } else {
    Serial.print("Polling...");
  }
 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
