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

class HeapMin {
private:
	vector <pair <ll, int>> heap;
	vector <int> query;

	void siftUp(int ind);
	void siftDown(int ind);
public:
	vector <int> queries;
	int insert_query_num = 0;

	ll getMin();
	void extractMin();
	void insert(ll element);
	void decreaseKey(int query_num, ll delta);


	HeapMin() {
		heap.clear();
		query.clear();
		query.pb(-1);
		queries.pb(-1);
	}

	~HeapMin() {}
};

void HeapMin::siftUp(int ind) {
	while (ind > 0) {
		if (ind < sz(heap) && heap[ind/2].ft > heap[ind].ft) {
			swap(query[heap[ind/2].sd], query[heap[ind].sd]);
			swap(heap[ind/2], heap[ind]);
		} else {
			break;
		}
		ind /= 2;
	}
}

void HeapMin::siftDown(int ind) {
	while (2 * ind < sz(heap)) {
		int j = -1;
		if (ind * 2 < sz(heap) && heap[ind].ft > heap[ind*2].ft) {
			j = ind * 2;
		}
		if (ind * 2 + 1 < sz(heap) && heap[ind].ft > heap[ind*2+1].ft && (j == -1 || heap[ind*2+1].ft < heap[ind*2].ft)) {
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

ll HeapMin::getMin() {
	queries.pb(-1);
	return heap[0].ft;
}

void HeapMin::extractMin() {
	swap(query[heap[0].sd], query[heap[heap.size()-1].sd]);
	swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	siftDown(0);
	queries.pb(-1);
}

void HeapMin::insert(ll element) {
	insert_query_num++;
	queries.pb(insert_query_num);

	heap.pb(mp(element, insert_query_num));
	query.pb(heap.size()-1);
	siftUp(heap.size()-1);
}

void HeapMin::decreaseKey(int query_num, ll delta) {
	heap[query[queries[query_num]]].ft -= delta;
	siftUp(query[queries[query_num]]);
	queries.pb(-1);
}

int solve(int test) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);

	int q;
	cin >> q;
	HeapMin heap1;
	string s;
	for (int i = 0; i < q; ++i) {
		cin >> s;
		if (s[0] == 'i') {
			ll elem;
			cin >> elem;
			heap1.insert(elem);
		} else if (s[0] == 'g') {
			cout << heap1.getMin() << '\n';
		} else if (s[0] == 'e') {
			heap1.extractMin();	
		} else {
			int ind;
			long long delta;
			cin >> ind >> delta;
			heap1.decreaseKey(ind, delta);
		}
	}

	return 0;
}

int main() {
	solve(179);
	return 0;
}
