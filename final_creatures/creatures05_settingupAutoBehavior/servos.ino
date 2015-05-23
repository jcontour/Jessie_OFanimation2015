void setupServos() {
  for (int i = 0; i < 15; i++) {
    pos[i] = 100;

    servos[i].attach(36 + i);
    servos[i].write(pos[i]);
    
    servos[i].detach();

  }
}

void servoGo(int i){
   servos[i].attach(36+i);
   servos[i].write(pos[i]);
}

void servoStop(int i){
  servos[i].detach();  
}
