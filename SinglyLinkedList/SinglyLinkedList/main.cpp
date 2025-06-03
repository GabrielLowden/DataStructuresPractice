#include <iostream>

using namespace std;

struct Node {

	//what is stored in a node
	int data;

	//pointer to next node
	Node* next;

	//constructor
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}


};

void static traverse(Node* head) {

	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int lengthOfList(Node* head) {
	int length = 0;
	while (head != nullptr) {
		length += 1;
		head = head->next;
	}
	return length;
}

static Node* insertAtBeginning(Node* head, int data) {
	Node* node = new Node(data);
	node->next = head;
	return node;
}

static Node* insertAtEnd(Node* head, int data) {
	Node* node = new Node(data);
	if (head == nullptr) {
		return node;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;

	}
	temp->next = node;
	return head;
}

static Node* insertAtPosition(Node* head, int data, int pos) {
	Node* node = new Node(data);
	int len = lengthOfList(head);
	if (pos == 1) {
		node->next = head;
		return node;
	}
	if (pos > len || pos < 0) {
		cout << "ERROR: that position does not exist in this list.";
	}
	for (int i = 1; i < pos; i++) {
		head = head->next;
	}
	node->next = head->next;
	head->next = node;
	return head;

}

int main() {
	
	Node* head = new Node(20);
	head->next = new Node(55);
	traverse(head);
	cout << lengthOfList(head);

	return 0;
}