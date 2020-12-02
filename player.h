#include <list>
#include "card.h"

// TODO 
// 탈주 가능하게 하는 함수 구현
// 먹은 카드를 보관하는 곳
// 고 스톱 상태를 나타내는 함수

struct PlayerInfo;

class Player {
 public:
  explicit Player(std::string name);           // 생성자
  PlayerInfo GetPlayerInfo();                  // 플레이어 정보 출력
  bool isPlaying();                            // 플레이어가 플레이중인지 확인하는 함수
  void UpScore(int amount);                    // 점수를 더하는 함수
  void DownScore(int amount);                  // 점수를 빼는 함수
  void ResetScore();                           // 점수를 0으로 초기화 하는 함수 
  Card* CardPop(std::string card_name);        // 카드를 내는 함수
  void EarnCard(std::list<Card*> cardList);    // 카드를 얻는 함수 필드로 보냄
 private:
  std::string name_;          // 플레이어 이름
  std::list<Card*> hand_;     // 플레이어가 손에 들고 있는 카드들
  std::list<Card*> field_;    // 플레이어가 가지고 있는 카드들
  bool isPlaying_;            // 플레이어가 플레이중인지
  int score_;                 // 플레이어의 점수
};

struct PlayerInfo {
  std::string name_;          // 플레이어 이름
  std::list<Card*> hand_;     // 플레이어가 손에 들고 있는 카드들
  std::list<Card*> field_;    // 플레이어가 가지고 있는 카드들
  bool isPlaying_;            // 플레이어가 플레이중인지
  int score_;
};