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
        T* newPointer = new T[newSize];


    }

};

int main()
{
    Vector<int> vector;
    


    return 0;
}