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
	Node *prev = nullptr, *current = first, *new_first = nullptr;
	while(current != nullptr) {
		if(should_be_removed(current->value, d, df)) { //Remove node
			//Link over the current node from prev if not nullptr, i.e current is first
			if(prev != nullptr)
      				prev->next = current->next;
			Node* old_current = current; //Save to delete
			current = current->next;
			delete old_current;
		} else { //Do not remove node
			if(new_first == nullptr) //Set first node
				new_first = current;
			prev = current;
			current = current->next;
		}
	}
	first = new_first; //Update first
}

void List::print() const {
	Node* n = first;
	while(n != nullptr) {
		cout << n->value << "  ";
		n = n->next;
	}
}

