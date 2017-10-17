#include <iostream>
#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
#else
    using std::cin;
    using std::cout;
#endif

int main() {
    std::string line;
    #ifdef JUDGE
        if (! cin.is_open() || ! cout.is_open()) {
            std::cerr << "Failed to open connection to file" << std::endl;
            return 1;
        }
    #endif
    while (std::getline(cin, line)) {
        cout << line;
    }
    #ifdef JUDGE
        infile.close();
        outfile.close();
    #endif
    return 0;
}
