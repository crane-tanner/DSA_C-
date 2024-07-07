#include <iostream>

using namespace std;


class Node {
public:
    int value; 
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value; 
        next = nullptr; 
        prev = nullptr; 
    }

};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail; 
    int length; 

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode; 
        length = 1; 

    }

    ~DoublyLinkedList() {
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
        Node* newNode = new Node(value); // pass in value to append and create a new node 
        if (length == 0) {
            head = newNode; // if no other node exists head and tail point to newNode
            tail = newNode;
        }
        else {
            tail->next = newNode; // next pointer of tail pts to newNode
            newNode->prev = tail; //prev pointer of newNode points to tail
            tail = newNode; // newNode is set as the tail
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = tail; 
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr; 
        }
        delete temp; 
        length--;
    }
    void prepend(int value) {
        Node* newNode = new Node(value); 
        if (length == 0) {
            head = newNode; 
            tail = newNode; 
        }
        else {
            newNode->next = head; 
            head->prev = newNode; 
            head = newNode; 
        }
        length++;
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
            head->prev = nullptr; 
        }
        delete temp; 
        length--; 
    }

    Node* get(int index) {
        if (index < 0 || index >= length)
        {
            return nullptr; 
        }
        Node* temp = head; 
        if (index < length/2) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail; 
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev; 

            }
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
    bool insert(int index, int value) {
        if (index < 0 || index > length) return false; 
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode->prev = before; //pointer redirection to insert in middle of DLL
        newNode->next = after; 
        before->next = newNode;
        after->prev = newNode;
        length++; 
        return true;
    }
    void deleteNode(int index)
    { 
        if (index < 0 || index >= length) return;
        if (index == 0) {
            return deleteFirst();
        }
        if (index == length-1) {
            return deleteLast();
        }
        Node* temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }

};



int main() {

    DoublyLinkedList* myDLL = new DoublyLinkedList(11);
    myDLL->append(3);
    myDLL->append(23);
    myDLL->append(7);
    //myDLL->getHead();
    //myDLL->getTail();
    //myDLL->getLength();
    cout << "\nDoubly Linked List:\n";
    myDLL->printList();
    cout << "\n";
    myDLL->deleteNode(3);
    //myDLL->insert(4, 0);
    myDLL->printList();

}

