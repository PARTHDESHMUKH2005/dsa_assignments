#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Shift left
                for (k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];

                n--;    // Reduce size
                j--;    // Recheck the new element at position j
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
