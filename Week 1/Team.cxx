#include <iostream>
#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    using std::cin;
    using std::cout;
#endif
#include <cmath>

void Solution(void) {
    double t[3][3], ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < 3; k++) {
                if (i == k || j == k) {
                    continue;
                }
                double a = t[0][i], b = t[1][j], c = t[2][k];
                double temp = sqrt(a * a + b * b + c * c);
                if (temp > ans) {
                    ans = temp;
                }
            }
        }
    }
    cout.precision(8);
    cout << std::fixed << ans << std::endl;
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
