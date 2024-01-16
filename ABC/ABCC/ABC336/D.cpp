#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    ll A[N];rep(i,N)cin >> A[i];
    vector<ll> preS(N+1,0);
    ll Spos = 0;
    repp(i,1,N){
        if(i-Spos+1 <= A[i]){
            preS[i] = preS[i-1]+1;
        }else{
            Spos = i-A[i]-1;
            preS[i] = A[i]-1;
        }
    }
    vector<ll> rpreS(N+1,0);
    ll rSpos = N-1;
    for(ll i = N-2; i >= 1; i--){
        if(rSpos-i+1<=A[i]){
            rpreS[i] = rpreS[i+1]+1;
        }else{
            rSpos = i+A[i]-1;
            rpreS[i] = A[i]-1;
        }
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans,min(preS[i],rpreS[i])+1);
    }cout << ans << endl;
}