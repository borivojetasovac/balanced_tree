#pragma once

#include <iostream>

using namespace std;

class Node {

private:
	int smaller, bigger;
	Node *above;
	Node *left;
	Node *middle;
	Node *right;

public:
	Node(int x);
	Node (int x, Node *above);
	Node(int x, int y, Node *above, Node *left, Node *middle, Node *right);
	void first_step(int x);
	int new_node(int x);
	void engine(int x);

};

/*
1.	prvi korak je poziv konstruktora sa nekim int-om


	koliko slucajeva imamo??

	1.	slucaj kada imamo 3 u nizu, pa se dva spustaju dole u dva nova cvora..		to sam resio sa 'new_node' metodom!
	2. kada u jednoj celiji imamo samo smaller, pa novi uporedimo sa tim i zavrsimo u istoj celiji koja sada ima i bigger i smaller		to sam resio sa 'first_step' metodom!
	3. 


*/