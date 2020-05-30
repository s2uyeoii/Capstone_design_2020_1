/*
8x32 dot matrix
아래 링크에서 LedControl 라이브러리를 다운로드
https://github.com/wayoda/LedControl
http://www.devicemart.co.kr/
*/


#include "LedControl.h" // 라이브러리 사용 선언


// Din 핀을 12번, ClK핀을 14번 CS핀을 13번에 연결, 매트릭스는 4개를 사용 선언
LedControl lc=LedControl(12,14,13,4); 
int num;


void setup()
{
 for(num=0; num<4; num++) // 매트릭스 0번부터 3번까지 세팅
  {
   lc.shutdown(num,false); // 0~3번까지 매트릭스 절전모드 해제
   lc.setIntensity(num,8); // 매트릭스의 밝기 선언 0~15의 수
   lc.clearDisplay(num); // 매트릭스 led를 초기화
  }
}


// matrix 함수 선언
void matrix()
{
  // 'S'
   byte m[8]={
             B11111111,
             B11000000,
             B11000000,
             B11000000,
             B11111111,
             B00000011,
             B00000011,
             B11111111
             };
  //'T'
 byte t[8]={
            B11111111,
            B11111111,
            B00111000,
            B00111000,
            B00111000,
            B00111000,
            B00111000,
            B00111000
            };


 // 'O'
 byte r[8]={
            B01111110,
            B01000010,
            B01000010,
            B01000010,
            B01000010,
            B01000010,
            B01000010,
            B01111110
           };
  //'P'
 byte x[8]={
            B11111111,
            B11000011,
            B11000011,
            B11111111,
            B11000000,
            B11000000,
            B11000000,
            B11000000
            };


 // lc.setRow 함수는 행(Row) 기준으로 도트매트릭스를 제어 lc.setRow(matrix_number,Row,value)
 for(int j=0; j<8; j++)
 {
   lc.setRow(3,j,m[j]); // 0번째 매트릭스에서 '매'출력
   lc.setRow(2,j,t[j]); // 1번째 매트릭스에서 '트'출력
   lc.setRow(1,j,r[j]); // 2번째 매트릭스에서 '릭'출력
   lc.setRow(0,j,x[j]); // 3번째 매트릭스에서 '스'출력
 }
 delay(1000);
}


void loop() {
  matrix();
  for(num=0; num<4; num++) // 4개의 매트릭스led 초기화
 {
  lc.clearDisplay(num);
 }
 delay(1000);


}
