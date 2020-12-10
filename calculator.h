#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "card.h"
#include "player.h"

class Calculator {
 public:
  void calculateScore(std::vector<Player*> &playerList); // 점수를 계산하는 함수
 private:
  static Calculator* instanse_; // Operator instance, instance함수로 만들기
};

#endif