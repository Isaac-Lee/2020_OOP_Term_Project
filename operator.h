#include "calculator.h"

// 필요하다면 함수 추가가능
// 파라미터도 임의로 필요할거 같은거 넣어둔거라 필요하면 추가하거나 빼는거 가능

class Operator {
 public:
  static Operator& instance() {}; // singleton 디자인을 위한 것
  void setGame(std::list<Card*> cardList, std::list<Player*> playerList) {} // 첫 게임 셋팅을 위한 함수
  bool validateCard(std::list<Card*> cardList, std::list<Player*> playerList, Card* card, Player* player) {} // 플레이어가 카드를 정상적으로 냈는지 검사하는 함수
  void gameOperate(std::list<Card*> cardList, std::list<Player*> playerList, Card* card, Player* player) {} // 플레이어가 카드를 냈을때 일어나는 일들을 구현하는 함수
  // gameOperate 함수에서 claculator 객체를 이용해서 점수를 계산하고 금액을 분배해야함.
  // 점수 계산하는 로직은 calculator에 구현되어있으니 그냥 함수 사용
  void isGameOver(std::list<Player*> playerList) {} // 게임이 종료됬는지 구하는 함수
 private:
  Operator() {} // 생성자
  static Operator* instanse_; // Operator instance, instance함수로 만들기
};