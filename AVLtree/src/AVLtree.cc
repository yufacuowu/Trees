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

#include "AVLtree.h"

void AVLtree::print_inorder(const unique_ptr<TreeNode> &node) const {
  if (node) {
    print_inorder(node->left);
    std::cout << node->value << ", ";
    print_inorder(node->right);
  }
}

void AVLtree::inorder_traversal() const {
  if (empty()) {
    std::cout << "{}\n";
    return;
  }
  std::cout << "{ ";
  print_inorder(_root);
  std::cout << "\b\b }\n";
}

AVLtree::AVLtree(const std::initializer_list<int> values) : AVLtree() {
  for (auto &value : values) {
    insert_item(value);
  }
}

const int &AVLtree::find_max(const unique_ptr<TreeNode> &node) const noexcept {
  TreeNode *tmp = node.get();
  if (tmp) {
    while (tmp->right) {
      tmp = tmp->right.get();
    }
  }
  return tmp->value;
}

const int &AVLtree::find_min(const unique_ptr<TreeNode> &node) const noexcept {
  TreeNode *tmp = node.get();
  if (tmp) {
    while (tmp->left) {
      tmp = tmp->left.get();
    }
  }
  return tmp->value;
}

void AVLtree::order_level_traversal() const {
  if (!this->_root) {
    return;
  }
  std::queue<const TreeNode *> queue;
  queue.push(_root.get());
  while (!queue.empty()) {
    auto size = queue.size();
    while (size--) {
      std::cout << queue.front()->value << '\t';
      if (queue.front()->left) {
        queue.push(queue.front()->left.get());
      }
      if (queue.front()->right) {
        queue.push(queue.front()->right.get());
      }
      queue.pop();
    }
    std::cout << std::endl;
  }
}

void AVLtree::_insert(unique_ptr<TreeNode> &node, const int item) {
  if (!node) {
    node = std::make_unique<TreeNode>(item);
  } else if (item > node->value) {
    _insert(node->right, item);
  } else if (item < node->value) {
    _insert(node->left, item);
  }

  balance(node);
}

bool AVLtree::_search(const unique_ptr<TreeNode> &node, const int item) {

  auto tp = node.get();

  while (tp) {
    if (tp->value == item) {
      return true;
    } else if (item > tp->value) {
      tp = tp->right.get();
    } else if (item < tp->value) {
      tp = tp->left.get();
    }
  }
  return false;
}

void AVLtree::_delete(unique_ptr<TreeNode> &node, const int item) {
  if (!node) {
    // if not find, end the function
    return;
  }
  if (item > node->value) {
    // if item greater than node's value, go to right subtree
    _delete(node->right, item);
  } else if (item < node->value) {
    // if item less than node's value, go to left subtree
    _delete(node->left, item);
  } else if (node->left && node->right) {
    // if item is found, and it has left child and right chile, then do this
    node->value = find_min(node->right);
    _delete(node->right, node->value);
  } else {
    /*
     * @brief This is really great implementation: if this node is a leaf node,
     * then whatever left or right is nullptr, then the node will be a nullptr;
     * or this node has left or right node, if it has left node, this node will
     * be its left node, or this node will be its right node.
     */
    unique_ptr<TreeNode> old(std::move(node));
    node = ((old->left) ? std::move(old->left) : std::move(old->right));
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
