#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    ll B[N];
    ll C[N];
    ll D[N];
    vector<ll> allN;
    rep(i,N){
        cin >> A[i];
        allN.push_back(A[i]);
    }
    rep(i,N){
        cin >> B[i];
        allN.push_back(B[i]);
    }
    rep(i,N){
        cin >> C[i];
        allN.push_back(C[i]);
    }
    rep(i,N){
        cin >> D[i];
        allN.push_back(D[i]);
    }
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);
    sort(D,D+N);
    ll ans = 1000000010;
    rep(i,allN.size()){
        ll SVal = allN[i];
        if(lower_bound(A,A+N,SVal) == A+N)continue;
        if(lower_bound(B,B+N,SVal) == B+N)continue;
        if(lower_bound(C,C+N,SVal) == C+N)continue;
        if(lower_bound(D,D+N,SVal) == D+N)continue;
        ll AVal = *lower_bound(A,A+N,SVal);
        ll BVal = *lower_bound(B,B+N,SVal);
        ll CVal = *lower_bound(C,C+N,SVal);
        ll DVal = *lower_bound(D,D+N,SVal);
        ans = min(ans,max({AVal,BVal,CVal,DVal}) - SVal);
    }
    cout << ans << endl;
}