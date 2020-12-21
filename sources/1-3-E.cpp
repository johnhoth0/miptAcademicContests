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

class SetOfSets {
private:
	map <int, set <ll>> sets;
	map <ll, set <int>> where;

public:
	void insert(ll x, ll y) {
		sets[y].insert(x);
		where[x].insert(y);
	}
	void erase(ll x, ll y) {
		sets[y].erase(x);
		where[x].erase(y);
	}
	void clear(ll x) {
		for (auto elem : sets[x]) {
			where[elem].erase(x);
		}
		sets[x].clear();
	}
	void listset(ll x) {
		if (sets[x].empty()) {
			cout << "-1\n";
		} else {
			for (auto elem : sets[x]) {
				cout << elem << ' ';
			}
			cout << '\n';
		}
	}
	void listsetof(ll x) {
		if (where[x].empty()) {
			cout << "-1\n";
		} else {
			for (auto elem : where[x]) {
				cout << elem << ' ';
			}
			cout << '\n';
		}
	}
};

int solve(int test) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	
	ll n;
	int m, k;
	cin >> n >> m >> k;

	string s;
	ll x, y;

	SetOfSets mem;

	while (k--) {
		cin >> s >> x;
		if (s[0] == 'A') {
			cin >> y;
			mem.insert(x, y);
		} else if (s[0] == 'D') {
			cin >> y;
			mem.erase(x, y);
		} else if (s[0] == 'C') {
			mem.clear(x);
		} else if (sz(s) == 7) {
			mem.listset(x);
		} else if (sz(s) == 10) {
			mem.listsetof(x);
		}
	}

	return 0;
}

int main() {
	solve(10);
	return 0;
}
