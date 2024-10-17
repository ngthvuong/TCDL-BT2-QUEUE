#include "modules/Queue.h"
#include <iostream>

using namespace std;

void queueScreen(Queue *);

int main()
{
    cout << "QUEUE PROGRAM" << endl;
    cout << "=====================" << endl;

    cout << "--------------------" << endl;
    cout << "Commands of main screen" << endl;
    cout << " - 0 : Exit program" << endl;
    cout << " - 1 : Array Queue" << endl;
    cout << " - 2 : Linked List Queue" << endl;

    Queue *queue = nullptr;
    int mainLoop = 0;
    do
    {
        cout << "--------------------" << endl;
        cout << "Command = ";
        cin >> mainLoop;

        switch (mainLoop)
        {
        case 0:
            cout << "Program exited" << endl;
            break;
        case 1:
            if (queue)
            {
                delete queue;
            }
            queue = new ARQueue();
            queueScreen(queue);
            break;
        case 2:
            if (queue)
            {
                delete queue;
            }
            queue = new LLQueue();
            queueScreen(queue);
            break;
        default:
            cout << "Wrong symbol, type again" << endl;
        }
    } while (mainLoop);

    if (queue)
    {
        delete queue;
    }
    return 0;
}

void queueScreen(Queue *queue)
{
    cout << "--------------------" << endl;
    cout << "Pick an action on queue" << endl;
    cout << " - 0 : Return Main Screen" << endl;
    cout << " - 1 : Enqueue" << endl;
    cout << " - 2 : Dequeue" << endl;
    cout << " - 3 : Peek " << endl;
    cout << " - 4 : Show Queue " << endl;

    int queueLoop = 0;
    do
    {
        cout << "--------------------" << endl;
        cout << "Action = ";
        cin >> queueLoop;

        switch (queueLoop)
        {
        case 0:
            cout << "--------------------" << endl;
            cout << "Commands of main screen" << endl;
            cout << " - 0 : Exit program" << endl;
            cout << " - 1 : Array Queue" << endl;
            cout << " - 2 : Linked List Queue" << endl;
            break;
        case 1:
            try
            {
                cout << "--------------------" << endl;
                cout << "Integer = ";
                int data;
                cin >> data;

                queue->enQueue(data);
                cout << "Enqueue successfully!" << endl;
            }
            catch (out_of_range &e)
            {
                cout << "Errors: " << e.what() << endl;
            }
            break;
        case 2:
            try
            {
                cout << "--------------------" << endl;
                cout << "Dequeue integer = " << queue->deQueue() << endl;
            }
            catch (out_of_range &e)
            {
                cout << "Errors: " << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                cout << "--------------------" << endl;
                cout << "Peek integer = " << queue->peek() << endl;
            }
            catch (out_of_range &e)
            {
                cout << "Errors: " << e.what() << endl;
            }
            break;
        case 4:
            try
            {
                cout << "--------------------" << endl;
                cout << "List Queue: " << endl;
                queue->printQueue();
            }
            catch (out_of_range &e)
            {
                cout << "Errors: " << e.what() << endl;
            }
            break;
        default:
            cout << "Wrong symbol, type again" << endl;
        }
    } while (queueLoop);
}