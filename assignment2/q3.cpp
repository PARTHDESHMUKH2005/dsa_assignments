a. #include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,6,7};
    int n = 7;
    int expectedSum = n * (n + 1) / 2;

    int actualSum = 0;
    for (int i = 0; i < n - 1; i++)
        actualSum += arr[i];

    cout << "Missing number = " << expectedSum - actualSum;
}
b. 

int findMissing(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1,2,3,4,6,7};
    cout << "Missing number = " << findMissing(arr, 6);
}
