int t = 0;

unsigned long last_modif_time = getStateLastModifiedTime();

void setup() {
  Serial.begin(9600);

  initState();
  initDisplay();
  initExecutor();

  displayState();
}

void loop() {
  t = millis();
  unsigned long last = getStateLastModifiedTime();

  if (t - last < EXE_TIME_WINDOW) {
    return;
  }

  if (last == last_modif_time) {
    return;
  }

  // execute according to the new state
  if (isCmdCompleted()) {
    //Serial.println("executing cmd ...");
    execute();
  }

  Serial.println("displayState");
  displayState();

  last_modif_time = last;
}
