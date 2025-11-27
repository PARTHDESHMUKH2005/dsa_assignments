#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // (a)
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // (b) 
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // (c) 
    void insertBeforeAfter(int value, int target, bool after = true) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node{value, nullptr};

        
        if (!after && head->data == target) {
            newNode->next = head;
            head = newNode;
            cout << value << " inserted before " << target << ".\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }

        if (after) {
            
            temp = head;
            while (temp != nullptr && temp->data != target)
                temp = temp->next;
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << value << " inserted after " << target << ".\n";
            } else {
                cout << "Node " << target << " not found.\n";
                delete newNode;
            }
        } else {
            
            if (temp->next == nullptr) {
                cout << "Node " << target << " not found.\n";
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << value << " inserted before " << target << ".\n";
            }
        }
    }

    // (d) 
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) 
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) 
    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            cout << target << " deleted.\n";
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Node " << target << " not found.\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            cout << target << " deleted.\n";
            delete toDelete;
        }
    }

    // (g) 
    void searchNode(int target) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == target) {
                cout << "Node " << target << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << target << " not found.\n";
    }

    // (h) 
void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

