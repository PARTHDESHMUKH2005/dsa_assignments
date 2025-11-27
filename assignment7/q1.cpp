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

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1), R(n2);
    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
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
    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\nChoice: ";
    cin >> choice;

    vector<int> arrCopy = arr; // keep original array intact

    switch(choice){
        case 1: selectionSort(arrCopy); break;
        case 2: insertionSort(arrCopy); break;
        case 3: bubbleSort(arrCopy); break;
        case 4: mergeSort(arrCopy,0,n-1); break;
        case 5: quickSort(arrCopy,0,n-1); break;
        default: cout << "Invalid choice\n"; return 0;
    }

    cout << "Sorted array: ";
    display(arrCopy);
    return 0;
}
