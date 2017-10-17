#include <fstream>

int main() {
    std::ifstream infile("input.txt", std::ios::in);
    std::ofstream outfile("output.txt", std::ios::out);
    if (! infile.is_open()) {
        return 1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        if (outfile.is_open()) {
            outfile << line;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
