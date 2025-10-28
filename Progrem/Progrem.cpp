#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* next;
    };

    struct Bucket
    {
        Node* head;
        int count;
    };

    int size;
    int capacity;

    Bucket* bucket;

public:
    HashTable()
    {
        size = 0;
        capacity = 8;

        bucket = new Bucket[capacity];

        for (int i = 0; i < capacity; i++)
        {
            bucket[i].head = nullptr;
        }
    }


};

int main()
{
    HashTable<int, string> hashtable;


    return 0;
}