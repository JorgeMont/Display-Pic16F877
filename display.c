//Version Final
//En esta version se emplearon los comandos completos
#include <16f877.h>
#fuses HS,NOPROTECT,
#use delay(clock=20000000)
#use rs232(baud=38400, xmit=PIN_C6, rcv=PIN_C7)
#org 0x1F00, 0x1FFF void loader16F877(void) {} //for the 8k 16F876/7

//Definiciones

#byte    PORTB =  0x06
#byte    PORTE =  0x09

#define  RS       2
#define  RW       1
#define  E        0

//Declaracion de funciones globales
void fncEscribe(char);

void teclado();

void tabla(int);

void cadena(int);

void apellidosm(); //5 Apellidos con M

void lenguasguatemala(); //5 lenguas de Guatemala

void africa(); //6 paises africanos

void playasc(); //5 playas de Cuba

void asia(); //seis paises asiaticos

void nombresmh(); //Muestra seis nombres de mujeres con H

void sabores(); //5 sabores de agua natural

void enp4(); //Nombre y direccion de ENP4

void error();

void espacio();

void comando();

int cont=0;
int DATA11[11], DATA;
int i=8,n;
int pos=0, com[16];   //vbles para los 8 comandos, si cambio esto puedo meter todos los comandos?

void main()
{

   //Puerto B como salida
   set_tris_b(0x00);
   //Puerto E como salida
   set_tris_e(0x00);

   //Condicion Inicial
   //Todos los puertos en 0
   output_b(0x00);
   output_e(0x00);

   delay_ms(16);        //Retardo de 16ms

   //Nota: Siempre que se manda un comando
   //la terminal de control debe ser puesta a 1 (E=1)
   //y luego rehresada a cero (E=0)

   bit_set(PORTE,E);    //E=1
   output_b(0x30);      //PORTB = 30H
   bit_clear(PORTE,E);  //E=0

   //3.
   delay_ms(5);         //Retardo de 5ms

   //4.
   bit_set(PORTE,E);    //E=1
   output_b(0x30);      //PORTB = 30H
   bit_clear(PORTE,E);  //E=0

   //5.
   delay_us(105);       //Retardo de 105us

   //6.
   bit_set(PORTE,E);    //E=1
   output_b(0x30);      //PORTB = 30H
   bit_clear(PORTE,E);  //E=0

   //Ahora debe haber retardos de 2ms entre cada
   //cada instruccion para que puedan ser leidos
   //por la LCD.

   delay_ms(2);         //Retardo de 2ms

   //7.Function Set
   bit_set(PORTE,E);    //E=1
   output_b(0x38);      //PORTB = 38H
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms

   //8.Display Off
   bit_set(PORTE,E);    //E=1
   output_b(0x08);      //PORTB = 08H
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms

   //9.Display Clear
   bit_set(PORTE,E);    //E=1
   output_b(0x01);      //PORTB = 01H
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms

   //10. Entry Mode Set
   bit_set(PORTE,E);    //E=1
   output_b(0x06);      //PORTB = 06H
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms

   //-----------------------------------//
   //Fin de la Inicializacion de la LCD
   //-----------------------------------//


   //Enciende el display
   bit_set(PORTE,E);    //E=1
   output_b(0x0F);      //PORTB = 0CH
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms

   for(n=0; n<40; n++){ //pasa cursor a 2a linea
   bit_set(PORTE,E);    //E=1
   output_b(0x14);      //PORTB
   bit_clear(PORTE,E);  //E=0
   delay_ms(2);         //Retardo de 2ms
   }
   //Pasar a modo dato
   bit_set(PORTE,RS);      //RS=1
   bit_clear(PORTE,RW);    //RW=0

      //Escribe el mensaje

   //pag 63 Compilador C Ccs
   //Mensaje personalizado

   espacio();
   fncEscribe('W');
   fncEscribe('A');
   fncEscribe('Z');
   fncEscribe('Z');
   fncEscribe('A');
   fncEscribe('P');
   fncEscribe(' ');
   fncEscribe(':');
   fncEscribe('P');
   fncEscribe(' ');

      //Pasar a modo comando
   bit_clear(PORTE,RS);      //RS=0
   bit_clear(PORTE,RW);    //RW=0

      //regresa cursor al inicio
   bit_set(PORTE,E);    //E=1
   output_b(0x02);      //PORTB = 02H
   bit_clear(PORTE,E);  //E=0

   delay_ms(2);         //Retardo de 2ms


   bit_clear(PORTE,RS);      //RS=1
   bit_clear(PORTE,RW);    //RW=0
   output_b(0xC0);

   bit_clear(PORTE,RS);      //RS=1
   bit_clear(PORTE,RW);    //RW=0
   output_b(0x0F);

   //Pasar a modo dato
   bit_set(PORTE,RS);      //RS=1
   bit_clear(PORTE,RW);    //RW=0
   teclado();

}//main


