#include <iostream>

using namespace std;

// 인접 행렬

// 2차원 배열로 그래프를 나타내는 자료 구조입니다.
// 노드의 개수를 N이라 할때 N x N 크기의 행렬을 사용하여,
// 노드 사이의 연결 관계를 표현합니다.

//    0 1 2 3
// 0  0 1 0 0
// 1  1 0 1 1
// 2  0 1 0 1
// 3  0 1 1 0

// 장점 : 인접한 노드의 존재 여부를 확인하기 쉽고, 
//		  간선의 존재 여부를 0(1) 시간에 확인할 수 있다.	

// 단점 : 노드 수가 많고, 간선이 적은 희소 그래프의 경우 메모리를
//        많이 사용하는 단점이 존재합니다.


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

	void resize()
	{
		int** newMatrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};
		}

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < size; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}

		for (int i = 0; i < count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;

		matrix = newMatrix;

		count = size;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency_matrix_is_empty" << endl;
		}
		if (i >= size || j >= size)
		{
			cout << "index_out_of_range" << endl;
		}
		else
		{
			if (matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size];

					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}
			else if (size > count)
			{
				resize();
			}

			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	friend ostream& operator << (ostream& ostream, const Graph<T>& graph)
	{
		ostream << "  ";

		for (int i = 0; i < graph.size; i++)
		{
			ostream << graph.vertex[i] << " ";
		}

		ostream << endl;

		for (int i = 0; i < graph.count; i++)
		{
			ostream << graph.vertex[i] << " ";

			for (int j = 0; j < graph.count; j++)
			{
				ostream << graph.matrix[i][j] << " ";
			}

			ostream << endl;
		}
		return ostream;
	}

	~Graph()
	{
		if (vertex != nullptr)
		{
			delete[] vertex;
			vertex = nullptr;
		}

		if (matrix != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
			matrix = nullptr;
		}

		size = 0;
		count = 0;
		capacity = 0;
	}

};

int main()
{
	Graph<int>graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');

	graph.edge(0, 1);
	graph.edge(1, 2);

	graph.push('D');

	graph.edge(0, 3);

	cout << graph << endl;

	return 0;
}