#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		Node* previous;
		T data;
		Node* next;
	};

	int size;

	Node* head;
	Node* tail;

public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;

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

		head = deleteNode->next;
		
		if (head != nullptr)
		{
			deleteNode->previous = nullptr;
		}
		else
		{
			tail = nullptr;
		}

		//if (head == tail)
		//{
		//	head = nullptr;
		//	tail = nullptr;
		//}
		//else
		//{
		//	deleteNode->next->privious = nullptr;

			delete deleteNode;

			size--;
		//}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node* deleteNode = tail;

		tail = deleteNode->previous;

		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}

		delete deleteNode;

		size--;
	}
};

int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(5);

	list.push_back(20);
	list.push_back(30);

	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();

	return 0;
}