#include "Card.h"
#include <iostream>

// Card 클래스
Card::Card() : month_(1), state_(gwang), isPpuk_(false) {}
// Card 생성 : 월,상태
Card::Card(const int month, const State state, const bool isPpuk) : month_(month), state_(state), isPpuk_(isPpuk) {}
// Card 월 리턴
int Card::GetMonthOfCard() const { return this->month_; }
// Card 상태 리턴
State Card::GetStateOfCard() const {  return this->state_; }
// 뻑 여부 리턴
bool Card::IsPpuk() const { return isPpuk_; }
// 뻑 여부 세팅
void Card::setPpuk(bool p) { this->isPpuk_ = p; }
// Card 상태 문자열로 변환
std::string Card::stateToString() {
  // switch 문으로 구현
  switch (this->state_) {
    case gwang:
      return "광";
      break;
    case bigwang:
      return "비광";
      break;
    case hongdan:
      return "홍단";
      break;
    case chodan:
      return "초단";
      break;
    case cheongdan:
      return "청단";
      break;
    case pi:
      return "피";
      break;
    case kkeut:
      return "열끗";
      break;
    case ssangpi:
      return "쌍피";
      break;
  }
}
// Card 정보 출력
std::string Card::toString() {
  return ("card info: month = " + std::to_string(this->month_)) +
         (" state = " + this->stateToString() + ((isPpuk_)? " - 뻑" : ""));
}

// Card의 equality는 월을 기준으로 하였음.
bool Card::operator==(const Card& other) {
  if (this->month_ == other.month_) {
    return true;
  }
  return false;
}

// CardSet에서 정렬을 위한 < operator overloading
bool Card::operator<(const Card& other) {
  if (this->month_ == other.month_) {
    return this->state_ < other.state_;
  } else {
    return this->month_ < other.month_;
  }
}
void Card::setState(State state) { this->state_ = state; }