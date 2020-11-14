#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include <locale>
#include <list>
#include <cstring>
int main(void)
{
  // TODO
  // card.txt 파일에 순서 대로 name, gwang, gyeolkkeut, godori, pi, _tti를 개행문자로 나누어서 작성
  // 예시로 하나 작성해둠.
  // 이 gostop.cpp 파일에 해당 card.txt 파일을 읽어서 카드 정보를 카드 객체로 만들어서 리스트에 넣는 코드 작성
  // for문 써써 파일 입력 받으시면 됩니다. 카드 id는 그냥 for문 돌리면서 사용하는 i로 작성
  std::list<Card*> cardList; // 카드 리스트

  std::ifstream readFile;
  readFile.open("card.txt"); //파일 열기
  if (readFile.is_open())
  {
    while (!readFile.eof())
    {
      std::string name; //카드 이름
      bool gwang;
      bool gyeolkkeut;
      bool godori;
      int pi;
      std::string tti; //띠

      std::string input1;
      std::string input2;
      std::string input3;
      std::string input4;
      std::string input5;
      std::string input6; //파일에서 읽어오는 string

      std::getline(readFile, input1); //카드 이름을 읽어온다
      name = input1;

      std::getline(readFile, input2); //광을 읽어온다
      if(input2.compare("true") == 0){ 
        gwang = true; //true일경우 광은 true
      } else{
        gwang = false;
      }
      //밑으론 다 비슷한 방식
      std::getline(readFile, input3); 
      if(input3.compare("true") == 0){ 
        gyeolkkeut = true;
      } else{
        gyeolkkeut = false;
      }

      std::getline(readFile, input4); 
      if(input4.compare("true") == 0){ 
        godori = true; //true일경우 광은 true
      } else{
        godori = false;
      }

      std::getline(readFile, input5); //피를 읽어온다
      if(input5.compare("false") == 0){ 
        pi = 0; //false일 경우 피는 0?
      } else{
          if(input5.compare("1") == 0){ 
          pi = 1;
        } else{
          pi = 0;
        }
      }

      std::getline(readFile, input6); 
      if(input4.compare("false") == 0){ 
        tti = ""; //false일 경우 공백;
      } else{
        tti = input6;
      }

      std::cout << name << gwang << gyeolkkeut << godori << pi << tti <<std::endl;
      //출력 확인
    //  Card* card = new Card(name, gwang, gyeolkkeut, godori, pi, tti);
    //  CardInfo ci;
    //  ci = card->GetCardInfo();
    //  cardList.push_back(card);
    }
    readFile.close(); //파일 닫아줍니다.
  }
  return 0;
}