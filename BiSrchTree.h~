#include <iostream>
#include <cstring>

using namespace std;

#ifndef BISRCHTREE_H
#define BISRCHTREE_H

struct node{
  int data;
  node* right;
  node* left;
};

class BiSrchTree{
 public:
  BiSrchTree();
  ~BiSrchTree();
  int insert(int data);
  int insert(node* newnode, node* current);
  int contains(int data, node* cur);
  int remove(int data);
  int remove(int data, node* cur);
  int visualize();
  int visualize(node* cur, int level);
 private:
  node* head;
};

#endif
