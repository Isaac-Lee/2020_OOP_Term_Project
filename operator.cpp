#include <random>
#include "operator.h"


void Operator::setGame(std::vector<Card*> cardList,  std::vector<Player*>playerList,  std::vector<Card*> fieldCard) {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(cardList.begin(), cardList.end(), g);
  //덱 셔플
  for(int i = 0; i < 6; i++){
    fieldCard.push_back(cardList.front());
    cardList.pop_back();
    //바닥 필드에 카드 6개 삽입, 덱에서 6개 제거
  }
  for(int i = 0; i < 7; i++){ //총 7장
    for(int j =0; j < 3; j++){ //총 3명
      playerList[j]->draw(cardList.front()); //각각 카드를 뽑음
      cardList.pop_back(); //덱에서 하나 제거
    }
  }
}
bool Operator::validateCard(std::vector<Card*> cardList, std::vector<Player*> playerList, Card* card, Player* player) {
  return true;
}

void Operator::isGameOver(std::vector<Player*> playerList) {
  int countPlayer = 0;
  for(int i = 0; i < 3; i++){ //총 7장
    if(playerList[i]->isPlaying() == true){ //플레이어가 게임중일 경우
    countPlayer++; //플레이어 수 한명 증가
    }  
  }
  if(countPlayer >=2) {
    //게임 진행중
  } else{
    //플레이어가 한명또는 없으므로 게임 종료
  }
}