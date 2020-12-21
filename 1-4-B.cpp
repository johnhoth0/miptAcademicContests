//
// Created by johnhoth
// 🍑 = 🐕
// Copyright © 2018 Ivan Zharov. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <math.h>
#include <set>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <time.h>

typedef long long int ll;
typedef long double ld;

#pragma comment(linker, "/STACK:64000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

const int INF = 2e9 + 179, MOD = 1e9+7;
const ll BIGINF = 2e18 + 179;
const ld EPS = 0.000001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb(a) push_back(a)
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define trace1(a) cerr<<#a" = "<<a<<endl
#define trace2(a, b) cerr<<#a" = "<<a<<" | "<<#b" = "<<b<<endl
#define trace3(a, b, c) cerr<<#a" = "<<a<<" | "<<#b" = "<<b<<" | "<<#c" = "<<c<<endl
#define trace4(a, b, c, d) cerr<<#a" = "<<a<<" | "<<#b" = "<<b<<" | "<<#c" = "<<c<<" | "<<#d" = "<<d<<endl
#define trace5(a, b, c, d, e) cerr<<#a" = "<<a<<" | "<<#b" = "<<b<<" | "<<#c" = "<<c<<" | "<<#d" = "<<d<<" | "<<#e" = "<<e<<endl

#define ft first
#define sd second
// #define endl "\n"

template <class INFO, typename T> 
class SegTree {
private:
    struct Node
    {
        T val, d;
        Node() {
            val = INFO::nullElement;
            d = INFO::nullElement;
        }
    };
    size_t n;
    std::vector <Node> t;


    const T MOD = 1000000009;

    void build(int v, int tl, int tr, std::vector <T> &arr) {
        if (tl > tr) {
            return;
        }
        if (tl == tr) {
            t[v].val = arr[tl];
            t[v].d = INFO::nullElement;
            return;
        }
        int mid = (tl + tr) >> 1;
        build(v << 1, tl, mid, arr);
        build(v << 1 | 1, mid + 1, tr, arr);
        t[v].val = INFO::func(
            t[v << 1].val, 
            t[v << 1 | 1].val);// % MOD;
        t[v].d = INFO::nullElement;
    }

    void push(int v, int tl, int tr) {
        if (t[v].d) {
            t[v].val = INFO::segFunc(t[v].val, t[v].d, tl, tr);// % MOD;
            if (tl != tr) {
                t[v << 1].d = t[v].d;
                t[v << 1 | 1].d = t[v].d;
            }
            t[v].d = INFO::nullElement;
        }
    }

    T get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (r < tl || tr < l) {
            return INFO::nullElement;
        }
        if (l <= tl && tr <= r) {
            return t[v].val;
        }
        int mid = (tl + tr) >> 1;
        return INFO::func(
            get(v << 1, tl, mid, l, r), 
            get(v << 1 | 1, mid + 1, tr, l, r));// % MOD;
    }

    void upd(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        if (r < tl || tr < l) {
            return;
        }
        if (l <= tl && tr <= r) {
            t[v].d = val;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) >> 1;
        upd(v << 1, tl, mid, l, r, val);
        upd(v << 1 | 1, mid + 1, tr, l, r, val);
        t[v].val = INFO::func(
            t[v << 1].val, 
            t[v << 1 | 1].val);// % MOD;
        push(v, tl, tr);
    }

public:
    SegTree(size_t _n) {
        n = _n;
        t.resize(n << 2);
    }

    SegTree(size_t _n, std::vector <T> &arr) {
        n = _n;
        t.resize(n << 2);
        build(1, 0, n, arr);
    }
    T get(int l, int r) {
        return get(1, 0, n, l, r);
    }
    T update(int pos, T val) {
        upd(1, 0, n, pos, pos, val);
    }

};


class SumOnLL {
public:
    static const ll nullElement = 0;

    static ll func(ll a, ll b) {
        return a + b;
    }
    static ll segFunc(ll oldVal, ll newVal, int tl, int tr) {
        return (tr - tl + 1) * newVal;
    }
};


int solve() {
    size_t n;
    std::cin >> n;
    std::vector <ll> arr0((n+1)/2, 0);
    std::vector <ll> arr1(n/2, 0);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            std::cin >> arr0[i/2];
        } else {
            std::cin >> arr1[i/2];
        }
    }
    
    SegTree<SumOnLL, ll> treeEven(sz(arr0), arr0);
    SegTree<SumOnLL, ll> treeOdd(sz(arr1), arr1);

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int cmd, x, y;
        std::cin >> cmd >> x >> y;
        x--;
        if (cmd == 1) {
            y--;
            int Ex=x/2, Ey=y/2, Ox=x/2, Oy=y/2;
            if (x % 2 == 0) {
                Ex = x / 2;
                Ox = x / 2;
            } else {
                Ex = std::min((x + 1) / 2, sz(arr0) - 1);
                Ox = x / 2;
            }
            if (y % 2 == 0) {
                Oy = std::max((y - 1) / 2, 0);
            } else {
                Ey = y / 2;
            }
            if (x != y) {
                if (x % 2 == 0) {
                    std::cout << treeEven.get(Ex, Ey) - treeOdd.get(Ox, Oy) << std::endl;
                } else {
                    std::cout << -treeEven.get(Ex, Ey) + treeOdd.get(sz(arr1), Ox, Oy) << std::endl;
                }
            } else {
                if (x % 2 == 0) {
                    std::cout << treeEven.get(Ex, Ey) << std::endl;
                } else {
                    std::cout << treeOdd.get(Ox, Oy) << std::endl;
                }

            }
        } else {
            if (x % 2 == 0) {
                treeEven.update(x/2, y);
            } else {
                treeOdd.update(x/2, y);
            }
        }
    }
    

    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
