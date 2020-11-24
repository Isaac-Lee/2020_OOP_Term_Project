#include <string>
#include <list>
#include "card.h"

struct PlayerInfo;

class Player {
 public:
  explicit Player(std::string name);  // 생성자
  PlayerInfo GetPlayerInfo();         // 플레이어 정보 출력
  bool isBroke();                     // 플레이어가 돈을 다 썼는지 확인하는 함수
  bool isPlaying();                   // 플레이어가 플레이중인지 확인하는 함수
  int HowManyMoney();                 // 플레이어가 가진 돈을 반환하는 함수
  void LoseMoney(int amount);          // 돈을 잃을 때 돈을 빼는 함수
  void WinMoney(int amount);           // 돈을 딸 때 돈을 더하는 함수
 private:
  std::string name_;         // 플레이어 이름
  std::list<Card> hand_;     // 플레이어가 가지고 있는 카드들
  int money_;                // 플레이어가 가지고 있는 돈
  bool isPlaying_;           // 플레이어가 플레이중인지
};

struct PlayerInfo {
  std::string name_;         // 플레이어 이름
  std::list<Card> hand_;     // 플레이어가 가지고 있는 카드들
  int money_;                // 플레이어가 가지고 있는 돈
  bool isPlaying_;           // 플레이어가 플레이중인지
};