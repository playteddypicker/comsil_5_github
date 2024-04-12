#include "LinkedList.h"

// 1. 템플릿 클래스로 확장해야함
// 2. Stack형식으로 Delete 함수 재정의해야함
// 주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를
// 사용하여 가져와야함

// LinkedList class를 상속받음
template <class T> class Stack : public LinkedList<T> {
public:
  bool Delete(int &element) {
    // first가 0이면 false반환
    if (this->first == 0) {
      cout << "error : trying to delete at empty data set." << endl;
      return false;
    }

    // LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
    Node<T> *before_first = this->first;
    Node<T> *after_first = this->first->link;
    this->first = after_first;
    delete before_first;
    (this->current_size)--;

    return true;
  }
};
