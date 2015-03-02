// Garduino Project 
// Author: cRAKENSIO   TWITTER: @crakensio

int moisture,Vout, bfre;



void setup()
{
  
  pinMode(A0,INPUT); // Analog input for Soil Moisture Sensor
  pinMode(A1,INPUT); // LDR VALUE
  pinMode(2,OUTPUT); // Enable Pin For Motor 
  pinMode(5,OUTPUT); // Enable B1
  pinMode(6,OUTPUT); // Enable B2
   pinMode(3,OUTPUT); //LED 1 visualize as a lamp :P
   pinMode(4,OUTPUT); // LED 2 visualize as another lamp :P
  digitalWrite(2,HIGH); // Enabling the Motor in ON state
  Serial.begin(9600);
  
}

void loop()
{
  
  moisture=analogRead(A0); // Reading the Moisture content from Soil
  Vout=analogRead(A1);  // Reading the Light intensity (" Light from the sun ") :D

  Serial.print("    ");
  Serial.print(moisture);
  Serial.print("       ");
  Serial.print(Vout);
  Serial.println(" ");
  
  if((moisture>=0)&&(moisture<=350)) // Moisture Content is too HIGH
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(1000);
    Serial.println(" Watery");   
  }
  
  else if((moisture>350)&&(moisture<700))   // Moisture Content is moderate i.e Humid
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(1000);
    Serial.println(" Im Humid");
  }
  
  else if((moisture>=700)&&(moisture<=1023))    // Moisture Content is too LOW I.E DRY
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(1000);
    Serial.println(" Im thirsty Pls pour some Water");
    delay(100);
  }

if((Vout>400))   // Light intensity is HIGH
{
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  delay(1000);
}

else if(Vout<399)    //  Light intensity is LOW artificial Light is needed
{
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
delay(1000);
}

}
