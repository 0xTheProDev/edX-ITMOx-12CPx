#include <iostream>
#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    using std::cin;
    using std::cout;
#endif
#include <string>

void Solution(void) {
    int W, H, Horiz[94], Vert[94];
    char ch;
    std::string Language[3], Code[3], temp;
    cin >> W >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> ch;
            Horiz[ch - 33] = H - i;
            Vert[ch - 33] = j;
        }
    }
    for (int i = 0; i < 3; i++) {
        std::getline(cin, Language[i]);
        cout << Language << std::endl;
        std::getline(cin, temp);
        std::getline(cin, temp);
        while (temp == "%TEMPLATE-END%") {
            Code[i] += temp;
            std::getline(cin, temp);
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << Language[i] << std::endl;
        cout << Code[i] << std::endl;
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
