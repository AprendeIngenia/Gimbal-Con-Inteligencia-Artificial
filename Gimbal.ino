#include <SoftwareSerial.h>
#include <Servo.h>

//Declaramos el servo
Servo servo;
Servo servo2;

//Declaramos la variable
char dato;
int angulo = 90;
int angulo2 = 90;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  servo.attach(3);
  servo2.attach(5);
  servo.write(angulo);
  servo2.write(angulo2);
}

void loop() {
  while(Serial.available()){
    dato = Serial.read();
    delay(10);
    Serial.println(dato);
    switch(dato){
      case 'd':
      //Gira servo hacia la derecha
      angulo = angulo - 2;
      servo.write(angulo);
      break;
      
      case 'i':
      //Gira servo hacia la izquierda
      angulo = angulo + 2;
      servo.write(angulo);
      break;

      case 'u':
      //Gira servo hacia arriba
      angulo2 = angulo2 + 2;
      servo2.write(angulo2);
      break;
      
      case 'b':
      //Gira servo hacia abajo
      angulo2 = angulo2 - 2;
      servo2.write(angulo2);
      break;
      
      case 'p':
      //Parar el servo
      angulo = angulo;
      servo.write(angulo);
      angulo2 = angulo2;
      servo2.write(angulo2);
      break;
      }
   }
 }
