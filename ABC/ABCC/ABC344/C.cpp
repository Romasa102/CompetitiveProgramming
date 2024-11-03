#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];rep(i,N)cin >> A[i];
    ll M;
    cin >> M;
    ll B[M];rep(i,M)cin >> B[i];
    ll L;
    cin >> L;
    ll C[L];rep(i,L)cin >> C[i];
    ll Q;
    cin >> Q;
    ll X[Q];rep(i,Q)cin >> X[i];

    map<ll,bool> ans;
    rep(i,N){
        rep(j,M){
            rep(k,L){
                ans[A[i]+B[j]+C[k]] = true;
            }
        }
    }
    rep(i,Q){
        if(ans.find(X[i]) != ans.end()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}