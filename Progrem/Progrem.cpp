#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    int size;
    Node* head;

public:
    List()
    {
        head = nullptr;
        size = 0;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;

            head = newNode;
        }
        size++;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
        }
        else
        {
            Node* deleteNode = head->next;

            if (head == deleteNode)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                head->next = deleteNode->next;
                delete deleteNode;
            }
        }
        size--;
    }

};

int main()
{
    List<int> list;

    list.push_back(10);
    list.push_back(20);

    list.push_front(5);
    list.push_front(1);

    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();

    return 0;
}