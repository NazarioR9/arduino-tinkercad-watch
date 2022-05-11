/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_B0  31
#define NOTE_DS8 3322
#define NOTE_DS7 2489
#define NOTE_A7 3520
#define DISCHARGE_PRECENTAGE 0.1
//Buzz when battery level is below 10%
#define INITIAL_LBOUND 0
#define INITIAL_UBOUND 1023
#define MAPPED_LBOUND 0
#define MAPPED_UBOUND 255
#define NOTIFY_N_TIMES 2
#define NOTIFY_INTERVAL 30

int sensorValue = 0;
int outputValue = 0;
int notifyCount = 0;
int lastNotifiedAt = -1;


// notes in the melody:
int melody[] = {
  NOTE_DS8, NOTE_B0, NOTE_DS8, NOTE_B0, NOTE_DS8
};

int noteDurations[] = {
  2,1,2,1,2
};

void notifyDischarge() {
  int startIndex = 0;
  
  
  for (int thisNote = 0; thisNote < 5; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    
    int startTime = millis();
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    while(millis() < startTime + pauseBetweenNotes); // wait a bit:
    noTone(8);// stop the tone playing:
  }
}
  

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, INITIAL_LBOUND, INITIAL_UBOUND, MAPPED_LBOUND, MAPPED_UBOUND);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  
  bool condition = outputValue < MAPPED_UBOUND * DISCHARGE_PRECENTAGE;
  condition &= (notifyCount < NOTIFY_N_TIMES);
  
  if (condition) {
    notifyDischarge();
	++notifyCount;
  }
  
  // wait 2 milliseconds before the next loop for the
  // analog-to-digital converter to settle after the
  // last reading:
  delay(2); // Wait for 2 millisecond(s)
}