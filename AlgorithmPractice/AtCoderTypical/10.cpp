#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll C[N];
    ll P[N];
    rep(i,N)cin >> C[i] >> P[i];
    ll Q;
    cin >> Q;
    ll FIRST[N+1];
    FIRST[0]=0;
    ll SECOND[N+1];
    SECOND[0]=0;
    rep(i,N){
        FIRST[i+1]=FIRST[i];
        SECOND[i+1]=SECOND[i];
        if(C[i]==1){
            FIRST[i+1]=FIRST[i]+P[i];
        }else{
            SECOND[i+1]=SECOND[i]+P[i];
        }
    }
    rep(i,Q){
        ll L,R;
        cin >> L >> R;
        cout << FIRST[R]-FIRST[L-1] << " " << SECOND[R]-SECOND[L-1] << endl;
    }
}