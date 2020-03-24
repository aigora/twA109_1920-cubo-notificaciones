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

-Módulo Bluethooot (HC-05)
 Primero tendremos que emparejar el módulo con nuestro dispositivo. El proceso de emparejado depende del sistema operativo.

Para establecer la comunicación desde el dispositivo, podemos usar el propio Serial Monitor del Arduino IDE.

Una vez conectados tanto el módulo como el dispositivo, se permitira el intercambio de datos de ambos, la cual sería la función principal de este módulo.

-Leds RGB
Es como un led normal, pero trae los tres colores primarios (azul, verde y rojo) y dependiendo de la intensidad de corriente que se le suministre lucirán los tres colores con distintas intensidades para dar lugar a la gama cromática.
## Bibliografía
Leds RGB https://ardubasic.wordpress.com/2014/04/08/led-rgb/

Módulo Bluethoot https://www.luisllamas.es/conectar-arduino-por-bluetooth-con-los-modulos-hc-05-o-hc-06/
