/**
 * @file main.cc
 * @author ZhengPeihao (zhengpeihao2001@163.com)
 * @brief use the smart pointer first, we will use the template soon
 * @version 0.1
 * @date 2023-12-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

enum class Color { RED, BLACK };
class RBtree_node {
  int value;
  shared_ptr<RBtree_node> left;
  shared_ptr<RBtree_node> right;
  weak_ptr<RBtree_node> parent;
  Color color;

public:
  RBtree_node(const int &val)
      : value(val), left(nullptr), right(nullptr), parent(), color(Color::RED) {
  }
};

class RBtree {
private:
  unique_ptr<RBtree_node> head;
};
