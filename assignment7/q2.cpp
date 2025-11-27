#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int>& arr){
    int n = arr.size();
    int start = 0, end = n-1;

    while(start < end){
        int minIdx = start;
        int maxIdx = start;

        for(int i=start; i<=end; i++){
            if(arr[i] < arr[minIdx]) minIdx = i;
            if(arr[i] > arr[maxIdx]) maxIdx = i;
        }

        // Move minimum to start
        if(minIdx != start) swap(arr[minIdx], arr[start]);

        // If max element was at start, it has been moved to minIdx
        if(maxIdx == start) maxIdx = minIdx;

        // Move maximum to end
        if(maxIdx != end) swap(arr[maxIdx], arr[end]);

        start++;
        end--;
    }
}

void display(const vector<int>& arr){
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    SelectionSort(arr);

    cout << "Sorted array: ";
    display(arr);
    return 0;
}
