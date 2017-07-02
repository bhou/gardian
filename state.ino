byte state_gear = GEAR_DRIVE;
int state_turn = 0; // how fast it turns, -90 to 90
int state_throttle = 0; // throttle value, controls how fast it runs, 0 to 99

// throttles for each side motor
int state_throttle_left = 0;
int state_throttle_right = 0;

// last modified time
unsigned long state_laste_modified_time = 0;

// enable lcd
boolean enableLcdDisplay = true;

/**
 * Initiate the state
 */
void initState() {
  state_gear = GEAR_DRIVE;
  state_turn = 0;
  state_throttle = 0;
  config_updateLRThrottle(state_gear, state_throttle, state_turn);
}

byte getGear() {
  return state_gear;
}

void setGear(byte gear) {
  if (gear < 0 || gear > 1) {
    return;
  }
  if (gear == state_gear) {
    return;
  }
  state_gear = gear;
  config_updateLRThrottle(state_gear, state_throttle, state_turn);
  state_laste_modified_time = millis();
}

int getTurn() {
  return state_turn;
}

void setTurn(int turn) {
  if (turn < -90 || turn > 90) {
    return;
  }
  if (turn == state_turn) {
    return;
  }
  state_turn = turn;
  config_updateLRThrottle(state_gear, state_throttle, state_turn);
  state_laste_modified_time = millis();
}

int getThrottle() {
  return state_throttle;
}

void setThrottle(int throttle) {
  if (throttle < 0 || throttle > 99) {
    return;
  }
  if (throttle == state_throttle) {
    return;
  }
  state_throttle = throttle;
  config_updateLRThrottle(state_gear, state_throttle, state_turn);
  state_laste_modified_time = millis();
}

int getLeftThrottle() {
  return state_throttle_left;
}

void setLeftThrottle(int throttle) {
  state_throttle_left = throttle;
}

int getRightThrottle() {
  return state_throttle_right;
}

void setRightThrottle(int throttle) {
  state_throttle_right = throttle;
}

int getThrottleOffset() {
  return state_throttle_offset;
}

void setThrottleOffset(int offset) {
  if (offset < -50 || offset > 50) {
    return;
  }
  if (state_throttle_offset == offset) {
    return;
  }
  state_throttle_offset = offset;
  // don't update throttle immiedately, it will be applied when throttle or turn changed
}

unsigned long getStateLastModifiedTime() {
  return state_laste_modified_time;
}

boolean lcdDisplayEnabled() {
  return enableLcdDisplay;
}

/**
 * load state from EEPROM
 */
void loadState() {
  // TODO: load state from EEPROM
}

/**
 * save state to EEPROM
 */
void saveState() {
  // TODO: save state to EEPROM
}
