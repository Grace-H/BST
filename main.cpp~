#include <cstring>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include "BiSrchTree.h"

using namespace std;

int remove(BiSrchTree* tree, char* nums);
int insert(BiSrchTree* tree, char* nums);

int main(){
  //commands
  char* filestr = new char[20];
  char* commandstr = new char[20];
  char* printstr = new char[20];
  char* insertstr = new char[20];
  char* removestr = new char[20];
  char* quitstr = new char[20];
  
  strcpy(filestr, "FILE");
  strcpy(commandstr, "COMMAND");
  strcpy(printstr, "PRINT");
  strcpy(insertstr, "INSERT");
  strcpy(removestr, "REMOVE");
  strcpy(quitstr, "QUIT");
  
  char* input = new char[256];
  char* nums = new char[100000];

  //initialize tree
  BiSrchTree* tree = new BiSrchTree();
  
  //keep asking for command until user asks to quit
  bool go = true;
  while(go){
    //get input
    cout << "'INSERT' 'REMOVE' 'PRINT' or 'QUIT'?" << endl;
    cin.get(input, 256);
    cin.get();

    //uppercase
    for(int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }
    
    //identify command & act accordingly
    //insert
    if(strcmp(insertstr, input) == 0){
      cout << "Input from 'COMMAND' line or 'FILE'?" << endl;
      cin.get(input, 256);
      cin.get();
 
      //uppercase
      for(int i = 0; i < strlen(input); i++){
        input[i] = toupper(input[i]);
      }
    
      //create char* from commamd line
      if(strcmp(commandstr, input) == 0){
	cout << "Enter numbers seperated by spaces: " << endl;
	cin.get(nums, 100000);
	cin.get();
      }
      //create char* from file
      else if(strcmp(filestr, input) == 0){
	cout << "Enter complete file name. Numbers must be seperated by spaces" << endl;
	cin.get(input, 256);
	cin.get();

	//get from file
	ifstream is(input);
	is.get(nums, 100000);
	cout << nums << endl;
	is.close();
      }
      //add to tree
      insert(tree, nums);
    }
    //remove from tree
    else if(strcmp(removestr, input) == 0){
      cout << "Enter spaced-seperated numbers to remove from tree: " << endl;
      cin.get(nums, 100000);
      cin.get();
      //remove
      remove(tree, nums);
    }
    else if(strcmp(printstr, input) == 0){
      //visualize
    }
    else if(strcmp(quitstr, input) == 0){
      go = false;
      //delete stuff
    }  
    else{
      cout << "not an option" << endl;
    }
  }
  return 0;
}

//remove numbers in tree from char* array
int remove(BiSrchTree* tree, char* nums){
  //get token
  int cur = 0;
  char* str;
  str = strtok(nums, " ");
  
  while(str != NULL){
    //convert to int  
    cur = atoi(str);
    //insert into heap  
    tree->remove(cur);
    str = strtok(NULL, " ");
  }
  tree->visualize();
  return 0;
}

//adds numbers to tree from a char* array
int insert(BiSrchTree* tree, char* nums){
  //get token
  int cur = 0;
  char* str;
  str = strtok(nums, " ");
  
  while(str != NULL){
    //convert to int  
    cur = atoi(str);
    //insert into heap  
    tree->insert(cur);
    str = strtok(NULL, " ");
  }
  tree->visualize();
  return 0;
}
