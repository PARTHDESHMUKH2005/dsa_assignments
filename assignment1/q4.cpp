a.
#include <iostream>
using namespace std;

int main() {
    int n, arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Reverse logic
    int i = 0, j = n - 1;
    while(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    cout << "Reversed array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
b.
#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    if(c1 != r2) {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    cout << "Enter Matrix A:\n";
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            cin >> B[i][j];

    // Multiplication logic
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix (A × B):\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
c.
#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int r, c;

    cout << "Enter rows and columns of the Matrix: ";
    cin >> r >> c;

    cout << "Enter the matrix:\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

    // Transpose logic
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            T[j][i] = A[i][j];

    cout << "Transpose of the Matrix:\n";
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return 0;
}
