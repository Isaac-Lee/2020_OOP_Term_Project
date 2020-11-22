#include "player.h"
#include <string>


Player::Player(std::string name) : name_(name), money_(500), isPlaying_(true) {};

PlayerInfo Player::GetPlayerInfo() {
  PlayerInfo player_info;
  
  player_info.name_ = name_;
  player_info.hand_ = hand_;
  player_info.money_ = money_;
  player_info.isPlaying_ = isPlaying_;
}

bool Player::isBroke() {
  return (money_ <= 0);
}

bool Player::isPlaying() {
  return isPlaying_;
}

int Player::HowManyMoney() {
  return money_;
}

void Player::LoseMoney(int amount) {
  if (this->HowManyMoney() < amount) {
    this->money_ = 0;
  } else {
    this->money_ -= amount;
  }
}

void Player::WinMoney(int amount) {
  this->money_ += amount;
}