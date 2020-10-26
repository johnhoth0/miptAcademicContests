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
// #include <multiset>
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

#pragma comment(linker, "/STACK:64000000")
#pragma GCC optimize("O3")
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
#define cotu cout
// #define endl "\n"

using namespace std;



bool mycmp(const pair <ll, ll> &a, const pair <ll, ll> &b) {
    if (a.sd == b.sd) {
        return a.ft < b.ft;
    }
    return a.sd < b.sd;
}

int solve(int test) {
    ll L;
    ll n, k;
    ll len;
    vector <ll> cell;
    vector <pair <ll, ll>> arr;
    


    cin >> L >> n >> k;
    cell.resize(n);

    len = L / k;

    ll start = INF;

    for (int i=0; i<n; ++i) {
        cin >> cell[i];
        cell[i]--;
        start = min(start, cell[i]);
    }

    /// zagluchka

    if (n == 1) {
        cout << "1 " << L << endl << L << endl;
        return 0;
    }


    for (int i=0; i<n; ++i) {
        cell[i] = (L + cell[i] - start) % L;
    }

    /// end of input and begin of solution

    int validol = 1;
    for (int i=0; i<n; ++i) {
        arr.push_back(make_pair(cell[i], cell[i]%len));
        if (i > 0) {
            if (arr[i-1].sd != arr[i].sd) validol = 0;
        }
    }

    if (validol) {
        cout << "0 " << L << endl << L << endl;
        return 0;
    }

    sort(all(arr), mycmp);

    // cerr << "arr : \n";
    // for (auto i:arr) {
    //     cout << i.ft << ' ' << i.sd << endl;
    // }
    // cout << endl;


    vector <ll> seg(k);
    vector <ll> gde(n);

    for (int i=0; i<n; ++i) {
        gde[i] = arr[i].ft/len;
        seg[gde[i]]++;
    }


    // cerr << "gde: ";
    // for (auto x:gde) cout << x << ' ';
    // cout << endl;
    // cerr << "seg: ";
    // for (auto x:seg) cout << x << ' ';
    // cout << endl;

    multiset <ll> heap;

    for (int i=0; i<k; ++i) {
        heap.insert(seg[i]);
    }

    // cerr << "heap: ";
    // for (auto x:heap) cout << x << ' ';
    // cout << endl;

    ll answer = 0; // kolichestvo
    ll result = (*heap.rbegin()) - (*heap.begin()); // F
    ll primer = 0;


    ll sdvig=0; // [0, len)



    vector <pair <ll, ll>> point;// = {mp(result, primer)};

    for (int i=0, j=0; i<n;) {
        j = i;
        // cout << "NEW SDVIG ";trace2(i, arr[i].sd);
        while (j<n && arr[j].sd == arr[i].sd) {
            /// seg v kotorom bil --

            // trace3(i, j, arr[j].sd);

            heap.erase(heap.find(seg[gde[j]]));
            seg[gde[j]]--;
            heap.insert(seg[gde[j]]);

            // cerr << "gde1: ";
            // for (auto x:gde) cout << x << ' ';
            // cout << endl;
            // cerr << "seg1: ";
            // for (auto x:seg) cout << x << ' ';
            // cout << endl;
            /// update gde

            gde[j] = (k - 1 + gde[j]) % k;

            /// seg v kotoriy popal ++

            heap.erase(heap.find(seg[gde[j]]));
            seg[gde[j]]++;
            heap.insert(seg[gde[j]]);

            // cerr << "gde2: ";
            // for (auto x:gde) cout << x << ' ';
            // cout << endl;
            // cerr << "seg2: ";
            // for (auto x:seg) cout << x << ' ';
            // cout << endl;

            // cerr << "heap: ";
            // for (auto x:heap) cout << x << ' ';
            // cout << endl;

            j++;
        }

        ll newresult = (*heap.rbegin()) - (*heap.begin());

        // trace2(i, newresult);

        result = min(result, newresult);

        /// TODO update answer
        point.pb(mp(newresult, arr[i].sd));


        if (i <= j) {
            i = j;
        }  else {
            i++;
        }

    }




    answer = 0;
    point.pb(point[0]);
    for (int i=0; i<sz(point)-1; ++i) {
        // trace2(point[i].ft, point[i].sd);
        if (point[i].ft == result) {
            primer = point[i].sd;
            answer += (len + point[i+1].sd - point[i].sd) % len;
            // trace1((len + point[i+1].sd - point[i].sd) % len);
        }
    }



    /// answers output

    cout << result << ' ' << answer * k << endl << ((primer + start) % L) + 1 << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    // int q;
    // cin >> q;
    // while (q--) {
        solve(179);
    // }
    return 0;
}