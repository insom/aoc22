#include <iostream>
#include <fstream>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ifstream ifs ("input3");
    std::string line;
    int score = 0;

    while(ifs.good()) {
        std::set<char> first_compartment;
        std::set<char> second_compartment;
        std::vector<char> intersection;
        int pos = 0;

        getline(ifs, line);
        int len = line.length();
        if(len == 0) break;

        for(char c : line) {
            if(pos < len/2) {
                first_compartment.insert(c);
            } else {
                second_compartment.insert(c);
            }
            pos++;
        }

        set_intersection(
                first_compartment.begin(),
                first_compartment.end(),
                second_compartment.begin(),
                second_compartment.end(),
                back_inserter(intersection));
        if('a' <= intersection[0] && 'z' >= intersection[0]) {
            score += 1 + intersection[0] - 'a';
        } else {
            score += 27 + intersection[0] - 'A';
        }
    }
    cout << score << "\n";
}
