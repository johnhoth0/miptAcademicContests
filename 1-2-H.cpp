//
// Created by johnhoth
// Copyright© 2020 Ivan Zharov. All rights reserved.
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

bool check_bit(ll num, int bit, int val) {
	return val == ((num >> bit) & 1LL);
}

void LSD_sort(vector <ll> &A, int l, int r, int bit) {
	int j = r - 1;
	for (int i = l; i < j; ++i) {
		if (((A[i] >> bit) & 1LL) == 0)
			continue;
		while (i < j && check_bit(A[j], bit, 1))
			j--;
		if (i < j)
			swap(A[i], A[j]);
	}
}


void LSD(vector <ll> &A, int l, int r, int bit) {
	if (r <= l + 1 || bit < 0)
		return;
	LSD_sort(A, l, r, bit);
	int j = l;
	while (j < r && check_bit(A[j], bit, 0))
		j++;
	LSD(A, l, j, bit-1);
	LSD(A, j, r, bit-1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector <ll> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	LSD(arr, 0, n, 63);

	for (ll elem : arr) 
		cout << elem << ' ';
	cout << endl;

	return 0;
}
