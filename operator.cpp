#include <random>
#include "operator.h"


void Operator::setGame(std::vector<Card*>& cardList,  std::vector<Player*>& playerList,  std::vector<Card*>& fieldCard) {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(cardList.begin(), cardList.end(), g);
  //덱 셔플
  for(int i = 0; i < 6; i++){
    fieldCard.push_back(cardList.back());
    cardList.pop_back();
    //바닥 필드에 카드 6개 삽입, 덱에서 6개 제거
  }
  for(int i = 0; i < 7; i++){ //총 7장
    for(int j =0; j < 3; j++){ //총 3명
      playerList[j]->draw(cardList.back()); //각각 카드를 뽑음
      cardList.pop_back(); //덱에서 하나 제거
    }
  }
}
bool Operator::validateCard(std::vector<Card*>& cardList, std::vector<Player*>& playerList, Card* card, Player* player) {
  return true;
}

bool Operator::isGameOver(std::vector<Player*>& playerList) {
  int countPlayer = 0;
  for(int i = 0; i < 3; i++){ //총 7장
  PlayerInfo p_info = playerList[i]->GetPlayerInfo();
    if (p_info.score_ >= 3) {
      return true;
    }
  }
  return false;
}