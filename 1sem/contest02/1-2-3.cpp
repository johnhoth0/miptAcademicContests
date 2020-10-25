//
// Created by johnhoth
// рџЌ‘ = рџђ•
// Copyright В© 2020 Ivan Zharov. All rights reserved.
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
#include <random>

typedef long long int ll;
typedef long double ld;

// #pragma comment(linker, "/STACK:64000000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")

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
#define cotu cout
// #define endl "\n"

using namespace std;


int partition(vector <int> &a, int l, int r) {
    
    int point = a[l + rand() % (r - l)];

    int i = l, j = r;
 
    while (i <= j) {
        while (a[i] < point)
            ++i;
        while (a[j] > point)
            --j;
        if (i >= j)
            break;
 
        swap(a[i], a[j]);
        i++;
        j--;
    }

    return j;    
}


int kOrderStatistics(vector <int> array, int n, int k) {
    int left = 0;
    int right = n - 1;
 
    while (left < right) {
        int pos = partition(array, left, right);
 
        if (k <= pos) {
            right = pos;    
        } else {
            left = pos + 1;
        }
    }
 
    return array[left];
}

int solve(int test) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << kOrderStatistics(a, n, k) << endl;
 
    return 0;
}

int main() {
    // int q;
    // cin >> q;
    // while (q--) {
    solve(0);
    // }
    return 0;
}