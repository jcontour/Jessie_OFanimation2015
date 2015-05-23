//individual behavior
void setupVariablesforIndividualBehavior() {

  for (int i = 0; i < 15; i ++) {
    isTouched[i] = false;
    atBottom[i] = false;
    reset[i] = false;
    counter[i] = 0;
  }

}

void trigger() {

  for (int i = 0; i < 15; i ++) {

    //if isTouched, change to red then move down
    if (isTouched[i]) {  
      counter[i] = 0;
      changeToRed(i);
      servoGo(i);
      if (pos[i] > 0) {
        pos[i] -= 1;
      } else {
        isTouched[i] = false;
        atBottom[i] = true;
      }
    }

    //wait at bottom
    if (atBottom[i]) {
      counter[i] ++;
      if (counter[i] > 200) {
        atBottom[i] = false;
        reset[i] = true;
      }
    }

    //reset position then change back to blue
    if (reset[i]) {
      if (pos[i] < 100) {
        pos[i] += 1;
      } else {
        changeToBlue(i);
        reset[i] = false;
        servoStop(i);
      }
    }
  }
}
