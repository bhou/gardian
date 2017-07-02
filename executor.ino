void initExecutor() {
  pinMode(LEFT_MOTOR_OUT_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_OUT_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_OUT_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_OUT_PIN2, OUTPUT);
}

void execute() {
  int left = getLeftThrottle();
  int right = getRightThrottle();
  int gear = getGear();

  // output to motor
  int l = map(left, 0, 99, 0, 255);
  int r = map(right, 0, 99, 0, 255);

  if (gear == GEAR_DRIVE) { // DRIVE
    analogWrite(LEFT_MOTOR_OUT_PIN1, l);
    analogWrite(LEFT_MOTOR_OUT_PIN2, 0);
    analogWrite(RIGHT_MOTOR_OUT_PIN1, r);
    analogWrite(RIGHT_MOTOR_OUT_PIN2, 0);
  } else { // REVERSE
    analogWrite(LEFT_MOTOR_OUT_PIN1, 0);
    analogWrite(LEFT_MOTOR_OUT_PIN2, l);
    analogWrite(RIGHT_MOTOR_OUT_PIN1, 0);
    analogWrite(RIGHT_MOTOR_OUT_PIN2, r);
  }
}
