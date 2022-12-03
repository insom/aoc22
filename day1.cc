#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ifstream ifs ("input1");
    std::string line;
    std::vector<int> elves;
    int elf = 0;
    elves.push_back(0);

    while(ifs.good()) {
        getline(ifs, line);
        if(line.length() > 0) {
            elves[elf] += stoi(line);
        } else {
            elves.push_back(0);
            elf++;
        }
    }
    sort(elves.begin(), elves.end(), greater<int>());
    cout << elves[0] << "\n";
}
