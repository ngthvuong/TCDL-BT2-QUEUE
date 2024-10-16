#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *pNext;
};

class Queue
{
public:
    virtual bool enQueue(int) = 0;
    virtual int deQueue() = 0;
    virtual int peek() = 0;
    virtual void printQueue() = 0;
    virtual ~Queue() {}
};

class ARQueue : public Queue
{
private:
    int *listItems;
    int length;
    int maxSize;
    void shiftLeft(int);

public:
    ARQueue(int size = 100);
    bool enQueue(int) override;
    int deQueue() override;
    int peek() override;
    void printQueue() override;
    ~ARQueue();
};

class LLQueue : public Queue
{
private:
    node *front;
    node *rear;
    node *createNode(int);
    void print(node*);
    

public:
    LLQueue();
    bool enQueue(int) override;
    int deQueue() override;
    int peek() override;
    void printQueue() override;
    ~LLQueue();
};
#endif