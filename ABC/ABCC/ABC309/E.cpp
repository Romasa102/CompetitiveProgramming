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
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll INF = 5000000;

vector<ll> parent(INF);
vector<vector<ll>> children(INF);
set<ll> INSOK;
vector<ll> insurance(INF);
void setNum(ll current){
    if(insurance[current] != -1){
        INSOK.insert(current);
    }
    rep(i,children[current].size()){
        if(children[current][i] == current) continue;
        insurance[children[current][i]] = max(insurance[children[current][i]], insurance[current]-1);
        setNum(children[current][i]);
    }
}
int main(){
    ll N,M;
    cin >> N >> M;
    rep(i,N-1){
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i+1);
    }
    rep(i,N){
        insurance[i] = -1;
    }
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--;
        insurance[a] = max(insurance[a],b);
    }
    setNum(0);
    cout << INSOK.size() << endl;
}