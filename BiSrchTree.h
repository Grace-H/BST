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
  int retrieve(int data);
  int remove(int data);
  int visulaize();
 private:
  node* head;
};

#endif
