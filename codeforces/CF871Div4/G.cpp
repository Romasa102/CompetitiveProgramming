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
#define sz(x) (int)(x).size()

template<class T>
struct SubMatrix {
        vector<vector<T>> p;
        SubMatrix(vector<vector<T>>& v) {
                int R = sz(v), C = sz(v[0]);
                p.assign(R+1, vector<T>(C+1));
                repp(r,0,R) repp(c,0,C)
                        p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
        }
        T sum(int u, int l, int d, int r) {
                return p[d][r] - p[d][l] - p[u][r] + p[u][l];
        }
};
int main(){
    vector<vector<ll>> pyr(2023,vector<ll>(2023));
    ll num = 1;
    map<ll,P> pos;
    rep(i,2023){
        ll x = i;
        ll y = 0;
        rep(j,i+1){
            pyr[x][y] = num*num;
            pos[num]={x,y};
            x--;y++;num++;
        }
    }
    SubMatrix<ll> sub(pyr);
    ll t;
    cin >> t;
    /*
    rep(i,10){
        rep(j,10){
            cout << sub.sum(0,0,i,j) << " ";
        }cout << endl;
    }
    rep(i,10){
        cout << i << "th coordinate is : " << pos[i].first << " "  << pos[i].second << endl;
    }*/
    rep(_,t){
        ll n;cin >> n;
        cout << sub.sum(0,0,pos[n].first+1,pos[n].second+1) << endl;
    }
}