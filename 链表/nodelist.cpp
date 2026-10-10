#include"nodelist.h"
#include<iostream>

Node* initList(){
    Node* head=new Node;
    head->val=0;
    head->next=NULL;
    head->pre=nullptr;
    return head;
}

void insertHead (listType x,Node* head){
    Node* temp=new Node;
    temp->val=x;
    temp->pre=head;
    temp->next=head->next;
    if(head->next!=nullptr)
    head->next->pre=temp;
    head->next=temp;
}

void insertTail(Node* head,listType x){
    Node* temp = new Node;
    temp->val=x;
    Node* cur=head;
    while(cur->next!=nullptr){
        cur=cur->next;
    }
    cur->next=temp;
    temp->pre=cur;
    temp->next=nullptr;
}

void insert(Node* head,listType x,int pos){
    Node* pr=head;
    while(pos--){
        pr=pr->next;
    }
    Node* cur=pr->next;
    Node* temp=new Node;
    pr->next=temp;
    temp->val=x;
    temp->pre=pr;
    temp->next=cur;
    if(cur!=nullptr)
    cur->pre=temp;
}

void delList(Node* head,int pos){
    Node* temp=head;
    while(pos--){
        temp=temp->next;
    }
    temp->pre->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->pre=temp->pre;
    }
    delete temp;
}

void listfree(Node* head){
    Node* pre=head;
    Node* cur=head->next;
    while(cur!=nullptr){
        delete pre;
        pre=cur;
        cur=cur->next;
    }
    delete pre;
}
