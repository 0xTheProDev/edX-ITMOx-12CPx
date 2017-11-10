#include <iostream>
#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    using std::cin;
    using std::cout;
#endif

void Solution(void) {
    int K, N, x = 0;
    cin >> K;
    int Divisor[K + 1];
    for (int N = 0; N <= K; N++) {
        Divisor[N] = 0;
    }
    for (int N = 1; N <= K; N++) {
        for (int i = N; i <= K; i += N) {
            Divisor[i]++;
        }
        if (Divisor[N] > Divisor[x]) {
            x = N;
        }
        // cout << N << " " << Divisor[N] << std::endl;
    }
    cout << (K - x + 1) << std::endl;
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
