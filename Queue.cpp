#include <iostream>

using namespace std;
// a queue is a first in first out (FIFO) data structure.

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr; 
    }


};


class Queue {
private:
    Node* first; 
    Node* last; 
    int length; 


public:
    Queue(int value) {
        Node* newNode = new Node(value); // create a new node 
        first = newNode; // first node ptr at newNode
        last = newNode; // last node ptr at newNode
        length = 1; // length is now 1 

    }

    ~Queue() {
        Node* temp = first;
        while (first) {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printQueue() {
        Node* temp = first;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst() {
        if (first == nullptr) {
            cout << "First: nullptr" << endl;
        }
        else {
            cout << "First: " << first->value << endl;
        }
    }

    void getLast() {
        if (last == nullptr) {
            cout << "Last: nullptr" << endl;
        }
        else {
            cout << "Last: " << last->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    bool isEmpty() {
        if (length == 0) return true;
        return false;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            first = newNode; 
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    int dequeue() {
        if (length == 0) return INT_MIN; 
        Node* temp = first;
        int dequeuedValue = first->value;
        if (length == 1) {
            first = nullptr; 
            last = nullptr; 
        }
        else { 
             first = first->next; 
        }
        delete temp;
        length--;
        return dequeuedValue;

    }
};



int main() {

    Queue* myQueue = new Queue(7);
    myQueue->dequeue();
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();
    cout << "\nQueue:\n";
    myQueue->printQueue();

}

