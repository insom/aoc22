#include <iostream>
#include <fstream>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ifstream ifs ("input4");
    std::string line;
    int score = 0;

    while(ifs.good()) {
        std::set<int> shifts[2];
        std::vector<char> intersection;
        int pos = 0;
        int bits[3];

        getline(ifs, line);
        int len = line.length();
        if(len == 0) break;

        for(int i = 0; i < 3; i++) {
            pos = line.find_first_of(",-", pos+1);
            bits[i] = pos;
        }

        auto elfA_start = line.substr(0, bits[0]);
        auto elfA_end = line.substr(bits[0] + 1, bits[1] - bits[0] - 1);
        auto elfB_start = line.substr(bits[1] + 1, bits[2] - bits[1] - 1);
        auto elfB_end = line.substr(bits[2] + 1);

        for(int i = stoi(elfA_start); i <= stoi(elfA_end); i++) {
            shifts[0].insert(i);
        }

        for(int i = stoi(elfB_start); i <= stoi(elfB_end); i++) {
            shifts[1].insert(i);
        }

        set_intersection(
                shifts[0].begin(),
                shifts[0].end(),
                shifts[1].begin(),
                shifts[1].end(),
                back_inserter(intersection));

        if(intersection.size() == shifts[0].size() ||
                intersection.size() == shifts[1].size()) {
            score++;
        }
    }
    cout << score << "\n";
}
