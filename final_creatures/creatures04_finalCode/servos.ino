void setupServos() {
  for (int i = 0; i < 15; i++) {
    pos[i] = 100;

    servos[i].attach(36 + i);
    servos[i].write(pos[i]);

  }
}
