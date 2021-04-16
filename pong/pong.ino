#define DEFAULT_BAUD 115200
#define XB_BAUD 9600
#define mSec 1000
#define SLEEP 10

void setup() {
  Serial.begin(DEFAULT_BAUD);
  Serial1.begin(XB_BAUD);
}

void loop() {
  while (Serial1.available() == 0);
  Serial.println("PONG");
  delay(SLEEP*mSec);
  Serial1.write(1);
}
