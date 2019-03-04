#include <cstring>
#include <iostream>
#include "BiSrchTree.h"

using namespace std;

BiSrchTree::BiSrchTree(){
  head = NULL;
}

BiSrchTree::~BiSrchTree(){
  //call remove function on head until empty
  //while(head != NULL){
  //remove(head->data);
  //}
}

int BiSrchTree::insert(int data){

  node* newnode;
  newnode->data = data;
  cout << "going to insert: " << newnode->data << endl;
  //if head is null, just make it head
  if(head == NULL){
    (*head) = (*newnode);
    cout << "new head: " << head->data << endl;
  }
  else{
    cout << "head: " << head->data << endl;
    insert(newnode, head);
  }
  return 0;
}

int BiSrchTree::insert(node* newnode, node* current){
  //determine if newnode goes to left or right
  cout << "newnode: " << newnode->data << endl;
  cout << "current: " << current->data << endl;
  //left
  if(current->data > newnode->data){
    //if no left child
    if(current->left == NULL){
      current->left = newnode;
      cout << "I'm a left child" << endl;
    }
    //else move to child
    else{
      cout << "moving to the left" << endl;
      insert(newnode, current->left);
    }
  }
  else{
    //if no right child
    if(current->right == NULL){
      current->right = newnode;
      cout << "I'm a right child" << endl;
    }
    else{
      cout << "moving to the right" << endl;
      insert(newnode, current->right);
    }
  }
  return 0;
}
int BiSrchTree::visualize(){
  visualize(head, 0);
  return 0;
}

int BiSrchTree::visualize(node* cur, int level){
  //print cur
  for(int i = level; i > 0; i--){
    cout << "   ";
  }
  cout << cur << endl;
  //print left if not NULL
  if(cur->left != NULL){
    visualize(cur->left, ++level);
  }
  //print right it not NULL
  if(cur->right != NULL){
    visualize(cur->right, ++level);
  }
  return 0;
}
