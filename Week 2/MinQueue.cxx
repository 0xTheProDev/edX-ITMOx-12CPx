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
    int n, minEle;
    cin >> n;
    int A[n], data, front = 0, rear = -1;
    char flag;
    for (int i = 0; i < n; i++) {
        cin >> flag;
        switch (flag) {
            case '+':
                cin >> data;
                if (rear == -1) {
                    minEle = A[++rear] = data;
                } else if (data >= minEle) {
                    A[++rear] = data;
                } else {
                    A[++rear] = 2 * data - minEle;
                    minEle = data;
                }
                break;
            case '-':
                if (A[front] < minEle) {
                    minEle = 2 * minEle - A[front];
                }
                ++front;
                break;
            case '?':
                cout << minEle << std::endl;
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
