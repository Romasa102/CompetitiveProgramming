#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,ll> cost;
ll dfs(ll N){
    if(N == 1)return 0;
    if(cost.find(N)!=cost.end())return cost[N];
    ll res = N;
    if(N%2==0){
        res += dfs(N/2)*2;
    }else{
        res += dfs(N/2) + dfs(N/2+1);
    }
    return cost[N] = res;
}
int main(){
    ll N;cin >> N;
    queue<ll> num;
    num.push(N);
    cout << dfs(N) << endl;
}