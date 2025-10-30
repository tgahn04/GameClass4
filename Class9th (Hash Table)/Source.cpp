#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
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
        int count;
        Node* head;
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
            bucket[i].count = 0;
        }
    }

    template<typename KEY>
    unsigned int hash_function(KEY key)
    {
        return (unsigned int)key % capacity;
    }

    template<>
    unsigned int hash_function(const char* key)
    {
        int sum = 0;

        for (int i = 0; *key != '\0'; i++)
        {
            sum += key[i];

            key = key + 1;
        }

        return (unsigned int)sum % capacity;
    }

    void insert(KEY key, VALUE value)
    {
        // 해시 함수를 통해서 값을 받는 임시 변수
        int hashIndex = hash_function(key);

        // 새로운 노드를 생성합니다.
        Node * newNode = new Node;

        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        // 노드가 1개라도 존재하지 않는다면
        if (bucket[hashIndex].count == 0)
        {
            // bucket[hashIndex]의 head 포인터가 newNode를 가리키게 됩니다.
            bucket[hashIndex].head = newNode;
        }
        else
        {
            newNode->next = bucket[hashIndex].head;

            bucket[hashIndex].head = newNode;
        }

        // bucket[hashIndex]의 count를 증가시킵니다.
        bucket[hashIndex].count++;

        size++;
    }

    void erase(KEY key)
    {
        // 1. 해시 함수를 통해서 값을 받는 임시 변수
        int hashIndex = hash_function(key);

        // 2. Node를 탐색할 수 있는 포인터 변수 선언
        Node* currentNode = bucket[hashIndex].head;

        // 3. 이전 Node를 저장할 수 있는 포인터 변수 선언
        Node* previousNode = nullptr;

        // 4. currentNode가 nullptr과 같다면 함수를 종료합니다.
        if (currentNode == nullptr)
        {
            cout << "not_key_found..." << endl;

            return;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                    break;

                previousNode = currentNode;
                currentNode = currentNode->next;
            }

            if (currentNode != nullptr)
            {
                if (previousNode == nullptr)
                {
                    bucket[hashIndex].head = currentNode->next;
                }
                else
                {
                    previousNode->next = currentNode->next;
                }

                delete currentNode;
                bucket[hashIndex].count--;
                size--;
            }
            else
            {
                cout << "not_key_found..." << endl;
            }
        }
    }
};

int main()
{
    HashTable<const char*, int> hashtable;

    // cout << hashtable.hash_function("Ko115frea") << endl;
    // cout << hashtable.hash_function("rqwr") << endl;
    // cout << hashtable.hash_function("Chirteyna") << endl;
    // cout << hashtable.hash_function("C5qdqdyna") << endl;
    // cout << hashtable.hash_function("C6wrrwrwyna") << endl;
    // cout << hashtable.hash_function("Chi868na") << endl;

    hashtable.insert("Abyssal Mask", 3000);
    hashtable.insert("Bami's Cinder", 1000);
    hashtable.insert("Chain Vast", 800);

    hashtable.erase("Abyssal Mask");
    hashtable.erase("Bami's Cinder");
    hashtable.erase("Frozen Heart");

    return 0;
}