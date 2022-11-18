# Data-Structure
Projects I made in Data Structure. I use visual studio for my projects.


## Data Structures
- [Stack](#stack)
- [Deque](#deque)
- [Threaded Binary Search Tree](#threaded-binary-search-tree)
- [AVL Tree](#avl-tree)


# Stack

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be **LIFO(Last In First Out)** or **FILO(First In Last Out)**.

There are many real-life examples of a stack. Consider an example of plates stacked over one another in the canteen. The plate which is at the top is the first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the longest period of time. So, it can be simply seen to follow LIFO(Last In First Out)/FILO(First In Last Out) order.

## Project Description
I use stack to solve arithmetic calculations.

1. When an operand is encountered, output it

2. When ’(’ is encountered, push it

3. When ’)’ is encountered, pop all symbols off the stack until ’(’ is encountered

4. When an operator, +, -, *, /, is encountered, pop symbols off the stack until you encounter a symbol that has
lower priority

5. Push the encountered operator to the stack

“20+2*3+(2*8+5)*4”

![Screenshot 2022-10-23 133939](https://user-images.githubusercontent.com/102357822/197387496-5139aa4d-4e5a-49d6-b1ac-b4806768ebbc.png)


“20 2 3 * + 2 8 * 5 + 4 * +” **Postfix**

![Screenshot 2022-10-23 134411](https://user-images.githubusercontent.com/102357822/197387682-d7127fa2-c27f-4df2-8f4c-e097069ae85c.png)

# Deque

A queue is defined as a linear data structure that is open at both ends and the operations are performed in **First In First Out (FIFO)** order.

We define a queue to be a list in which all additions to the list are made at one end, and all deletions from the list are made at the other end.  The element which is first pushed into the order, the operation is first performed on that.

Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the front of the queue(sometimes, head of the queue), similarly, the position of the last entry in the queue, that is, the one most recently added, is called the rear (or the tail) of the queue.
I use a doubly-linked list to implement the Deque.

## Project Description

All operations run in O(1).

Operations are addFront, addRear, removeFront, removeRear, front, rear, ısEmpty, size.


![Screenshot 2022-11-05 201507](https://user-images.githubusercontent.com/102357822/200132754-6ff105ce-fde7-4a17-b56e-ee28f869c22c.png)


# Threaded Binary Search Tree

A Threaded BST is a BST where a the normally NULL left/right child pointers of a BST node point to the in-order predecessor/in-order successor node in the BST respectively. This allows us to walk over the threaded BST in forward or backward direction iteratively in O(n) time, where “n” is the number of keys in the tree.

![Screenshot 2022-11-13 000546](https://user-images.githubusercontent.com/102357822/201494619-4ce11ce1-3832-4e5b-b8ae-8eb45c342875.png)

Pay special attention to node that have 0 or 1 child. In a BST, the pointers pointing to a non-existent child would be set to NULL. But in the threaded BST, the right child pointer that would normally be NULL points to the in-order successor node.

Similarly, a left child pointer that would normally be NULL points to the in-order predecessor node. If the in-order predecessor/successor does not exist, then and only then is the corresponding pointer set to NULL.

## Project Description

Operations are add, remove, getRoot, find, min, max, previous, next.

*previous* returns *max* node on its *left subtree*.
*next* returns *min* node on its *right subtree*.

![Screenshot 2022-11-13 000635](https://user-images.githubusercontent.com/102357822/201494738-025980fe-f90d-4acc-8aa7-6435f397c5cc.png)

![Screenshot 2022-11-13 000610](https://user-images.githubusercontent.com/102357822/201494740-7ac6ab02-3461-4bbc-8216-0c8d1f127705.png)


# AVL Tree

AVL Tree can be defined as height balanced binary search tree in which each node is associated with a balance factor which is calculated by subtracting the height of its right sub-tree from that of its left sub-tree.

Tree is said to be balanced if balance factor of each node is in between -1 to 1, otherwise, the tree will be unbalanced and need to be balanced.

**Balance Factor (k) = height (left(k)) - height (right(k))**

If balance factor of any node is **1**, it means that the *left sub-tree is one level higher than the right sub-tree*.

If balance factor of any node is **0**, it means that the *left sub-tree and right sub-tree contain equal height*.

If balance factor of any node is **-1**, it means that the *left sub-tree is one level lower than the right sub-tree*.

## Project Description

Given a text file, I implement an algorithm that returns a list of the most frequently occurring “k” words in the file, in the order of their frequencies. The words that have the same frequency will be given in sorted order. 

In processing the file:
• Read the file line by line, parse each line into its words, and insert each word into a map containing <word, frequency> pairs. Convert all words to lower-case characters and then store them in the map. Ignore words that are less than 3 characters long. This means that words such as “a”, “to”, “in” etc. will be ignored.
• Ignore all non-letter characters. That it, your words will only contain letters in the alphabet ‘a’-‘z’. Other characters will be used to delimit the words.

text file example:
A text file is a file that only contains
text and has no special formatting
such as bold text, italic text, images, etc.
bold, and, file, that, and.

When this file is processed, you will get the following <word, frequency> pairs:

![Screenshot 2022-11-19 000736](https://user-images.githubusercontent.com/102357822/202804238-6ece7a9a-82aa-4b63-872b-706a00645177.png)

![Screenshot 2022-11-19 000655](https://user-images.githubusercontent.com/102357822/202804255-e74be090-0504-416f-be44-46ce756cf597.png)

You will then be asked to return the most frequent “k” words. For example, if we want you to return the most frequent 7 words from this list, then the result would be given in the following order:


![Screenshot 2022-11-19 000819](https://user-images.githubusercontent.com/102357822/202804274-045d1cfc-2f14-46ca-bf05-561aea7e7477.png)



Notice that the list is ordered with respect to the frequencies of the words. Also notice that the words that have the same frequency are given in sorted order. That is, “and” comes before “file” in the returned list. Similarly, “bold” comes before “that” both of which have a frequency of 2.
Your algorithm must take O(nlogn + k) time and O(n) space, where “n” is the number of words in the file. Here is how you would implement this algorithm:

1. Implement the map ADT using a BST as the underlying data structure. The map will store <word, frequency> pairs. The first time a word is inserted into the map ADT, its frequency will be set to 1. The next time the same word is to be inserted, simply increment its frequency. Thus, when all words are inserted into the map ADT, you will have the <word, frequency> pairs and you can access all words in sorted order. Assuming that we use a regular BST and insert the words in the order we encounter them in the file, the BST will look like as shown in the previous page. We expect you to modify the AVL tree code we gave you and implement this map ADT so that all insertions take at most O(logN) time. Thus, inserting “N” words would take O(NlogN) time.

2. After you process all words in the file and insert them into the map, it is now time to get the most frequent “k” words and return them to the user in the required order. To implement this efficiently, you will allocate an array with “t+1” slots, where “t” is the frequency of the most frequent word. This is 4 in our example. Each slot of the array will store the words that have that frequency. That is, words that have a frequency of “i”, where 1<=i<=t will be stored in the list at slot “i”. You can use the C++ vector for this purpose. After you insert all words from the map ADT into this array of lists, it should look like as follows:

![Screenshot 2022-11-19 000849](https://user-images.githubusercontent.com/102357822/202804305-02dfa6e2-d84e-4597-9214-eccdae8d74d8.png)

You can declare this structure in C++ as follows: vector<vector<string>> words(t+1);
Here “t” is the highest frequency, which is 4 in our example.

3. After you have this array of list of words, you can simply start from the last slot, which contains the words with the highest frequency, and walk backwards filling in the result. After you copy “k” words into the result, stop and return the result. If there is less than “k” words, then simply return all the words. Notice that the words that have the same frequency are returned in sorted order. That is, the words “bold”, “only”, “that” each having a frequency of 2 are returned in sorted order.

