#include <cstring>
#include <iostream>
#include "BiSrchTree.h"

using namespace std;

BiSrchTree::BiSrchTree(){
  head = NULL;
}

BiSrchTree::~BiSrchTree(){
  while(head != NULL){
    remove(head->data);
  }
}

int BiSrchTree::insert(int data){

  node* newnode = new node;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  cout << "going to insert: " << newnode->data << endl;
  //if head is null, just make it head
  if(head == NULL){
    cout << "head is NULL" << endl;
  }
  if(head == NULL){
    head = newnode;
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
  if(current->data < newnode->data){
    cout << "current is less" << endl;
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
  else if(current->data >= newnode->data){
    cout << "current is more" << endl;
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

int BiSrchTree::contains(int data, node* cur){
  if(data == cur->data){
    return 0;
  }
  else if(data > cur->data && cur->left != NULL){
    return contains(data, cur->left);
  }
  else if(data <= cur->data && cur->right != NULL){
    return contains(data, cur->right);
  }
  else{
    return 1;
  }
}

int BiSrchTree::remove(int data){
  cout << data << " exists: " << contains(data, head) << endl;
  //confirm node exists
  if(contains(data, head) == 0){
    //find node in tree
    bool found = false;
    node* parent = NULL;
    node* cur = head;
    while(!found){
      cout << "cur: " << cur->data << endl;
      if(cur->data == data){
	cout << "found" << endl;
	found = true;
      }
      else if(cur->data < data){
	cout << "going left" << endl;
	parent = cur;
	cur = cur->left;
      }
      else if(cur->data > data){
	cout << "going right" << endl;
	parent = cur;
	cur = cur->right;
      }
    }
    cout << "found node: " << cur->data << endl;
    //if node has two children
    if(cur->left != NULL && cur->right != NULL){
      cout << "has two children" << endl;
      //find next smallest node
      node* prev = cur;
      node* replace = cur->right;
      while(replace->left != NULL){
	prev = replace;
	replace = replace->left;
      }

      cout << "found replacement: " << replace->data << endl;
      //if it has a left child, assign that to parent
      if(replace->left != NULL){
	cout << "has left child" << endl;
	prev->right = replace->left;
      }
      
      //transfer children
      if(cur->right != replace){
	replace->right = cur->right;
      }
      else{
	replace->right = NULL;
      }
      if(cur->left != replace){
	replace->left = cur->left;
      }
      else{
	replace->left = NULL;
      }
      
      //point parent to it
      if(cur == head){
	head = replace;
      }
      else if(cur->data <= parent->data){
	cout << "cur is a right child" << endl;
	parent->right = replace;
      }
      else{
	cout << "cur is a left child" << endl;
	parent->left = replace;
      }
      //      visualize();
      cout << "done" << endl;
    }
    //if node has left child
    else if(cur->left != NULL){
      if(cur == head){
	head = cur->left;
      }
      else if(cur->data <= parent->data){
	parent->left = cur->left;
      }
      else{
	parent->right = cur->right;
      }
    }  
    //if node has right child
    else if(cur->right != NULL){
      if(cur == head){
	head = cur->right;
      }
      else if(cur->data <= parent->data){
	parent->left = cur->left;
      }
      else{
	parent->right = cur->right;
      }
    }  
    //if node has no children
    else{
      if(cur == head){
	head = NULL;
      }
      else if(cur->data <= parent->data){
	parent->left = NULL;
      }
      else{
	parent->right = NULL;
      }
    }
    delete cur;
  }
  else{
    cout << "Does not exist: " << data << endl;
  }
  return 0;
}

int BiSrchTree::remove(int data, node* cur){
  return 0;
}

int BiSrchTree::visualize(){
  visualize(head, 0);
  return 0;
}

int BiSrchTree::visualize(node* cur, int level){
  //if has left child, go left
  if(cur->left != NULL){
    int newlevel = level + 1;
    visualize(cur->left, newlevel);
  }
  //print
  for(int i = level; i > 0; i--){
        cout << "    ";
  }
  cout << cur->data << endl;
  //if right child go right
  if(cur->right != NULL){
    int newlevel = level + 1;
    visualize(cur->right, newlevel);
  }
  return 0;
}
