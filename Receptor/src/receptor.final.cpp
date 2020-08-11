
//Primera revision del codigo 

#include <VirtualWire.h>

uint8_t dato;
uint8_t datoleng=1;

//int E1 =6;
int D1 =7;
int D2 =8;

//int E2 =9;
int Di1 =10;
int Di2 =11;

//hola mundo
Serial.println();

int luz = 3;
void avanzar()
{
  digitalWrite(D1,HIGH);
  digitalWrite(Di1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(Di2,HIGH);
}

void retroceder()
{
  digitalWrite(D1,HIGH);
  digitalWrite(Di1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(Di2,HIGH);
}

void derecha()
{
  digitalWrite(D1,HIGH);
  digitalWrite(Di1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(Di2,HIGH);
}

void izquierda()
{
  digitalWrite(D1,HIGH);
  digitalWrite(Di1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(Di2,HIGH);
}


void girar()
{
  
}

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(12);  //Pin 2 como entrada del RF
    vw_rx_start();       // Se inicia como receptor
    
    pinMode(13, OUTPUT);    //Configuramos el pin del Led como entrada
    
    
    pinMode(D1, OUTPUT);
    pinMode(Di1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(Di2, OUTPUT);
}

void loop()
{
    
    //verificamos si hay un dato valido en el RF
    if (vw_get_message(&dato,&datoleng))
    {
        if((char)dato=='a')
        {
            //Carrito avanza
            avanzar();
        }
        else 
        {
       
        digitalWrite(D1, false); 
        
        digitalWrite(Di1, false);
        }

        if((char)dato=='d')
        {
          
            digitalWrite(D1, true); 
            digitalWrite(D2, false);
        }
        else 
        {
       
        digitalWrite(D1, false); 
       
        digitalWrite(Di1, false);
        }

}
}
