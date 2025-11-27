#include <iostream>
using namespace std;

// Node for DLL
struct DNode {
    char data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(char value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayList() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Palindrome check
    bool isPalindrome() {
        if (!head) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next) right = right->next; // go to tail

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};
