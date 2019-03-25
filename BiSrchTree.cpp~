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
  //cout << "newnode: " << newnode->data << endl;
  //cout << "current: " << current->data << endl;
  //left
  if(current->data >= newnode->data){
    //cout << "current is less" << endl;
    //if no left child
    if(current->left == NULL){
      current->left = newnode;
      //cout << "I'm a left child" << endl;
    }
    //else move to child
    else{
      //cout << "moving to the left" << endl;
      insert(newnode, current->left);
    }
  }
  else if(current->data < newnode->data){
    //cout << "current is more" << endl;
    //if no right child
    if(current->right == NULL){
      current->right = newnode;
      //     cout << "I'm a right child" << endl;
    }
    else{
      // cout << "moving to the right" << endl;
      insert(newnode, current->right);
    }
  }
  return 0;
}

int BiSrchTree::contains(int data, node* cur){
  if(head == NULL){
    cout << "head is NULL" << endl;
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

int BiSrchTree::remove(int data){
  cout << data << " exists: " << contains(data, head) << endl;
  //confirm node exists
  if(contains(data, head) == 0){
    //find node in tree
    bool found = false;
    node* parent = NULL;
    node* todelete = head;
    while(!found){
      //cout << "cur: " << cur->data << endl;
      if(todelete->data == data){
	//cout << "found" << endl;
	found = true;
      }
      else if(todelete->data > data){
	//cout << "going left" << endl;
	parent = todelete;
	todelete = todelete->left;
      }
      else if(todelete->data < data){
	//	cout << "going right" << endl;
	parent = todelete;
	todelete = todelete->right;
      }
    }
    cout << "todelete: " << todelete->data << endl;
    if(parent != NULL){
      cout << "parent: " << parent->data << endl;
    }

    if(parent->right == todelete){
      cout << "todelete is a right child at this point in time" << endl;
    }
    
    else if(parent->left == todelete){
      cout << "todelete is a left child at this point in time" << endl;
    }
    //IF todelete has no children
    if(todelete->left == NULL && todelete->right == NULL){
      cout << "todelete has no children" << endl;
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
      cout << "has no left child" << endl;
      if(todelete != head){
	if(parent->left == todelete){
	  parent->left = todelete->right;
	  cout << "todelete is left child" << endl;
	}
	else if(parent->right == todelete){
	  parent->right = todelete->right;
	  cout << "todelete is right child" << endl;
	}
      }
      else{
	head = todelete->right;
	cout << "todelete is head" << endl;
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
      cout << "replace: " << replace->data << endl;
      //transfer children
      //IF todelete's left child is replacement
      if(todelete->left == replace){
	replace->right = todelete->right;
      }


      //change parent of todelete
      //IF todelete is head
      if(todelete == head){
	head = replace;
      }
      //ELSE IF todelete is a left child
      else if(parent->left == todelete){
	cout << "todelete is left child of: " << parent->data << endl;
	parent->left = replace;
      }
      //ELSE IF todelete is a right child
      else if(parent->right == todelete){
	cout << "todelete is right child of: " << parent->data << endl;
	parent->right = replace;
      }
    }
    //delete todelete;
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
  if(head != NULL){
  //if has left child, go left
    if(cur->right != NULL){
      //cout << "left" << endl;
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
      //cout << "right" << endl;
      int newlevel = level + 1;
      visualize(cur->left, newlevel);
    }
  }
  else{
    cout << "Tree is empty" << endl;
  }
  return 0;
}
