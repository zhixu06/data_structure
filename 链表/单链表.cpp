#include <iostream>
using namespace std;
using ElemType = int;

struct Node
{
    ElemType data;
    Node *next;
};

Node *initlist()
{
    Node *l = new Node;
    l->data = 0;
    l->next = NULL;
    return l;
}

void insertHead(Node &l, ElemType x)
{
    Node *y = new Node;
    y->data = x;
    y->next = l.next;
    l.next = y;
}

void insertTail(Node *Tail, ElemType x)
{
    Node *p = new Node;
    p->next = NULL;
    Tail->next = p;
    p->data = x;
    Tail = p;
}

void insert(ElemType x, int pos, Node *list)
{
    Node *l = list;
    int i = 0;
    while (i < pos - 1)
    {
        l = l->next;
        i++;
        if (l == NULL)
            return;
    }
    Node *y = new Node;
    y->data = x;
    y->next = l->next;
    l->next = y;
}

void deleteData(int pos, Node *list)
{
    Node *l = list;
    int i = 0;
    while (i < pos - 1)
    {
        l = l->next;
        i++;
        if (l == NULL)
            return;
    }
    if (l->next == NULL)
        return;
    Node *temp = l->next;
    l->next = temp->next;
    delete temp;
}

void freelist(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
    head->next = NULL;
}

void print(Node &head)
{
    Node *p = head.next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return;
}

ElemType findlast(int pos, Node *list)
{
    Node *fast = list;
    Node *slow = list;
    while (pos--)
    {
        fast = fast->next;
        if (fast == NULL)
            return 0;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

Node *reverselist(Node *list)
{
    Node *pre = NULL;
    Node *cur = list->next;
    while (cur != NULL)
    {
        Node *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    Node *head = new Node;
    head->data = 0;
    head->next = pre;
    return head;
}

void delmid(Node* list){
    Node* fast=list->next;
    Node* slow=list;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    } 
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete(temp);
}
Node *getTail(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

int main()
{
    Node *list = initlist();
    insertHead(*list, 10);
    Node *tail = getTail(list);
}
