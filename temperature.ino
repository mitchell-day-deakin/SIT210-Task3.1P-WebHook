// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>


int tempPin = D6;
//int temp, temp1;
String temp;
int sensorValue;
#define DHTTYPE DHT11

DHT dht(tempPin, DHTTYPE);


void setup() {
    pinMode(tempPin,INPUT);
    //Particle.variable("temp", temp);
    dht.begin();
}


void loop() {
    float t = dht.getTempCelcius();
    //temp = digitalRead(tempPin);
    temp = String(t);
    //temp1 = rand() % 100;
    Particle.publish("temp", temp, PUBLIC);
    delay(30000);
}