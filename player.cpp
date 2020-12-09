#include "player.h"
#include <iostream>


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

void Player::draw(Card* card) {
  this->hand_.push_back(card);
}

void Player::earn(Card* card) {
  this->field_.push_back(card);
}

Card* Player::drop(int number) {
  Card* card;
  int count = 1;
  for (std::vector<Card*>::iterator it = this->hand_.begin(); it != this->hand_.end(); it++) {
    if (count == number) {
      card = this->hand_[number-1];
      it = this->hand_.erase(it);
      break;
    } else {
      count++;
    }
  }
  return card;
}