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
    int n, sum = 0, pcount = 0, tcount = 0;
    cin >> n;
    int p[n], t[n], d[n], min = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        d[i] = p[i] > t[i] ? p[i] - t[i] : t[i] - p[i];
        if (d[i] < d[min]) {
            min = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] > t[i]) {
            sum += p[i];
            pcount++;
        } else {
            sum += t[i];
            tcount++;
        }
    }
    if (tcount == 0) {
        sum = sum - p[min] + t[min];
    } else if (pcount == 0) {
        sum = sum - t[min] + p[min];
    }
    cout << sum << std::endl;
}

int main() {
    std::string line;
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
