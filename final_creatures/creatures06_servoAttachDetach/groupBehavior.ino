//group behavior

//if time since last trigger > random length of time
//set random i to random color
//short timer
//set i + 1, i - 1 to same color
//etc

//short timer
//set another i to random color

int talkingTimer1 = 0;
int talkingTimer2 = 0;
int talkingTimer3 = 0;
int talkingTimer4 = 0;
bool isAuto = false;

void checkTimeSinceTrigger() {
  int talker;
  if (timeSinceLastTrigger > randomLengthofTime) {
    isAuto = true;
    talker = int(random(0, 16));
    Serial.println("talking start");
  }
  if (isAuto) {
    groupBehavior(talker);
    isAuto = false;
    timeSinceLastTrigger = 0;
    randomLengthofTime = int(random(200, 500));
  }
}

void groupBehavior(int _talker) {
  changeToRandom(_talker);
  int t = _talker;
  Serial.print(t);
  Serial.println(" talking");
  //changeToRandom(talker);
  
  int _r = targetR[t];
  int _g = targetG[t];
  int _b = targetB[t];
  
  if (talkingTimer1 < 100) {
    talkingTimer1 ++;
  } else {
    changeToColor(t + 1, _r, _g, _b);
    changeToColor(t - 1, _r, _g, _b);
    //changeToBlue(t);
    if (talkingTimer2 < 100) {
      talkingTimer2 ++;
    } else {
      changeToColor(t + 2, _r, _g, _b);
      changeToColor(t - 2, _r, _g, _b);
    //  changeToBlue(t + 1);
    //  changeToBlue(t - 1);
      if (talkingTimer3 < 100) {
        talkingTimer3 ++;
      } else {
        changeToColor(t + 3, _r, _g, _b);
        changeToColor(t - 3, _r, _g, _b);
     //   changeToBlue(t + 2);
     //   changeToBlue(t - 2);
        if (talkingTimer4 < 100) {
          talkingTimer4 ++;
        } else {
    //      changeToBlue(t + 3);
    //      changeToBlue(t - 3);
        }
      }
    }
  }
}
