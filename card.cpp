#include "card.h"
#include <string>

Card::Card(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string tti) {
  SetCard(name, gwang, yeolkkeut, godori, pi, _tti);
}

void Card::SetCard(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string tti) {
  _name = name;
  _gwang = gwang;
  _yeolkkeut = yeolkkeut;
  _godori = godori;
  _pi = pi;
  _tti = tti;
}

CardInfo Card::GetCardInfo() {
  CardInfo card_info;
  
  card_info.name = _name;
  card_info.gwang = _gwang;
  card_info.yeolkkeut = _yeolkkeut;
  card_info.godori = _godori;
  card_info.pi = _pi;
  card_info.tti = _tti;

  return card_info;
}

std::string Card::ToString() {
  return _name + " " + std::to_string(_id);
}