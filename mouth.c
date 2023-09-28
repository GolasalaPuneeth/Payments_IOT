#include <Servo.h>
// creating a servo object
Servo myservo;

int ServoPin = 9;
int SoundInPin = A2;

void setup()
{

    Serial.begin(115200);
    myservo.attach(ServoPin);
    pinMode(SoundInPin, INPUT);
}

void loop()
{
    int sensorValue = analogRead(SoundInPin);
    Serial.println("sensor value ...");
    Serial.println(sensorValue);
    sensorValue = map(sensorValue, 0, 40, 90, 180);
    Serial.println("sensor value after mapping ...");
    Serial.println(sensorValue);
    myservo.write(90);
    if (sensorValue > 100)
    {
        for (short i = 0; i <= sensorValue; i++)
        {
            myservo.write(i);
            delay(15);
        }
    }

    else
    {

        for (short j = sensorValue; j <= 0; j--)
        {
            myservo.write(j);
            delay(7);
        }
    }
}
