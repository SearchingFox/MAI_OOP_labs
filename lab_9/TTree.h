#ifndef TTREE_H
#define TTREE_H

#include <memory>
#include <iostream>
#include <functional>
#include <future>

#include "Figure.h"

template <typename Q> class TTree {
 private:
  class Node {
  public:
    Q data;
    std::shared_ptr<Node> son;
    std::shared_ptr<Node> sibling;
    Node();
    Node(Q);
  };

  std::shared_ptr<Node> root;
  unsigned int N;

  void recInsert(std::shared_ptr<Node>&, Q);
  void recInorder(const std::shared_ptr<Node>&);
 public:
  TTree(const unsigned int&);

  void insert(Q);
  void inorder(); 
};

#include "TTree.hpp"
#endif