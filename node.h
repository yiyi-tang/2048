#ifndef _NODE_H_
#define _NODE_H_

//For constructing the linked list to store the tiles on each move.
struct Node{
  int info;
  Node * next;
};
//announce Node as a global struct.
extern Node globalStruct;

#endif
