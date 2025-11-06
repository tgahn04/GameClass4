#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int count;
	int size;
	int capacity;

	T* vertex;
	Node** list;

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		list = nullptr;
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

		if (list != nullptr)
		{
			resize();
		}
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
		Node** newList = new Node * [size];

		for (int i = 0; i < size; i++)
		{
			newList[i] = nullptr;
		}
		for (int i = 0; i < count; i++)
		{
			newList[i] = list[i];
		}

		delete[] list;

		list = newList;

		count = size;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency_list_is_empty" << endl;
		}
		if (i >= size || j >= size)
		{
			cout << "index_out_of_range" << endl;
		}
		else
		{
			if (list == nullptr)
			{
				list = new Node * [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = nullptr;
				}

				count = size;
			}
			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}

	}

	friend ostream& operator << (ostream& ostream, const Graph<T>& graph)
	{
		ostream << "  ";

		for (int i = 0; i < graph.size; i++)
		{
			ostream << graph.vertex[i] << " : ";

			typename Graph<T>::Node* currentNode = graph.list[i];

			while (currentNode != nullptr)
			{
				ostream << currentNode->data << " ";

				currentNode = currentNode->next;
			}

			ostream << endl;
		}

		ostream << endl;

		return ostream;
	}

	~Graph()
	{
		for (int i = 0; i < size; i++)
		{
			Node* deleteNode = list[i];
			Node* nextNode = list[i];

			if (deleteNode == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}

		delete[] list;
		delete[] vertex;
	}
};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');
	graph.push('D');

	graph.edge(1, 2);
	graph.edge(1, 3);

	graph.push('E');

	graph.edge(2, 4);

	cout << graph << endl;

	return 0;
}