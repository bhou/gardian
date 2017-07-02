String cmdStr = "";
String cmdValueStr = "";
boolean cmdComplete = false;

unsigned long cmd_last_time = 0;
int const CMD_TIME_WINDOW = 20; // in ms

boolean isCmdCompleted() {
  return cmdComplete;
}

String getCmdStr() {
  return cmdStr;
}

int getCmdValue() {
  return cmdValueStr.toInt();
}

void serialEvent() {
  int t = millis();
  if (t - cmd_last_time < CMD_TIME_WINDOW) {
    return;
  }

  while (Serial.available()) {
    char inChar = (char) Serial.read();

    switch(inChar) {
      case 'A': // throttle
        cmdStr = "THROTTLE";
        cmdComplete = false;
        break;
      case 'B': // turn
        cmdStr = "TURN";
        cmdComplete = false;
        break;
      case 'R': // R gear
        cmdStr = "REVERSE";
        cmdComplete = false;
        break;
      case 'D': // D gear
        cmdStr = "DRIVE";
        cmdComplete = false;
        break;
      case 'O': // offset
        cmdStr = "OFFSET";
        cmdComplete = false;
      case '\n':
        executeCmd(cmdStr, cmdValueStr);
        clearCmd();
        break;
      default:
        if (isDigit(inChar)) {
          cmdValueStr += inChar;
        }
    }
  }

  cmd_last_time = millis();
}

void clearCmd() {
  cmdStr = "";
  cmdValueStr = "";
  cmdComplete = true;
}

void executeCmd(String cmdStr, String cmdValueStr) {
  if (cmdStr == "THROTTLE") {
    updateThrottle(cmdValueStr.toInt());
  } else if (cmdStr == "TURN") {
    updateTurn(cmdValueStr.toInt()); // 0 - 179
  } else if (cmdStr == "DRIVE") {
    updateGear(GEAR_DRIVE);
  } else if (cmdStr == "REVERSE") {
    updateGear(GEAR_REVERSE);
  } else if (cmdStr == "OFFSET") {
    updateOffset(cmdValueStr.toInt());
  }
}

void updateThrottle(int throttle) {
  int normalizedThrottle = throttle; //map(throttle, 0, 99, 0, 255);
  //Serial.println("update throttle to " + String(normalizedThrottle));
  setThrottle(normalizedThrottle);
}

void updateTurn(int turn) {
  int angle = map(turn, 0, 179, -90, 90);
  //Serial.println("update turn to " + String(turn) + "-" + String(angle));
  setTurn(angle);
}

void updateGear(byte gear) {
  //Serial.println("update gear to D");
  setGear(gear);
}

void updateOffset(int offset) {
  //Serial.println("update throttle offset to " + String(offset));
  setThrottleOffset(offset);
}
