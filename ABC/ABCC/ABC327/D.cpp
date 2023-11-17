#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> m;
vector<ll> color(2000000);
bool done = false;
void dfs(ll a,bool col){
    color[a]=col;
    for(ll i:m[a]){
        if(color[i]!=-1&&color[i]==col){
            if(!done)cout << "No" << endl;
            done = true;
            return;
        }else{
            if(color[i]==-1){
                dfs(i,!col);
            }
        }
    }
}
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M];
    rep(i,N){
        color[i]=-1;
    }
    rep(i,M)cin >> A[i];
    rep(i,M)cin >> B[i];
    rep(i,M){
        m[A[i]-1].push_back(B[i]-1);
        m[B[i]-1].push_back(A[i]-1);
    }
    rep(i,N){
        if(color[i]==-1){
            dfs(i,0);
        }
    }
    if(!done)cout << "Yes" << endl;
}