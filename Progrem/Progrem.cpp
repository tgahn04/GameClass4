#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>
class Queue
{
private:
    int front;
    int rear;

    T container[SIZE];

public:
    Queue()
    {
        front = 0;
        rear = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (rear == SIZE)
        {
            cout << "linear queue overflow" << endl;
            return;
        }
        container[rear++] = data;
    }

    void pop()
    {
        if (empty())
        {
            exit(1);
        }
        for (int i = 0; i < rear - 1; i++)
        {
            container[i] = container[i + 1];
        }
        container

    }

    const bool& empty()
    {
        bool emp = false;
        emp = (front == rear);
        return emp;
    }

    const T peek()
    {

    }
};

int main()
{
    Queue<int> queue;



    return 0;
}