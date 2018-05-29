

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int tab[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 7, 10, 10, 10, 10 };
    unordered_map<int, size_t> map;

    for(auto num : tab)
        map[num] += 1;

    for(const auto &pair : map)
        cout << pair.first << ": " << pair.second << endl;
    return 0;
}
