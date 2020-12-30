# LevelUp 동아리 발표회

<br><br>
**1인당 C콘솔 또는 게임엔진을 이용한 게임 한개 제출**

**동아리내에서 발표할 .pptx파일 (플레이영상과 부연 설명)**<br>
**동아리 평가회에 사용할 .mp4파일 (플레이영상)**
**을 포함해 깃허브에 제출**
<br><br>

**기간**
* 2020.12.03    ~ 2020.01.03

<br>

**조건**  
* 더블 버퍼 사용
* 마우스 커서 숨기기
* 서로 겹치지 않는 게임
* 플레이에 따른 성공/실패 구현

<br>

**중요** 
*  완성도가 떨어지거나 기능을 설명 못할 시 동아리에 잘릴 수 있음
<br><br><br>


**콘솔게임**

* ***마우스 커서 숨기기***
<br>HANDLE consoleHandel = GetStdHandle(STD_OUTPUT_HANDLE);
<br> *( 현재 장치의 핸들에 접근 )*
<br>CONSOLE_SURSOR_INFO consoleCursor;
<br>consoleCursor.bVisible = 0; 
<br>*( 0 : 커서X,1 : 커서O )*
<br>consoleCursor.dwSize = 1; 
<br>SetConsoleCursorInfo(consoleHandle, &consoleCursor);
<br>*( 현재 커서에 적용 )*

<br><br>
* ***더블 버퍼링***
<br>[[더블 버퍼 사용법]](https://bloghelloworld.tistory.com/4)