/*header file for Binary Search Tree, implemented as BiSrchTree Class
 *contains node struct
 *Author: Grace Hunter
 *Date: 24 March 2019
 */

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
  int visualize();
  int visualize(node* cur, int level);
 private:
  node* head;
};

#endif
