#include <iostream>
#include <stack>
using namespace std;

using ElemType = int;
struct treeNode
{
    ElemType val;
    treeNode *lchild;
    treeNode *rchild;
};
using bitree = treeNode *;

bitree createbitree(ElemType x)
{
    bitree temp = new treeNode;
    temp->val = x;
    temp->lchild = nullptr;
    temp->rchild = nullptr;
    return temp;
}
void preOrder(bitree t)
{
    if (t == nullptr)
        return;
    cout << t->val << " ";
    preOrder(t->lchild);
    preOrder(t->rchild);
}

void inOrder(bitree t)
{
    if (t == nullptr)
        return;
    inOrder(t->lchild);
    cout << t->val << " ";
    inOrder(t->rchild);
}

void postOrder(bitree t)
{
    if (t == nullptr)
        return;
    postOrder(t->lchild);
    postOrder(t->rchild);
    cout << t->val << " ";
}

void iterPreOrder(bitree t)
{
    stack<bitree> s;
    while (t != nullptr || !s.empty())
    {
        while (t != nullptr)
        {
            cout << t->val << ' ';
            s.push(t);
            t = t->lchild;
        }
        t = s.top();
        s.pop();
        t = t->rchild;
    }
}

int maxHeight(bitree root)
{
    if (root == nullptr)
        return 0;
    int left = maxHeight(root->lchild);
    int right = maxHeight(root->rchild);
    return max(left, right) + 1;
}

int getNodeCount(bitree root)
{
    if (root == nullptr)
        return 0;
    int left = getNodeCount(root->lchild);
    int right = getNodeCount(root->rchild);
    return left + right + 1;
}

int getLeafCount(bitree root)
{
    if (root == nullptr)
        return 0;
    if (root->lchild == nullptr && root->rchild == nullptr)
    {
        return 1;
    }
    int left = getLeafCount(root->lchild);
    int right = getLeafCount(root->rchild);
    return left + right;
}

int main()
{
    bitree root = createbitree(1);
    root->lchild = createbitree(2);
    root->rchild = createbitree(3);
    root->lchild->lchild = createbitree(4);
    root->lchild->rchild = createbitree(5);
    root->rchild->lchild = createbitree(6);
    root->rchild->rchild = createbitree(7);
    return 0;
}
