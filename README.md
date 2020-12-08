# 2020_OOP_Term_Project

02분반 3조 텀프로젝트 repo입니다.
***

## GoStop Game

### 고스톱 프로그램 설계

카드 구현

- 카드 객체
- 카드 객체를 담는 배열에 넣어둠
- 카드 정보는 txt파일로 저장

플레이어 - 3인 게임

- 일단은 한 콘솔에서 3명이 플레이
- 각자 500(만원)씩 들고 시작
- 파산하면 게임 종료
- 탈주 가능 >> 남을 플레이어끼리 절반씩 나눠갖음

점수 계산기

- 사용자가 카드를 얻을 때 마다 점수 계산

승리 조건

- 1000(만원) 먼저 만들면 승리
- 다 탈주 해서 혼자 남으면 승리

게임 규칙

- 7장 손에 들고 6장은 바닥에
- 3점 먼저 내면 이김. 고 또는 스톱 결정
- 선은 1번 플레이어가 선


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
