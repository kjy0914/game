//아두이노(C언어) 코딩할 때는 python과 다르게 뒤에 세미콜론(;)을 써줘야함 - 안 쓸 경우 컴파일 에러 발생할 수 있음
int green=10; //RGB LED 초록 색을 회로상 10번에 연결 
int blue=9; //RGB LED 파란 색을 회로상 9번에 연결 
int red=11; //RGB LED 빨간 색을 회로상 11번에 연결 
#include <Wire.h>  //헤더파일 
#include <LiquidCrystal_I2C.h> //헤더파일        
LiquidCrystal_I2C lcd(0x27, 16, 2); //자신이 사용하는 lcd 디스플레이 모듈이 어떤 것인지 알려주는 것 


void setup() { //기본적인 설정(python과 다르게 콜론(:)을 쓰는 게 아니라 중괄호({})를 사용함) 
  Serial.begin(9600);  //통신 속도를 맞춰주기 위해 9600으로 설정 
  pinMode(red, OUTPUT); //회로상 11번에 연결해놓은 빨간 색 RGB LED 핀을 OUTPUT으로 설정 
  pinMode(green, OUTPUT); //위와 동일
  pinMode(blue, OUTPUT); //위와 동일
  lcd.init(); //lcd 초기화                
  lcd.backlight(); //lcd 백라이트를 켜는 것          
  lcd.clear(); //lcd의 모든 내용 지우고 커서 위치 (0,0)으로 옮기는 것
}

void loop() { //밑 과정을 반복시키기 위해 사용 
  int a = analogRead(A0); //회로상 A0에 연결된 소리 센서의 측정값을 받아들이기 위해 변수 a를 선언하고 측정값을 a에 할당(변수 초기화와 값 할당을 동시에 하는 것)

  delay(100); //100ms 동안 기다림

  lcd.clear();  //lcd의 모든 내용 지우고 커서 위치 (0,0)으로 옮기는 것                          
  lcd.setCursor(5, 0);  //커서 위치 (5,0)으로 설정                  
  lcd.print("DB:"); //lcd에 ""안에 있는 문자열 출력
  lcd.print(a); //lcd에 위에서 선언한 변수 a 출력
  lcd.println("           ");  //공백을 위해서 출력 (println은 해당 값을 출력하고 한 줄 띄어서 다시 시작하는 거 - 엔터 치는 거라고 생각)          
  lcd.setCursor(5,1); //커서 위치를 (5,1)로 설정 
  delay(100); // 100ms 동안 기다림                             


  if (a>115 and a<125) { //if문 - 위에서 선언한 변수 a의 값이 115와 125 사이라면(python과 다른 점은 python은 괄호를 사용하지 않지만 아두이노 코딩에서는 사용해야함)
    digitalWrite(red,0); //위 조건에 부합할 경우 RGB LED에서 빨간 색이 나오지 않게 함 
    digitalWrite(green,120); //위 조건에 부합할 경우 RGB LED에서 초록 색이 나오게 함
    digitalWrite(blue,0); //위 조건에 부합할 경우 RGB LED에서 파란 색이 나오지 않게 함 
    delay(100);
  }

  
  else  { //if 문의 조건을 제외한 모든 다른 경우라면 
    digitalWrite(red,120); //위 조건에 부합할 경우 RGB LED에서 빨간 색이 나오게 함
    digitalWrite(green,0); //위 조건에 부합할 경우 RGB LED에서 초록 색이 나오지 않게 함 
    digitalWrite(blue,0); //위 조건에 부합할 경우 RGB LED에서 파란 색이 나오지 않게 함 
    delay(100); //100ms 동안 기다림
  }
  Serial.print(" DB:"); //터미널에 ""안에 있는 문자열 출력 
  Serial.println(a); //터미널에 위에서 선언한 변수 a값 출력
  delay(100); //100ms 동안 기다림 
}

