#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	int size;		// 정점의 개수
	int count;		// 인접 행렬의 크기
	int capacity;	// 최대 용량

	T* vertex;		// 정점의 집합
	int** matrix;	// 인접 행렬

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		matrix = nullptr;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;
	}

	void resize(int newSize)
	{
		capacity = newSize;
		
		T* container = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			container[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		delete[] vertex;

		vertex = container;
	}

	void edge(int i, int j)
	{
		if (size == 0)
		{
			cout << "adjacency_matrix_is_empty" << endl;
			return;
		}

		if (i >= size || j >= size || i < 0 || j < 0)
		{
			cout << "index_out_of_range" << endl;
			return;
		}

		if (!matrix)
		{
			matrix = new int* [size];

			for (int x = 0; x < size; x++)
			{
				matrix[x] = new int[size];

				for (int y = 0; y < size; y++)
				{
					matrix[x][y] = 0;
				}
			}
		}
		matrix[i][j] = 1;
		matrix[j][i] = 1;
	}

};

int main()
{
	Graph<int>graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');

	graph.edge(0, 2);
	graph.edge(1, 2);

	return 0;
}