#include <bits/stdc++.h>
using ll = long long;
#define rep(i,r,n) for(ll i = r; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
vector<ll> dfs(int before,int M,int N,vector<ll> P){
    if(N == 1){
        rep(i,0,N){
            cout << "END" << endl;
        }
    }
    rep(i,before+1,M-N+2){
        dfs(i,M,N-1,P);
    }
}
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> P;
    P.push_back(0);
    dfs(0,M,N,P);
}