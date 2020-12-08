#include "player.h"

// 필요하다면 함수 추가가능
// 파라미터도 임의로 필요할거 같은거 넣어둔거라 필요하면 추가하거나 빼는거 가능

class Claculator {
 public:
  void isRoundOver(std::vector<Player*> playerList);    // 한 라운드마다 승리인지 판별하는 함수
  void calculateScore(std::vector<Player*> playerList, int goCount); // 점수를 계산하는 함수
  void calculateMoney(std::vector<Player*> playerList); // 점수에 따라 돈을 계산해서 플레이어에게 전달하는 함수
  void distributeMoney(std::vector<Player*> playerList, Player* Player); // 탈주한 플레이어 돈 분배하는 함수
 private:
  static Claculator* instanse_; // Operator instance, instance함수로 만들기
};