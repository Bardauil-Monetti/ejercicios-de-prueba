//hacer un contador que valla del 00 al 99;
#include"Arduino.h"
int pines1[7]{8,9,10,11,12,13,14};
int pines2[7]{15,16,17,18,19,20,21};

int unidad[9][7]{
              {1,1,1,1,1,1,0},
              {0,1,1,0,0,0,0},
              {1,1,0,1,1,0,1},
              {1,1,1,1,0,0,1},
              {0,1,1,0,0,1,1},
              {1,0,1,1,0,1,1},
              {1,0,1,1,1,1,1},
              {1,1,1,0,0,0,0},
              {1,1,1,1,1,1,1},
              {1,1,1,1,0,1,1},
};
int desenas[9][7]{
              {1,1,1,1,1,1,0},
              {0,1,1,0,0,0,0},
              {1,1,0,1,1,0,1},
              {1,1,1,1,0,0,1},
              {0,1,1,0,0,1,1},
              {1,0,1,1,0,1,1},
              {1,0,1,1,1,1,1},
              {1,1,1,0,0,0,0},
              {1,1,1,1,1,1,1},
              {1,1,1,1,0,1,1},
};
int t_intervalo=0;
int t_delay=200;
int t_actual=0;
int direccion=0;
int i;
int cont=0;
int pulsador=2;
volatile bool flag=false;
void IRAM_ATTR pulsado_isr(){
    flag=true;
}
void setup(){
 for(i=0 ; i<7 ; i++){
    pinMode(pines1[i],OUTPUT);
    pinMode(pines2[i],OUTPUT);
}
attachInterrupt(digitalPinToInterrupt(pulsador),pulsado_isr,RISING);
pinMode(pulsador,INPUT_PULLUP);

}
void loop(){
    desenas=cont/10;
    unidad=cont%10;

    if(flag){
     t_actual=millis();
     if(t_actual - t_intervalo=t_delay){
     }
       flag=false;
       direccion=!direccion;
     }
     if(direccion==1){
        cont++;
        if(cont<99){
        cont=00;

     }else{
        cont--;
        if(cont<00){
            cont=99;
        }
  }
 }
}