//Funcion que escribe un caracter en la LCD
void fncEscribe(char car){
      //Pasar a modo dato
      bit_set(PORTE,RS);
      bit_clear(PORTE,RW);

      bit_set(PORTE,E);    //E=1
      output_b(car);       //PORTB = car
      bit_clear(PORTE,E);  //E=0
      delay_ms(300);
}
void apellidosm(){
   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe(' ');
   fncEscribe('M');
   fncEscribe('O');
   fncEscribe('N');
   fncEscribe('T');
   fncEscribe('E');
   fncEscribe('R');
   fncEscribe('R');
   fncEscribe('O');
   fncEscribe('S');
   fncEscribe('A');
   fncEscribe('S');
   fncEscribe(' ');

      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('M');
   fncEscribe('E');
   fncEscribe('N');
   fncEscribe('D');
   fncEscribe('I');
   fncEscribe('O');
   fncEscribe('L');
   fncEscribe('A');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('M');
   fncEscribe('E');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe(' ');

      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('M');
   fncEscribe('E');
   fncEscribe('D');
   fncEscribe('I');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('M');
   fncEscribe('O');
   fncEscribe('R');
   fncEscribe('A');
   fncEscribe('L');
   fncEscribe('E');
   fncEscribe('S');
   fncEscribe(' ');
}

void lenguasguatemala(){
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('K');
   fncEscribe('A');
   fncEscribe('Q');
   fncEscribe('C');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe('K');
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('M');
   fncEscribe('A');
   fncEscribe('M');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('P');
   fncEscribe('O');
   fncEscribe('Q');
   fncEscribe('O');
   fncEscribe('M');
   fncEscribe('C');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('Z');
   fncEscribe('U');
   fncEscribe('T');
   fncEscribe('U');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe('L');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('A');
   fncEscribe('C');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe(' ');
}

void asia(){
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('B');
   fncEscribe('A');
   fncEscribe('N');
   fncEscribe('G');
   fncEscribe('L');
   fncEscribe('A');
   fncEscribe('D');
   fncEscribe('E');
   fncEscribe('S');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('C');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();

   espacio();
   fncEscribe('J');
   fncEscribe('A');
   fncEscribe('P');
   fncEscribe('O');
   fncEscribe('N');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('R');
   fncEscribe('U');
   fncEscribe('S');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('T');
   fncEscribe('A');
   fncEscribe('I');
   fncEscribe('L');
   fncEscribe('A');
   fncEscribe('N');
   fncEscribe('D');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('V');
   fncEscribe('I');
   fncEscribe('E');
   fncEscribe('T');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe('M');
   fncEscribe(' ');
}

void africa(){
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('B');
   fncEscribe('U');
   fncEscribe('R');
   fncEscribe('U');
   fncEscribe('N');
   fncEscribe('D');
   fncEscribe('I');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('E');
   fncEscribe('G');
   fncEscribe('I');
   fncEscribe('P');
   fncEscribe('T');
   fncEscribe('O');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('G');
   fncEscribe('H');
   fncEscribe('A');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('K');
   fncEscribe('E');
   fncEscribe('N');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('N');
   fncEscribe('I');
   fncEscribe('G');
   fncEscribe('E');
   fncEscribe('R');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('Z');
   fncEscribe('A');
   fncEscribe('M');
   fncEscribe('B');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');

}

