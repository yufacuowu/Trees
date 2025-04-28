/*
  zhengpeihao
  2025/4/28
  zhengpeihao2001@outlook.com
  use vector to implementation a heap for intiger

*/
# pragma once
# include <vector>

using std::vector;

class Heap{
  private:
    unsigned int _size;
    vector<int> _heap_tree;

  public:
    // default construstor function
    Heap(): _heap_tree(), _size(0) {}
    // default destructor function
    ~Heap() = default; 
    explicit Heap(int const element): _heap_tree{element}, _size(1) {}
    // initializer_list construstor
    Heap(const std::initializer_list<int> values);
    // 

};
