#include <SoftwareSerial.h> 

SoftwareSerial maginiBLUE(10, 11);
char DATO = 0;      // variable para almacenar caracter recibido
int LEDROJO = 2;    // LED rojo a pin digital numero 2
int LEDVERDE = 3;   // LED verde a pin digital numero 3
   
void setup(){
  maginiBLUE.begin(38400);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
}

void loop(){
if (maginiBLUE.available()){      // si hay informacion disponible desde modulo
  DATO = maginiBLUE.read();   // almacena en DATO el caracter recibido desde modulo
  if( DATO == '1' )   // 
  digitalWrite(LEDROJO, !digitalRead(LEDROJO));  

  if( DATO == '2' )   // 
  digitalWrite(LEDVERDE, !digitalRead(LEDVERDE)); 
}
}
