LiquidCrystal lcd(9, 8, 7, 4, 3, 2);

void initDisplay() {
  lcd.begin(16, 2);
}

/**
 * print on lcd screen with 2 lines of text
 */
void lcdPrint(String line1, String line2) {
  lcd.clear();
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

/**
 * debug info on lcd screen
 */
void lcdDebug(String text) {
  lcd.clear();
  lcd.print(text);
}

/**
 * display current state
 */
void displayState() {
  if (!lcdDisplayEnabled()) {
    return;
  }
  byte gear = getGear();
  String strGear = "D";
  if (gear == GEAR_DRIVE) {
    strGear = "D";
  } else {
    strGear = "R";
  }
  int lThrottle = getLeftThrottle();
  int rThrottle = getRightThrottle();
  int turn = getTurn();

  lcdPrint(
    "G : " + strGear + "  | T : " + String(turn),
    "L : " + getThrottleStr(lThrottle) + "| R : " + String(rThrottle)
  );
}

void serialPrintState() {
  Serial.println("Throttle: " + String(getThrottle()));
  Serial.println("Left: " + String(getLeftThrottle()));
  Serial.println("Right: " + String(getRightThrottle()));
  Serial.println("Turn: " + String(getTurn()));
  Serial.println("loffset: " + String(getThrottleOffset()));
}

String getThrottleStr(int throttle) {
  int d = throttle/10;
  if (d == 0) {
    return String(throttle) + "  ";
  } else {
    return String(throttle) + " ";
  }
}
