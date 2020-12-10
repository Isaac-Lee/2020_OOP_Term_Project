#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

struct PlayerInfo;

class Player {
 public:
  explicit Player(std::string name);   // 생성자
  PlayerInfo GetPlayerInfo();          // 플레이어 정보 출력
  bool isPlaying();                    // 플레이어가 플레이중인지 확인하는 함수
  void UpScore(int amount);            // 점수를 더하는 함수
  void DownScore(int amount);          // 점수를 빼는 함수
  void ResetScore();                   // 점수를 0으로 초기화 하는 함수 
  void draw(Card* card);               // 카드를 하나 핸드에 얻는 함수
  void earn(Card* card);               // 카드를 하나 필드에 얻는 함수
  Card* drop(int number);
 private:
  std::string name_;            // 플레이어 이름
  std::vector<Card*> hand_;     // 플레이어가 손에 들고 있는 카드들
  std::vector<Card*> field_;    // 플레이어가 가지고 있는 카드들
  bool isPlaying_;              // 플레이어가 플레이중인지
  int score_;                   // 플레이어의 점수
};

struct PlayerInfo {
  std::string name_;            // 플레이어 이름
  std::vector<Card*> hand_;     // 플레이어가 손에 들고 있는 카드들
  std::vector<Card*> field_;    // 플레이어가 가지고 있는 카드들
  bool isPlaying_;              // 플레이어가 플레이중인지
  int score_;
};

#endif