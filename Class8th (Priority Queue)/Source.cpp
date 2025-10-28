#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
    int index;
    int capacity;

    T* container;

public:
    PriorityQueue()
    {
        index = 0;
        capacity = 0;
        container = nullptr;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T* temporary = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }

        for (int i = 0; i < index; i++)
        {
            temporary[i] = container[i];
        }

        delete[] container;

        container = temporary;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (index >= capacity)
        {
            resize(capacity * 2);
        }

        container[index++] = data;
        int child = index - 1;
        int parent = (child - 1) / 2;

        while (child > 0)
        {
            if (container[parent] < container[child])
            {
                swap(container[parent], container[child]);
            }

            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "PriorityQueue is empty" << endl;

            return;
        }
        else
        {
            container[0] = container[--index];

            container[index] = NULL;

            int parent = 0;
            int child = parent * 2 + 1;

            while (child < index)
            {
                child = parent * 2 + 1;

                if (container[child] < container[child + 1])
                {
                    child++;
                }

                if (container[child] < container[parent])
                {
                    break;
                }
                else
                {
                    swap(container[parent], container[child]);

                    parent = child;
                }
            }
        }
    }

    const bool& empty()
    {
        return index <= 0;
    }

    const int& size()
    {
        return index;
    }

    const T& top()
    {
        if (empty())
        {
            exit(1);
        }
        else
        {
            return container[0];
        }
    }

    ~PriorityQueue()
    {
        delete[] container;
    }
};

int main()
{
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(5);
    priorityQueue.push(33);

    while (priorityQueue.empty() == false)
    {
        cout << priorityQueue.top() << endl;

        priorityQueue.pop();
    }

    cout << "Priority_Queue_is_size : " << priorityQueue.size() << endl;

    return 0;
}