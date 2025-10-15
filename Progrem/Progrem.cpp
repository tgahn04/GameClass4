#include <iostream>

using namespace std;

template <typename T>
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
		size = 0;
		head = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* deleteNode = head;

		head = head->next;

		delete deleteNode;

		size--;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		
		Node* currentNode = head;

		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;

		size++;
	}
};


int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(5);

	list.pop_front();
	list.pop_front();
	list.pop_front();

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	return 0;
}