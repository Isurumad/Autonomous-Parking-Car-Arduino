#include <NewPing.h>
#define TRIGGER_PIN1 13
#define ECHO_PIN1 12
#define MAX_DISTANCE1 200
NewPing sonar1 ( TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1);
int d1;
void Read () ;
#define TRIGGER_PIN2 11
#define ECHO_PIN2 10
#define MAX_DISTANCE2 200
NewPing sonar2 ( TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2);
int d2;

#define TRIGGER_PIN3 9
#define ECHO_PIN3 8
#define MAX_DISTANCE3 200
NewPing sonar3 ( TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE3);
int d3;

#define TRIGGER_PIN4 7
#define ECHO_PIN4 6
#define MAX_DISTANCE4 200
NewPing sonar4 ( TRIGGER_PIN4, ECHO_PIN4, MAX_DISTANCE4);
int d4;


int in1LF = 2;
int in2LR = 3;
int in3RR = 4;
int in4RF = 5;

void setup() {

  pinMode(in1LF, OUTPUT);
  pinMode(in2LR, OUTPUT);
  pinMode(in3RR, OUTPUT);
  pinMode(in4RF, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  Read();
  if ((d1 < 10 && d3 < 15 && d4 < 15) || (d2 < 5 && d3 < 15 && d4 < 15)) {
    digitalWrite (in1LF, LOW);
    digitalWrite (in2LR, LOW);
    digitalWrite (in3RR, LOW);
    digitalWrite (in4RF, LOW);
  }
  else if (d1 > 10) {
    digitalWrite (in1LF, HIGH);
    digitalWrite (in2LR, LOW);
    digitalWrite (in3RR, LOW);
    digitalWrite (in4RF, HIGH);
    if (d3 < 55 && d3 > 27) {
      digitalWrite(in1LF, LOW);
      digitalWrite(in3RR, LOW);
      digitalWrite(in4RF, LOW);
      digitalWrite(in2LR, LOW);

      while (1) {
        digitalWrite(in1LF, HIGH);
        digitalWrite(in3RR, HIGH);
        digitalWrite(in4RF, LOW);
        digitalWrite(in2LR, LOW);
        Read ();
        if (d1 > 20 && d3 > 40)
        { break;
        }

      }
    }
    else if (d4 < 55 && d4 > 27) {


      digitalWrite(in1LF, LOW);
      digitalWrite(in3RR, LOW);
      digitalWrite(in4RF, LOW);
      digitalWrite(in2LR, LOW);

      while (1) {
        digitalWrite(in1LF, LOW);
        digitalWrite(in3RR, LOW);
        digitalWrite(in4RF, HIGH);
        digitalWrite(in2LR, HIGH);
        Read ();
        if (d1 > 20 && d4 > 40)
        { break;
        }
      }
    }
  }
  else if (d1 < 10 && d2 > 70 && d3 < 15 && d4 < 15)
  { digitalWrite(in1LF, LOW);
    digitalWrite(in3RR, LOW);
    digitalWrite(in4RF, LOW);
    digitalWrite(in2LR, LOW);


    while (1)
    { digitalWrite(in1LF, LOW);
      digitalWrite(in3RR, HIGH);
      digitalWrite(in4RF, LOW);
      digitalWrite(in2LR, HIGH);
      Read ();
      if (d2 > 10)
      { break;
      }
    }
  }
}
void Read()
{
  int uS1 = sonar1.ping();
  Serial.print("pingF: ");
  Serial.print(uS1 / US_ROUNDTRIP_CM);
  Serial.println("cm                        ");
  d1 = uS1 / US_ROUNDTRIP_CM;

  int uS2 = sonar2.ping();
  Serial.print("pingB ");
  Serial.print(uS2 / US_ROUNDTRIP_CM);
  Serial.print("cm                 ");
  d2 = uS2 / US_ROUNDTRIP_CM;

  int uS3 = sonar3.ping();
  Serial.print("pingR: ");
  Serial.print(uS3 / US_ROUNDTRIP_CM);
  Serial.print("cm         ");
  d3 = uS3 / US_ROUNDTRIP_CM;

  int uS4 = sonar4.ping();
  Serial.print("pingL: ");
  Serial.print(uS4 / US_ROUNDTRIP_CM);
  Serial.print("cm              ");
  d4 = uS4 / US_ROUNDTRIP_CM;
}
