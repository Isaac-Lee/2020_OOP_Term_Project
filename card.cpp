#include "card.h"
#include <string>
#include <iostream>

Card::Card(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string tti) : name_(name), gwang_(gwang), yeolkkeut_(yeolkkeut), godori_(godori), pi_(pi), tti_(tti) {}

CardInfo Card::getCardInfo() {
  CardInfo card_info;
  
  card_info.name = this->name_;
  card_info.gwang = this->gwang_;
  card_info.yeolkkeut = this->yeolkkeut_;
  card_info.godori = this->godori_;
  card_info.pi = this->pi_;
  card_info.tti = this->tti_;

  return card_info;
}

void Card::toString(int i) {
  std::cout << i << ". " << this->name_ << std::endl;
  std::cout << "디버깅" << std::endl;
}