#include <iostream>

using namespace std;


class Node {

public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        }
        else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        }
        else {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) { 
        Node* newNode = new Node(value); // create a new node 

        if (head == nullptr) // if empty LL
        {
            head = newNode;
            tail = newNode;
        }
        else { // if items already in the LL
            tail->next = newNode; 
            tail = newNode;
        }

        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {

        Node* pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
        delete temp;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value); // create a new node with the passed in value

        if (length == 0) { // if LL is empty then head and tail point to newNode
            head = newNode;
            tail = newNode; 
        }
        else { // otherwise newNode next pointer to head then head point (move over) to newNode

            newNode->next = head;
            head = newNode;
        
        }

        length++; // increment length of LL
    }
    
    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head; 
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp; 
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;

        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value; 
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length) return false; // if index is out of range
        if (index == 0) { // if index is at first node
            prepend(value);
            return true;
        }
        if (index == length) // if index is at the last node 
        {
            append(value);
            return true;
        }
        Node* newNode = new Node(value); // create a new node with provided value and store in newNode pointer
        Node* temp = get(index - 1); // get the index at the node before we want to insert and set in temp pointer
        newNode->next = temp->next; // set the next pointer of newNode to next pointer of the node pointed to by temp pointer
        temp->next = newNode; // set next pointer of the node pointed to by the temp pointer to newNode
        length++;
        return true; // operation was successful 
    }
    void deleteNode(int index) {
        if (index < 0 || index ==  length) return; 
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast(); 
        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }
    void reverse() {
        Node* temp = head;
        head = tail; 
        tail = temp; 
        Node* after = temp->next;
        Node* before = nullptr; 
        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp; 
            temp = after; 
        }
    }




};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);

    /*
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    */
    /*
    myLinkedList->append(5);
    myLinkedList->prepend(3);
    myLinkedList->prepend(2);
    myLinkedList->append(6);
    myLinkedList->set(1, 23);
    */
    //myLinkedList->deleteLast();
    //myLinkedList->deleteFirst();

    cout << "\nLinked List:\n";
    myLinkedList->printList();

    myLinkedList->reverse();
    cout << "Linked List after reverse:\n";
    myLinkedList->printList();
    //cout << myLinkedList->get(1)->value;
   

}

