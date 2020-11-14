#include "card.h"
#include <set>

int main(int argc, char const *argv[])
{
  std::set<Card> cards;
  Card* card = new Card("test_card", false, false, false, 100, "test_tti");
  CardInfo ci;
  ci = card->GetCardInfo();

  std::cout << ci.name << std::endl;
  std::cout << ci.gwang << std::endl;
  std::cout << ci.godori << std::endl;
  std::cout << ci.yeolkkeut << std::endl;
  std::cout << ci.pi << std::endl;
  std::cout << ci.tti << std::endl;
  // TODO
  // card.txt 파일에 순서 대로 name, gwang, yeolkkeut, godori, pi, _tti를 개행문자로 나누어서 작성
  // 예시로 하나 작성해둠.
  // 이 gostop.cpp 파일에 해당 card.txt 파일을 읽어서 카드 정보를 카드 객체로 만들어서 리스트에 넣는 코드 작성
  // for문 써써 파일 입력 받으시면 됩니다. 카드 id는 그냥 for문 돌리면서 사용하는 i로 작성
  return 0;
}
