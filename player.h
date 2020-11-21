#include <iostream>
#include <list>
#include "card.h"

struct PlayerInfo;

class Player {
 public:
  Player(std::string name);
  PlayerInfo GetPlayerInfo();   // 플레이어 정보 출력
  bool isBroke();               // 플레이어가 돈을 다 썼는지 확인하는 함수
  int LoseMoney(int amount);    // 돈을 잃을 때 돈을 빼는 함수
  int WinMoney(int amount);     // 돈을 딸 때 돈을 더하는 함수
 private:
  std::string name_;         // 플레이어 이름
  int money_;                // 플레이어가 가지고 있는 이름
  std::list<Card> hand_;     // 플레이어가 가지고 있는 카드들
};