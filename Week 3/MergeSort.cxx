#include <iostream>
#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    using std::cin;
    using std::cout;
#endif
using std::endl;

void merge(int* A, int beg, int mid, int end) {
    int i, j, k;
    int m = mid - beg + 1, n = end - mid;
    int B[m], C[n];
    for (int i = 0; i < m; i++) {
        B[i] = A[beg + i];
    }
    for (int j = 0; j < n; j++) {
        C[j] = A[mid + j + 1];
    }
    for (i = j = 0, k = beg; k <= end; k++) {
        if (i < m && ((j < n && B[i] < C[j]) || j >= n)) {
            // Element of B comes first
            A[k] = B[i++];
        } else {
            // Element of C comes first
            A[k] = C[j++];
        }
    }
    // cout << beg + 1 << " " << end + 1 << " " << A[beg] << " " << A[end] << endl;
}

void mergesort(int* A, int i, int j) {
    if (i >= j) {
        return;
    }
    int k = (i + j) / 2;
    mergesort(A, i, k);
    mergesort(A, k + 1, j);
    merge(A, i, k, j);
    cout << i + 1 << " " << j + 1 << " " << A[i] << " " << A[j] << endl;
}

void Solution(void) {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    mergesort(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    #ifdef JUDGE
        if (! cin.is_open() || ! cout.is_open()) {
            std::cerr << "Failed to open connection to file" << std::endl;
            return 1;
        }
    #endif
    Solution();
    #ifdef JUDGE
        cin.close();
        cout.close();
    #endif
    return 0;
}
