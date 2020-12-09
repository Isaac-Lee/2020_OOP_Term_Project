#ifndef OPERATOR_H
#define OPERATOR_H

#include "card.h"
#include "player.h"
#include "calculator.h"

// 필요하다면 함수 추가가능
// 파라미터도 임의로 필요할거 같은거 넣어둔거라 필요하면 추가하거나 빼는거 가능

class Operator {
 public:
  void setGame(std::vector<Card*>& cardList, std::vector<Player*>& playerList, std::vector<Card*>& fieldCard); // 첫 게임 셋팅을 위한 함수
  void playerDraw(std::vector<Card*>& cardList, Player* Player); // 플레이어가 카드를 드로우 하는 행동
  void openCard(std::vector<Card*>& cardList, std::vector<Card*>& fieldCard); // 카드 덱에서 하나를 필드로 까는 행동
  void giveCardTo(Player* Player, Card* card); // 플레이어에게 카드를 주는 함수
  bool isGameOver(std::vector<Player*>& playerList); // 게임이 종료됬는지 구하는 함수
 private:
  static Operator* instance_; // Operator instance, instance함수로 만들기
};

#endif