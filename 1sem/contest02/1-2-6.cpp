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


// void Heapify1(vector<int>& A, int length, int i) {
//     int l = 2 * i + 1;
//     int r = 2 * i + 2;
//     int largest = i;
//     if (l < length && A[l] > A[largest])
//         largest = l;
//     if (r < length && A[r] > A[largest])
//         largest = r;
//     if (largest != i) {
//         swap(A[i], A[largest]);
//         Heapify1(A, length, largest);
//     }
// }

// void Build_Heap1(vector<int>& A, int length) {
//     for (int i = length / 2 - 1; i != (int)(-1); i--)
//         Heapify1(A, length, i);
// }

// void Heapsort1(vector<int>& A) {
//     Build_Heap1(A, A.size());
//     for (int i = A.size() - 1; i > 0; i--) {
//         swap(A[0], A[i]);
//         Heapify1(A, i, 0);
//     }
// }

// void Heap_Increase_Key1(vector<int>& A, int length, int i, int key) {
//     if (key < A[i])
//             return;
//     A[i] = key;
//     while (i > 0 && A[(i-1)/2] < A[i]) {
//         swap(A[(i-1)/2], A[i]);
//         i = (i-1)/2;
//     }
// }

// void Heap_Insert1(vector<int>& A, int length, int key) {
//     length++;
//     if (length > A.size())
//         A.resize(length);
//     Heap_Increase_Key1(A, length, length - 1, key);
// }

// int Heap_Extract1(vector<int>& A, int length) {
//     if (length == 0)
//         return -1;
//     int max_element = A[0];
//     A[0] = A[length - 1];
//     length--;
//     Heapify1(A, length, 0);
//     return max_element;
// }

// /////////////////////////////


// void Heapify2(vector<int>& A, int length, int i) {
//     int l = 2 * i + 1;
//     int r = 2 * i + 2;
//     int largest = i;
//     if (l < length && A[l] < A[largest])
//         largest = l;
//     if (r < length && A[r] < A[largest])
//         largest = r;
//     if (largest != i) {
//         swap(A[i], A[largest]);
//         Heapify2(A, length, largest);
//     }
// }

// void Build_Heap2(vector<int>& A, int length) {
//     for (int i = length / 2 - 1; i != (int)(-1); i--)
//         Heapify2(A, length, i);
// }

// void Heapsort2(vector<int>& A) {
//     Build_Heap2(A, A.size());
//     for (int i = A.size() - 1; i > 0; i--) {
//         swap(A[0], A[i]);
//         Heapify2(A, i, 0);
//     }
// }

// void Heap_Increase_Key2(vector<int>& A, int length, int i, int key) {
//     if (key > A[i])
//             return;
//     A[i] = key;
//     while (i > 0 && A[(i-1)/2] > A[i]) {
//         swap(A[(i-1)/2], A[i]);
//         i = (i-1)/2;
//     }
// }

// void Heap_Insert2(vector<int>& A, int length, int key) {
//     length++;
//     if (length > A.size())
//         A.resize(length);
//     Heap_Increase_Key2(A, length, length - 1, key);
// }

// int Heap_Extract2(vector<int>& A, int length) {
//     if (length == 0)
//         return -1;
//     int min_element = A[0];
//     A[0] = A[length - 1];
//     length--;
//     Heapify2(A, length, 0);
//     return min_element;
// }
// //////////////////

ll jojo, koichi=jojo;
int n, k;
ll len=-1;
vector <ll> a;
vector <pair <ll, int>> theworld;
// vector <int> avdol;

vector <pair <ll, ll>> hamon;

ll dist_anticlock(ll p1, ll p2) {
    if (p1 <= p2) {
        return p2 - p1;
    } else {
        return jojo - (p1 - p2);
    }
}

ll dist_clock(ll p1, ll p2) {
    if (p1 < p2) {
        return jojo - abs(p1 - p2);
    } else {
        return abs(p2 - p1);
    }
}


ll well_good(ll p, ll move) {
    ll lol = p % len;
    ll kek = (koichi+move) % len;
    if (lol <= kek) return kek - lol;
    else return len - (lol - kek);
}


ll well_tenet(ll p, ll move) {
    ll lol = p % len;
    ll kek = (koichi+move) % len;
    if (lol >= kek) return lol - kek;
    else return len - (kek - lol);
}

bool cmpwell(const pair <ll, int> &a, const pair <ll, int> &b) {

    ll resa = well_good(a.ft, 0);
    ll resb = well_good(b.ft, 0);

    return (resa < resb || (resa == resb && a.ft < b.ft));
}



