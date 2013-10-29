/*
  ir_sensor_read
  Andrew Kerr <www.andrewjkerr.com>
  
  Takes in reading from SHARP GP2Y0A02YK0F <https://www.sparkfun.com/products/895> and, if ~1 foot away from sensor, turns on the
    on board LED.
*/
 
int lowerBound = 400;              // Lower bound sensor reading for 1 foot
int upperBound = 480;              // Upper bound sensor reading for 1 foot
int led = 13;                      // On board LED is pin 13
// Below will allow for an external LED to be connected to the Arduino
//int led = xx;                      // External LED is pin xx
const int numValues = 10;          // Number of values to average

// the setup routine runs once when you press reset:
void setup() {
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    pinMode(led,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    // read the input on analog pin 0:
    double avgMeasurement = 0;
    int sensorValue = analogRead(A0);
    for(int i = 0; i < numValues; i++){
       avgMeasurement += analogRead(A0);
    }
    
    avgMeasurement /= numValues;
    
    Serial.println(avgMeasurement);
    
    if((avgMeasurement > lowerBound) && (avgMeasurement < upperBound)){
        digitalWrite(led,HIGH);
        delay(10);
    }
    else{
        digitalWrite(led,LOW);
        delay(10);
    }
}
