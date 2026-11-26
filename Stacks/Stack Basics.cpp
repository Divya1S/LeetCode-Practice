Stack:
A stack is a linear data structure that stores items in a highly specific, restricted order.
It operates on the LIFO (Last In, First Out) principle. 
This means that the last element added to the stack will be the first one to be removed.

To visualize a stack, think of a stack of plates at a buffet: you can only add a new plate to the top, and you can only take a plate off the top. If you want the plate at the bottom, you have to remove all the plates above it first.

Core Operations:
A stack is defined by a strict set of operations. You cannot access random elements in the middle of a stack, you can only interact with the top.

1. push(item): Adds a new element to the top of the stack.
2. pop(): Removes and returns the element currently at the top of the stack.
3. peek() or top(): Returns the top element without removing it, allowing you to see what's next.
4. isEmpty(): Returns a boolean indicating whether the stack has any elements left.
5. isFull(): Mainly for array-based stacks. Checks if the stack has reached its maximum capacity.

2. Time & Space Complexity:
One of the primary reasons stacks are more popular is their efficiency.
Bcoz you only ever interact with one end of the data structure (the top) the performance is extremely fast.
TC: push(), pop(), top(), isEmpty() all operate in O(1) constant time.
The time it takes to perform these actions does not change regardless of how large the stack grows.
SC: O(n) n is the number if elements in the stack.

Real World Applications:
Stacks are heavily used by our operating system, compiler and everyday applications.
1. Function Call Stack(Recursion):
Whenever a program calls a function the computer pauses the current function, pushes its current state (variables, return address) onto the call stack and executes the new function. 
When the new function finishes, the computer pop()'s the previous state to resume where it left off.
2. Undo/Redo Mechanisms:
Text editors and design software push your actions onto a stack. 
When you hit Ctrl + Z (Undo), it pops the last action off the stack and reverses it.
3. Browser History:
The back button works via a stack. 
Every new page you visit gets pushed to the stack.
Clicking back pops the current page, taking you to the previous one at the new top of the stack.
4. Syntax Parsing:
Compilers use stacks to check for matching brackets and balanced parentheses in your code(eg: ensuring every { has a matching })
5. Expression Evaluation: Used heavily in converting and evaluating mathematical expression such as converting standard Infix notation (like A + B) into Postfix/Reverse Polish Notation (like A B +)

Limitations:
Lack of Flexibility: 
You cannot access, search or modify an element in the middle or bottom of a stack without removing everything above it first.

Stack Overflow: 
If a stack is given a fixed size (or during infinite recursion call stack), adding too many elements will cause a fatal "Stack Overflow" error crashing the program.

Implementation of Stack using Array:

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr; //Pointer to dynamic array
    int top; //Index of the top element
    int capacity; //Maximum capacity of the stack

public:
    //Constructor to initialize the stack
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        top = -1; //-1 indicates the stack is initially empty
    }

    //Destructor to free memory 
    ~Stack() {
        delete[] arr;
    }

    //Push: Adds the element to the top of the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack OverFlow! Cannot push" << x << endl;
            return;
        }
        arr[++top] = x; //Increment top then insert the element 
        cout << x << "pushed into stack" << endl;
    }

    //Pop: Removes and returns the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        return arr[top--]; //Return the element and decrement top
    }

    //Top: Returns the top element without removing it 
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    //Checks if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    //Checks if the stack is full 
    bool isFull() {
        return top == capacity - 1;
    }
};

// Driver code to test the stack
int main() {
    Stack myStack(5); // Create a stack of capacity 5

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element is: " << myStack.peek() << endl;

    cout << myStack.pop() << " popped from stack." << endl;
    cout << "Top element is now: " << myStack.peek() << endl;

    return 0;
}

TC: Bcoz we are only ever interacting with the last element inserted (tracked by the top index var) we never have to shift other elements around. O(1)

SC: O(N)
N is the max capacity of the stack. 
We must allocate the full size of the array upfront regardless of how many elements are currently stored inside it.

Implementation of Stack using Linked List:
Implementing a stack using LL solves the biggest limitation of an array based stack: fixed capacity. 
With linked list the stack can grow and shrink dynamically means we never have to worry about the stack overflow(unless our computer completely runs out of heap memory)
Instead of using an index like top we maintain a top pointer that always points to the first node in our linked list (the head).
When we push we insert a new node at the head. When we pop we remove the node at the head.

#include <iostream>
using namespace std;

//Define the node structure 
struct Node {
    int data;
    Node* next;

    //Constructor to easily create new nodes 
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; //Pointer to the top of the stack

public:
    //Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
    }

    //Destructor to free memory when the stack is destroyed 
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    //Push: Adds an element to the top of the stack
    void push(int x) {
        Node* newNode = new Node(x);
        // The new node points to the current top 
        newNode->next = top;
        //The new node becomes the new top 
        top = newNode;
        cout << x << "pushed into stack" << end;
    }

    //Pop: Removes and returns the top element 
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow cannot pop" << endl;
            return -1;
        }

        Node* temp = top; //Temp store the top node 
        int poppedValue = temp->data; //Extract the data 
        top = top->next; //Move top pointer to the next node 

        delete temp; //Free the memory of old top node
        return poppedValue; 
    }

    //Peek: Returns the top element without removing it 
    int peek() {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    //Checks if the stack is empty 
    bool isEmpty() {
        retirn top = nullptr;
    }
};

// Driver code to test the stack
int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element is: " << myStack.peek() << endl;

    cout << myStack.pop() << " popped from stack." << endl;
    cout << "Top element is now: " << myStack.peek() << endl;

    return 0;
}

TC: O(1)
SC: O(N)


Implement stack using queue:
To make the queue behave like a stack we do all the heavy lifting during the push operation.
Whenever a new element is added we push it to the back of the queue and then take all the elements 
that were previously in the queue and rotate them (pop from the front and push to the back)
behind the new element. This guarantees the newest element is always at the front of the queue, ready to be popped.

class MyStack{
private:
    queue<int> q;
public:
    MyStack() {}

    //Push element x onto the stack
    void push(int x) {
        int size = q.size();
        q.push(x);

        //Rotate the key to put the newly added element at the front 
        for (i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    //Remove the element on the top of the stack and returns the element 
    int pop() {
        if (q.empty()) {
            cerr << "Stack underflow";
            return -1;
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    //Get the top element 
    int top() {
        if (q.empty()) {
            cerr << "Stack is emtpy";
            return -1;
        }
        return q.front();
    }

    //Return whether the stack is empty 
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Top element: " << stack.top() << "\n";   // Outputs 30
    std::cout << "Popped: " << stack.pop() << "\n";        // Outputs 30
    std::cout << "Top element now: " << stack.top() << "\n"; // Outputs 20
    std::cout << "Is empty? " << (stack.empty() ? "Yes" : "No") << "\n"; // Outputs No
    
    return 0;
}

TC: 
Push: O(n) Every time we insert an element, we must dequeue and enqueue all existing $N$ elements to keep the new element at the front.
Pop: O(1) Because the "newest" element is always sitting at the front of the queue, we just remove it instantly.
Top: O(1) We just check the front of the queue.
Empty: O(1) We just check if the underlying queue is empty.

SC: O(N) for the queue itself to hold the elements.