#include <iostream>
#include "klase.h"

using namespace std;

Node::Node(int x) {
	smaller = x;
	bigger = NULL;
	*above = NULL;
	*left = NULL;
	*middle = NULL;
	*right = NULL;
}

Node::Node (int x, Node *above_arg) {
	smaller = x;
	bigger = NULL;
	*above = *above_arg;
	*left = NULL;
	*middle = NULL;
	*right = NULL;
}

Node::Node(int x, int y, Node *above_arg, Node *left_arg, Node *middle_arg, Node *right_arg) {
	smaller = x;
	bigger = y;
	*above = *above_arg;
	*left = *left_arg;
	*middle = *middle_arg;
	*right = *right_arg;
}

void Node::first_step (int x) {

	if (smaller < x)
		bigger = x;
	else {
		bigger = smaller;
		smaller = x;
	}
}

int Node::new_node (int x) {	// ubaci i drugi konstruktor: ako postoji *left i *middle ide onaj veliki, a ako ne postoji ide ovaj koji vec postoji
	if (x < bigger)
		if (x < smaller) {		//smaller ide gore
			if (left == NULL && middle == NULL && right == NULL) {
				*left = Node(x, this);
				*middle = Node(bigger, this);
				//smaller ostaje isti
				bigger = NULL;
				return smaller;
			}
			else {
				*left = Node(x, NULL, this, );
				*middle = Node(bigger, NULL, this, );
				//smaller ostaje isti
				bigger = NULL;
				return smaller;
			}
		}

		else {		//x ide gore
			*left = Node(smaller, this);
			*middle = Node(bigger, this);
			smaller = x;
			bigger = NULL;
			return x;
		}

	else {		//bigger ide gore
		*left = Node(smaller, this);
		*middle = Node(x, this);
		smaller = bigger;
		bigger = NULL;
		return smaller;
	}
}

void Node::engine (int x) {	//	ako odem samo jedan korak nize, moram da radim sa current, tako da sve treba da se promeni

	bool flag = false;
	Node current = Node (smaller, bigger, above, left, middle, right);	//kopija trenutnog cvora

	while (!flag) {

		if (bigger == NULL && (left == NULL && middle == NULL)) {
			this->first_step(x);   //	ovo znaci da sam dosao do poslednjeg
			flag = true;
		}

		else if (bigger == NULL && (left != NULL && middle != NULL)) {
			if (x < smaller)
				current = *left;
			else
				current = *middle;	// ovim sam otisao korak nize u lancu
		}

		else {	// ovde idemo u above i tamo radimo first step
			x = this->new_node(x);
			Node temp_left = *left;
			Node temp_middle = *middle;

			if (above == NULL)
				return;	//	to znaci da smo na vrhu
			
			else {	//	onda smo u celiji sa jednim clanom, u koju treba da upisemo x kao novi (drugi) clan, koji ce pritom biti sigurno manji od postojeceg
				current = *above;
				
				*current.left = temp_left;
				*current.right = *current.middle;
				*current.middle = temp_middle;
				
			}
			flag = true;
		}

	}
	//	izmeni new_node da radi sa pointerima
}