void nombresmh(){
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe('L');
   fncEscribe('D');
   fncEscribe('A');
   fncEscribe(' ');
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('E');
   fncEscribe('I');
   fncEscribe('D');
   fncEscribe('I');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe('E');
   fncEscribe('N');
   fncEscribe('A');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('A');
   fncEscribe('Y');
   fncEscribe('D');
   fncEscribe('E');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe('G');
   fncEscribe('A');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H');
   fncEscribe('E');
   fncEscribe('R');
   fncEscribe('M');
   fncEscribe('I');
   fncEscribe('O');
   fncEscribe('N');
   fncEscribe('E');
   fncEscribe(' ');

}

void sabores(){
   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('J');
   fncEscribe('A');
   fncEscribe('M');
   fncEscribe('A');
   fncEscribe('I');
   fncEscribe('C');
   fncEscribe('A');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('L');
   fncEscribe('I');
   fncEscribe('M');
   fncEscribe('O');
   fncEscribe('N');
   fncEscribe(' ');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('H'); //1
   fncEscribe('O'); //2
   fncEscribe('R'); //3
   fncEscribe('C'); //4
   fncEscribe('H'); //5
   fncEscribe('A'); //6
   fncEscribe('T'); //7
   fncEscribe('A'); //8
   fncEscribe(' ');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio(); //9
   fncEscribe('S'); //10
   fncEscribe('A'); //11
   fncEscribe('N'); //12
   fncEscribe('D'); //13
   fncEscribe('I'); //14
   fncEscribe('A'); //15
   fncEscribe(' '); //16

   //Pasar a modo comando
   comando();
   espacio(); //5
   fncEscribe('M'); //6
   fncEscribe('E'); //7
   fncEscribe('L'); //8
   fncEscribe('O'); //9
   fncEscribe('N'); //10
   fncEscribe(' '); //11
}
//playas
void playasc(){

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('V');
   fncEscribe('A');
   fncEscribe('R');
   fncEscribe('A');
   fncEscribe('D');
   fncEscribe('E');
   fncEscribe('R');
   fncEscribe('O');
   fncEscribe(' ');
      //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('A');
   fncEscribe('N');
   fncEscribe('C');
   fncEscribe('O');
   fncEscribe('N');
   fncEscribe(' ');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe(' ');
   fncEscribe('P');
   fncEscribe('I');
   fncEscribe('L');
   fncEscribe('A');
   fncEscribe('R');
   fncEscribe(' ');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('C');
   fncEscribe('A');
   fncEscribe('Y');
   fncEscribe('O');
   fncEscribe(' ');
   fncEscribe('L');
   fncEscribe('A');
   fncEscribe('R');
   fncEscribe('G');
   fncEscribe('O');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   espacio();
   fncEscribe('S');
   fncEscribe('A');
   fncEscribe('E');
   fncEscribe('T');
   fncEscribe('I');
   fncEscribe('A');
   fncEscribe(' ');
}//termina playas

