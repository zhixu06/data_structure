#include <iostream>
using namespace std;

using queueType = int;
#define MAXSIZE 100

struct queueNode
{
    queueType arr[MAXSIZE];
    int front;
    int rear;
};

queueNode *initQueue()
{
    queueNode *q = new queueNode;
    q->front = 0;
    q->rear = 0;
    return q;
}

int push(queueNode *q, queueType x)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        cout << "满了";
        return 0;
    }
    q->arr[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

int pop(queueNode *q, queueType &x)
{
    if (q->front == q->rear)
    {
        cout << "空";
        return 0;
    }
    x = q->arr[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

int isEmpty(queueNode* q){
    if(q->front==q->rear){
        cout << "空";
        return 1;
    }else return 0;
}


int main()
{

    return 0;
}
