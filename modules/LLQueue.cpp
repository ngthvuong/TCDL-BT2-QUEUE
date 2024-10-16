#include "Queue.h"
#include <iostream>

using namespace std;

LLQueue::LLQueue()
{
    front = nullptr;
    rear = nullptr;
}

node *LLQueue::createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->pNext = nullptr;
    return newNode;
}
void LLQueue::print(node *node)
{
    if (!node)
    {
        return;
    }
    cout << node->data << " ";
    print(node->pNext);
}
bool LLQueue::enQueue(int data)
{
    node *newNode = createNode(data);
    if (!front)
    {
        front = rear = newNode;
    }
    else
    {
        rear->pNext = newNode;
        rear = newNode;
    }

    return true;
}

int LLQueue::deQueue()
{
    if (!front)
    {
        throw out_of_range("- Queue is empty");
    }
    node *targetNode = front;
    int value = targetNode->data;

    front = front->pNext;
    if (!front)
    {
        rear = nullptr;
    }

    delete targetNode;
    return value;
}

int LLQueue::peek()
{
    if (!front)
    {
        throw out_of_range("- Queue is empty");
    }
    return front->data;
}
void LLQueue::printQueue()
{
    if (!front)
    {
        cout << "- Queue is empty";
    }
    print(front);
    cout << endl;
}
LLQueue::~LLQueue()
{
    while (!front)
    {
        deQueue();
    }
}