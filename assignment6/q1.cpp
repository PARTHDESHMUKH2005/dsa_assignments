#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // (a) Insert at beginning, end, or after/before a specific node
    void insertAtBeginning(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted at beginning.\n";
    }

    void insertAtEnd(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << value << " inserted at end.\n";
    }

    void insertAfterBefore(int value, int target, bool after=true) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == target) {
                CNode* newNode = new CNode{value, nullptr};
                if (after) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout << value << " inserted after " << target << ".\n";
                } else {
                    // insert before: swap data and insert after
                    newNode->data = temp->data;
                    temp->data = value;
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout << value << " inserted before " << target << ".\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    // (b) Delete specific node
    void deleteNode(int target) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        CNode* temp = head;
        CNode* prev = nullptr;

        // head node deletion
        if (head->data == target) {
            if (head->next == head) { // only one node
                delete head;
                head = nullptr;
            } else {
                CNode* last = head;
                while (last->next != head) last = last->next;
                CNode* toDelete = head;
                head = head->next;
                last->next = head;
                delete toDelete;
            }
            cout << target << " deleted.\n";
            return;
        }

        // middle or last node
        prev = head;
        temp = head->next;
        while (temp != head && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            cout << "Node " << target << " not found.\n";
        } else {
            prev->next = temp->next;
            delete temp;
            cout << target << " deleted.\n";
        }
    }

    // (c) Search node
    void searchNode(int target) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == target) {
                cout << "Node " << target << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    // Display nodes including head at end
    void displayList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head
    }

    // Find size
    int size() {
        if (!head) return 0;
        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};
