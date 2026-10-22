#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


//helper function implementation
void split(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head==NULL){
    return;
  }
  Node* curr = head;
  Node* rest = head->next;
  curr->next = NULL;

  split(rest, smaller,larger, pivot);
  
  if(curr->val > pivot){
    curr->next = larger;
    larger = curr;
  }else{
    curr->next = smaller;
    smaller = curr;
  }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  smaller = NULL;
  larger = NULL;

  //splits the list 
  split(head, smaller, larger, pivot);

  head=NULL;
}

