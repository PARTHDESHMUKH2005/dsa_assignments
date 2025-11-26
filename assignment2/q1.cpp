#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int pos = binarySearch(arr, 6, key);

    if (pos != -1) cout << "Found at index: " << pos << endl;
    else cout << "Not Found\n";
}
