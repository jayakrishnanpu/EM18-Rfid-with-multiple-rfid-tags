#include <SoftwareSerial.h>
const int t=3; //total number of rfid tags
String tag[3]={"430039FA42C2","430039FA3FBF"}; //your rfid codes
const byte rxPin = 2; //defining rx pin 
const byte txPin = 3; //defining rx pin
String id;
int flag=0;
// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Scan RFID Tag!");

  // set the data rate for the SoftSerial port
  mySerial.begin(9600);
}

void loop()                     // run over and over again
{

  if (mySerial.available()>0) {
   id= mySerial.readString();
   Serial.print("Given Id:");
   Serial.print(id); //prints the scanned id
   Serial.println();

   for(int i=0;i<t;i++){
     if(id==tag[i])  //checking for a match
     {
       flag=1;break; 
     }
   }
   
   if(flag==1){
     Serial.println("Access Granted"); //result
     flag=0;
   }
   else{
     Serial.println("Access Denied"); //result
   }
  }

}