#include "card.h"
#include <string>

Card::Card(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string tti) {
  SetCard(name, gwang, yeolkkeut, godori, pi, tti);
}

void Card::SetCard(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string tti) {
  name_ = name;
  gwang_ = gwang;
  yeolkkeut_ = yeolkkeut;
  godori_ = godori;
  pi_ = pi;
  tti_ = tti;
}

CardInfo Card::GetCardInfo() {
  CardInfo card_info;
  
  card_info.name = name_;
  card_info.gwang = gwang_;
  card_info.yeolkkeut = yeolkkeut_;
  card_info.godori = godori_;
  card_info.pi = pi_;
  card_info.tti = tti_;

  return card_info;
}

std::string Card::ToString() {
  return name_ + " " + std::to_string(id_);
}