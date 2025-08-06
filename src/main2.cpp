//habitacion sensores 
int est[6][7]{
              {1,1,1,1,1,1,0},//0
              {0,1,1,0,0,0,0},//1
              {1,1,0,1,1,0,1},//2
              {1,1,1,1,0,0,1},//3
              {0,1,1,0,0,1,1},//4
              {0,0,0,0,0,0,1},//-
};
int pines[7]{8,9,10,11,12,13,14};
int sensor[4]{5,6,7,8};
int hab1,hab2,hab3,hab4;
int pulsador=2;
int t_intervalo=0;
int t_intervalo=0;
int t_delay=1000;
int j;
int i;
volatile bool flag=true;
volatile bool t_guon=false;
void IRAM_ATTR pulsado_isr(){
    flag=true;
}

void IRAM_ATTR sen1_isr(){
    flag=true;
    hab1;
}
void IRAM_ATTR sen2_isr(){
    flag=true;
    hab2;
}
void IRAM_ATTR sen3_isr(){
    flag=true;
    hab3;
}
void IRAM_ATTR sen4_isr(){
    flag=true;
    hab4;
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
    if(flag=true){
        t_actual=millis();
        if(t_actual-t_intervalo>=t_delay){
            t_intervalo=millis();
             for(j=0 ; j<7 ; j++){
                if(t_guion){
            digitalWrite(pines[j],est[6][J]);
                }else{
              digitalWrite(pines[j],LOW);
                }
     
        }
    }
}else{
    for(i=0 ; i<3 ; i++){
        if(digitalread(sensores[i])==HIGH){
            for(j=0 ;j<6 ; j++){
                 digitalWrite(pines[j],est[num][J]);
            }
        }else{
        flag=false;
        t_actual=millis();
        if(t_actual-t_intervalo>=t_delay){
            t_intervalo=millis();
             for(j=0 ; j<7 ; j++){
                if(t_guion){
            digitalWrite(pines[j],est[6][J]);
                }else{
              digitalWrite(pines[j],LOW);
                }
     
        }
        }
    }
}
}