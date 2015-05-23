void setupPixels() {

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 3; j++) {
      strips[i].begin();
      strips[i].setPixelColor(j, 255, 0, 0);
      strips[i].show();
    }

    r[i] = 0;
    g[i] = 0;
    b[i] = 255;

    targetR[i] = 0;
    targetG[i] = 0;
    targetB[i] = 255;

  }
}

void colorLerp(int i) {

  if (r[i] > targetR[i]) {
    r[i] --;
  } else if (r[i] < targetR[i]) {
    r[i] ++;
  }

  if (g[i] > targetG[i]) {
    g[i] --;
  } else if (g[i] < targetG[i]) {
    g[i] ++;
  }

  if (b[i] > targetB[i]) {
    b[i] --;
  } else if (b[i] < targetB[i]) {
    b[i] ++;
  }

  for (int j = 0; j < 3; j++) {
    strips[i].setPixelColor(j, r[i], g[i], b[i]);
    strips[i].show();
  }
}

void changeToBlue(int i) {
  targetR[i] = 0;
  targetG[i] = 0;
  targetB[i] = 255;
}

void changeToRed(int i) {
  targetR[i] = 255;
  targetG[i] = 0;
  targetB[i] = 0;
}

void changeToRandom(int i) {
  targetR[i] = int(random(0, 255));
  targetG[i] = int(random(0, 255));
  targetB[i] = int(random(0, 255));
}

void changeToColor(int i, float _r, float _g, float _b) {
  targetR[i] = _r;
  targetG[i] = _g;
  targetB[i] = _b;
}

