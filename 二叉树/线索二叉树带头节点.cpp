#include <iostream>
using namespace std;
using ElemType = int;
struct ThreadNode
{
    ElemType val;
    ThreadNode *lchild;
    ThreadNode *rchild;
    int ltag;
    int rtag;
};

using ThreadTree = ThreadNode *;
ThreadTree pre = nullptr;

ThreadTree createThread(ElemType x)
{
    ThreadTree p = new ThreadNode;
    p->val = x;
    p->lchild = nullptr;
    p->rchild = nullptr;
    p->ltag = 0;
    p->rtag = 0;
    return p;
}

void threading(ThreadTree root){
    if(root->ltag==0) threading(root->lchild);
    if(root->lchild==nullptr){
        root->lchild=pre;
        root->ltag=1;
    }
    if(pre!=nullptr && pre->rchild==nullptr){
        pre->rtag=1;
        pre->rchild=root;
    }
    pre=root;
    if(root->rtag==0) threading(root->rchild); 
}

ThreadTree inOrderThread(ThreadTree root)
{
    ThreadTree head = new ThreadNode;
    head->ltag = 0;
    head->rtag = 1;
    head->lchild = root;
    head->rchild = head;
    if (root == nullptr)
    {
        head->lchild = head;
        return head;
    }
    pre=head;
    threading(root);
    pre->rchild=head;
    pre->rtag=1;
    head->rchild=pre;
    return head;
}

void inOrder(ThreadTree head){
    ThreadTree cur= head->lchild;
    while(cur!=nullptr&&cur->ltag==0){
        cur=cur->lchild;
    }
    while(cur!=head){
        cout << cur->val << ' ';
        if(cur->rtag==1){
            cur=cur->rchild;
        } else {
            cur=cur->rchild;
            while(cur->ltag==0){
                cur=cur->lchild;
            }
        }
    }
}

int main()
{
    ThreadTree root = createThread(1);

    root->lchild = createThread(2);
    root->rchild = createThread(3);

    root->lchild->lchild = createThread(4);
    root->lchild->rchild = createThread(5);
}
