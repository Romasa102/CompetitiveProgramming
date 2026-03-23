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
map<ll,bool> haveSeen;
vector<bool> visited;

vector<bool> ans;
map<ll,vector<ll>> mp;

vector<ll> A;    
void dfs(ll x,bool past){
    if(visited[x])return;
    visited[x]=true;
    bool flagged = false;
    if(past || (haveSeen.find(A[x])!=haveSeen.end() && haveSeen[A[x]] == true)){
        ans[x]=true;
        flagged = true;
    }else{
        ans[x]=false;
        haveSeen[A[x]]=true;
    }
    for(auto i : mp[x]){
        if(visited[i])continue;
        dfs(i,flagged);
    }
    if(!flagged)haveSeen[A[x]] = false;
    return;
}
int main(){
    ll N;
    cin >> N;
    A.resize(N);
    rep(i,N)cin >> A[i];
    ll U[N],V[N];
    rep(i,N-1){
        cin >> U[i] >> V[i];
        U[i]--;
        V[i]--;
        mp[U[i]].push_back(V[i]);
        mp[V[i]].push_back(U[i]);
    }
    visited.resize(N,false);
    ans.resize(N,false);
    dfs(0,false);
    rep(i,N){
        if(ans[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}