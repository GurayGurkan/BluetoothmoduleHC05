#include <ADXL345.h>
#include <Wire.h>
#include <SoftwareSerial.h>


SoftwareSerial bt(7, 8); //RX,TX
unsigned long START;
int trigger=9;

bool BTmode;
bool go;

unsigned long tic;

ADXL345 accelerometer;

int n;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigger,OUTPUT);
  //Serial.begin(115200);
  bt.begin(115200);
  delay(1000);
  bt.println("Waiting For Start (g)...");
  //Serial.println("Waiting For Start (g)...");
  do
  {
    delay(500);
  }
  while (bt.read() != 'g');
  //while (Serial.read() != 'g');
  //bt.println("Connection OK...");

  accelerometer.begin();
  delay(10);

  accelerometer.setDataRate(ADXL345_DATARATE_200HZ);
  delay(1);
  accelerometer.setRange(ADXL345_RANGE_2G);
  delay(1);
  //bt.println("Accelerometer OK");
  delay(10);
  go = true;
  n = 0;
  START = millis();
  PORTB &= ~0x02;
}

void loop() {

  if (bt.available() == 0 and go)
  //if (Serial.available() == 0 and go)
  {
    
    PORTB |=0x02;
    Vector raw = accelerometer.readRaw();
    do
    {
      }
    while(!accelerometer.readActivites().isDataReady);
    
    /*  
            
            
            Serial.print((int) raw.XAxis);
            Serial.print(",");
            Serial.print((int)raw.YAxis);
            Serial.print(",");
            Serial.println((int)raw.ZAxis);
            
      */      
      
      //         BT Mode
      
      bt.print((int) raw.XAxis);
      bt.print(",");
      bt.print((int)raw.YAxis);
      bt.print(",");
      bt.println((int)raw.ZAxis);
    
    PORTB &=~0x02;
    delayMicroseconds(1000);
    
  }
  
  else if (bt.available())
  {
    if (bt.read() == 'f')
    {
      bt.println("Finished");
      go = false;
    }
  }
  
  /*
  
    else if (Serial.available())
    {
      if (Serial.read() == 'f')
      {
  
        Serial.println(millis() - START);
        go = false;
      }
    }
  */
}
