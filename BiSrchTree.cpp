/*Binary Search Tree Class
 *Manages tree of struct nodes by inserting, removing, printing
 *Author: Grace Hunter
 *Date: 24 March 2019
 */

#include <cstring>
#include <iostream>
#include "BiSrchTree.h"

using namespace std;

//constuctor
BiSrchTree::BiSrchTree(){
  head = NULL;
}

//destructor
BiSrchTree::~BiSrchTree(){
  while(head != NULL){
    remove(head->data);
  }
}

//creates node from data value, then calls recursive insert to insert node
int BiSrchTree::insert(int data){
  node* newnode = new node;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  //if head is null, just make it head
  if(head == NULL){
    head = newnode;
  }
  else{
    insert(newnode, head);
  }
  return 0;
}

//inserts a node using recursion
int BiSrchTree::insert(node* newnode, node* current){
  //determine if newnode goes to left or right
  //left
  if(current->data >= newnode->data){
    //if no left child
    if(current->left == NULL){
      current->left = newnode;
    }
    //else move to child
    else{
      insert(newnode, current->left);
    }
  }
  //right
  else if(current->data < newnode->data){
    //if no right child
    if(current->right == NULL){
      current->right = newnode;
    }
    else{
      insert(newnode, current->right);
    }
  }
  return 0;
}

//determines whether data value exists in tree below/including node* cur
//returns 1 if data value does not exist
//returns 0 if data value does exist
int BiSrchTree::contains(int data, node* cur){
  if(head == NULL){
    return 1;
  }
  else if(data == cur->data){
    return 0;
  }
  else if(data <= cur->data && cur->left != NULL){
    return contains(data, cur->left);
  }
  else if(data > cur->data && cur->right != NULL){
    return contains(data, cur->right);
  }
  else{
    return 1;
  }
}

//find a node using a given integer, remove it from tree
int BiSrchTree::remove(int data){
  //confirm node exists
  if(contains(data, head) == 0){
    bool found = false;
    node* parent = NULL;
    node* todelete = head;
    while(!found){
      if(todelete->data == data){
	found = true;
      }
      else if(todelete->data > data){
	parent = todelete;
	todelete = todelete->left;
      }
      else if(todelete->data < data){
	parent = todelete;
	todelete = todelete->right;
      }
    }
    
    //IF todelete has no children
    if(todelete->left == NULL && todelete->right == NULL){
      if(todelete != head){
	if(parent->left == todelete){
	  parent->left = NULL;
	}
	else if(parent->right == todelete){
	  parent->right = NULL;
	}
      }
      else{
	head = NULL;
      }
    }

    //ELSE IF todelete has no left child
    else if(todelete->left == NULL){
      if(todelete != head){
	if(parent->left == todelete){
	  parent->left = todelete->right;
	}
	else if(parent->right == todelete){
	  parent->right = todelete->right; 
	}
      }
      else{
	head = todelete->right;
      }
    }
    
    //ELSE (todelete has left or two children)
    else{
      node* replace = todelete;
      node* prev = replace;
      replace = replace->left;
      while(replace->right != NULL){
	prev = replace;
	replace = replace->right;
      }
      //transfer children
      //IF todelete's left child is replacement
      if(todelete->left == replace){
	replace->right = todelete->right;
      }
      //deal with replacement's children
      else{
	prev->right = replace->right;
	replace->left = todelete->left;
	replace->right = todelete->right;
      }

      //change parent of todelete
      //IF todelete is head
      if(todelete == head){	
	head = replace;
      }
      //ELSE IF todelete is a left child
      else if(parent->left == todelete){
	parent->left = replace;
      }
      //ELSE IF todelete is a right child
      else if(parent->right == todelete){
	parent->right = replace;
      }
    }
    delete todelete;
  }
  else{
    cout << "Does not exist: " << data << endl;
  }   
  return 0;
}

//calls recursive visualize method
int BiSrchTree::visualize(){
  visualize(head, 0);
  return 0;
}

//uses recursion to print tree horizontally:
//left side printed first, lower levels on the right
int BiSrchTree::visualize(node* cur, int level){
  if(head != NULL){
  //if has left child, go left
    if(cur->right != NULL){
      int newlevel = level + 1;
      visualize(cur->right, newlevel);
    }
    //print
    for(int i = level; i > 0; i--){
      cout << "    ";
    }
    cout << cur->data << endl;
    //if right child go right
    if(cur->left != NULL){
      int newlevel = level + 1;
      visualize(cur->left, newlevel);
    }
  }
  else{
    cout << "Tree is empty" << endl;
  }
  return 0;
}
