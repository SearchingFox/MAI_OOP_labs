#include <iostream>

#include "TTree.h"
#include "TList.h"

#include "Trapezium.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main(void) {
  TList<Figure> list;
  TTree<std::shared_ptr<std::function<void(void)>>> tree(4);
  srand (time(NULL));

  std::function<void(void)> Insert = [&]() {
    std::cout << "Command: Insert" << std::endl;
    for (int i = 0; i < 10; i++) {
      int side  = std::rand() % 10 + 1;
      int angle = std::rand() % 10 + 1;
      if ((side % 2) == 0) {
        list.PushFront(std::make_shared<Trapezium>(Trapezium(side, side+1, side+2, side+3)));
      } else if((side % 3) == 0) {
        list.PushFront(std::make_shared<Rhombus>(Rhombus(side, angle)));
      } else {
        list.PushFront(std::make_shared<Pentagon>(Pentagon(side)));
      }
    }
  };

  std::function<void(void)> Print = [&]() {
    std::cout << "Command: Print" << std::endl;
    for (const auto& i : list) {
      i->Print();
    }
  };

  std::function<void(void)> Remove = [&]() {
    std::cout << "Command: Remove" << std::endl;
    auto iterr = list.begin();
    double sqr = (double) (std::rand()) / RAND_MAX * 12;
    while (sqr > iterr->getSquare()) {
      sqr = (double) (std::rand()) / RAND_MAX * 12;
    }
    std::cout << "Lesser than " << sqr << std::endl;
    for (int i = 0; i < 10; i++) {
      auto iter = list.begin();
      
      for (int k = 0; k < list.GetLength(); k++) {
        if (iter->getSquare() < sqr) {
          list.Pop(k + 1);
          break;
        }
        ++iter;
      }
    }
  };
  
  tree.insert(std::shared_ptr<std::function<void(void)>>(&Insert, [](std::function<void(void)>*){}));
  tree.insert(std::shared_ptr<std::function<void(void)>>(&Print,  [](std::function<void(void)>*){}));
  tree.insert(std::shared_ptr<std::function<void(void)>>(&Remove, [](std::function<void(void)>*){}));
  tree.insert(std::shared_ptr<std::function<void(void)>>(&Print,  [](std::function<void(void)>*){}));              
  tree.inorder();
  
  return 0;
}