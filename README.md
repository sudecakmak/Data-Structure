# Data-Structure
Projects I made in Data Structure. I use visual studio for my projects.


## Data Structures
- [Stack](#stack)
- [Deque](#deque)
- [Threaded Binary Search Tree](#threaded-binary-search-tree)
- [AVL Tree](#avl-tree)


# Stack

Stack is a **linear data structure** which follows a particular order in which the operations are performed. The order may be *LIFO(Last In First Out)* or *FILO(First In Last Out)*.

There are many real-life examples of a stack. Consider an example of plates stacked over one another in the canteen. The plate which is at the top is the first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the longest period of time. So, it can be simply seen to follow LIFO(Last In First Out)/FILO(First In Last Out) order.

## Project Description

I use stack to **solve arithmetic calculations**.

## Algorithm
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

A queue is defined as a **linear data structure that is open at both ends** and the operations are performed in *First In First Out (FIFO)* order.

We define a queue to be a list in which all **additions to the list are made at one end**, and all **deletions from the list are made at the other end**. The element which is first pushed into the order, the operation is first performed on that.

Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the *front (or the head)* of the queue, similarly the position of the last entry in the queue, that is, the one most recently added, is called the *rear (or the tail)* of the queue.

## Project Description

I use a **doubly-linked list** to implement the Deque.
All operations run in **O(1)**.

Operations are addFront, addRear, removeFront, removeRear, front, rear, ısEmpty, size.


![Screenshot 2022-11-05 201507](https://user-images.githubusercontent.com/102357822/200132754-6ff105ce-fde7-4a17-b56e-ee28f869c22c.png)


# Threaded Binary Search Tree

A Threaded BST is a *BST* where a the *normally NULL left/right child pointers of a BST node point to the in-order predecessor/in-order successor node* in the BST respectively. This allows us to **walk over the threaded BST in forward or backward direction iteratively in O(n)** time, where “n” is the number of keys in the tree.

![Screenshot 2022-11-13 000546](https://user-images.githubusercontent.com/102357822/201494619-4ce11ce1-3832-4e5b-b8ae-8eb45c342875.png)

Pay special attention to node that have 0 or 1 child. In a BST, the pointers pointing to a non-existent child would be set to NULL. But in the threaded BST, the right child pointer that would normally be NULL points to the in-order successor node.

Similarly, a left child pointer that would normally be NULL points to the in-order predecessor node. If the in-order predecessor/successor does not exist, then and only then is the corresponding pointer set to NULL.

## Project Description

Operations are add, remove, getRoot, find, min, max, previous, next.

*Previous* returns *max* node on its *left subtree*.

*Next* returns *min* node on its *right subtree*.

![Screenshot 2022-11-13 000635](https://user-images.githubusercontent.com/102357822/201494738-025980fe-f90d-4acc-8aa7-6435f397c5cc.png)

![Screenshot 2022-11-13 000610](https://user-images.githubusercontent.com/102357822/201494740-7ac6ab02-3461-4bbc-8216-0c8d1f127705.png)


# AVL Tree

AVL Tree can be defined as *height balanced binary search tree* in which each node is associated with a *balance factor* which is calculated by subtracting the height of its right sub-tree from that of its left sub-tree.

Tree is said to be balanced if balance factor of each node is in between -1 to 1, otherwise, the tree will be unbalanced and need to be balanced.

**Balance Factor (k) = height (left(k)) - height (right(k))**

If balance factor of any node is **1**, it means that the *left sub-tree is one level higher than the right sub-tree*.

If balance factor of any node is **0**, it means that the *left sub-tree and right sub-tree contain equal height*.

If balance factor of any node is **-1**, it means that the *left sub-tree is one level lower than the right sub-tree*.

## Project Description

An algorithm that returns a list of the most frequent "k" words in the given text file, in order of frequency. Words with the same frequency are displayed sequentially.

When processing the file:
• The file is read line by line, each line is parsed according to its own words, and each word is appended to a map containing <word, frequency> pairs. All words are converted to lowercase letters and then stored on the map. Words shorter than 3 characters are ignored. This means “a”, “to”, “in” etc. means the words will be ignored.
• All non-letter characters are ignored. That is, words will only contain letters from the 'a'-'z' alphabet. Other characters will be used to delimit words.

text file example:
A text file is a file that only contains
text and has no special formatting
such as bold text, italic text, images, etc.
bold, and, file, that, and.

When this file is processed, I will get the following <word, frequency> pairs:

![Screenshot 2022-11-19 000736](https://user-images.githubusercontent.com/102357822/202804238-6ece7a9a-82aa-4b63-872b-706a00645177.png)

![Screenshot 2022-11-19 000655](https://user-images.githubusercontent.com/102357822/202804255-e74be090-0504-416f-be44-46ce756cf597.png)

Then I will return the most frequent “k” words. For example, if we want to return the most frequent 7 words from this list, then the result would be given in the following order:

![Screenshot 2022-11-19 000819](https://user-images.githubusercontent.com/102357822/202804274-045d1cfc-2f14-46ca-bf05-561aea7e7477.png)


Notice that the list is ordered with respect to the frequencies of the words. Also notice that the words that have the same frequency are given in sorted order. That is, “and” comes before “file” in the returned list. Similarly, “bold” comes before “that” both of which have a frequency of 2.

Algorithm take **O(nlogn + k)** *time* and **O(n)** *space*, where “n” is the number of words in the file.

## Algorithm

1. Implement the map ADT using a BST as the underlying data structure. The map will store <word, frequency> pairs. The first time a word is added to the ADT map, its frequency is set to 1. The next time the same word is added, its frequency is only increased. Thus, when all words are added to the ADT map, the <word, frequency> pairs are available and all words can be accessed in a sequential manner. All insertions take at most O(logN) time. Therefore, adding the word "N" will take O(NlogN) time.

2. After processing all the words in the file and adding them to the map, it's time to take the most used "k" word and return it to the user in the required order. To implement this efficiently, an array with slots "t+1" is allocated where "t" is the frequency of the most frequently used word. In the example this is 4. Each slot of the array stores words with that frequency. That is, words with frequency "i", where 1<=i<=t, will be stored in the list in slot "i". For this purpose, the C++ vector is used. After adding all the words in the ADT map to this list array, it looks like this:

![Screenshot 2022-11-19 000849](https://user-images.githubusercontent.com/102357822/202804305-02dfa6e2-d84e-4597-9214-eccdae8d74d8.png)

**vector<vector<string>> words(t+1)**
Here “t” is the highest frequency, which is 4 in the example.

3. Once you have this word list, start from the last blank containing the words with the highest frequency and walk backwards by filling in the result. After copying the "k" word to the result, pause and return the result. If there are fewer words than the "k" word, then all the words are returned. Words with the same frequency are returned in sequential order. That is, the words "thick", "only", "it", each of which has 2 frequencies, are returned sequentially.

