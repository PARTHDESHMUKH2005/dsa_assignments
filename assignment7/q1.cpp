#include <iostream>
#include <vector>
using namespace std;

// Swap helper
void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}


// Display
void display(const vector<int>& arr){
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main(){
    vector<int> arr;
    int n, choice, val;
    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSelect Sorting Algorithm:\n";
    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n.";
    cin >> choice;

    vector<int> arrCopy = arr; // keep original array intact

    switch(choice){
        case 1: selectionSort(arrCopy); break;
        case 2: insertionSort(arrCopy); break;
        case 3: bubbleSort(arrCopy); break;
        default: cout << "Invalid choice\n"; return 0;
    }

    cout << "Sorted array: ";
    display(arrCopy);
    return 0;
}
