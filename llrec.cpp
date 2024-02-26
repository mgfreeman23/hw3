#include "llrec.h"

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //initialize larger and smaller lists to null
  smaller = nullptr;
  larger = nullptr;
  //checks if input list is empty
  if(head == nullptr){
    return;
  }
  //head recursion to reach last item
  llpivot(head->next, smaller, larger, pivot);
  //if node value is greater than pivot
  if(head->val > pivot){
    //correctly links the nodes larger list
    head->next = larger;
    larger = head;
  } 
  //if node value is less than or equal pivot
  else {
    //correctly links the nodes in smaller/equal list
    head->next = smaller;
    smaller = head;
  }
  //sets head to null before returning
  head = nullptr;
  return;
}

