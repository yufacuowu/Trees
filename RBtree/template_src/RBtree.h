/**
 * @file main.cc
 * @author ZhengPeihao (zhengpeihao2001@163.com)
 * @brief use the raw pointer first, we will use the smart pointer soon
 * @version 0.1
 * @date 2023-12-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

enum Attributes { red, black };
template <typename T> class RBtree_node {
  T value;
  RBtree_node *left;
  RBtree_node *right;
  RBtree_node *parent;
  Attributes att;

public:
  RBtree_node(T val) : value(val) {}
};

template <typename V> class RBtree {
private:
  RBtree_node *head;
};
