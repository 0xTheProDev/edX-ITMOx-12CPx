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
    long long int a0, a1, a2, an, n;
    cin >> a0 >> a1 >> a2 >> n;
    if (n == 0) {
        an = a0;
    } else if (n == 1) {
        an = a1;
    } else if (n == 2) {
        an = a2;
    } else {
        for (int i = 2; i < n; i++) {
            an = a2 + a1 - a0;
            a0 = a1;
            a1 = a2;
            a2 = an;
        }
    }
    cout << an << std::endl;
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
