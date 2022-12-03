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

enum {
    LOSE = 1,
    DRAW = 2,
    WIN = 3
};

int main() {
    std::ifstream ifs ("input2");
    std::string line;
    int score = 0;

    while(ifs.good()) {
        getline(ifs, line);
        auto their_choice = 1 + line[0] - 'A';
        auto my_outcome = 1 + line[2] - 'X';
        int my_choice = 0;
        if(line.length() == 0) break;

        if(my_outcome == DRAW) {
            my_choice = their_choice;
        } else if(my_outcome == WIN) {
            if(their_choice == ROCK)
                my_choice = PAPER;
            if(their_choice == PAPER)
                my_choice = SCISSORS;
            if(their_choice == SCISSORS)
                my_choice = ROCK;
        } else {
            if(their_choice == ROCK)
                my_choice = SCISSORS;
            if(their_choice == PAPER)
                my_choice = ROCK;
            if(their_choice == SCISSORS)
                my_choice = PAPER;
        }

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
