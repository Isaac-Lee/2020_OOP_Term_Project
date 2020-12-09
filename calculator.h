#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "card.h"
#include "player.h"

// 필요하다면 함수 추가가능
// 파라미터도 임의로 필요할거 같은거 넣어둔거라 필요하면 추가하거나 빼는거 가능

class Calculator {
 public:
  void calculateScore(std::vector<Player*> &playerList); // 점수를 계산하는 함수
 private:
  static Calculator* instanse_; // Operator instance, instance함수로 만들기
};

#endif