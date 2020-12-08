#ifndef OPERATOR_H
#define OPERATOR_H

#include "card.h"
#include "player.h"
#include "calculator.h"

// 필요하다면 함수 추가가능
// 파라미터도 임의로 필요할거 같은거 넣어둔거라 필요하면 추가하거나 빼는거 가능

class Operator {
 public:
  void setGame(std::vector<Card*> cardList, std::vector<Player*> playerList, std::vector<Card*> fieldCard); // 첫 게임 셋팅을 위한 함수
  bool validateCard(std::vector<Card*> cardList, std::vector<Player*> playerList, Card* card, Player* player); // 플레이어가 카드를 정상적으로 냈는지 검사하는 함수
  void isGameOver(std::vector<Player*> playerList); // 게임이 종료됬는지 구하는 함수
 private:
  static Operator* instance_; // Operator instance, instance함수로 만들기
};

#endif