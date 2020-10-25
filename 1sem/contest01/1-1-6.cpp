//
// Created by Ivan Zharov on 2020-09-23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

long long merge(std::vector<int> &arr, int l, int r) {
    int mid = (l + r) / 2;
    std::vector <int> first(arr.begin() + l, arr.begin() + mid), second(arr.begin() + mid, arr.begin() + r);
    long long res = 0;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] >= second[j]) {
            arr[i + j + l] = second[j];
            j++;
        } else {
            arr[i + j + l] = first[i];
            res += j;
            i++;
        }
    }

    while (j < second.size()) {
        arr[i + j + l] = second[j];
        j++;
    }

    while (i < first.size()) {
        res += j;
        arr[i + j + l] = first[i];
        i++;
    }

    return res;
}

long long countInv(std::vector<int> &arr, int l, int r) {
    if (r == l + 1) return 0;
    int mid = (l + r) / 2;
    return countInv(arr, l, mid) + countInv(arr, mid, r) + merge(arr, l, r);
}

int solve(int test) {
    int n;
    std::cin >> n;
    std::vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << countInv(arr, 0, n) << std::endl;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);

    solve(0);

    return 0;
}