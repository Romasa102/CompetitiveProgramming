#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
queue<ll> ans;
vector<ll> parents;//people in back
void dfs(ll a){
    ans.push(a);
    if(parents[a] == 1LL<<32)return;
    dfs(parents[a]);
}
int main(){
    ll N;cin >> N;
    parents.resize(N,1LL<<32);
    ll A[N];rep(i,N)cin >> A[i];
    ll mainP =0 ;
    rep(i,N){
        if(A[i] == -1){
            mainP = i;
            continue;
        }
        parents[A[i]-1] = i;
    }
    dfs(mainP);
    while(!ans.empty()){
        cout << ans.front()+1 << " ";
        ans.pop();
    }cout << endl;
}