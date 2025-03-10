/**
 * @file AVLtree.cc
 * @author ZhengPeihao (zhengpeihao2001@163.com)
 * @brief
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include "AVLtree.h"

template <typename T> void AVLtree<T>::order_level_traversal() {
  if (!this->head) {
    return;
  }
  std::queue<const TreeNode<T> *> queue;
  queue.push(head);
  while (!queue.empty()) {
    auto size = queue.size();
    while (size--) {
      std::cout << queue.front()->value << '\t';
      if (queue.front()->left) {
        queue.push(queue.front()->left);
      }
      if (queue.front()->right) {
        queue.push(queue.front()->right);
      }
      queue.pop();
    }
    std::cout << std::endl;
  }
}

/*

template <typename N>
TreeNode<N>::TreeNode(const N &val, unique_ptr<TreeNode<N>> lp,
                      unique_ptr<TreeNode<N>> rp, size_t high)
    : value(val), left(std::move(lp)), right(std::move(rp)), height(high) {}

template <typename N>
TreeNode<N>::TreeNode(const N &val)
    : value(val), left(nullptr), right(nullptr), height(0) {}
template <typename N> TreeNode<N>::TreeNode() : TreeNode(0) {}
*/
