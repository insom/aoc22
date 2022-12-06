#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    std::ifstream ifs ("input5");
    std::vector<string> stacks;
    bool move_phase = false;
    std::regex re("move (\\d*) from (\\d*) to (\\d*)");

    stacks.push_back("QMGCL");
    stacks.push_back("RDLCTFHG");
    stacks.push_back("VJFNMTWR");
    stacks.push_back("JFDVQP");
    stacks.push_back("NFMSLBT");
    stacks.push_back("RNVHCDP");
    stacks.push_back("HCT");
    stacks.push_back("GSJVZNHP");
    stacks.push_back("ZFHG");

    while(ifs.good()) {
        std::string line;

        getline(ifs, line);
        int len = line.length();
        if(len == 0 && !move_phase) {
            move_phase = true;
            continue;
        }
        if(len == 0 || !move_phase) continue;

        std::smatch match;
        std::regex_search(line, match, re);

        auto times = stoi(match[1]);
        auto src = stoi(match[2]);
        auto dst = stoi(match[3]);

        auto& src_stack = stacks[src-1];
        auto& dst_stack = stacks[dst-1];
        std::vector<char> temp;
        for(int i = 0; i < times; i++) {
            char &c = src_stack.back();
            temp.push_back(c);
            src_stack.pop_back();
        }
        for(int i = 0; i < times; i++) {
            char &c = temp.back();
            dst_stack.push_back(c);
            temp.pop_back();
        }
    }
    for(int i = 0; i < stacks.size(); i++) {
        cout << stacks[i].back();
    }
    cout << "\n";
}
