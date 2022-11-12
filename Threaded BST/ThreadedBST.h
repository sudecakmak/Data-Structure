#pragma once
#ifndef _THREADED_BST_H_
#define _THREADED_BST_H_

#include <iostream>
#include "BSTNode.h"

class ThreadedBST {
private:
	BSTNode* root;

	void eraseTreeNodes(BSTNode* node);
public:
	ThreadedBST() { root = NULL; }
	~ThreadedBST() { eraseTreeNodes(root); root = NULL; }

	void add(int key);
	void remove(int key);

	BSTNode* getRoot() { return root; }
	BSTNode *find(int key);
	BSTNode* min();
	BSTNode* max();
	BSTNode* previous(BSTNode* node);
	BSTNode* next(BSTNode* node);
};

#endif
