#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    T* pointer;
    int count;
    int capacity;

public:
    Vector()
    {
        count = 0;
        capacity = 0;
        pointer = nullptr;
    }

    void resize(int newSize)
    {
        // 1. capacity에 새로운 size 값을 저장합니다.
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진
        //    매모리 공간을 가리키도록 합니다.
        T* temporary = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }

        // 4. 기존 배ㅑ열에 있는 값을 복사해서 새로운
        //    배열에 넣어줍니다.
        for (int i = 0; i < count; i++)
        {
            temporary[i] = pointer[i];
        }

        // 5, 기본 배열의 메모리를 해제합니다.
        delete[] pointer;

        // 6. 기존 배열을 가리키던 포인터 변수의 값을
        //    새로운 배열의 시작 주소로 가리킵니다.
        pointer = temporary;
    }

    void push_back(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (count >= capacity)
        {
            resize(capacity * 2);
        }
        pointer[count++] = data;
    }

    void pop_back()
    {
        if (count <= 0)
        {
            cout << "vector is empty" << endl;
        }
        else
        {
            pointer[--count] = NULL;
        }
    }

    const int& size()
    {
        return count;
    }

    const T& operator [] (const int& index)
    {
        return pointer[index];
    }

    ~Vector()
    {
        delete[] pointer;
    }
};

int main()
{
    Vector<int> vector;



    return 0;
}