void intro(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*------------------*");
  lcd.setCursor(0,1);
  lcd.print("| Caja de Arena:   |");
  lcd.setCursor(0,2);
  lcd.print("|   NIMBUS 2015    |");
  lcd.setCursor(0,3);
  lcd.print("*------------------*");
  lcd.setCursor(16, 2);
  lcd.write(Escobachar);
  return;  
}


void experimento(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Elegir Experimento:");
  lcd.setCursor(1,2);
  lcd.print("1   2   3   4   5 ");
  lcd.setCursor(1,3);
  lcd.print("6   7   8   9   * ");
  return;
}

void expunoscreen(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("---EXPERIMENTO 1---");
  lcd.setCursor(0,1);
  lcd.print("MotorA:");
  lcd.setCursor(7,1);
  lcd.write(Chulochar);
  lcd.setCursor(0,2);
  lcd.print("V=38 um/s");
  lcd.setCursor(0,3);
  lcd.print("Pas=3200");
  lcd.setCursor(10,1);
  lcd.print("MotorB:");
  lcd.setCursor(17,1);
  lcd.write(Chulochar);
  lcd.setCursor(10,2);
  lcd.print("V=9.6um/s");
  lcd.setCursor(10,3);
  lcd.print("Pas=800");
  return;
}



void Pasos(int dira, int pasos, int velocidad, int dirb, int razon){
  
  if(dira == 1){
    digitalWrite(direcciona, HIGH);   
  }
  else if (dira == 0){
    digitalWrite(direcciona, LOW);    
  }
  if(dirb == 1){
    digitalWrite(direccionb, HIGH);   
  }
  else if (dirb == 0){
    digitalWrite(direccionb, LOW);    
  }
  
  
  
    
  for (int i = 0; i<pasos; i++)       
  {
    digitalWrite(stepsa, HIGH);
    //delay(velocidada); 
    digitalWrite(stepsa, LOW);   
    if(i%razon == 0){    
    digitalWrite(stepsb, HIGH);
    //delay(velocidadb); 
    digitalWrite(stepsb, LOW);
    posb+=1;   
    }
    delay(velocidad);  
    posa+=1;
    
    Experimentoscreen();
    
  }
  
}


float Porcentaje(){
  float porcentaje = ((posa*100.0)/pasos);
  return porcentaje;
}

void Tiempo(){
  
  long int tiemptot = total - (posa*(velocidad/1000));
  float horas = total / 3600;
  long int over;
  
  h=int(tiemptot/3600);
  m= int(tiemptot/60);
  s=int(tiemptot%60);
  
  //h=int(tiemptot/3600);
  //over=tiemptot%3600;
  //m=int(over/60);
  //over=over%60;
  //s=int(over);

  
  
}

void Experimentoscreen(){
  lcd.setCursor(4,2);
  lcd.print(posa);
  lcd.setCursor(14,2);
  lcd.print(posb);
  lcd.setCursor(0,3);
  lcd.print(Porcentaje(), 2);
  lcd.setCursor(4,3);
  lcd.print('%');
  Tiempo();
  lcd.setCursor(9,3);
  lcd.print(h,0);
  lcd.setCursor(11,3);
  lcd.print('h');
  lcd.setCursor(13,3);
  lcd.print(m,0);
  lcd.setCursor(15,3);
  lcd.print('m');
  lcd.setCursor(17,3);
  lcd.print(s,0);
  lcd.setCursor(19,3);
  lcd.print('s');
}

