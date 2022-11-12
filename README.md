# Data-Structure
Projects I made in Data Structure. I use visual studio for my projects.

## Stack
(1) When an operand is encountered, output it

(2) When ’(’ is encountered, push it

(3) When ’)’ is encountered, pop all symbols off the stack until ’(’ is encountered

(4) When an operator, +, -, *, /, is encountered, pop symbols off the stack until you encounter a symbol that has
lower priority

(5) Push the encountered operator to the stack

“20+2*3+(2*8+5)*4”

![Screenshot 2022-10-23 133939](https://user-images.githubusercontent.com/102357822/197387496-5139aa4d-4e5a-49d6-b1ac-b4806768ebbc.png)


“20 2 3 * + 2 8 * 5 + 4 * +” postfix

![Screenshot 2022-10-23 134411](https://user-images.githubusercontent.com/102357822/197387682-d7127fa2-c27f-4df2-8f4c-e097069ae85c.png)

## Deque

I use a doubly-linked list to implement the Deque.

All operations run in O(1).

Operations are addFront, addRear, removeFront, removeRear, front, rear, ısEmpty, size.


![Screenshot 2022-11-05 201507](https://user-images.githubusercontent.com/102357822/200132754-6ff105ce-fde7-4a17-b56e-ee28f869c22c.png)


## Threaded Binary Search Tree

A threaded BST is a BST where a the normally NULL left/right child pointers of a BST node point to the in-order predecessor/in-order successor node in the BST respectively. This allows us to walk over the threaded BST in forward or backward direction iteratively in O(n) time, where “n” is the number of keys in the tree.

![Screenshot 2022-11-13 000546](https://user-images.githubusercontent.com/102357822/201494619-4ce11ce1-3832-4e5b-b8ae-8eb45c342875.png)


Pay special attention to node that have 0 or 1 child. In a BST, the pointers pointing to a non-existent child would be set to NULL. But in the threaded BST, the right child pointer that would normally be NULL points to the in-order successor node.

Similarly, a left child pointer that would normally be NULL points to the in-order predecessor node. If the in-order predecessor/successor does not exist, then and only then is the corresponding pointer set to NULL.

Operations are add, remove, getRoot, find, min, max, previous, next.

previous returns max node on its left subtree.
next returns min node on its right subtree.

![Screenshot 2022-11-13 000635](https://user-images.githubusercontent.com/102357822/201494738-025980fe-f90d-4acc-8aa7-6435f397c5cc.png)

![Screenshot 2022-11-13 000610](https://user-images.githubusercontent.com/102357822/201494740-7ac6ab02-3461-4bbc-8216-0c8d1f127705.png)

