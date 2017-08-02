#include <HX711.h>
HX711 scale(A2, A3);

void setup() {
   Serial.begin(9600);
}

void loop() {
    
    float average = 0;
    for (int j=0;j<10;j++){
      average += scale.read();
      delay(50);
    }
    Serial.println(average); 
}
