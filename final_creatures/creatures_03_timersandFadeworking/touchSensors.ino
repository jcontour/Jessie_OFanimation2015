void readTouch1() {
  currtouched1 = cap1.touched();

  for (uint8_t i = 0; i < 10; i++) {
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #1 touched");
      //when touched, trigger
      turnRed(i);
    }

    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #1 released");
      isReleased[i] = true;
    }
  }
  lasttouched1 = currtouched1;
}

void readTouch2() {
  currtouched2 = cap2.touched();

  for (uint8_t i = 0; i < 5; i++) {
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #2 touched");
      //when touched, trigger
       turnRed(i+10);
     }
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #2 released");

      isReleased[i+10] = true;

    }
  }
  lasttouched2 = currtouched2;
}
