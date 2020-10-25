//
// Created by Ivan Zharov on 2020-09-23.
//

#include <iostream>
#include <algorithm>
#include <deque>


int solve(int test) {
    int n;
    std::cin >> n;
    std::deque <int> beginning, ending;

    for (int query = 0; query < n; ++query) {
        char cmd;
        std::cin >> cmd;
        if (cmd == '-') {
            std::cout << beginning.front() << std::endl;
            beginning.pop_front();
        } else if (cmd == '+') {
            int goblin;
            std::cin >> goblin;
            ending.push_back(goblin);
        } else if (cmd == '*') {
            int goblin;
            std::cin >> goblin;
            ending.push_front(goblin);
        }

        if (ending.size() > beginning.size()) {
            beginning.push_back(ending.front());
            ending.pop_front();
        }
    }


    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve(0);

    return 0;
}