#include "Queue.h"
#include <iostream>

using namespace std;

#define MAX_SIZE = 100;

ARQueue::ARQueue(int size)
{
    listItems = new int[size];
    length = 0;
    maxSize = size;
}

void ARQueue::shiftLeft(int k)
{
    if (k == 0)
    {
        return;
    }
    shiftLeft(k - 1);
    listItems[k - 1] = listItems[k];
}

bool ARQueue::enQueue(int data)
{
    if (length == maxSize)
    {
        throw out_of_range("- Queue is full!");
    }

    listItems[length] = data;
    length++;
    return true;
};
int ARQueue::deQueue()
{
    if (length == 0)
    {
        throw out_of_range("- Queue is empty!");
    }

    int value = listItems[0];

    shiftLeft(length);
    length--;

    return value;
};

int ARQueue::peek()
{
    if (length == 0)
    {
        throw out_of_range("- Queue is empty");
    }
    return listItems[0];
};
void ARQueue::printQueue()
{
    if (!length)
    {
        cout << "- Queue is empty";
    }
    for (int i = 0; i < length; i++)
    {
        cout << listItems[i] << " ";
    }
    cout << endl;
}

ARQueue::~ARQueue()
{
    delete[] listItems;
}