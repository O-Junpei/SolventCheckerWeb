float getAverageWeight(){

  float average = 0;
  for (int i=0;i<10;i++){
    average += scale.read();
    delay(50);
  }
  return average/10;
}
