#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int x;
    cout << "Enter 6 elements: ";
    for (int i = 0; i < 6; i++) {
        cin >> x;
        q.push(x);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
