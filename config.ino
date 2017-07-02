// throttle offset applied to left throttle;
int state_throttle_offset = 0;

/**
 * update throttle for left and right motors
 */
void config_updateLRThrottle(byte gear, int throttle, int turn) {
  config_simpleThrottleDist(gear, throttle, turn);
  serialPrintState();
}

/**
 * a simple throttle distribution function
 */
void config_simpleThrottleDist(byte gear, int throttle, int turn) {
  int turnWheelThrottle = throttle;
  if (turn < 0) { // turn left
    turnWheelThrottle = map(turn, -90, 0, 0, throttle);
    setLeftThrottle(turnWheelThrottle + state_throttle_offset);
    setRightThrottle(throttle);
  } else if (turn > 0) {  // turn right
    turnWheelThrottle = map(turn, 0, 90, throttle, 0);
    setLeftThrottle(throttle + state_throttle_offset);
    setRightThrottle(turnWheelThrottle);
  } else {
    setLeftThrottle(throttle + state_throttle_offset);
    setRightThrottle(throttle);
  }
}
