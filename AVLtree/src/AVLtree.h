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
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>
using std::unique_ptr;

class AVLtree;

class TreeNode {
  friend AVLtree;

private:
  int value;
  unique_ptr<TreeNode> left;
  unique_ptr<TreeNode> right;
  int height;

public:
  TreeNode(const int &val, unique_ptr<TreeNode> lp, unique_ptr<TreeNode> rp,
           int high)
      : value(val), left(std::move(lp)), right(std::move(rp)), height(high) {}
  TreeNode(const int &val) : TreeNode(val, nullptr, nullptr, 1) {}
  ~TreeNode() = default;
  // ~TreeNode() { std::cout << __func__ << std::endl; }
};

class AVLtree {
private:
  unique_ptr<TreeNode> _root;
  size_t _size;

public:
  // create a null tree
  AVLtree() : _root(nullptr), _size(0) {}
  // create a tree with list
  AVLtree(const std::initializer_list<int> values);
  size_t size() const { return _size; }
  void order_level_traversal() const;
  //~AVLtree() { std::cout << __func__ << std::endl; }
  //  ~AVLtree() { clear(); }
  ~AVLtree() = default;
  bool empty() const { return !_root; }
  const int &max_elemet() const;
  const int &min_elemet() const;
  // invoke by ~AVLtree()
  void clear() {
    _root.reset(nullptr);
    _size = 0;
  }
  // insert
  void insert_item(const int item) {
    _insert(_root, item);
    ++_size;
  }
  // search
  bool search_item(const int item) { return _search(_root, item); }
  // delete
  void delete_item(const int item) {
    _delete(_root, item);
    --_size;
  }
  // todo functions
  // inorder-traversal
  void inorder_traversal() const;

private:
  const int &find_max(const unique_ptr<TreeNode> &node) const noexcept;
  const int &find_min(const unique_ptr<TreeNode> &node) const noexcept;
  // left rotate
  inline void left_rotate(unique_ptr<TreeNode> &node);
  // right rotate
  inline void right_rotate(unique_ptr<TreeNode> &node);
  // left double rotate
  void right_left_rotate(unique_ptr<TreeNode> &node) {
    right_rotate(node->right);
    left_rotate(node);
  }
  // right double rotate
  void left_right_rotate(unique_ptr<TreeNode> &node) {
    left_rotate(node->left);
    right_rotate(node);
  }
  // getheight
  inline int get_height(unique_ptr<TreeNode> &node) {
    return node == nullptr ? 0 : node->height;
  }
  // private insert
  void _insert(unique_ptr<TreeNode> &node, const int item);
  // private search
  bool _search(const unique_ptr<TreeNode> &node, const int item);
  //  balence
  inline void balance(unique_ptr<TreeNode> &node);
  //  todo functions
  void print_inorder(const unique_ptr<TreeNode> &node) const;
  // private delete
  void _delete(unique_ptr<TreeNode> &node, const int item);
};

/*
 * @brief Some more than one line inline functions
 */

inline const int &AVLtree::max_elemet() const {
  if (empty()) {
    throw std::logic_error("Empty container");
  }
  return find_max(_root);
}

inline const int &AVLtree::min_elemet() const {
  if (empty()) {
    throw std::logic_error("Empty container");
  }
  return find_min(_root);
}

inline void AVLtree::balance(unique_ptr<TreeNode> &node) {
  const int balance_factor = 1;
  if (get_height(node->left) - get_height(node->right) > balance_factor) {
    if (get_height(node->left->left) >
        get_height(node->left->right)) { // I dont think there is a situation is
                                         // equal, below too
      right_rotate(node);
    } else {
      left_right_rotate(node);
    }
  } else if (get_height(node->right) - get_height(node->left) >
             balance_factor) {
    if (get_height(node->right->right) > get_height(node->right->left)) {
      left_rotate(node);
    } else {
      right_left_rotate(node);
    }
  }

  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}

inline void AVLtree::left_rotate(unique_ptr<TreeNode> &node) {
  unique_ptr<TreeNode> tmp(std::move(node->right));
  node->right = std::move(tmp->left);
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
  tmp->left = std::move(node);
  node = std::move(tmp);
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}

inline void AVLtree::right_rotate(unique_ptr<TreeNode> &node) {
  unique_ptr<TreeNode> tmp(std::move(node->left));
  node->left = std::move(tmp->right);
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
  tmp->right = std::move(node);
  node = std::move(tmp);
  node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}
