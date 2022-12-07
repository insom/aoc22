#include <iostream>
#include <fstream>
#include <set>
#include <list>

using namespace std;

/* For Part 1 */
// #define BUFFERSIZE 4
/* For Part 2 */
#define BUFFERSIZE 14

int main() {
    std::ifstream ifs ("input6");
    std::list<char> buf;
    int pos = 0;
    std::string line;
    std::set<char> chars;

    getline(ifs, line);

    for(int pos = 0; pos < line.length(); pos++) {
        char &c = line[pos];
        buf.push_back(c);
        if(buf.size() > BUFFERSIZE)
            buf.pop_front();
        chars.clear();
        for(char &x : buf) {
            chars.insert(x);
        }
        if(chars.size() == BUFFERSIZE) {
            cout << pos + 1 << "\n";
            break;
        }
    }
}
