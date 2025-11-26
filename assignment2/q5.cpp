a. class Diagonal {
    int n;
    int *A;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
};
b. Tri-diagonal Matrix (3 diagonals)
Space = 3n − 2

  
  c.Lower Triangular Matrix
Space = n(n+1)/2
Index Formula (row-major):
A[i*(i-1)/2 + (j-1)] 


d. Upper Triangular Matrix
Space = n(n+1)/2


e. Symmetric Matrix
Store lower triangle only
Space = n(n+1)/2
