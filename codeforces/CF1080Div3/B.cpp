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
int main(){
    ll t;cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i,n)cin >> a[i];
        bool work = true;
        vector<bool> visited(n,false);
        repp(i,1,n){
            if(visited[i-1])continue;
            vector<ll> idx;
            ll k = i;
            while(k <= n){
                idx.push_back(k-1);
                visited[k-1]=true;
                k *= 2;
            }
            vector<ll> cur, target;
            for(auto id : idx){
                cur.push_back(a[id]);
                target.push_back(id+1);
            }
            sort(cur.begin(), cur.end());
            sort(target.begin(), target.end());
            if(cur != target) work = false;
        }
        if(work){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}