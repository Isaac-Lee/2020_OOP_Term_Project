#include <iostream>
#include <fstream>
#include <locale>
#include <iterator>
#include <algorithm>
#include "operator.h"

void initCard(std::string path, std::vector<Card*> &cardlist, bool debug) {
  std::ifstream readFile;
  readFile.open("card.txt"); //파일 열기
  if (readFile.is_open())
  {
    while (!readFile.eof())
    {
      std::string name; //카드 이름
      bool gwang;
      bool gyeolkkeut;
      bool godori;
      int pi;
      std::string tti; //띠

      std::string input1;
      std::string input2;
      std::string input3;
      std::string input4;
      std::string input5;
      std::string input6; //파일에서 읽어오는 string

      std::getline(readFile, input1); //카드 이름을 읽어온다
      name = input1;

      std::getline(readFile, input2); //광을 읽어온다
      if(input2.compare("true") == 0){ 
        gwang = true; //true일경우 광은 true
      } else{
        gwang = false;
      }
      //밑으론 다 비슷한 방식
      std::getline(readFile, input3); 
      if(input3.compare("true") == 0){ 
        gyeolkkeut = true;
      } else{
        gyeolkkeut = false;
      }

      std::getline(readFile, input4); 
      if(input4.compare("true") == 0){ 
        godori = true; //true일경우 고도리는 true
      } else{
        godori = false;
      }

      std::getline(readFile, input5); //피를 읽어온다
      if(input5.compare("false") == 0){ 
        pi = 0; //false일 경우 피는 0
      } else{
          if(input5.compare("1") == 0){ 
          pi = 1;
        } else{
          pi = 2;
        }
      }

      std::getline(readFile, input6); 
      if(input4.compare("false") == 0){ 
        tti = ""; //false일 경우 공백;
      } else{
        tti = input6;
      }

      if (debug) {
        std::cout << name << gwang << gyeolkkeut << godori << pi << tti <<std::endl;
      }
      //출력 확인
      Card* card = new Card(name, gwang, gyeolkkeut, godori, pi, tti);
      // CardInfo ci;
      // ci = card->getCardInfo();
      cardlist.push_back(card);
    }
    readFile.close(); //파일 닫아줍니다.
  }
}

void startGame() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "********************** Game Start **********************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
} 
int goOrStop() {
  int choice;
  std::cout << "******  1. 못먹어도 고! / 2. 욕심은 금물 스톱!  ******" <<std::endl;
  std::cout << "선택 : ";
  std::cin >> choice;
  return choice;
}
int pickCard(Player &player) {
  PlayerInfo info = player.GetPlayerInfo();
  std::vector<Card*> hand = info.hand_;
  for (int i = 0; i < hand.size(); i++) {
    hand[i]->toString(i+1);
  }
}

// TODO
// 게임 시작 세팅을 해주는 함수
// 게임 규칙대로 플레이어가 카드를 내는지 확인
// 카드를 냈을때 일어나는 일들 구현하는 함수
// 게임의 종료를 구하는 함수

// 승리 판별기
// 점수 계산하는 함수 만들어야함
// 돈 계산 해주는 함수 - 승자의 점수를 따라 돈 계산
// 플레이어 탈주시 갖고 있는 돈을 다른 플레이어에게 나눠주는 함수

// 고랑 스톱이 가능한지 출력하는 함수
// 게임 진행시 진행상황을 사용자에게 보여주는 함수

int main(void)
{
  std::vector<Card*> cardList; // 카드 리스트
  std::vector<Card*> fieldCard; //바닥 카드 리스트 -> 시작에 6장
  std::vector<Player*> plaerList; // 플레이어 리스트 -> 3명
  Operator gameOP;
  Claculator gameCal;
  
  initCard("card.txt", cardList, false);
  
  // 처음 판을 깔기
  // 플레이어 1부터 한명씩 돌아가면서 정보 입력 받기
  // 한턴마다 돌아다가면서 카드를 내고, 카드더미에서 한장 뒤집는다
  // 두 카드중에 바닥에 깔려있는것과 같은 종류가 있다면 그 두장을 거둔다
  // 점수 계산
  // 이간 사람 있는지 판별
  // 이긴 사람이 없다면 다시 진행
  // 이긴 사람이 있다면 고할지 스톱할지 알려준다.
  // 고라면 고 카운트를 센다.
  // 스톱이라면 점수 계산하고 다시 진행

  return 0;
}