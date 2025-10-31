#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	int size;
	int count;
	int capacity;

	T* vertex;
	int** matrix;

public:
	Graph(T data)
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		matrix = nullptr;
	}
};

int main()
{
	Graph<int> graph;



	return 0;
}