int solve(int test) {
    cin >> jojo;
    cin >> n >> k;
    len = jojo / k;
    a.resize(n);
    set <ll> avdol; 
    // avdol.resize(k, INF);


    vector <pair <ll, int>> jopa;
    vector <pair <ll, ll>> dovod;

    koichi = jojo;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        a[i]--;
        jopa.pb(mp((a[i])%len, i));
        jopa.pb(mp((a[i]+1)%len, i));
        koichi = min(koichi, a[i]);
        koichi = min(koichi, (a[i]+1)%jojo);
    }
    
    koichi %= len;

    sort(all(jopa));
    // jopa.erase(unique(all(jopa)), jopa.end());

    // for (int i=0; i<sz(jopa); ++i) {
    //     cout << jopa[i].ft << ' ' << jopa[i].sd << endl;
    // }
    // return 0;
    theworld.pb(jopa[0]);
    for (int i=1; i<sz(jopa); ++i) {
        if (jopa[i].ft!=jopa[i-1].ft) {
            theworld.pb(jopa[i]);
        }
    }

    sort(all(theworld), cmpwell);
    
    // avdol.insert(koichi % len);

    hamon.resize(sz(a));
    // dovod.resize(sz(theworld));


    for (int i=0; i<sz(a); ++i) {
        hamon[i] = mp(well_tenet(a[i], 0), i);
        // dovod[i] = mp(well_good(theworld[i].ft), i);
        trace3(i, a[i], hamon[i].ft);
    }

    vector <int> speedwagon(k, 0);
    vector <int> senpai(n, 0);
    // int minim=INF, maxim=-INF; 
    for (ll i=0; i<sz(a); ++i) {
        senpai[i] = (a[i]-koichi) / len;
        speedwagon[senpai[i]]++;

    }


    trace1(koichi);
    // cout << "senpai ";
    // for (int i=0; i<n; ++i) {
    //     cout << senpai[i]  << ' ';
    // }
    // cout << endl;


    multiset <int> heap;
    for  (int i:speedwagon) {
        heap.insert(i);
        // minim = min(minim, i);
        // maxim = max(maxim, i);
        cout << i << ' ';
    }
    cout << endl;
    cout << "popa" << endl;

    sort(all(hamon));


    int killdaho=(*heap.rbegin())-(*heap.begin());
    ll bitch=koichi%len;
    avdol.insert(bitch);// = killdaho;
    ll numbrew=1;


    // for (int i=0; i<sz(hamon); ++i) {
    //     cout << i << ' ' << hamon[i].ft << ' ' << hamon[i].sd << endl;
    // }
    // cout << endl << endl;

    // return 0;


    ll thehand=0;
    int lisalisa=0;
    for (int i=1; i<sz(theworld); ++i) {
        // move for well_good(theworld[i].ft)

        ll yournextline = well_good(theworld[i].ft, thehand);
        trace3(i, theworld[i].ft, yournextline);
        thehand += yournextline;
        while (thehand > hamon[lisalisa%sz(hamon)].ft) {
            trace1(thehand);

            cout << "senpai ";
            for (int i=0; i<n; ++i) {
                cout << senpai[i]  << ' ';
            }
            cout << endl;



            ll whothefuckitis = hamon[lisalisa%sz(hamon)].sd;
            trace2(whothefuckitis, theworld[whothefuckitis].sd);
            cout << "find for " << speedwagon[senpai[theworld[whothefuckitis].sd]] << endl;
            heap.erase(heap.find(speedwagon[senpai[theworld[whothefuckitis].sd]]));
            speedwagon[senpai[theworld[whothefuckitis].sd]]--;
            heap.insert(speedwagon[senpai[theworld[whothefuckitis].sd]]);

            senpai[theworld[whothefuckitis].sd] = (senpai[theworld[whothefuckitis].sd]+k-1)%k;


            cout << "look for " << speedwagon[senpai[theworld[whothefuckitis].sd]] << endl;

            heap.erase(heap.find(speedwagon[senpai[theworld[whothefuckitis].sd]]));
            speedwagon[senpai[theworld[whothefuckitis].sd]]++;
            heap.insert(speedwagon[senpai[theworld[whothefuckitis].sd]]);

            hamon[lisalisa%sz(hamon)].ft += yournextline;

            cout << "WE MOVED " << hamon[lisalisa%sz(hamon)].sd << endl;

            cout << "heap : ";
            for (int x:heap) {
                cout << x << ' ';
            }
            cout << endl;
            lisalisa++;
        }
        
        cout << "opa " << (*heap.rbegin())-(*heap.begin()) << endl;
        if (killdaho > (*heap.rbegin())-(*heap.begin())) {
            killdaho = (*heap.rbegin())-(*heap.begin());
            numbrew = 0;
            avdol.clear();
            trace1(sz(avdol));
            bitch = theworld[i].ft;
        }
        if (killdaho == (*heap.rbegin())-(*heap.begin())) {
            numbrew++;
            avdol.insert(theworld[i].ft % len);
            trace2(killdaho, theworld[i].ft);
            // = killdaho;
            // avdol[theworld[i].ft % k] = killdaho;
        }


    }



    cerr << "JOPA" << endl; ///////////////////////////////////////////////

    // ll echoes=koichi;
    // for (int i=0; i<k; ++i,echoes+=k, echoes%=jojo)
    //     theworld.pb(mp(echoes, -1));



    ///////// ASWER 
    cout << "avdol : ";
    int yesiam=sz(avdol);
    for (auto elem : avdol) {
        cout << (elem)<< ' '; 
    }
    cout << endl << endl;
    cout << killdaho << ' ' << (yesiam) * k << endl << bitch+1 << endl;

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