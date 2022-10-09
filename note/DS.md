# DS


<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Stack](#stack)
  - [1. recap:](#1-recap)
  - [2. LeetCode Problems](#2-leetcode-problems)
- [Queue](#queue)
  - [1. recap:](#1-recap-1)
  - [2. LeetCode Problems](#2-leetcode-problems-1)
- [Linked list](#linked-list)
  - [1. recap:](#1-recap-2)
  - [2. LeetCode Problems](#2-leetcode-problems-2)

<!-- /code_chunk_output -->


## Stack
### 1. recap:
- char.: FILO
- impl.: array / linked list
- perf.: push() / pop() : O(1)

### 2. LeetCode Problems
**[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**
- thinking
Use stack, when receiving a left parenthesis, push it in. Otherwise, pop out element to match received right parenthesis. At last, test the emptiness of the stack.
- details
Use map to store the parentheses patterns.
Use stringstream to manipulate string input.
- other stuff
VSCode C/C++: add `"setupCommands"` to launch.json, set the c_cpp_properties.json --> correctly display STL container contents while debugging.
Learn how to watch values of pointer variables while debugging. For example, to watch string type variable: `*(char(*)[5])s`.
`cout << boolalpha;`- - to print the bool variable in 'true' / 'false' manner. 
- troubleshooting
Get the wrong order when checking corresponding parenthsis with map. `if (y != m[x])` should be `if (x != m[y])` (x is the current input char., y is the char. poped up from the stack, map element is like m[ '(' ] = ')' )

## Queue
### 1. recap:
- char.: FIFO
- impl.: array (wrapped around) / linked list
- perf.: enqueue() / dequeue() : O(1)

### 2. LeetCode Problems
**[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)**
- thinking
(After referring to the solution) pop() will use O(n) time with a stack used in auxiliary way. Other operations are simple.
Note that as required by the problem, the method Q.back() cannot be used.
It's easier that the call to every top() and pop() will be valid.
- details
Used two variables to kept condition of the top element.
- other stuff
There's another approach #2 (Two Queues, push - O(n), pop O(1) ). 
    >The algorithm inserts each new element to queue q2 and keep it as the top element. In case queue q1 is not empty (there are elements in the stack), we remove all elements from q1 and add them to q2. In this way the new inserted element (top element in the stack) will be always positioned at the front of q2. 

**[232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)**
- thinking
To attain the property LILO of queue, when push() is called, first send all elements in the main stack (if any) to the aux stack (by first popping then pushing), then push the new element into the main stack. Finally pop all the elements in the aux stack and push them into the main stack so that the new element is always at the bottom of the stack. We maintain this fact to simulate the function of queue.
The time complexity of push() is O(n), of pop() is O(1).
- details
Considering the order of elements in stack, we don't use swap() but write a new function to transfer all the elements from stack a to b in first-pop-then-push order.
- other stuff

## Linked list
### 1. recap:
- char.: 
    Consists of node(object), which has a pointer determining the linear order of this ds. .
    There're several forms -- singly linked/doubly linked, sorted/not sorted, circular/not circular. 
    L.head points to the first element of the list. (if the list is empty then L.head = NIL)
    Set sentinel L.nil (replace all NIL in original code) to simpify code. (ignore boundary conditions)
- (doubly, unsorted) operations & performance:
search(): linear search, O(n) time complexity.
insert(): O(1)
delete(): 
        O(1) (given element)
        O(n) (given key, use search() to find the element)
etc.
- [c++ reference](http://c.biancheng.net/view/1570.html)

### 2. LeetCode Problems
**[21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)**
- thinking
Use the procedure like merge() in MergeSort, compare every element of two lists in a while loop, point to the one with larger value and go on.
The order need consider, since the whole procedure is "splicing together the nodes of the first two lists", it's not convenient to use head insertion, so just iterate from head to tail and change the next pointer of each element.
- details
- other stuff
[There's a more elegant way using recurrence.](https://leetcode.com/problems/merge-two-sorted-lists/discuss/1826666/C%2B%2B-oror-Easy-To-Understand-oror-2-Approaches-oror-Recursive-oror-Iterative)

**[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)**
- thinking
The carry bit situation can be handled generally as x%10 + x/10
- details
How to handle last time carry? Also, there's possibility that the carry will exist until to the end(eg. 9999999 and 9999). Still maintain the method above, use carry to check edge case.(eg. 9+9 = 18, we need to add a 1 even l1 and l2 are both exhausted already)

**[83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)**
- thinking
Use two pointers to iterate the list, if they point to the same element then delete the first one and go ahead until there's no more duplicates then the last pointer go ahead.
- details
- review(could have been done by ..)

**[✘141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)**
- thinking
Do it the way like dfs on graph, if there is a back edge(here, if the next of a node is a marked one), then there is a cycle. But how to implement?
- solution
[from Discuss](https://leetcode.com/problems/linked-list-cycle/discuss/1829489/C%2B%2B-oror-Easy-To-Understand-oror-2-Pointer-oror-Fast-and-Slow)
[Floyd’s Cycle-Finding Algorithm](https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/#:~:text=Floyd's%20cycle%20finding%20algorithm%20or,fast%20as%20the%20other%20one.)
[proof](https://abhisekbunty94.medium.com/why-does-floyds-cycle-detection-algorithm-work-59f61984dc3e) and proof by contraposition.
Or [proof using modular arithmetic](https://math.stackexchange.com/questions/913499/proof-of-floyd-cycle-chasing-tortoise-and-hare)
time O(n) space O(1)

**[✘160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)**
- thinking
Brute-froce way is to compare each node of one list with all the other nodes of the other list, time O(mn).
- solution
[from Discuss](https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!) make sure two pointers reach the intersection node at the same time. By 'synchronizing', make two pointer have the same remaining steps to go in the second iteration.
time: worst case 2(m+n) => O(m+n)
space: O(1)

**[203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)**
- thinking
First check whether need to change the head (after the boundary check), then use two pointer to iterate the list and do the deletion.
- details
We can do the head check before the boundary check, these two can solve two cases: empty list and the list where all the elements are the same, equal to val.
it1 is the pointer ahead, it2 is the one behind.
When deletion, if it1 hit the val, then it continue going, it2 stop to see whether there're more hits in a row. Otherwise, both the pointers move forward one step.
- review
[A recursive solution](https://leetcode.com/problems/remove-linked-list-elements/discuss/57306/3-line-recursive-solution)

**[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)**
( iteratively or recursively )
- thinking
Iteratively: 
Use three pointers, the one in the front is responsible for guiding the next node, the other two are for present changing.
Or, use a stack, push every node in turn then pop and change the pointer.
recursively: Think about the stack way.
- details
bottoms out --> conquer --> use the result back and deal at this level --> return
Need to carry another parameter in the recursive procedure to remember the new head (or it will just return the old head). Also take care of code in main procedure. 
☞ The parameter to recursive procedure should be as reference!

**[234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)**
- thinking
Brute-force method: use a stack, push in turn, then pop and compare. time O(n), space O(n)
O(n) time, O(1) space method ?
- solution
[from Discuss](https://leetcode.com/problems/palindrome-linked-list/discuss/64500/11-lines-12-with-restore-O(n)-time-O(1)-space)
The idea is to use two pointers (fast and slow) to locate the middle of the list (check whether fast->next == nullptr(then the length is odd) or fast == nullptr(then the length is even) when finisthing the first loop, and adjust), during the first loop, at the same time, also reverse the first half of the list(using another two pointer, rev and tmp). Then compare(and also restore the list, same flavor as reversing).
☞ Always initialize the variable. (I didn't initialize the bool variable 'flag' and thought it would be true by default, however it is accroding to the compiler.)

**[876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)**
- thinking
Just the sub-procedure of problem #234.

**[1290. Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)**
- thinking
Add each bit by weight, recursively (or use a stack).
- details
use member variables to simplify recursive code.
- review
[a cool discuss](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/1615821/C%2B%2B-or-All-approaches-Detailed-explanation-or-Bit-Manipulation)

**[19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)**
- thinking
Brute-force: Use a stack. time O(n) space O(n)
one pass?: Use a map, put all the node in the map and direct index to the desired one. time θ(n), space O(n)
- details
Since our keys are increasing integers, just use a ListNode* vector.
Take care of the situation where the node to be removed is the head node.
- review(could have been done by ..)

**[24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)**
- thinking
Use two queues, enqueue and dequeue the nodes in a crossed way. Space O(n).
Use some pointers to deal pair by pair, it's complex since the nodes are coupled.
- details
Method 1 will cause *Memory Limit Exceeded*.
Apply method 2, using three pointers. Take care of the head case.
The issue of odd or even length turns out not to be a problem, just don't need to change the last element.

**[61. Rotate List](https://leetcode.com/problems/rotate-list/)**
- thinking
First use one iteration to get the length len of the list. Then k%len will be the exactly rotated place. Finally, pointer operations, in order, let the last node point to the old head(if there is actually rotation); let len-(k%len) node point to nullptr and its next node point become the new head.
- details
Make sure the first iteration pointer stop at the last node since we need to change that node's next field.
- :hourglass: 22min used.