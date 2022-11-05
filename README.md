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

