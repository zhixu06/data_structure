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

void threading(ThreadTree root)
{
    if (root == nullptr)
        return;
    if (root->ltag == 0)
        threading(root->lchild);
    if (root->lchild == nullptr)
    {
        root->ltag = 1;
        root->lchild = pre;
    }
    if (pre != nullptr && pre->rchild == nullptr)
    {
        pre->rtag = 1;
        pre->rchild = root;
    }
    pre = root;
    if (root->rtag == 0)
        threading(root->rchild);
}

ThreadTree firstNode(ThreadTree root)
{
    while (root != nullptr && root->ltag == 0)
    {
        root = root->lchild;
    }
    return root;
}

void inOrder(ThreadTree root)
{
    ThreadTree cur = firstNode(root);
    while (cur != nullptr)
    {
        cout << cur->val << ' ';
        if (cur->rtag == 1)
        {
            cur = cur->rchild;
        }
        else
        {
            cur = firstNode(cur->rchild);
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
    threading(root);
}

void threading(ThreadTree t)
{
    if (t != nullptr)
    {
        threading(t->lchild);
        if (t->lchild == nullptr)
        {
            t->ltag = 1;
            t->lchild = pre;
        }
        if (pre->rchild == nullptr)
        {
            pre->rtag = 1;
            pre->rchild = t;
        }
        pre = t;
        threading(t->rchild);
    }
}
void inOrderthread(ThreadTree *head, ThreadTree t)
{
    *head = new ThreadNode;
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);
    if (t == nullptr)
    {
        (*head)->lchild = *head;
    }
    else
    {
        (*head)->lchild = t;
        pre = (*head);
        threading(t);
        pre->rchild = *head;
        pre->rtag = 1;
        (*head)->rchild = pre;
    }
}