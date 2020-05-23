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
      float rojo;
      float verde;
      float azul;
    }; //Se utiliza una estructura para los botones
    
  Colores c;
    
    /*float s_r;
    float s_v;
    float s_a;
    */
    float vector_color[3]; //Se utiliza un vector para los sliders
    
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

void sliders(float vector_color[])
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
