# 2020_OOP_Term_Project

02분반 3조 텀프로젝트 repo입니다.
***

## GoStop Game

### 고스톱 프로그램 설계

카드 구현

- 카드 객체
- 카드 객체를 담는 vector에 넣어둠
- 카드 정보는 txt파일로 저장

플레이어 - 3인 게임

- 플레이어 객체
- 플레이어 이름은 사용자 입력
- 한 콘솔에서 3명이 플레이

점수 계산기

- 사용자가 카드를 얻을 때 마다 점수 계산

승리 조건

- 3점을 먼저 만들면 승리!

게임 규칙

- 7장 손에 들고 6장은 바닥에
- 3점 먼저 내면 이김.
- 선은 1번 플레이어가 선
- 한 라운드만 진행한다고 가정한다.

***

### 컴파일 방법

```bash
clang++ -std=c++17 -c card.cpp -o card.o
clang++ -std=c++17 -c player.cpp -o player.o
clang++ -std=c++17 -c calculator.cpp -o calculator.o
clang++ -std=c++17 -c operator.cpp -o operator.o
clang++ -std=c++17 -o gostop  gostop.cpp operator.o calculator.o player.o card.o
```

### 실행방법

```bash
./gostop
```

***

### 구현 상황

 - 카드 클래스, 플레이어 클래스 구현
 - 게임 진행기 구현