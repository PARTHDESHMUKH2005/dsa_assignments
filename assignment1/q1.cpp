#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, value, key, i;
    bool created = false;

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        // CREATE
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (i = 0; i < n; i++)
                cin >> arr[i];
            created = true;
            cout << "Array created successfully.\n";
            break;

        // DISPLAY
        case 2:
            if (!created) {
                cout << "Array not created yet!\n";
                break;
            }
            cout << "Array elements: ";
            for (i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        // INSERT
        case 3:
            if (!created) {
                cout << "Array not created yet!\n";
                break;
            }
            cout << "Enter position to insert (1 to " << n+1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1) {
                cout << "Invalid position!\n";
                break;
            }

            cout << "Enter value: ";
            cin >> value;

            for (i = n; i >= pos; i--)
                arr[i] = arr[i - 1];

            arr[pos - 1] = value;
            n++;

            cout << "Element inserted successfully.\n";
            break;

        // DELETE
        case 4:
            if (!created) {
                cout << "Array not created yet!\n";
                break;
            }
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n) {
                cout << "Invalid position!\n";
                break;
            }

            for (i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;

            cout << "Element deleted successfully.\n";
            break;

        // LINEAR SEARCH
        case 5:
            if (!created) {
                cout << "Array not created yet!\n";
                break;
            }
            cout << "Enter element to search: ";
            cin >> key;

            for (i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at position: " << i + 1 << endl;
                    break;
                }
            }
            if (i == n)
                cout << "Element not found.\n";
            break;

        // EXIT
        case 6:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