void enp4(){
   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('V');
   fncEscribe('I');
   fncEscribe('D');
   fncEscribe('A');
   fncEscribe('L');
   fncEscribe(' ');
   fncEscribe('C');
   fncEscribe('A');
   fncEscribe('S');
   fncEscribe('T');
   fncEscribe('A');
   fncEscribe('N');
   fncEscribe('E');
   fncEscribe('D');
   fncEscribe('A');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('A');
   fncEscribe('V');
   fncEscribe('.');
   fncEscribe('O');
   fncEscribe('B');
   fncEscribe('S');
   fncEscribe('E');
   fncEscribe('R');
   fncEscribe('V');
   fncEscribe('A');
   fncEscribe('T');
   fncEscribe('O');
   fncEscribe('R');
   fncEscribe('I');
   fncEscribe('O');

   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('N');
   fncEscribe('O');
   fncEscribe('.');
   fncEscribe('1');
   fncEscribe('7');
   fncEscribe('0');
   fncEscribe(' ');
   fncEscribe('C');
   fncEscribe('O');
   fncEscribe('L');
   fncEscribe('.');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('T');
   fncEscribe('A');
   fncEscribe('C');
   fncEscribe('U');
   fncEscribe('B');
   fncEscribe('A');
   fncEscribe('Y');
   fncEscribe('A');
   fncEscribe(' ');
   fncEscribe('D');
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe('.');
   fncEscribe(' ');

   //Pasar a modo comando
   comando();
   fncEscribe(' ');
   fncEscribe('M');
   fncEscribe('I');
   fncEscribe('G');
   fncEscribe('U');
   fncEscribe('E');
   fncEscribe('L');
   fncEscribe(' ');
   fncEscribe('H');
   fncEscribe('I');
   fncEscribe('D');
   fncEscribe('A');
   fncEscribe('L');
   fncEscribe('G');
   fncEscribe('O');
   fncEscribe(' ');

}

