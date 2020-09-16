#include <iostream>
#include <list>
using namespace std;
int n = 0 , k = 0;
class Node {
public:
	Node(int data) {
		this->data = data;
	}
	int data;
	Node* next;
};

class List {
public:
	List() {
		head = tail = NULL;
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		if (head == NULL)
			head = tail = newNode;
		else {
			tail->next = newNode;
			tail = newNode;
		}
		tail->next = head;
	}

	void remove() {
		Node* current = head;
		Node* delNode = NULL;

		
		if (k == 1) {
			while (n--) {
				if (n == 0) {
					cout << current->data;
					return;
				}
				head = head->next;
				tail->next = head;
				cout << current->data << ", ";
				delNode = current;
				current = current->next;
				delete delNode;
			}
		}
		while (n--)
		{
			if (n == 0) {
				cout << current->data;
				return;
			}
			delNode = current->next;
			for (int i = 0; i < k - 2; i++) {
				delNode = delNode->next;
				current = current->next;
			}
			if (delNode == tail)
				tail = current;
			if (delNode == head)
				head = head->next;
			current->next = delNode->next;
			current = current->next;
			cout << delNode->data << ", ";
			delete delNode;
		}
	}
	Node* head;
	Node* tail;
};

int main() {
	
	cin >> n >> k;
	List l;
	for (int i = 0; i < n; i++) {
		l.insert(i+1);
	}
	cout << '<';
	l.remove();
	cout << '>';
}