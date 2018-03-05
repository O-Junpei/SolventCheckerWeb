
//ゼルダの謎解き音
void callZeldaSound() {
  ledcWriteTone(LEDC_CHANNEL, 3136); // ソ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2960); // ♯ファ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2489); // ♯レ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 1760); // ラ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 1661); // ♯ソ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2637); // ミ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 3322); // ♯ソ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 4186); // ド
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 0);    // 音を止める
}

//エリーゼのために
void callEliseSound() {
  ledcWriteTone(LEDC_CHANNEL, 2637); // ミ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2489); // ♯レ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2637); // ミ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2489); // ♯レ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2637); // ミ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 1975.50); // シ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2349.50); // レ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 2093.00); // ド
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 1760); // ラ
  delay(150);
  ledcWriteTone(LEDC_CHANNEL, 0);    // 音を止める
}

//ベートーベン運命
void callDestinySound() {
  ledcWriteTone(LEDC_CHANNEL, 3136.00); // ソ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 3136.00); // ソ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 3136.00); // ソ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2489); // ♯レ
  delay(400);
  ledcWriteTone(LEDC_CHANNEL, 2794.00); // ファ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2794.00); // ファ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2794.00); // ファ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2349.50); // レ
  delay(400);
  ledcWriteTone(LEDC_CHANNEL, 0);    // 音を止める
}

//メリーさんの羊
void callMaryHadLittleLampSound() {
  ledcWriteTone(LEDC_CHANNEL, 2637.00); // ミ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2349.50); // レ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2093.00); // ド
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2349.50); // レ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2637.00); // ミ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2637.00); // ミ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 2637.00); // ミ
  delay(250);
  ledcWriteTone(LEDC_CHANNEL, 0);    // 音を止める
}

