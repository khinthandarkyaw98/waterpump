
const int trigPin = 8;
const int echoPin = 9;
const int motorpin = 7;
const int LED = 2;
int pflag = 1;

void setup() 
{
  // initialize serial communication:
  pinMode(motorpin,OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  long duration, inches;
  
  digitalWrite(LED, LOW);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  inches = microsecondsToInches(duration);

  if(pflag == 1 && inches >=7)
    {
      digitalWrite(motorpin,HIGH);
      digitalWrite(LED,HIGH);
      delay(1000);
    }
    else if (pflag == 1 &&  inches >3)
    {
      digitalWrite(motorpin,HIGH);
      digitalWrite(LED,HIGH);
      pflag=1;
      delay(1000);
    }
    else if(pflag == 1 &&  inches <3)
    {
      digitalWrite(motorpin,LOW);
      digitalWrite(LED,LOW);
      pflag=0;
      delay(1000);
    }
     else if(pflag == 0 &&  inches <7)
    {
      digitalWrite(motorpin,LOW);
      digitalWrite(LED,LOW);
      pflag=0;
      delay(1000);
    }
    else
    {
      pflag=1;
      delay(1000);
    }
 delay(1000);

}

long microsecondsToInches(long microseconds)
{
    return microseconds / 74 / 2;
}
