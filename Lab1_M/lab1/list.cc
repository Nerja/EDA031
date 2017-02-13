#include <iostream>
#include "list.h"

using std::cout;

List::List() {
	first = nullptr;
}

List::~List() {
	while(first != nullptr) {
		Node* next = first->next;
		delete first;
		first = next;
	}
}

bool List::exists(int d) const {
	Node* n = first;
	//while(n->value != d)
	while(n != nullptr && n->value != d)
		n = n->next;
	return n != nullptr;
}

int List::size() const {
	Node* n = first;
	int nbrElements = 0;
	while(n != nullptr) {
		n = n->next;
		nbrElements++;

	}
	return nbrElements;
}

bool List::empty() const {
	return size() == 0;
}

void List::insertFirst(int d) {
	first = new Node(d, first);
}

// Check if node containing element el should be removed
bool should_be_removed(int el, int d, List::DeleteFlag df) {
	if(df == List::DeleteFlag::LESS && el < d)
		return true;
	else if(df == List::DeleteFlag::EQUAL && el == d)
		return true;
	else if(df == List::DeleteFlag::GREATER && el > d)
		return true;
	else
		return false;
}

void List::remove(int d, List::DeleteFlag df) {
	if(first != nullptr) {
		if(should_be_removed(first->value, d, df)) {
			Node* old_first = first;
			first = first->next;
			delete old_first;
		} else {
			Node *prev = first, *curr = first->next;
			bool removed = false;
			while(curr != nullptr && !removed) {
				if(should_be_removed(curr->value, d, df)) {
					Node* note_to_del = curr;
					prev->next = curr->next;
					delete note_to_del;
					removed = true;
				} else {
					prev = curr;
					curr = curr->next;
				}
			}
		}
	}
}

void List::print() const {
	Node* n = first;
	while(n != nullptr) {
		cout << n->value << "  ";
		n = n->next;
	}
}
