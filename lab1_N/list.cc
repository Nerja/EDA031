#include <iostream>
#include "list.h"

using namespace std;

List::List() {
	first = nullptr;
}

List::~List() {
	Node* temp;
	while(first != nullptr){
		temp = first->next;
		delete first;
		first = temp;
	}
}

bool List::exists(int d) const {
	Node* temp = first;
	while(temp != nullptr){
		if(temp->value == d)
			return true;
		temp = temp->next;
	}
	return false;
}

int List::size() const {
	int sz = 0;
	Node* temp = first;
	while(temp != nullptr){
		++sz;
		temp = temp->next;
	}
	return sz;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	if(first == nullptr){
		first = new Node(d, nullptr);
	}
	else {
		Node* n = new Node(d, first);
		first = n;
	}

}

void List::remove(int d, DeleteFlag df) {
	Node* temp = first;
	Node* prev = nullptr;

	bool found = false;
	while(temp != nullptr && !found){
		switch (df) {
			case DeleteFlag::LESS:
				if(temp->value < d){
					found = true;
				}
				break;
			case DeleteFlag::EQUAL:
				if(temp->value == d){
					found = true;
				}
				break;
			case DeleteFlag::GREATER:
				if(temp->value > d){
					found = true;
				}
				break;
			default:
				break;
		}

		if(!found){
					prev = temp;
					temp = temp->next;
		}
	}

	if(found){
		if(temp == first){
			first = temp->next;
		}
		else {
			prev->next = temp->next;
		}
		delete temp;
	}
}



void List::print() const {
	Node* temp = first;
	while(temp != nullptr){
		cout << temp->value << " ";
		temp = temp->next;
	}
}
