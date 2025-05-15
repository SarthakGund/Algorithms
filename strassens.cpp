#include <bits/stdc++.h>
using namespace std;

// Add two matrices
vector<vector<int>> add(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
vector<vector<int>> subtract(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Matrix Multiplication
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
                        A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)),
                        B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    auto P1 = strassen(A11, subtract(B12, B22));
    auto P2 = strassen(add(A11, A12), B22);
    auto P3 = strassen(add(A21, A22), B11);
    auto P4 = strassen(A22, subtract(B21, B11));
    auto P5 = strassen(add(A11, A22), add(B11, B22));
    auto P6 = strassen(subtract(A12, A22), add(B21, B22));
    auto P7 = strassen(subtract(A11, A21), add(B11, B12));

    auto C11 = add(subtract(add(P5, P4), P2), P6);
    auto C12 = add(P1, P2);
    auto C21 = add(P3, P4);
    auto C22 = subtract(subtract(add(P5, P1), P3), P7);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    return C;
}

// Print matrix
void printMatrix(const vector<vector<int>> &mat) {
    for (auto row : mat) {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter size of matrix (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A:\n";
    for (auto &row : A)
        for (auto &val : row)
            cin >> val;

    cout << "Enter matrix B:\n";
    for (auto &row : B)
        for (auto &val : row)
            cin >> val;

    vector<vector<int>> C = strassen(A, B);

    cout << "Product matrix:\n";
    printMatrix(C);

    return 0;
}
