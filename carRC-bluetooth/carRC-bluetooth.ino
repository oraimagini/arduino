#include <Servo.h>                // Incluye la libreria Servo
Servo servo1;                    // Crea el objeto servo1 con las caracteristicas de Servo

int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)
int estado = 'c';         // inicia detenido


void setup()  { 
  Serial.begin(38400);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(13,OUTPUT);

  servo1.attach(11,660,1400);    // Asocia el servo1 al pin 11, define el min y max del ancho del pulso  
                                 // eso depende del fabricante del servo
} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='a'){           // Boton desplazar al Frente
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);       
  }
  if(estado=='b'){          // Boton IZQ 
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);      
  }
  if(estado=='c'){         // Boton Parar
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0); 
  }
  if(estado=='d'){          // Boton DER
    analogWrite(derB, 0);     
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);  
  } 

  if(estado=='e'){          // Boton Reversa
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);      
  }
  


    if(estado=='h'){                 //Programacion de los botones 13-10-9-6-5
    digitalWrite(13,1);        
  }
      if(estado=='m'){           
    digitalWrite(13,0);        
  }
    if(estado=='i'){           
    digitalWrite(derB,1);        
  }
    if(estado=='n'){           
    digitalWrite(derB,0);        
  }
    if(estado=='j'){           
    digitalWrite(derA,1);        
  }
    if(estado=='o'){           
    digitalWrite(derA,0);        
  }
    if(estado=='k'){           
    digitalWrite(izqB,1);        
  }
    if(estado=='p'){           
    digitalWrite(izqB,0);        
  }
    if(estado=='l'){           
    digitalWrite(izqA,1);        
  }
    if(estado=='q'){           
    digitalWrite(izqA,0);        
  }
  
}
