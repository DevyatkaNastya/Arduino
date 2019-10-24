#define max_char 12
char message[max_char];    
char currentChar;               
byte index = 0;            
int i;

int redPin = 11;     
int greenPin = 10;   
int bluePin = 9;       

String redStrVal;     
String greenStrVal;   
String blueStrVal;     

int flag = 0;
char currentColor;  

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0){
    flag = 0;
    if(index < (max_char-1)){         
      currentChar = Serial.read();      
      message[index] = currentChar;     
      if(currentChar=='R'){
         currentColor = 'R';
         redStrVal = "";
      }
      else if(currentChar=='G'){
         currentColor = 'G';
         greenStrVal = "";
      }
      else if(currentChar=='B'){
         currentColor = 'B';
         blueStrVal = "";
      }
      if(currentColor == 'R' && currentChar!='R'){
         redStrVal += currentChar;
      }
      else if(currentColor == 'G' && currentChar!='G'){
         greenStrVal += currentChar;
      }
      else if(currentColor == 'B' && currentChar!='B'){
         blueStrVal += currentChar;
      }
      index++;                    
      message[index] = '\0';       
   }
 }
 
 if(flag == 0){
   analogWrite(redPin, 255-redStrVal.toInt());
   analogWrite(greenPin, 255-greenStrVal.toInt());
   analogWrite(bluePin, 255-blueStrVal.toInt());
   flag=1;
       for(i=0; i<max_char; i++){
      message[i] = '\0';
    } 
    index=0;  
 }
}
