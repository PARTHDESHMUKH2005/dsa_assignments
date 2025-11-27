int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, value, target;
    char c;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. CLL Insert Beginning\n";
        cout << "2. CLL Insert End\n";
        cout << "3. CLL Insert Before/After Node\n";
        cout << "4. CLL Delete Node\n";
        cout << "5. CLL Search Node\n";
        cout << "6. Display CLL\n";
        cout << "7. CLL Size\n";
        cout << "8. DLL Insert End (char)\n";
        cout << "9. Display DLL\n";
        cout << "10. DLL Size\n";
        cout << "11. Check DLL Palindrome\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                cll.insertAtBeginning(value); break;
            case 2:
                cout << "Enter value: "; cin >> value;
                cll.insertAtEnd(value); break;
            case 3:
                cout << "Enter value: "; cin >> value;
                cout << "Target node: "; cin >> target;
                cout << "Insert after target? (1-yes, 0-before): ";
                int after; cin >> after;
                cll.insertAfterBefore(value, target, after); break;
            case 4:
                cout << "Enter node to delete: "; cin >> target;
                cll.deleteNode(target); break;
            case 5:
                cout << "Enter node to search: "; cin >> target;
                cll.searchNode(target); break;
            case 6:
                cll.displayList(); break;
            case 7:
                cout << "CLL Size: " << cll.size() << endl; break;
            case 8:
                cout << "Enter character: "; cin >> c;
                dll.insertAtEnd(c); break;
            case 9:
                dll.displayList(); break;
            case 10:
                cout << "DLL Size: " << dll.size() << endl; break;
            case 11:
                if (dll.isPalindrome())
                    cout << "DLL is a palindrome.\n";
                else
                    cout << "DLL is not a palindrome.\n";
                break;
            case 12:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 12);

    return 0;
}
