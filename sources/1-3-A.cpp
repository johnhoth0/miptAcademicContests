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

class AvlTree {
private:
	struct node {
		int key;
		int height;
		node* left;
		node* right;

		node(int k) {
			key = k;
			height = 1;
			left = nullptr;
			right = nullptr;
		}
	};

	node* root = nullptr;

	int height(node* p) {
		return (p ? p->height : 0);
	}

	int balance_factor(node* p) {
		return height(p->right) - height(p->left);
	}

	void fix_height(node* p) {
		int height_left = height(p->left);
		int height_right = height(p->right);
		p->height = (height_left > height_right ? height_left : height_right) + 1;
	}

	node* rotate_right(node* p) {
		node* q = p->left;
		p->left = q->right;
		q->right = p;
		fix_height(p);
		fix_height(q);
		return q;
	}

	node* rotate_left(node* q) {
		node* p = q->right;
		q->right = p->left;
		p->left = q;
		fix_height(q);
		fix_height(p);
		return p;
	}

	node* balance(node* p) {
		fix_height(p);
		if (balance_factor(p) == 2) {
			if (balance_factor(p->right) < 0) {
				p->right = rotate_right(p->right);
			}
			return rotate_left(p);
		} else if (balance_factor(p) == -2) {
			if (balance_factor(p->left) > 0) {
				p->left = rotate_left(p->left);
			}
			return rotate_right(p);
		} else {
			return p;
		}
	}

	node* do_insert(node* p, int k) {
		if (!p) {
			return new node(k);
		}
		
		if (k < p->key) {
			p->left = do_insert(p->left, k);
		} else {
			p->right = do_insert(p->right, k);
		}
		return balance(p);
	}



	node* find_min(node* p) {
		return (p->left ? find_min(p->left) : p);
	}

	bool find(node* p, int k) {
		// cout << "find " << k;
		if (!p) {
			return false;
		}
		// trace1(p->key);
		if (p->key == k) {
			return true;
		} else if (p->key > k) {
			return find(p->left, k);
		} else {
			return find(p->right, k);
		}
	}

	node* insert(node* p, int k) {
		if (!find(p, k)) {
			return do_insert(p, k);
		} else {
			return p;
		}
	}


	int find_next(node* p, int k) {
		node* cur = p;
		node* successor = nullptr;

		while (cur != nullptr) {
			if (cur->key > k) {
				successor = cur;
				cur = cur->left;
			} else {
				cur = cur->right;
			}
		}
		if (successor == nullptr) return INF;
		else return successor->key;
	}


	int find_prev(node* p, int k) {
		node* cur = p;
		node* successor = nullptr;

		while (cur != nullptr) {
			if (cur->key < k) {
				successor  = cur;
				cur = cur->right;
			} else  {
				cur = cur->left;
			}
		}
		if (successor == nullptr) return INF;
		else return successor->key;
	}

	node* remove_min(node* p) {
		if (!p) return nullptr;
		if (!(p->left)) {
			return p->right;
		}
		p->left = remove_min(p->left);
		return balance(p);
	}

	node* do_remove(node* p, int k) {
		if (!p) {
			return nullptr;
		}

		if (k < p->key) {
			p->left = do_remove(p->left, k);
		} else if (k > p->key) {
			p->right = do_remove(p->right, k);
		} else {
			node* L = p->left;
			node* R = p->right;
			delete p;
			if (!R) {
				return L;
			}
			if (!L) {
				return R;
			}

			node* minimum = find_min(R);
			minimum->right = remove_min(R);
			minimum->left = L;
			return balance(minimum);
		}
		return balance(p);
	}

	node* remove(node *p, int k) {
		if (find(p, k)) {
			return do_remove(p, k);
		} else {
			return p;
		}
	}

	void print(node* p) {
		if (!p) return;
		cout << p->key << ' ';
		print(p->left);
		print(p->right);
	}

public:
	AvlTree() {
		node* root = new node(INF);
	}
	// ~AvlTree() { 
	// 	delete root;
	// }

	void insert(int x) {
		root = insert(root, x);
	}
	void remove(int x) {
		root = remove(root, x);
	}
	bool find(int x) {
		return find(root, x);
	}
	int find_next(int x) {
		return find_next(root, x);
	}
	int find_prev(int x) {
		return find_prev(root, x);
	}
};
int solve(int test) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);

	string s;
	int x;
	AvlTree mytree;
	
	while (cin >> s) {
		cin >> x;

		if (s[0] == 'i') { // insert x
			mytree.insert(x);
		} else if (s[0] == 'd') { // delete x
			mytree.remove(x);
		} else if (s[0] == 'e') { // exists x
			cout << (mytree.find(x) ? "true\n" : "false\n");
		} else if (s[0] == 'n') { // next x
			int tmp = mytree.find_next(x);
			if (tmp == INF) {
				cout << "none\n"; 
			} else {
				cout << tmp << '\n';
			}
		} else if (s[0] == 'p') { // prev x
			int tmp = mytree.find_prev(x);
			if (tmp == INF) {
				cout << "none\n"; 
			} else {
				cout << tmp << '\n';
			}
		}
	}


	return 0;
}

int main() {
	solve(10);
	return 0;
}
