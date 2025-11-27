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

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // (b) Insertion at the end
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

    // (c) Insertion before/after a specific node
    void insertBeforeAfter(int value, int target, bool after = true) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node{value, nullptr};

        // Insert before head
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
            // Find target node
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
            // Insert before target node (not head)
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

    // (d) Deletion from the beginning
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

    // (e) Deletion from the end
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

    // (f) Deletion of a specific node
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

    // (g) Search for a node and display its position
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

    // (h) Display all node values
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

// Main function with menu
int main() {
    SinglyLinkedList list;
    int choice, value, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert after target? (1 for yes, 0 for before): ";
                cin >> after;
                list.insertBeforeAfter(value, target, after);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter node value to delete: ";
                cin >> target;
                list.deleteNode(target);
                break;
            case 7:
                cout << "Enter node value to search: ";
                cin >> target;
                list.searchNode(target);
                break;
            case 8:
                list.displayList();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
