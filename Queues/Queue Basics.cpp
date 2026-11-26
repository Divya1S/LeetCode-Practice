Queue:
Queue is also a linear data structure, but it is the exact opposite of a stack when it comes to order.
It operates on the FIFO(First In First Out) principle. 
This means first element added to the queue will be the very first one to be removed.

To visualize a queue, think of a physical line at a coffee shop or a movie theater.
The first person to get in line is the first person to be served. 
If you arrive last you join the back of the line and wait for your turn.

Core Operations:
Unlike a stack which uses one end, a queue interacts with both ends: you add items to the back (rear) and remove them from front.
enqueue(item): Adds a new element to the back (rear) of the queue. push()
dequeue(): Removes and returns the element from the front of the queue. pop()
peek(): Looks at the item at the front of the queue but does not removes it.
front()
isEmpty(): Checks if the queue has any elements

TC and SC:
For properly implemented queue the operations are highly efficient:
TC: 
Enqueue: O(1)
Dequeue: O(1)
Peek()/Front(): O(1)
Search: O(n) bcoz you would have to dequeue elements to find a specific one which queues are not designed for.

SC: O(n)

How it is implemented:
Queues are typically built using one of the two underlying structures:
1. Linked Lists:
Excellent for queues bcoz you can easily add to the tail and remove from the head in O(1) time without shifting any elements.
2. Arrays:
Can be tricky. If you remove the first element of a standard array, all other elements have to shift forward which takes O(n) time. 
To fix this we use "Circular Queue" approach where two pointers (front and rear) wrap around the arrays boundaries to maintain O(1) performance.

Important Variations:
1. Circular Queue:
The last position connects back to the first forming a circle.
Memory management where you want to reuse empty spaces left by dequeued items.

2. Priority Queue: 
Elements are dequeued based on priority not arrival time.
Often implemented using Heaps.
Emergency room triage; CPU scheduling for high-priority systems tasks.

3. Deque(Double-Ended):
Allows insertion and deletion at both the front and rear.
Browser history(storing the list of recently visited pages where you might need to drop the oldest)

Real World Applications:
Queues are everywhere in software specifically whenever things happen faster than they can be processed or when fairness and order matter.
Operating Systems:
CPU task scheduling (handling processes in the order they were received)
Asynchronous Data Transfer: IO Buffers, pipes and file IO handle data streams via queues.
Print Spooling:
Sending 5 documents to a printer creates a queue; the printer handles them one by one in the order they were sent.
Web Servers: 
Handling incoming API requests. I a server can handle only 1000 requests per second, request 1001 goes in the queue.
Algorithms: 
Breadth First Search in trees and graphs uses a queue to keep track of which nodes to visit next.


Implementation of Queue using Array:
To make this efficient we use a Circular Array approach.
If we just used a normal array and removed the front element we would have to shift every other element forward which is slow. 
BY wrapping the rear and front pointers around the end of the array using the the modulo operator (%) we can add and remove items without ever shifting anything.

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr; //pointer to dynamic array
    int front; //Index of the front element 
    int rear; //index of the rear element 
    int capacity; //Maximum capacity of the queue 
    int currentSize; //Current number of elements in the queue

public:
    //Constructor to intialize the queue 
    Queue(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    //Destructor to free memory 
    ~Queue() {
        delete[] arr;
    }

    //Enqueue: Adds an element to the back of the queue 
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue" << x << endl;
            return;
        }
        //Wrap around using modulo if rear reaches the end of the array 
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        currentSize++;
        cout << x << "enqueued to the queue" << endl;
    }

    //Dequeue: Remove and returns the front element 
    int dequeue() {
        if (isEmpty()) {
            count << "Queue Underflow cannot dequeue from empty queue" << endl;
            return -1;
        }
        int item = arr[front];
        //Wrap around using modulo if the front reaches the end of the array 
        front = (front + 1) % capacity;
        currentSize--;
        return item;
    }

    //Peek: Returns the front element without removing it 
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    //Checks if the queue is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    //Checks if the queue is full 
    bool isFull() {
        return currentSize == capacity;
    }
};

// Driver code to test the queue
int main() {
    Queue myQueue(5); // Create a queue of capacity 5

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element is: " << myQueue.peek() << endl;

    cout << myQueue.dequeue() << " dequeued from queue." << endl;
    cout << "Front element is now: " << myQueue.peek() << endl;

    // Testing circular behavior
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60); // Queue should now be full (20, 30, 40, 50, 60)
    
    myQueue.enqueue(70); // This should trigger Overflow

    return 0;
}

TC: Bcoz we are using circular array with front and rear pointers we calculate the exact index for insertion and deletion without shifting any other data.
O(1)

SC: O(N)

Implementation of Queue using Linked List:
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front; // Points to the front (head) of the queue
    Node* rear;  // Points to the back (tail) of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to prevent memory leaks
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Enqueue: Adds an element to the rear of the queue
    void enqueue(int x) {
        Node* newNode = new Node(x);
        
        // If queue is empty, new node is both front and rear
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued to queue." << endl;
    }

    // Dequeue: Removes and returns the front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
            return -1;
        }

        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;

        // If queue becomes empty, set rear to nullptr as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Free memory
        return dequeuedValue;
    }

    // Peek: Returns the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

// Driver code to test the queue
int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element is: " << myQueue.peek() << endl;

    cout << myQueue.dequeue() << " dequeued from queue." << endl;
    cout << "Front element is now: " << myQueue.peek() << endl;

    return 0;
}

TC: O(1)
SC: O(N)


Implement Queue using Stack 
#include <bits/stdc++.h>
using namespace std;

// Queue implementation using stack
class StackQueue {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue () {
        
    }
    
    // Method to push elements in the queue
    void push(int x) {
        /* Pop out elements from the first stack 
        and push on top of the second stack */
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Insert the desired element
        st1.push(x);
        
        /* Pop out elements from the second stack 
        and push back on top of the first stack */
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop element from the queue
    int pop() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    
    // Method to get the front element from the queue 
    int peek() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Return the top element
        return st1.top();
    }
    
    // Method to find whether the queue is empty
    bool isEmpty() {
        return st1.empty();
    }
};

int main() {
    StackQueue q;
    
    // List of commands
    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}

TC: O(n) for push operation and O(1) for pop and peek operation 
SC: O(n) for storing the elements in the stacks.

#include <bits/stdc++.h>
using namespace std;

class StackQueue {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    StackQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

TC: O(1) for push operation and O(n) for pop and peek operations in the worst case when elements need to tbe shifted 
SC: O(n) for storing elements in the 2 stacks 