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
void initPlayer(std::vector<Player*> &playerList) {
  for (int i = 0; i < 3; i++) {
    std::string name;
    std::cout << i+1 << "번째 플레이어의 이름을 입력하세요: ";
    std::cin >> name;
    if (name.length() >= 10) {
      std::cout << "이름이 너무 깁니다. 다시 입력해주세요." <<std::endl;
      i--;
      continue;
    }
    Player* p = new Player(name);
    playerList.push_back(p);
  }
  for (int i = 0; i < 3; i++) {
    PlayerInfo p_info = playerList[i]->GetPlayerInfo();
    std::cout << i+1 << "번째 플레이어 : " << p_info.name_ << std::endl;
  }
}


void startGame() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "********************** Game Start **********************" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
} 
void showHand(Player* player) {
  PlayerInfo info = player->GetPlayerInfo();
    std::cout << info.name_ << "님의 손 패 입니다." << std::endl;
    std::vector<Card*> hand = info.hand_;
    for (int j = 0; j < hand.size(); j++) {
      std::cout << hand[j]->toString(j+1) << std::endl;
    }
    std::cout << std::endl;
}
Card* pickHandCard(Player* player) {
  showHand(player);
  int cardNumber;
  std::cout << "카드 번호를 입력하세요 : ";
  std::cin >> cardNumber;

  Card* card;
  card = player->drop(cardNumber);
  std::cout << card->toString(cardNumber) << "를 냈습니다." << std::endl;
  return card;
}
void showField(std::vector<Card*> &fieldCard) {
  std::cout << std::endl;
  std::cout << "판에 깔려있는 카드" << std::endl;
  for (int i = 0; i < 6; i++) {
    std::cout << fieldCard[i]->toString(i+1) << std::endl;
  }
  std::cout << std::endl;
}


int main(void)
{
  std::vector<Card*> cardList; // 카드 리스트
  std::vector<Card*> fieldCard; //바닥 카드 리스트 -> 시작에 6장
  std::vector<Player*> playerList; // 플레이어 리스트 -> 3명
  Operator gameOP; // 게임 진행자
  Calculator gameCal; // 점수 계산기

  initCard("card.txt", cardList, false);
  initPlayer(playerList);
  startGame();
  gameOP.setGame(cardList, playerList, fieldCard);

  bool isPlaying = true;
  while(isPlaying) {
    for (int i = 0; i < 3; i++) {
      Player *p = playerList[i];
      PlayerInfo p_info = p->GetPlayerInfo();
      std::cout << p_info.name_ << "님 차례입니다." << std::endl;
      showField(fieldCard);
      Card* cardPick = pickHandCard(p);
      std::string isTurnOff;
      std::cout << "턴을 넘기시겠습니까? [Y/n] : ";
      std::cin >> isTurnOff;
      if (isTurnOff.compare("n") == 0) {
        i--;
        continue;
      } else {
        continue;
      }
    }
    gameOP.isGameOver(playerList);
  }

  return 0;
}