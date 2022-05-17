 // Rotary Encoder Inputs qui s'incrémente en fonction des tours
 #define inputCLK 4
 #define inputDT 5
 
 int counter = 0; 
 int currentStateCLK;
 int previousStateCLK;
 
 const float pi = 3.14;
 const float R = 1.5;
 const int N = 10;
 float distance = 0;

 void setup() { 
   
   // Set encoder pins as inputs  
   pinMode (inputCLK,INPUT);
   pinMode (inputDT,INPUT);
   
   // Setup Serial Monitor
   Serial.begin (9600);
   
   // Read the initial state of inputCLK
   // Assign to previousStateCLK variable
   previousStateCLK = digitalRead(inputCLK);

 } 

 void loop() { 
  
  // Read the current state of inputCLK
   currentStateCLK = digitalRead(inputCLK);
    
   // If the previous and the current state of the inputCLK are different then a pulse has occured
   if (currentStateCLK != previousStateCLK){ 
       
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT) != currentStateCLK) { 
       //counter --;
counter ++;
       
     } /*else {
       // Encoder is rotating clockwise
       counter ++;     
     }*/

    distance = ((2*pi*R)/N) * counter / 2
    ;

    // distance = (2*pi*R) * counter ;
     
     
     Serial.print("Direction: ");
     Serial.println(counter);
     Serial.println(distance); 
   } 
   // Update previousStateCLK with the current state
   previousStateCLK = currentStateCLK; 
 }
