const int LEDPin1= 27;
const int LEDPin2= 26;
const int LEDPin3= 13;
const int LEDPin4= 12;

const int PIRPin1= 15;
const int PIRPin2= 16;
const int PIRPin3= 17;
const int PIRPin4= 18;

void setup()
{
  Serial.begin(9600); 
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
 

  pinMode(PIRPin1, INPUT);
  pinMode(PIRPin2, INPUT);
  pinMode(PIRPin3, INPUT);
  pinMode(PIRPin4, INPUT);
}
void loop()
{
  int value1= digitalRead(PIRPin1);
  int value2= digitalRead(PIRPin2);
  int value3= digitalRead(PIRPin3);
  int value4= digitalRead(PIRPin4);

  if (!value1==1 || !value1==0){
    digitalWrite(LEDPin1, !value1);
    delay(50);
    digitalWrite(LEDPin2, !value1);
    delay(50);
  }
   
   if (!value2==1 || !value2==0){ 
    
    digitalWrite(LEDPin2, !value2);
    delay(50);
    digitalWrite(LEDPin1, !value2);
    delay(50);
    digitalWrite(LEDPin3, !value2);
    delay(50);
    }
  
    
  if (!value3==1 || !value3==0){ 
   
    digitalWrite(LEDPin3, !value3);
    delay(50);
    digitalWrite(LEDPin2, !value3);
    delay(50);
    digitalWrite(LEDPin4, !value3);
    delay(50);
    }
    
    if (!value4==1 || !value4==0){
    digitalWrite(LEDPin4, !value4);
    delay(50); 
    digitalWrite(LEDPin3, !value4);
    delay(50);
    
    }
   Serial.println("valor1");
   Serial.println(!value1);
   Serial.println("valor2");
   Serial.println(!value2);
   Serial.println("valor3");
   Serial.println(!value3);
   Serial.println("valor4");
   Serial.println(!value4);
 
 





    
    

      
 

         
        
      
   
  

}



  
/*if (!value1==1){
    digitalWrite(LEDPin1, !value1);
    delay(500);
    digitalWrite(LEDPin2, !value2);
}
   if (!value==1){ 
    digitalWrite(LEDPin3, !value3);
    delay(500);
    digitalWrite(LEDPin4, !value4);
    
  

    }*/
