/**
 * @file main.cc
 * @author ZhengPeihao (zhengpeihao2001@163.com)
 * @brief
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <iostream>
#include <memory>
#include <queue>
using std::unique_ptr;

template <typename N> class AVLtree;

template <typename N> class TreeNode {
  // template <typename N> friend AVLtree;
  friend AVLtree<N>;

private:
  N value;
  unique_ptr<TreeNode<N>> left;
  unique_ptr<TreeNode<N>> right;
  size_t height;

public:
  TreeNode(const N &val, unique_ptr<TreeNode<N>> lp, unique_ptr<TreeNode<N>> rp,
           size_t high);
  TreeNode(const N &val);
  TreeNode();
  ~TreeNode() = default;

public:
  N get_val() const { return value; }
  void set_val(N val) { value = val; }
  const TreeNode *get_left() const { return left.get(); }
  const TreeNode *get_right() const { return right.get(); }
  void set_right(unique_ptr<TreeNode<N>> &node) { right = std::move(node); }
  void set_left(unique_ptr<TreeNode<N>> &node) { left = std::move(node); }
};

template <typename N>
TreeNode<N>::TreeNode(const N &val, unique_ptr<TreeNode<N>> lp,
                      unique_ptr<TreeNode<N>> rp, size_t high)
    : value(val), left(std::move(lp)), right(std::move(rp)), height(high) {}

template <typename N>
TreeNode<N>::TreeNode(const N &val)
    : value(val), left(nullptr), right(nullptr), height(0) {}
template <typename N> TreeNode<N>::TreeNode() : TreeNode(0) {}
/**
 * @brief AVLtree
 *
 * @tparam T
 */
template <typename T> class AVLtree {
private:
  unique_ptr<TreeNode<T>> head;

public:
  AVLtree();
  void order_level_traversal();
  ~AVLtree();
};
/*
template <typename T> void AVLtree<T>::order_level_traversal() {

  if (!head) {
    return;
  }
  std::queue<const TreeNode<T> *> queue;
  queue.push(node);
  while (!queue.empty()) {
    auto size = queue.size();
    while (size--) {
      std::cout << queue.front()->get_val() << '\t';
      if (queue.front()->get_left()) {
        queue.push(queue.front()->get_left());
      }
      if (queue.front()->get_right()) {
        queue.push(queue.front()->get_right());
      }
      queue.pop();
    }
    std::cout << std::endl;
  }
}
*/
