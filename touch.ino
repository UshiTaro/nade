bool touch(int po, int pi){
  int i = 0;
  digitalWrite(po,HIGH);
  while(digitalRead(pi)==LOW)
    i++;
  digitalWrite(po,LOW);
  delay(1);
  return i>0?1:0;
}
