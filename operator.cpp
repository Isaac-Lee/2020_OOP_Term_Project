#include <random>
#include "operator.h"

class Operator {
 public:
  void setGame(std::vector<Card*> cardList, std::vector<Player*> playerList,  std::vector<Card*> fieldCard) {
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(cardList.begin(), cardList.end(), g);
    //덱 셔플
    for(int i = 0; i < 6; i++){
      fieldCard.push_back(cardList.front());
      cardList.pop_back();
      //바닥 필드에 카드 6개 삽입, 덱에서 6개 제거
    }
    for(int i = 0; i < 7; i++){ //총 7장
      for(int j =0; j < 3; j++){ //총 3명
        playerList[j]->draw(cardList.front()); //각각 카드를 뽑음
        cardList.pop_back(); //덱에서 하나 제거
      }
    }
    gameOperate(cardList, playerList); // 게임 진행(카드뽑기)
  } // 첫 게임 셋팅을 위한 함수
  bool validateCard(std::vector<Card*> cardList, std::vector<Player*> playerList, Card* card, Player* player) {} // 플레이어가 카드를 정상적으로 냈는지 검사하는 함수
  void gameOperate(std::vector<Card*> cardList, std::vector<Player*> playerList) {
    //게임진행 (player1부터 진행) - 무한반복(3점 날 때까지)
    // 플레이어가 카드를 얻고 그 카드를 낼때 gameoperate 함수 실행
    while(true){
      if(playerList[0]->current_score() > 3){ // player1이 현재 점수가 3점이상일때
        break;
      }
      else if(playerList[0]->current_score() <= 3 && playerList[0] -> current_score() >= 0){
        playerList[0]->draw(cardList.front()); //카드를 뽑아 손에 쥔 카드들 리스트에 추가
        cardList.pop_back(); //덱에서 하나 제거
        //손에 쥔 카드 리스트 중 랜덤으로 하나를 빼고 바닥 카드리스트에 추가
        //바닥 카드리스트에 있는 카드들끼리 비교하여 같은 종류의 카드가 존재시 점수 획득
      }
    }
  } 
  // 플레이어가 카드를 냈을때 일어나는 일들을 구현하는 함수
  // gameOperate 함수에서 claculator 객체를 이용해서 점수를 계산하고 금액을 분배해야함.
  // 점수 계산하는 로직은 calculator에 구현되어있으니 그냥 함수 사용 
  
  // 게임이 종료됬는지 구하는 함수
  void isGameOver(std::vector<Player*> playerList) {
    int countPlayer = 0;
    for(int i = 0; i < 3; i++){ //총 7장
      if(playerList[i]->isPlaying() == true){ //플레이어가 게임중일 경우
      countPlayer++; //플레이어 수 한명 증가
      }  
    }
    if(countPlayer >=2) {
      //게임 진행중
    } else{
      //플레이어가 한명또는 없으므로 게임 종료
    }
  }

 private:
  static Operator* instanse_; // Operator instance, instance함수로 만들기
};