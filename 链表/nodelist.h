#ifndef NODELIST_H
#define NODELIST_H

using listType=int;
struct Node
{
    listType val;
    Node* next;
    Node* pre;

};
Node* initList();
void insertHead (listType x,Node* head);
void insertTail(Node* head,listType x);
void insert(Node* head,listType x,int pos);
void delList(Node* head,int pos);
void listfree(Node* head);

#endif
