/*  
 Iraduino-Ejemplo #6 DipSwitch
 Más información: http://tecdigitaldelbajio.com/productos1/arduino/iraduino.html
 Síguenos: https://www.facebook.com/TecnologiaDigitaldelBajio
 Tienda Virtual: http://tiendavirtual-tdb.com/
 Irapuato, Gto. 21 de febrero de 2016,  Tecnología Digital del Bajío
 */
  
#define DELAY 500 //** Retardo de 500 mSeg
#define SW1 A0
#define SW2 A1
#define SW3 A2
#define SW4 A3


int pin[]={2,3,4,5,6,7,8,9}; // se declara este arreglo, para el acceso a cada PIN que se va a usar.

// the setup function runs once when you press reset or power the board
int i,j;                  
  // Arreglo bidimensional para el display, orden de los segmentos: a, b, c, d, e, f, g, x, el display es ánodo común, para que encienda un led se envía un "0"
byte Display7Seg[10][7] = { { 0,0,0,0,0,0,1 }, // Número 0 en 7 segmentos
                           { 1,0,0,1,1,1,1 },  // #1
                           { 0,0,1,0,0,1,0 },  // #2
                           { 0,0,0,0,1,1,0 },  // #3
                           { 1,0,0,1,1,0,0 },  // #4 
                           { 0,1,0,0,1,0,0 },  // #5
                           { 0,1,0,0,0,0,0 },  // #6
                           { 0,0,0,1,1,1,1 },  // #7                                 
                           { 0,0,0,0,0,0,0 },  // #8
                           { 0,0,0,0,1,0,0 },  // #9                           
                        };
 
void setup() {
   
  for(i=0;i<8;i++){ //Ciclo para configurar cada uno de los PINES como de Salida.
     pinMode(pin[i],OUTPUT);
  }
  pinMode(SW1, INPUT); pinMode(SW2, INPUT), pinMode(SW3, INPUT); pinMode(SW4, INPUT);
}
void MostrarEnDisplay(int Digito) {
    for (j=0;j<8;j++){
     digitalWrite(pin[j], Display7Seg[Digito][j]);       
    }
}    
// the loop function runs over and over again forever
void loop() {
  int x, valor1, valor2, valor3, valor4, valorHEX;
  valor1 = digitalRead(SW1);
  valor2 = digitalRead(SW2); valor3 = digitalRead(SW3);  valor4 = digitalRead(SW4);
  valorHEX = 0x0F & ((valor4 << 3) | (valor3 << 2) | (valor2 << 1) | valor1);  
  switch(valorHEX) {
    case 0x00:MostrarEnDisplay(0); break;
    case 0x01:MostrarEnDisplay(1); break;
    case 0x02:MostrarEnDisplay(2); break;
    case 0x03:MostrarEnDisplay(3); break;
    case 0x04:MostrarEnDisplay(4); break;
    case 0x05:MostrarEnDisplay(5); break;
    case 0x06:MostrarEnDisplay(6); break;
    case 0x07:MostrarEnDisplay(7); break;
    case 0x08:MostrarEnDisplay(8); break;
    case 0x09:MostrarEnDisplay(9); break;
  }      
}
