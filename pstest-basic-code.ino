int reference = 512;
void setup() {
  t();l();t();l();f();//ภารกิจแรก
  b();l();t();l();t();l();t();l();f(); //ภารกิจสอง
  b();l();fd(100);sleep(3400);l();t();l();b();f(); //ภารกิจสาม
  b();l();b();t();l();t();l();t();b();l();b(); //check point1
  fd(100);sleep(3400);l(); b();fd(100);sleep(3400);l();t();l();f(); //ภารกิจสี่
  b();l();b();fd(100);sleep(1900);l();b();t();l();t();r();t(); //check point2
  bk(100);sleep(2000);r();fd(100);sleep(1890);
  l();b();t();fd(100);sleep(1000); //เข้าจอด
}
void loop() {
}
void track_forward(int power) {
  if (analog(0) > reference && analog(1) > reference && analog(2) > reference && analog(3) > reference) {
    fd(power*80/100);
  } else if (analog(0) < reference && analog(1) > reference && analog(2) > reference && analog(3) > reference) {
    sr(power);
  } else if (analog(0) > reference && analog(1) < reference && analog(2) > reference && analog(3) > reference) {
    sl(power);
  } else if (analog(0) > reference && analog(1) > reference && analog(2) > reference && analog(3) < reference) {
    sl(power);
  } else if (analog(0) > reference && analog(1) > reference && analog(2) < reference && analog(3) > reference) {
    sr(power);
  } else if (analog(0) > reference && analog(1) < reference && analog(2) < reference && analog(3) > reference) {
    ao();
  }
}
void track_backward(int power) {
  if (analog(4) > reference && analog(5) > reference && analog(6) > reference && analog(7) > reference) {
    bk(power*80/100);
  } else if (analog(4) < reference && analog(5) > reference && analog(6) > reference && analog(7) > reference) {
    sr(power);
  } else if (analog(4) > reference && analog(5) < reference && analog(6) > reference && analog(7) > reference) {
    sl(power);
  } else if (analog(4) > reference && analog(5) > reference && analog(6) > reference && analog(7) < reference) {
    sl(power);
  } else if (analog(4) > reference && analog(5) > reference && analog(6) < reference && analog(7) > reference) {
    sr(power / 2);
  } else if (analog(4) > reference && analog(5) < reference && analog(6) < reference && analog(7) > reference) {
    ao();
  }
}
void t(){
  while(true){
    if(analog(1)<reference && analog(2)<reference)
    {
      bk(100);sleep(200);ao();
      break;
    }else{
      track_forward(100);
    }
  }
}
void b(){
  while(true){
    if(analog(5)<reference && analog(6)<reference)
    {
      fd(100);sleep(200);ao();
      break;
    }else{
      track_backward(100);
    }
  }
}
void r(){
  ao();sleep(100);sr(99);sleep(691);ao();sleep(100);
}
void l(){
 ao(); sleep(100);sl(99);sleep(691);ao();sleep(100);
}
void f(){
  t();ao();sleep(500);ao();
}