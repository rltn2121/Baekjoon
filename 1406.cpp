#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	Node(char data) {
		this->data = data;
		next = prev = NULL;
	}
	char data;
	Node* next;
	Node* prev;
};

class List {
public:
	List() {
		header = new Node(NULL);
		trailer = new Node(NULL);
		cursor = trailer;
		header->next = trailer;
		trailer->prev = header;
	}

	void addBack(char c) {
		Node* newNode = new Node(c); 
		newNode->prev = trailer->prev;
		newNode->next = trailer;

		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
	}

	void moveLeft() {
		if (cursor == header)
			return;
		cursor = cursor->prev;
	}

	void moveRight() {
		if (cursor == trailer)
			return;
		cursor = cursor->next;
	}

	void remove() {
		if (cursor == header->next)
			return;
		Node* delNode = cursor->prev;
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
		delete delNode;
	}

	void insert(char c) {
		if (cursor == header)
			cursor = cursor->next;
			Node* newNode = new Node(c);
			newNode->prev = cursor->prev;
			newNode->next = cursor;
			newNode->prev->next = newNode;
			newNode->next->prev = newNode;
		
	}

	void print() {
		Node* current = header->next;
		while (current ->next!= NULL) {
			cout << current->data;
			current = current->next;
		}
	}
	Node* header;
	Node* trailer;
	Node* cursor;
};
int main() {
	
	string str;
	cin >> str;
	List l;
	for (char c : str)
		l.addBack(c);

	int n;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "L")
			l.moveLeft();
		else if (str == "D")
			l.moveRight();
		else if (str == "B")
			l.remove();
		else if (str == "P") {
			char c;
			cin >> c;
			l.insert(c);
		}
	}
	l.print();
}