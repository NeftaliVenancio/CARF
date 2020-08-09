
//Primera revisión del proyecto
#include <VirtualWire.h>

char dato[1];

int btni =7;
int btna =8;
int btnd =9;
int btnr = 10;


void setup()
{

    Serial.begin(9600);    
    Serial.println("Emisor RF");

    // Se inicializa el RF
    vw_setup(2000); // velocidad: Bits per segundo
    vw_set_tx_pin(12); //Pin 2 como salida para el RF 

    pinMode(btni, INPUT);
    pinMode(btnd, INPUT);
    pinMode(btna, INPUT); 
    pinMode(btnr, INPUT);   

}


void loop() {

if (digitalRead(btna) == LOW) 
    {

        dato[0] ="a";
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();

        digitalWrite(13,HIGH);

        //Serial.println("enviado2");
    
    }

else
    {

        digitalWrite(13,LOW);

    }

if (digitalRead(btnd) == LOW) 
    {

        dato[0] ="d";
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();
        digitalWrite(13,HIGH);
        Serial.println("enviado");

    }

else 
    {

        digitalWrite(13,LOW);

    }

if (digitalRead(btni) == HIGH) 
    {

        dato[0] ="i";
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();

    }

else 
    {

        digitalWrite(13,LOW);

    }

if (digitalRead(btnr) == HIGH) 
    {

        dato[0] ="r";
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();

    }

else 
    {

        digitalWrite(13,LOW);

    }

} 
