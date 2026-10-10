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
vector<ll> visited;
map<ll,vector<ll>> connection;
ll numberOfCycle = 0;
vector<ll> parents;

struct UF {
        vector<ll> e;
        UF(int n) : e(n, -1) {}
        bool sameSet(int a, int b) { return find(a) == find(b); }
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
        bool join(int a, int b) {
                a = find(a), b = find(b);
                if (a == b) return false;
                if (e[a] > e[b]) swap(a, b);
                e[a] += e[b]; e[b] = a;
                return true;
        }
};

UF uf(1);

void dfs(ll x, ll origin, ll n = 1){
    bool moved = false;
    for(int i : connection[x]){
        if(i == origin && n>2){
            numberOfCycle++;
            return;
        }
        if(!visited[i]){
            uf.join(i,x);
            moved = true;
            visited[i]=true;
            dfs(i,origin,n+1);
        }
    }
}
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n;
        cin >> n;

        numberOfCycle = 0;
        connection.clear();
        visited.assign(n,false);
        ll a[n];
        rep(i,n){
            cin >> a[i];
            a[i]--;
            connection[i].push_back(a[i]);
            connection[a[i]].push_back(i);
        }
        UF ufo(n);
        uf = ufo;
        rep(i,n){
            if(!visited[i]){
                visited[i] = true;
                dfs(i,i);
            }
        }
        set<ll> numberOfEdge;
        rep(i,n){
            numberOfEdge.insert(uf.find(i));
        }
        //cout << "numCycle = " << numberOfCycle << " ; numberEdge = " << numberOfEdge.size() << endl;
        cout << numberOfCycle + (bool)(numberOfEdge.size()-numberOfCycle) << " " << numberOfEdge.size() << endl;
    }
}