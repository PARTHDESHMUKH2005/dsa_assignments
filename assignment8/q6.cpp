#include <queue>
#include <vector>

void demoPriorityQueue(){
    priority_queue<int> pq; // max-heap
    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << "Max priority queue elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Min-heap using greater<>
    priority_queue<int, vector<int>, greater<int>> pqMin;
    pqMin.push(10); pqMin.push(5); pqMin.push(20);
    cout << "Min priority queue elements: ";
    while(!pqMin.empty()){
        cout << pqMin.top() << " ";
        pqMin.pop();
    }
    cout << endl;
}
