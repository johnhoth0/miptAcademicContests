//
// Created by Ivan Zharov on 2020-09-23.
//

#include <iostream>
#include <algorithm>
#include <deque>

struct MyQueue
{
    std::deque <int> beginning, ending;
    
    void normalize() {
        if (ending.size() > beginning.size()) {
            beginning.push_back(ending.front());
            ending.pop_front();
        }
    }

    int pop_front() {
        int val = beginning.front();
        beginning.pop_front();
        normalize();
        return val;
    }

    void push_back(int val) {
        ending.push_back(val);
        normalize();
    }

    void push_center(int val) {
        ending.push_front(val);
        normalize();
    }

};


int solve(int test) {
    int n;
    std::cin >> n;

    MyQueue G;

    for (int query = 0; query < n; ++query) {
        char cmd;
        std::cin >> cmd;
        if (cmd == '-') {
            std::cout << G.pop_front() << std::endl;
        } else if (cmd == '+') {
            int goblin;
            std::cin >> goblin;
            G.push_back(goblin);
        } else { // if (cmd == '*') 
            int goblin;
            std::cin >> goblin;
            G.push_center(goblin);
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
