#include <iostream>

struct CardInfo;

class Card {
 public:
  Card();
  Card(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string _tti);
  void SetCard(std::string name, bool gwang, bool yeolkkeut, bool godori, int pi, std::string _tti);
  CardInfo GetCardInfo();    // 카드의 정보(id를 제외한 모든 필드)를 구조체 형태로 반환
  std::string ToString();    // 카드의 아이디와 카드의 이름을 공백 기준으로 구분한 문자열을 반환
 private:
  int _id;                   // 카드 구분을 위한 카드 id 만드는 순서대로 1부터 숫자 부여
  bool _gwang;               // 광인지 아닌지
  bool _yeolkkeut;           // 열끗인지 아닌지
  bool _godori;              // 고도리인지 아닌지
  int _pi;                   // 피인경우 1, 쌍피인 경우 2, 아닌경우 0
  std::string _tti;          // 띠의 종류를 한글을 로마자 표기로 작성
  std::string _name;         // 카드의 이름 예) 송학 광, 송학 홍단, 송학 피1, 송학 피2
};

struct CardInfo {
  bool gwang;               // 광인지 아닌지
  bool yeolkkeut;           // 열끗인지 아닌지
  bool godori;              // 고도리인지 아닌지
  int pi;                   // 피인경우 1, 쌍피인 경우 2, 아닌경우 0
  std::string tti;          // 띠의 종류를 한글을 로마자 표기로 작성
  std::string name;         // 카드의 이름 예) 송학 광, 송학 홍단, 송학 피1, 송학 피2
};