#include <iostream>
#include <vector>
#include "ThreadedBST.h"

using namespace std;

int Test1();
int Test2();

int main() {
	int grade = Test1();
	grade += Test2();

	printf("Your grade is: %d\n", grade);

	return 0;
} //end-main

///----------------------------------------------
/// Test 1
///
int Test1() {
	ThreadedBST bst;

	bst.add(10);
	bst.add(5);
	bst.add(15);
	bst.add(2);
	bst.add(7);
	bst.add(12);
	bst.add(6);

	// Check if the bst is set up correctly
	BSTNode* root = bst.getRoot();
	if (root->key != 10) return 0;

	BSTNode* p = root->left;
	if (p->key != 5) return 0;

	p = root->left->left;
	if (p->key != 2) return 0;
	if (p->left != NULL) return 0;
	if (p->right != root->left) return 0;

	p = root->left->right;
	if (p->key != 7) return 0;
	if (p->right != root) return 0;

	p = root->left->right->left;
	if (p->key != 6) return 0;
	if (p->left != root->left) return 0;
	if (p->right != root->left->right) return 0;

	p = root->right;
	if (p->key != 15) return 0;
	if (p->right != NULL) return 0;

	p = root->right->left;
	if (p->key != 12) return 0;
	if (p->left != root) return 0;
	if (p->right != root->right) return 0;

	// Forward walk
	vector<int> keys = { 2, 5, 6, 7, 10, 12, 15 };
	p = bst.min();
	for (auto key : keys) {
		if (p->key != key) return 0;
		p = bst.next(p);  // Go to the next node
	} //end-for
	if (p != NULL) return 0;

	// Backward walk
	p = bst.max();
	for (int i = keys.size() - 1; i >= 0; i--) {
		if (p->key != keys[i]) return 0;
		p = bst.previous(p);  // Go to the previous node
	} // end-for
	if (p != NULL) return 0;

	// OK. Passed all tests
	return 20;
} //end-Test1

///----------------------------------------------
/// Test 2
///
int Test2() {
	ThreadedBST bst;

	bst.add(10);
	bst.add(5);
	bst.add(15);
	bst.add(2);
	bst.add(7);
	bst.add(12);
	bst.add(6);

	// Delete two nodes
	bst.remove(7);
	bst.remove(15);

	// Check if the bst is correct
	BSTNode* root = bst.getRoot();
	if (root->key != 10) return 0;

	BSTNode* p = root->left;
	if (p->key != 5) return 0;

	p = root->left->left;
	if (p->key != 2) return 0;
	if (p->left != NULL) return 0;
	if (p->right != root->left) return 0;

	p = root->left->right;
	if (p->key != 6) return 0;
	if (p->left != root->left) return 0;
	if (p->right != root) return 0;

	p = root->right;
	if (p->key != 12) return 0;
	if (p->left != root) return 0;
	if (p->right != NULL) return 0;

	// Forward walk
	vector<int> keys = { 2, 5, 6, 10, 12 };
	p = bst.min();
	for (auto key : keys) {
		if (p->key != key) return 0;
		p = bst.next(p);  // Go to the next node
	} //end-for
	if (p != NULL) return 0;

	// Backward walk
	p = bst.max();
	for (int i = keys.size() - 1; i >= 0; i--) {
		if (p->key != keys[i]) return 0;
		p = bst.previous(p);  // Go to the previous node
	} // end-for
	if (p != NULL) return 0;

	// OK. Passed all tests
	return 20;
} //end-Test2
