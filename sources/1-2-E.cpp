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


void siftUp(vector<pair<ll, int>> &heap, vector<int> &query, int ind) {
	while (ind > 0) {
		if (ind < sz(heap) && heap[ind/2].ft < heap[ind].ft) {
			swap(query[heap[ind/2].sd], query[heap[ind].sd]);
			swap(heap[ind/2], heap[ind]);
		} else {
			break;
		}
		ind /= 2;
	}
}

void siftDown(vector<pair<ll, int>> &heap, vector<int> &query, int ind) {
	while (2 * ind < sz(heap)) {
		int j = -1;
		if (ind * 2 < sz(heap) && heap[ind].ft < heap[ind*2].ft) {
			j = ind * 2;
		}
		if (ind * 2 + 1 < sz(heap) && heap[ind].ft < heap[ind*2+1].ft && (j == -1 || heap[ind*2+1].ft > heap[ind*2].ft)) {
			j = ind * 2 + 1;
		}
		if (j == -1) {
			break;
		} else {
			swap(query[heap[ind].sd], query[heap[j].sd]);
			swap(heap[ind], heap[j]);
			ind = j;
		}
	}
}

ll getMax(vector<pair<ll, int>> &heap) {
	return heap[0].ft;
}

pair <ll, int> extractMax(vector <pair <ll, int>> &heap, vector<int> &query) {
	swap(query[heap[0].sd], query[heap[heap.size()-1].sd]);
	swap(heap[0], heap[heap.size()-1]);
	auto res = heap.back();
	heap.pop_back();
	siftDown(heap, query, 0);
	return res;
}

void insert(vector <pair <ll, int>> &heap, vector <int> &query, ll element, int query_num) {
	heap.pb(mp(element, query_num));
	query.pb(heap.size()-1);
	siftUp(heap, query, heap.size()-1);
}


int solve(int test) {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);

	int n, k;
	cin >> n >> k;
	vector<int> queries;
	vector<pair<ll, int>> heap;
	vector<int> query;
	query.pb(-1);
	queries.pb(-2);
	int insert_query_num = 0;
	ll inp;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		// if (s[0] == 'i') {
			insert_query_num++;
			queries.pb(insert_query_num);
			// ll element;
			// cin >> element;
			insert(heap, query, inp, insert_query_num);
		if (sz(heap) > k) {
			extractMax(heap, query);
		}
		// }
		// else if (s[0] == 'g') {
		// 	cout << getMax(heap) << '\n';
		// 	queries.pb(-1);
		// }
		// else if (s[0] == 'e') {
		// 	extractMax(heap, query);
		// 	queries.pb(-1);
		// }
	}
	vector <ll> ans;
	while (!heap.empty()) {
		auto tmp = extractMax(heap, query);
		ans.pb(tmp.ft);
	}

	sort(all(ans));
	for (auto x : ans) cout << x << ' ';
	cout << endl;

	return 0;
}

int main() {
	// int q;
	// cin >> q;
	// while (q--) {
			solve(179);
	// }
		return 0;
}
