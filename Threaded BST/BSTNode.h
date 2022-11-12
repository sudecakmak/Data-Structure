#pragma once

#ifndef _BSTNODE_H_
#define _BSTNODE_H_

// Link type: Real child or thread?
// If the link is a CHILD, then it points to a real child node
// If the link is a THREAD, then 
// --> left points to the in-order predecessor, right points to the in-order successoressor
#define CHILD	1
#define THREAD	2

struct BSTNode {
	int key;
	BSTNode* left, *right;
	char leftLinkType, rightLinkType; // The link type for the left/right pointers (CHILD or THREAD)

	// When the node is first created, it is a leaf node. So, both links must be THREAD
	BSTNode(int key) { this->key = key; left = right = NULL; leftLinkType = rightLinkType = THREAD; }
};

#endif