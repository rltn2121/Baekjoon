#include <iostream>
using namespace std;
class Node {
public:
	char c;
	Node* next;
	Node* prev;

	Node(char c) {
		this->c = c;
		next = NULL;
		prev = NULL;
	}
};

class LinkedList {
public:
	Node* header;
	Node* trailer;
	Node* cursor;
	
	LinkedList() {
		header = new Node(NULL);
		trailer = new Node(NULL);

		header->next = trailer;
		trailer->prev = header;
		cursor = trailer;
	}
	void addData(char c) {
		Node* newNode = new Node(c);
		if (header->next == trailer) {
			newNode->prev = header;
			newNode->next = trailer;
			header->next = newNode;
			trailer->prev = newNode;
			
		}
		else {
			newNode->next = trailer;
			newNode->prev = trailer->prev;
			newNode->prev->next = newNode;
			trailer->prev = newNode;
		}
	}
	void moveCursorLeft() {
		if (cursor == header)
			return;
		cursor = cursor->prev;
	}

	void moveCursorRight() {
		if (cursor == trailer)
			return;
		if (cursor == header)
			cursor = cursor->next;
		cursor = cursor->next;
	}

	void deleteCursorLeft() {
		if (cursor == header || cursor == header->next)
			return;
		Node* delNode = cursor->prev;
		if (header->next->next == trailer) {
			header->next = trailer;
			trailer->prev = header;
			cursor = header;
		}
		
		else
		{
			cursor->prev = delNode->prev;
			delNode->prev->next = cursor;
		}
		
	}

	void addCursorLeft(char c) {
		if (header == trailer)
			addData(c);
		else {
			Node* newNode = new Node(c);

			if (cursor == header)
				cursor = cursor->next;
			newNode->next = cursor;
			newNode->prev = cursor->prev;
			newNode->prev->next = newNode;
			cursor->prev = newNode;
		}

	}
	void display() {
		Node* current = header->next;
		while (current != NULL) {
			cout << current->c;
			current = current->next;
		}
		cout << endl;
	}
};

int main() {
	string str;
	cin >> str;

	LinkedList l;
	for (char c : str)
		l.addData(c);

	int t;
	cin >> t;
	while (t--) {
		char c;
		cin >> c;
		if (c == 'L')
			l.moveCursorLeft();
		else if (c == 'D')
			l.moveCursorRight();
		else if (c == 'B')
			l.deleteCursorLeft();
		else if (c == 'P') {
			char data;
			cin >> data;
			l.addCursorLeft(data);
		}
		l.display();
	}

	
}
/*
초기 상태 : a(커서)

L : (커서)a

L : (커서)a < ---- - (커서가 이미 가장 왼쪽이므로 L 명령은 무시됨)

D : a(커서)

P x : ax(커서)
*/