void error(){
   //Pasar a modo comando
   comando();
   // Mensaje de error
   espacio();
   fncEscribe('1');
   fncEscribe('6');
   fncEscribe('F');
   fncEscribe('8');
   fncEscribe('7');
   fncEscribe('7');
   fncEscribe(' ');
}
void comando(){
   //Pasar a modo comando
   bit_clear(PORTE,RS);
   bit_clear(PORTE,RW);
   //Clear display
   bit_set(PORTE,E);
   output_b(0x01);
   bit_clear(PORTE,E);
   //Cursor al inicio
   bit_set(PORTE,E);
   output_b(0x02);
   bit_clear(PORTE,E);
}
void espacio(){
   fncEscribe(' ');
   fncEscribe(' ');
   fncEscribe(' ');
   fncEscribe(' ');

}//fin espacio
void cadena(int){
      com[pos]=DATA; //esta parte para longitud
      pos++;
      if(DATA == 0b01011010){
            if(com[0]==0x38 && com[1]==0xB2 && com[2]==0x24 && com[3]==0xD2 && com[4]==0xD2 && com[5]==0xC2 && com[6]==0xC4 && com[7]==0x22 && com[8]==0xD8 && com[9]==0x5C){
            apellidosm();
            delay_ms(3000);
            }else if(com[0]==0xD2 && com[1]==0x24 && com[2]==0x8C && com[3]==0x2C && com[4]==0x3C && com[5]==0x38 && com[6]==0xD8 && com[7]==0x2C && com[8]==0x3C && com[9]==0x38 && com[10]==0x34 && com[11]==0x24 && com[12]==0x5C && com[13]==0x38 && com[14]==0xD2 && com[15]==0x38){
        lenguasguatemala();
        delay_ms(3000);
        }else if(com[0]==0x38 && com[1]==0xD8 && com[2]==0xC2 && com[3]==0x38){
               asia();
                delay_ms(3000);
         }else if(com[0]==0x38 && com[1]==0xD4 && com[2]==0xB4 && com[3]==0xC2 && com[4]==0x84 && com[5]==0x38){
                africa();
                delay_ms(3000);
               }else if(com[0]==0x8C && com[1]==0x22 && com[2]==0x5C && com[3]==0x4C && com[4]==0xB4 && com[5]==0x24 && com[6]==0xD8 && com[7]==0x5C && com[8]==0xCC){
                 nombresmh();
                 delay_ms(3000);
                }else if(com[0]==0xD8 && com[1]==0x38 && com[2]==0x4C && com[3]==0x22 && com[4]==0xB4 && com[5]==0x24 && com[6]==0xD8){
                   sabores();
                    delay_ms(3000);
                 }else if(com[0]==0x24 && com[1]==0x8C && com[2]==0xB2 && com[3]==0xD6){
                         enp4();
                        delay_ms(3000);
                  }else if(com[0]==0xB2 && com[1]==0xD2 && com[2]==0x38 && com[3]==0xAC && com[4]==0x38 && com[5]==0xD8 && com[6]==0x84){
                         playasc();
                        delay_ms(3000);
                        }else{
                               error();
                          }
      }
}
void tabla(int){

            if(DATA == 0b00111000){ //= 0x38
               fncEscribe('A');
            }
            if(DATA == 0b01001100){ //= 0x4C
               fncEscribe('B');
            }
            if(DATA == 0b10000100){ // = 0x84
               fncEscribe('C');
            }
            if(DATA == 0b11000100){ //= 0xC4
               fncEscribe('D');
            }
            if(DATA == 0b00100100){ //= 0x24

               fncEscribe('E');
            }
            if(DATA == 0b11010100){ // = 0xD4
               fncEscribe('F');
            }
            if(DATA == 0b00101100){ //= 0x2C
               fncEscribe('G');
            }
            if(DATA == 0b11001100){ //= 0xCC
               fncEscribe('H');
            }
            if(DATA == 0b11000010){ //= 0xC2
               fncEscribe('I');
            }
            if(DATA == 0b11011100){ //= 0xDC
               fncEscribe('J');
            }
            if(DATA == 0b01000010){ //= 0x42
               fncEscribe('K');
            }
            if(DATA == 0b11010010){ //= 0xD2
               fncEscribe('L');
            }
            if(DATA == 0b01011100){ //= 0x5C
               fncEscribe('M');
            }
            if(DATA == 0b10001100){ //= 0x8C
               fncEscribe('N');
            }
            if(DATA == 0b00100010){ // = 0x22
               fncEscribe('O');
            }
            if(DATA == 0b10110010){ //= 0xB2
               fncEscribe('P');
            }
            if(DATA == 0b10101000){ //= 0xA8
               fncEscribe('Q');
            }
            if(DATA == 0b10110100){ //= 0xB4
               fncEscribe('R');
            }
            if(DATA == 0b11011000){ //= 0xD8
               fncEscribe('S');
            }
            if(DATA == 0b00110100){ //= 0x34
               fncEscribe('T');
            }
            if(DATA == 0b00111100){ //= 0X3C
               fncEscribe('U');
            }
            if(DATA == 0b01010100){ //= 0x54
               fncEscribe('V');
            }
            if(DATA == 0b10111000){ //= 0xB8
               fncEscribe('W');
            }
            if(DATA == 0b01000100){ //= 0x44
               fncEscribe('X');
            }
            if(DATA == 0b10101100){ //= 0xAC
               fncEscribe('Y');
            }
            if(DATA == 0b01011000){ //= 0x58
               fncEscribe('Z');
            }
            if(DATA == 0b01011010){ //= 0x58
               fncEscribe(' ');
            }
            if(DATA == 0b11010110){ //= 0xD6
               fncEscribe('4');
            }
}
void teclado(){
//Definiciones
//#byte    PORTB =  0x06
#byte    PORTD =  0x08
//#byte    TRISB =  0x86
#byte    TRISD =  0x88
   //Bits 0 y 1 del puerto D como entrada
   bit_set(TRISD,0);
   bit_set(TRISD,1);
   //Puerto B como salida
   set_tris_b(0x00);
   //Condicion Inicial
   //Todos los puertos en 0
   output_b(0x00);
   //Redardo para que todo se estabilice
   delay_ms(1000);
   while(1)
   {
      while(bit_test(PORTD,0)==1);
      DATA11[cont++] = bit_test(PORTD,1);
      while(bit_test(PORTD,0)==0);
      if(cont==11){
         int i;
         cont=0;
         for(i=1;i<=8;i++){
            if(DATA11[i]==1)
               bit_set(DATA,8-i);
            else
               bit_clear(DATA,8-i);
         }
         if(DATA!=0x0F){  //Si es diferente del Codigo de Liberacion de Tecla
               tabla(DATA);
               cadena(DATA);
         } //if(DATA!=0x0F)
      }//if(cont==11)
   }//while
}
