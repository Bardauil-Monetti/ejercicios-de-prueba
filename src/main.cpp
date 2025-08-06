//sensores en una casa
int est[7][7]{
              {1,1,1,1,1,1,0},//0
              {0,1,1,0,0,0,0},//1
              {1,1,0,1,1,0,1},//2
              {1,1,1,1,0,0,1},//3
              {0,1,1,0,0,1,1},//4
              {0,0,0,0,0,0,1},//-
              {1,0,0,1,1,1,0},
};
int pines[7]{8,9,10,11,12,13,14};
int sensor[4]{5,6,7,8};
int zona1,zona2,zona3,zona4;
int pulsador=2;
int t_intervalo=0;
int t_intervalo=0;
int t_delay=500;
int t_espara=10000;
int j;
int i;
volatile bool flag=true;
volatile bool t_guon=false;
void IRAM_ATTR pulsado_isr(){
    flag=true;
}

void IRAM_ATTR sen1_isr(){
    flag=true;
    zona1;
}
void IRAM_ATTR sen2_isr(){
    flag=true;
       zona2;
}
void IRAM_ATTR sen3_isr(){
    flag=true;
       zona3;
}
void IRAM_ATTR sen4_isr(){
    flag=true;
    zona4;
}
void setup(){
 for(i=0 ; i<7 ; i++){
    pinMode(pines[i],OUTPUT);

}
 for(i=0 ; i<4 ; i++){
    pinMode(sensor[i],INPUT_PULLUP);

}
attachInterrupt(digitalPinToInterrupt(pulsador),pulsado_isr,FALLING);
attachInterrupt(digitalPinToInterrupt(sensor[i]),sen1_isr,RISING);
attachInterrupt(digitalPinToInterrupt(sensor[i]),sen2_isr,RISING);
attachInterrupt(digitalPinToInterrupt(sensor[i]),sen3_isr,RISING);
attachInterrupt(digitalPinToInterrupt(sensor[i]),sen4_isr,RISING);
pinMode(pulsador,INPUT_PULLUP);
}
void loop(){
    if(flag==true){
         T_actual=millis();
        if(t_actual-t_intervalo<=t_delay){
            if(t_guion==true){
        for(j=0 ; j<7 ; j++){
            digitalWrite(pines[j],est[6][j]);
   }
 }else{
    digitaWrite(pines[j],LOW);
    
 }
}
    }
    flag=flase;
      if(digitalread(sensor[1])==HIGH){
        for(j=0 ; j<7 ; j++){
            digitalWrite(pines[j],est[1][J]);
            flag=false;
        }
    }else{
        digitalWrite(pines[j],LOW);
    }
       if(digitalread(sensor[2])==HIGH){
        for(j=0 ; j<7 ; j++){
            digitalWrite(pines[j],est[2][J]);
             flag=false;
        }
    }else{
        digitalWrite(pines[j],LOW);
    }
       if(digitalread(sensor[3])==HIGH){
        for(j=0 ; j<7 ; j++){
            digitalWrite(pines[j],est[3][J]);
             flag=false;
        }
    }else{
        digitalWrite(pines[j],LOW);
    }
       if(digitalread(sensor[4])==HIGH){
        for(j=0 ; j<7 ; j++){
            T_actual=millis();
            if(t_actual-t_delay<=t_espera){
            digitalWrite(pines[j],est[7][J]);
            }
             flag=false;
        }
    }else{
        digitalWrite(pines[j],LOW);
    }
  
}