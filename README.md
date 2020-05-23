# Cubo Notificaciones

Cubo translúcido que recibirá notificaciones desde un teléfono. Según de la aplicación de la que venga la notificación se iluminará de un color u otro.

## Integrantes del equipo

Alberto Vicente Chacón (albertovic) 
Carlos Miguel Martín (CarlosMiguelMartin)

## Objetivos del trabajo

Analizar y comprender cómo funciona el sistema de notificaciones de un smartphone a nivel de programación. 
Aprender a comunicar un teléfono inteligente con una placa de arduino. 
Comprender cómo funcionan los led RGB.
 
 ## Identificación de sensores y actuadores
 
 Sistema electrónico basado en un microcontrolador capaz de detectar las distintas notificaciones de un doispositivo móvil. El sistema incorporará un módulo bluethooth, tal que este pueda comunicarse con el dispositivo móvil. También incorporará unos leds RGB, dependiendo de que tipo de notificación sea luzcan de un color o de otro.
 
 ### Fundamento Teórico

-Módulo Bluethooot (HC-06)
 Primero tendremos que emparejar el módulo con nuestro dispositivo. El proceso de emparejado depende del sistema operativo.

Para establecer la comunicación desde el dispositivo, podemos usar el propio Serial Monitor del Arduino IDE.

Una vez conectados tanto el módulo como el dispositivo, se permitira el intercambio de datos de ambos, la cual sería la función principal de este módulo.

-Leds RGB
Es como un led normal, pero trae los tres colores primarios (azul, verde y rojo) y dependiendo de la intensidad de corriente que se le suministre lucirán los tres colores con distintas intensidades para dar lugar a la gama cromática.

## Identificar subprogramas

Vamos a utilizar dos funciones principalmente:

-funcion_seleccion1 (sliders):

El argumento que vamos a usar es un vector fila de tipo int llamado "vector_color" que tendrá tres variables dentro. Cada variable (vector_color[0],vector_color[1],vector_color[2]) irá asignada a la intensidad de uno de los tres colores primarios del led.
El procesamiento será la asignación de los valores de los "sliders" a sus variables correspondientes, dependiendo de la posición de estos. El valor de la variable irá de 0 a 255, siendo esto el rango de intensidad que puede tomar cada color del led.
La salida será cada una de las variables con su valor.

La salida es el vector con los valores cambiados, listo para ser leido por los led.

-funcion_seleccion2 (botones predeterminados):

El argumento que vamos a usar en esta función es una estructura de datos, formada por tres variables de tipo int. Cada variable irá asignada a un color (Rojo, verde o azul).
El procesamiento será leer el botón que se está pulsando en ese momento y, tras eso, mandar la información de cada color predeterminado a los led para que la lean.
La salida será la estructura de datos con los valores de sus variables modificados.

## Código 

#include <SoftwareSerial.h>

    SoftwareSerial BT (9, 10);
    
    void botones(struct Colores *);

    void sliders(float vector_color[]);
    
    int pinR = 6;
    int pinG = 5;
    int pinB = 3;
    //Se utilizan pines compatibles con señales PWM
    
    int x; //Será nuestra variable para controlar qué funcion usar
    
    struct Colores
    {
      int rojo;
      int verde;
      int azul;
    }; //Se utiliza una estructura para los botones
    
  Colores c;
    
    /*float s_r;
    float s_v;
    float s_a;
    */
    int vector_color[3]; //Se utiliza un vector para los sliders
    
    void setup(){
      BT.begin(9600);
      Serial.begin(9600);
      
        pinMode(pinR,OUTPUT); // Es el pin que dará la intensidad al color rojo (Red)
        pinMode(pinG,OUTPUT); // Es el pin que dará la intensidad al color verde (Green)
        pinMode(pinB,OUTPUT); // Es el pin que dará la intensidad al color azul (Blue)
    }


void loop(){
  
   while(BT.available())
{
  x = BT.parseInt();
  if (x=1)
  {
    sliders(vector_color);
  }
  if (x=2)
  {
  botones(&c);
  }
  }
}    

void botones (struct Colores * c)
{
    c->rojo = BT.parseInt();
    c->verde = BT.parseInt();
    c->azul = BT.parseInt();
  
  if (BT.read()=='\n')
    {
      analogWrite(pinR, c->rojo);
      analogWrite(pinG, c->verde);
      analogWrite(pinB, c->azul);
    }
}

void sliders(int vector_color[])
{
    vector_color[0] = BT.parseInt();
    vector_color[1] = BT.parseInt();
    vector_color[2] = BT.parseInt();

    if (BT.read()=='\n')
    {
      analogWrite(pinR, vector_color[0]);
      analogWrite(pinG, vector_color[1]);
      analogWrite(pinB, vector_color[2]);
    }
} 
      
## Bibliografía
Leds RGB https://ardubasic.wordpress.com/2014/04/08/led-rgb/

Módulo Bluethoot https://www.luisllamas.es/conectar-arduino-por-bluetooth-con-los-modulos-hc-05-o-hc-06/
