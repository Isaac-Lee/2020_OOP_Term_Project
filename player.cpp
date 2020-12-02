#include "player.h"
#include <string>


Player::Player(std::string name) : name_(name), isPlaying_(true) {};

PlayerInfo Player::GetPlayerInfo() {
  PlayerInfo player_info;
  
  player_info.name_ = name_;
  player_info.hand_ = hand_;
  player_info.isPlaying_ = isPlaying_;

  return player_info;
}

bool Player::isPlaying() {
  return isPlaying_;
}

void Player::UpScore(int amount) {
  this->score_ += amount;
}

void Player::DownScore(int amount) {
  if (score_ - amount < 0) {
    this->score_ = 0;
  }
  this->score_ -= amount;
}

void Player::ResetScore() {
  this->score_ = 0;
}
