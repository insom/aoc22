#include <iostream>
#include <fstream>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ifstream ifs ("input3");
    std::string line;
    int score = 0;
    int pos = 0;
    std::set<char> lines[3];

    while(ifs.good()) {
        std::vector<char> intersection;
        std::vector<char> intersectioner;

        getline(ifs, line);
        int len = line.length();
        if(len == 0) break;

        lines[pos % 3].insert(line.begin(), line.end());

        if(pos % 3 == 2) {
            set_intersection(
                    lines[0].begin(),
                    lines[0].end(),
                    lines[1].begin(),
                    lines[1].end(),
                    back_inserter(intersection));
            set_intersection(
                    lines[2].begin(),
                    lines[2].end(),
                    intersection.begin(),
                    intersection.end(),
                    back_inserter(intersectioner));
            lines[0].clear();
            lines[1].clear();
            lines[2].clear();
            if('a' <= intersectioner[0] && 'z' >= intersectioner[0]) {
                score += 1 + intersectioner[0] - 'a';
            } else {
                score += 27 + intersectioner[0] - 'A';
            }
        }
        pos++;
    }
    cout << score << "\n";
}
