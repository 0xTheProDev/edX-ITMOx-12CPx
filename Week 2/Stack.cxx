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
    int n;
    cin >> n;
    int A[n], top = -1;
    char flag;
    for (int i = 0; i < n; i++) {
        cin >> flag;
        switch (flag) {
            case '+':
                // ++top;
                cin >> A[++top];
                break;
            case '-':
                cout << A[top--] << std::endl;
        }
    }
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
