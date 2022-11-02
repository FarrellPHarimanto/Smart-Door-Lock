#include <Servo.h>
String readString;
#define RELAY 3    //Connect relay1 to pin D3

Servo servoini;

void setup()
{
  Serial.begin(9600);           //Set rate for com
  municating with phone
  pinMode(RELAY, OUTPUT);      //Set relay1 as an output 
  servoini.attach(8);
}
void loop()
{
   digitalWrite(RELAY, LOW);
   while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
                  
     if(readString == "f success"){
        digitalWrite(RELAY, HIGH);
        delay(1000);
        
        int sudut = 0;
        for (sudut = 0; sudut <= 90; sudut += 1)
    {
        servoini.write(sudut);
        delay(15);
    }
    
        delay(5000);
        for (sudut = 90; sudut >= 0; sudut -= 1)
    {
        servoini.write(sudut);
        delay(15);
    }
}
      
      else {
        servoini.write(0);
}
      }
      readString="";
    }
