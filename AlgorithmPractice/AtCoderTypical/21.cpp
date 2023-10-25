#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> connection;
map<ll,vector<ll>> Rconnection;
ll N,M;
bool searched[110000];
ll NoMore[110000];
ll cur = 0;
ll dfs(ll a){
    for(ll i:connection[a]){
        if(!searched[i]){
            dfs(i);
        }
    }
    NoMore[a]=cur;
    cur++;
}
int main(){
    cin >> N >> M;
    ll A[M],B[M];
    rep(i,M){
        cin >> A[i] >> B[i];
        connection[A[i]].push_back(B[i]);
        Rconnection[B[i]].push_back(A[i]);
    }

}