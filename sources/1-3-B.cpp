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

const int INF = 2e9 + 179, MOD = 1e9;
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



class SplayTree {
private:
	struct Node {
		int key;
		long long sum = 0;
		Node* parent;
		Node* left;
		Node* right;

		Node(int key, long long sum, Node* parent, Node* left, Node * right):
			key(key), sum(sum), left(left), right(right), parent(parent) {}
		
		~Node(){};
	};

	Node* root = nullptr;

	long long getSum(Node* node) {
		if (!node) {
			return 0;
		} else {
			return node->sum;
		}
	}
	void setParent(Node* child, Node* parent) {
		if (child) {
			child->parent = parent;
		}
	}
	void updateNode(Node* node) {
		if (!node) {
			return;
		} else {
			node->sum = node->key + getSum(node->left) + getSum(node->right);
			setParent(node->left, node);
			setParent(node->right, node);
		}
	}

	bool hasParent(Node* node) {
		if (!node || !(node->parent)) {
			return false;
		} else {
			return true;
		}
	}
	bool hasGrandParent(Node* node) {
		if (!node || !(node->parent) || !(node->parent->parent)) {
			return false;
		} else { 
			return true;
		}
	}
	bool isLeftChild(Node* node) {
		if (!node || !(node->parent)) {
			return false;
		}
		if (node->parent->left == node) {
			return true;
		}
		return false;
	}
	bool isRightChild(Node* node) {
		if (!node || !(node->parent)) {
			return false;
		}
		if (node->parent->right == node) {
			return true;
		}
		return false;
	}

	
	void rotate(Node* n) {
		if (!hasParent(n)) {
			return;
		}
		Node* parent = n->parent;
		Node* grand_parent = parent->parent;
		if (isLeftChild(n)) {
			Node* nR = n->right;
			n->right = parent;
			parent->left = nR;
		} else {
			Node* nL = n->left;
			n->left = parent;
			parent->right = nL;
		}
		updateNode(parent);
		updateNode(n);
		n->parent = grand_parent;
		if (grand_parent) {
			if (grand_parent->left == parent) {
				grand_parent->left = n;
			} else {
				grand_parent->right = n;
			}
		}
	}
	void bigRotate(Node* n) {
		if (!hasGrandParent(n)) {
			return;
		}
		if (isLeftChild(n) && isLeftChild(n->parent)) {
			rotate(n->parent);
			rotate(n);
		} else if (isRightChild(n) && isRightChild(n->parent)) {
			rotate(n->parent);
			rotate(n);
		} else {
			rotate(n);
			rotate(n);
		}
	}
	void Splay(Node *n) {
		if (!n) {
			return;
		} else {
			while (hasParent(n)) {
				if (hasGrandParent(n)) {
					bigRotate(n);
				} else {
					rotate(n);
					break;
				}
			}
			root = n;
		}
	}

public:
	SplayTree(){}
	SplayTree(Node* root): root(root) {}
	~SplayTree(){}

	Node* find(int key) {
		Node *v = root;
		Node *last = root;
		Node *next = nullptr;
		while (v) {
			if (v->key >= key && (!next || v->key < next->key)){
				next = v;
			}
			last = v;
			if (v->key == key) {
				break;
			} else if (v->key > key) {
				v = v->left;
			} else {
				v = v->right;
			}
		}
		Splay(last);
		return next;
	}

	void split(Node*& first, Node*& second, int value) {
		if (!root) {
			first = nullptr;
			second = nullptr;
		} else {
			second = find(value);
			Splay(second);
			if (!second) {
				first = root;
			} else {
				first = second->left;
				second->left = nullptr;
				setParent(first, nullptr);
				updateNode(first);
				updateNode(second);
			}
		}
	}

	static Node* merge(Node* left, Node* right) {
		if (!left) {
			return right;
		}
		if (!right) {
			return left;
		}

		SplayTree rtree(right);
		Node *minr = right;
		while (minr->left) {
			minr = minr->left;
		}
		rtree.Splay(minr);
		minr->left = left;
		rtree.updateNode(minr);
		return minr;
	}

	void insert(int value) {
		Node *left, *right;
		split(left, right, value);
		Node *nn = nullptr;
		if (!right || right->key != value){
			nn = new Node(value, (long long)(value), nullptr, nullptr, nullptr);
		}
		root = SplayTree::merge(SplayTree::merge(left, nn), right);
	}

	long long sum(int l, int r){
		if (l > r) {
			return 0;
		} else {
			Node *left, *middle, *right;
			split(left, middle, l);
			SplayTree mt(middle);
			mt.split(middle, right, r+1);
			long long ans = 0;
			if (middle != nullptr) {
				ans += (long long)(middle->sum);
			}
			Node *nmiddle = SplayTree::merge(left, middle);
			root = SplayTree::merge(nmiddle, right);
			return ans;
		}
	}
};

int solve(int test) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cout << std::fixed << std::setprecision(20);


	SplayTree splay;
	int n;
	std::cin >> n;

	long long sum = 0;
	bool flag = false;

	for (int i = 0; i < n; ++i) {
		char cmd;
		std::cin >> cmd;
		if (cmd == '+') { // cmd = '+'
			int x;
			std::cin >> x;
			if (!flag) {
				splay.insert(x);
			} else {
				splay.insert((x + sum) % MOD);
			}

			flag = false;
			sum = 0;
		} else { // cmd = '?'
			int l, r;
			std::cin >> l >> r;
			sum = splay.sum(l, r);
			std::cout << sum << '\n';

			flag = true;
		}
	}

	return 0;
}

int main() {
	solve(179);
	return 0;
}
