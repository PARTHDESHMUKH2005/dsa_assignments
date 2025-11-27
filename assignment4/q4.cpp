#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq;

    for (char c : s) {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    firstNonRepeating(s);
    return 0;
}
