#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

enum {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

int main() {
    std::ifstream ifs ("input2");
    std::string line;
    int score = 0;

    while(ifs.good()) {
        getline(ifs, line);
        auto their_choice = 1 + line[0] - 'A';
        auto my_choice = 1 + line[2] - 'X';
        if(line.length() == 0) break;
        score += my_choice;

        if(their_choice == my_choice) {
            score += 3;
        } else if (my_choice == ROCK && their_choice == SCISSORS) {
            score += 6;
        } else if (my_choice == PAPER && their_choice == ROCK) {
            score += 6;
        } else if (my_choice == SCISSORS && their_choice == PAPER) {
            score += 6;
        }
    }
    cout << score << "\n";
}
