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

auto main() -> int {
  std::cout << "This test 1:\n";
  AVLtree tree1;
  tree1.insert_item(42);
  tree1.insert_item(42);
  tree1.insert_item(18);
  std::cout << "try to insert_item:\n";
  tree1.insert_item(22);
  tree1.insert_item(9);
  tree1.insert_item(21);
  tree1.insert_item(6);
  tree1.insert_item(8);
  tree1.insert_item(20);
  tree1.insert_item(63);
  tree1.insert_item(50);
  tree1.insert_item(62);
  tree1.insert_item(51);
  std::cout << "let us see what it contains:\n";
  tree1.inorder_traversal();
  std::cout << "totally " << tree1.size() << "items:\n";
  std::cout << "This layer traversal:\n";
  std::cout << "The min element is :" << tree1.min_elemet() << std::endl;
  std::cout << "The max element is :" << tree1.max_elemet() << std::endl;

  tree1.order_level_traversal();
  tree1.clear();


  std::cout << "This test 2:\n";
  AVLtree tree2{42, 42, 18, 22, 9, 21, 6, 8, 20, 63, 50, 62, 51};
  std::cout << "let us see what it contains:\n";
  tree2.inorder_traversal();
  std::cout << "totally " << tree2.size() << " items:\n";
  tree2.delete_item(20);
  tree2.delete_item(2);

  std::cout << "This layer traversal:\n";
  tree2.order_level_traversal();
  return 0;
}
