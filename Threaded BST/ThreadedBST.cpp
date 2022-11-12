// Sude Çakmak
// 152120201044

#include "ThreadedBST.h"

void ThreadedBST::add(int key) {

	BSTNode *parent = root;

	while (parent) {

		if (parent->key == key) return;

		else if (key < parent->key)
		{
			if (parent->leftLinkType == 1)
				parent = parent->left;
			else
				break;
		}
		else
		{
			if (parent->rightLinkType == 1)
				parent = parent->right;
			else
				break;
		}
	}

	BSTNode *node = new BSTNode(key);

	if (root == NULL)
	{
		root = node;
	}
	else if (key < parent->key)
	{
		node->left = parent->left;
		node->right = parent;
		parent->leftLinkType = 1;
		parent->left = node;
	}
	else
	{
		node->left = parent;
		node->right = parent->right;
		parent->rightLinkType = 1;
		parent->right = node;
	}
}

void ThreadedBST::eraseTreeNodes(BSTNode* node) {

	if (node == NULL) return;
	delete node;
}

void ThreadedBST::remove(int key) {

	BSTNode *parent = NULL;
	BSTNode *ptr = root;

	// Find ptr's parent and ptr location
	while (ptr) {

		if (ptr->key == key) break;

		else if (key < ptr->key)
		{
			parent = ptr;
			ptr = ptr->left;
		}
		else
		{
			parent = ptr;
			ptr = ptr->right;
		}
	}

	if (ptr == NULL) return;

	if (ptr->leftLinkType == 2 && ptr->rightLinkType == 2) // node with no children
	{
		if (ptr == parent->left)
		{
			parent->leftLinkType = 2;
			parent->left = ptr->left;
		}
		else if (ptr == parent->right)
		{
			parent->rightLinkType = 2;
			parent->right = ptr->right;
		}

		delete ptr;
	}
	else if ((ptr->leftLinkType == 1 && ptr->rightLinkType == 2) || (ptr->leftLinkType == 2 && ptr->rightLinkType == 1)) // node with one children
	{
		BSTNode *child, *next_ptr, *previous_ptr;

		if (ptr->leftLinkType == 1)
			child = ptr->left;
		else
			child = ptr->right;

		if (ptr == parent->left)
			parent->left = child;
		else if (ptr == parent->right)
			parent->right = child;

		next_ptr = next(ptr);
		previous_ptr = previous(ptr);

		if (ptr->rightLinkType == 1) next_ptr->left = previous_ptr;
		else if (ptr->leftLinkType == 1) previous_ptr->right = next_ptr;
		delete ptr;
	}
	else if (ptr->leftLinkType == 1 && ptr->rightLinkType == 1)  // node with 2 children
	{
		BSTNode *parent_next = ptr;
		BSTNode *successor = ptr->right;

		while (successor->left != NULL) 
		{
			parent_next = successor;
			successor = successor->left;
		}

		ptr->key = successor->key;

		if (successor->leftLinkType == 2 && successor->rightLinkType == 2)
		{
			if (successor == parent_next->left)
			{
				parent_next->leftLinkType = 2;
				parent_next->left = successor->left;
			}
			else if (successor == parent_next->right)
			{
				parent_next->rightLinkType = 2;
				parent_next->right = successor->right;
			}

			delete successor;
		}
		else
		{
			BSTNode *child, *next_ptr, *previous_ptr;

			if (successor->leftLinkType == 1)
				child = successor->left;
			else
				child = successor->right;

			if (successor == parent_next->left)
				parent_next->left = child;
			else
				parent_next->right = child;

			next_ptr = next(successor);
			previous_ptr = previous(successor);

			if (successor->rightLinkType == 1) next_ptr->left = previous_ptr;
			else if (successor->leftLinkType == 1) previous_ptr->right = next_ptr;
			delete successor;
		}
	}
}


BSTNode *ThreadedBST::find(int key) {

	BSTNode *ptr = root;

	while (ptr != NULL) {

		if (key == ptr->key)
			return ptr;

		if (key < ptr->key)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	return NULL;
}


BSTNode* ThreadedBST::min() {

	if (root == NULL) return NULL;

	BSTNode *ptr = root;

	while (ptr->left != NULL)
		ptr = ptr->left;

	return ptr;
}


BSTNode* ThreadedBST::max() {

	if (root == NULL) return NULL;

	BSTNode *ptr = root;

	while (ptr->right != NULL)
		ptr = ptr->right;

	return ptr;
}


BSTNode* ThreadedBST::next(BSTNode* node) {

	if (root == NULL) return NULL;

	if (node->rightLinkType == THREAD)
	{
		return node->right;
	}
	else
	{
		// minimum node on its right sub-tree.
		node = node->right;

		while (node->leftLinkType == CHILD)
			node = node->left;

		return node;
	}
}


BSTNode* ThreadedBST::previous(BSTNode* node) {

	if (root == NULL) return NULL;

	if (node->leftLinkType == THREAD)
	{
		return node->left;
	}
	else
	{
		// maximum node on its left sub-tree.
		node = node->left;

		while (node->rightLinkType == CHILD)
			node = node->right;

		return node;
	}
}