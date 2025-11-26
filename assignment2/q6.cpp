a.
  void transpose(int T[][3], int A[][3], int n) {
    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];

    int k = 1;
    for (int i = 1; i <= A[0][2]; i++) {
        T[k][0] = A[i][1];
        T[k][1] = A[i][0];
        T[k][2] = A[i][2];
        k++;
    }
}
