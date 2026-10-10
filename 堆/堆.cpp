#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int heap[100];
int n;

void siftDown(int x, int len)
{
    int i = x;
    while (1)
    {
        int smallest = i;
        int left = i * 2;
        int right = i * 2 + 1;
        if (left <= len && heap[left] < heap[smallest])
            smallest = left;
        if (right <= len && heap[right] < heap[smallest])
            smallest = right;
        if (smallest == i)
            break;
        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

void push(int x)
{
    n++;
    heap[n] = x;
    int i = n;
    while (i > 1)
    {
        int par = i / 2;
        if (heap[i] < heap[par])
        {
            swap(heap[i], heap[par]);
        }
        else
            break;
        i = par;
    }
}

void pop()
{
    if (n == 0)
        return;
    heap[1] = heap[n];
    n--;
    siftDown(1, n);
}

void buildHeap()
{
    for (int i = n / 2; i > 0; i--)
    {
        siftDown(i, n);
    }
}

void heapSort()
{
    int len = n;
    buildHeap();
    while (len > 1)
    {
        swap(heap[1], heap[len]);
        len--;
        siftDown(1, len);
    }
}

int main()
{
    priority_queue<int> q;                             // 大根堆
    priority_queue<int, vector<int>, greater<int>> mq; // 小根堆
}