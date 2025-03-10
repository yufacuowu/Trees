/**
 * @file main.cc
 * @author ZhengPeihao (zhengpeihao2001@163.com)
 * @brief use the raw pointer first, we will use the smart pointer soon
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "AVLtree.h"

// 显式实例化定义
template class TreeNode<int>;

auto main() -> int {
  int i = 5;
  AVLtree<int> tree();
  return 0;
}
