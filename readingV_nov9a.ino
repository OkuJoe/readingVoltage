// Voltage Warning Project
// Reads from Potentiometer, converts to Voltage.
// Turns on LED if Voltage > 4V.

// 1. VARIABLES
int my_Led = 9;
int pin = A3;

// Syntax Fix: Variable initialization uses '=' not brackets '()'
int delay_time = 250; 

int read_val; // Raw value (0-1023)
float V;      // Calculated Voltage

void setup() {
  // CONFIGURATION
  Serial.begin(9600);
  
  // Syntax Fix: 'pinMode' uses camelCase (small p, big M).
  pinMode(my_Led, OUTPUT); 
  
  // Good Practice: Explicitly define the input pin
  pinMode(pin, INPUT);
}

void loop() {
  // 2. READ INPUT
  // Syntax Fix: No dot in 'analogRead'. It is one word.
  read_val = analogRead(pin); 

  // 3. CONVERT TO VOLTAGE
  // We divide by 1023.0 because the max reading is 1023 (0 to 1023).
  V = (5.0 / 1023.0) * read_val;  

  // 4. PRINT TO SERIAL MONITOR
  // Syntax Fix: 'Serial.print' (small p).
  Serial.print("The reading is: ");
  
  // Syntax Fix: Corrected spelling of 'Serial' and 'println' (small p).
  Serial.println(V);

  // 5. LOGIC CHECK
  if (V > 4.0) {
    // Syntax Fix: No dot in 'digitalWrite'. Added missing semicolon ';'.
    digitalWrite(my_Led, HIGH);
  } 
  else {
    // Logic Improvement: Using 'else' covers everything 4.0 or less.
    // Syntax Fix: Corrected spelling of 'digitalWrite'.
    digitalWrite(my_Led, LOW);
  }
  
  delay(delay_time);
}


/*
draft code 

// reading value from the potentiometerand then converting it into volatge
// i will add an led to give warnoing if the voltage exceeds 4v 
int my_Led=9;
int delay_time2;
int pin=A3;
int read_val; // the value were reading from the potentiometer
float V; // the voltage we are converting to
int delay_time(250);
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
pinMODE(my_Led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
read_val=analog.Read(pin); // we are getting the read value from the pin A3
V=(5.0/1024)*read_val;  // thea arduino doesnt read 0v 5v or 3v bat instead it reads from(0 to 1024)
 Serial.Print("the reading is:");
 Serail.Println(V);
 delay(delay_time);

if(V>4.0){
digital.Write(my_Led,HIGH)
}
if(V<4.0){  // we can use other operators such as and and Or 
  digitlal.Write(my_Led,LOW);
}
}

/*
For this project the serial monitor displays the value of voltage on the screen as we turn the potentiometer and
when it exceeds 4V the led lightsto give us warning until we reduce the Pd to a value less than 4 then led goes off
*/

*/