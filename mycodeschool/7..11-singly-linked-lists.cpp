// https://www.youtube.com/watch?v=IbvsNF22Ud0&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=7

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node* next;
};

Node* head = NULL;

void print() {
	Node* curr = new Node();
	curr->next = head;

	while (curr->next != NULL) {
		curr = curr->next;
		std::cout << curr->value << " ";
	}

	cout << endl;
}

void Insert(int value, int pos) {
	Node* newpos = new Node();
	newpos->value = value;
	
	// (20, 0)

	// h
	// x
	if (pos == 0) {
		newpos->next = head;
		head = newpos;
		return;
	}

	// (4, 2)

	//       P
	//     n
	//   p
	// h
	// 2 3 x 6
	Node* prepos = head;
	for (int i = 0; i < pos - 1; i++) {
		prepos = prepos->next;	
	}

	Node* postpos = prepos->next;

	newpos->next = postpos; // Postpos
	prepos->next = newpos;
}

void Delete(int pos) {

	// (2)

	//       P
    //     d 
  //     p
	// h
	// 2 3 4 6
	Node* prepos = head;

	if (pos == 0) {
		head = head->next;	
		delete prepos;
		return;
	}

	for (int i = 0; i < pos - 1; i++) {
		prepos = prepos->next;
	}

	Node* delpos = prepos->next;

	printf("prepos val %d, delpos val %d, postpos val %d \n", prepos->value, delpos->value, delpos->next->value);

	prepos->next = delpos->next;
	delete delpos;
}

void Reverse() {
	if (head == NULL) {
		return;
	}

	Node* previous = NULL;
	Node* losable;

	while (head->next != NULL) {
		losable = head->next;

		head->next = previous;

		previous = head;

		head = losable;
	}

	head->next = previous;
}

void ReverseWithCurrent() {
	Node* previous = NULL;
	Node* current = head;
	Node* losable;

	while (current != NULL) {
		losable = current->next;
		current->next = previous;
		previous = current;
		current = losable;
	}

	head = previous;
}

Node* ReverseWithRecursion(Node* curr) {
	if (curr->next == NULL) {
		head = curr;
		return curr;
	}

	Node* reversedLatest = ReverseWithRecursion(curr->next);

	reversedLatest->next = curr;
	curr->next = NULL;

	return curr;
}

int main() {
	Insert(2, 0); // 2
	Insert(3, 1); // 2 3
	Insert(4, 2); // 2 3 4
	Insert(20, 0); // 20 2 3 4

	Insert(100, 4); 
	Insert(200, 5); 
	Insert(300, 6); 

	print();

	Delete(2); // 20 2 4
	print();

	Delete(0); // 2 4
	print();

	Delete(0); // 4
	print();

	// ReverseWithCurrent();
	// Reverse();
	ReverseWithRecursion(head);
	print();

	return 0;
}
