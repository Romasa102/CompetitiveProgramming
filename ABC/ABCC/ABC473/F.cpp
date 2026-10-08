#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
const ll INF = 1LL << 60;

class SegTree {
    int N;
    vector<ll> Min, Lazy;

    // index 番目のノードについて遅延評価を行う
    void Eval(int index, int l, int r) {
        if (Lazy[index] == 0) return;
        Min[index] += Lazy[index];
        if (r - l > 1) {                     // 最下段でないなら子に伝播
            Lazy[2 * index + 1] += Lazy[index];
            Lazy[2 * index + 2] += Lazy[index];
        }
        Lazy[index] = 0;
    }

    void Add(int a, int b, ll value, int index, int left, int right) {
        Eval(index, left, right);
        if (b <= left || right <= a) return;
        if (a <= left && right <= b) {
            Lazy[index] += value;
            Eval(index, left, right);
        } else {
            int mid = (left + right) / 2;
            Add(a, b, value, 2 * index + 1, left, mid);
            Add(a, b, value, 2 * index + 2, mid, right);
            Min[index] = min(Min[2 * index + 1], Min[2 * index + 2]);
        }
    }

    ll GetMin(int a, int b, int index, int left, int right) {
        if (a >= right || b <= left) return INF;
        Eval(index, left, right);
        if (a <= left && right <= b) return Min[index];
        int mid = (left + right) / 2;
        return min(GetMin(a, b, 2 * index + 1, left, mid),
                   GetMin(a, b, 2 * index + 2, mid, right));
    }

public:
    SegTree(int n, const vector<ll>& values) {
        N = 1;
        while (N < n) N *= 2;
        Min.assign(2 * N, INF);
        Lazy.assign(2 * N, 0);
        for (int i = 0; i < n; i++) Min[N - 1 + i] = values[i];
        for (int i = N - 2; i >= 0; i--)
            Min[i] = min(Min[2 * i + 1], Min[2 * i + 2]);
    }

    void Add(int a, int b, ll x) { Add(a, b, x, 0, 0, N); }
    ll GetMin(int a, int b) { return GetMin(a, b, 0, 0, N); }
    ll Get(int i) { return GetMin(i, i + 1); }
};


int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> val(N,0);
    if(S[0] == 'A'){
        val[0] = 1;
    }else{
        val[0] = -1;
    }
    repp(i,1,N){
        if(S[i] == 'A'){
            val[i]=val[i-1]+1;
        }else{
            val[i]=val[i-1]-1;
        }
    }
    SegTree seg(N,val);
    ll Q;
    cin >> Q;
    rep(_,Q){
        ll task;
        cin >> task;
        if(task == 1){ //change ith to c
            ll i; char c;
            cin >> i >> c; i--;
            if(S[i] == c)continue;
            if(c == 'A'){
                S[i] = 'A';
                seg.Add(i,N-1,2);
            }else{
                S[i] = 'B';
                seg.Add(i,N-1,-2);
            }
        }else{
            ll l,r;
            cin >> l >> r; l--;r;
            ll ans = seg.GetMin(l,r);
            if(S[l] == 'A'){
                ans -= (seg.Get(l)-1);
            }else{
                ans -= (seg.Get(l)+1);
            }
            if(ans < 0){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }
}