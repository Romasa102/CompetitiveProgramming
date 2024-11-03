#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;string S;
    cin >> N >> S;
    ll C[N];rep(i,N)cin >> C[i];
    bool iob = true;//01010101
    bool ioe=true;//10101010
    if(N%2==0){
        ioe=false;
    }
    vector<ll>costB(N+1,0);
    vector<ll>costB2(N+1,0);
    vector<ll>costl(N+1,0);
    vector<ll>costl2(N+1,0);
    rep(i,N){
        iob=!iob;
        costB[i+1]=costB[i];
        costB2[i+1]=costB2[i];
        if(S[i]-'0' != iob){
            costB[i+1]=costB[i]+C[i];
        }else{
            costB2[i+1]=costB2[i]+C[i];
        }
    }
    for(ll i = N;i>0;i--){
        ioe=!ioe;
        costl[i-1]=costl[i];
        costl2[i-1]=costl2[i];
        if(S[i-1]-'0' != ioe){
            costl[i-1]=costl[i]+C[i-1];
        }else{
            costl2[i-1]=costl2[i]+C[i-1];
        }
    }
    ll ans = 1e18;
    repp(i,1,N){
        ans = min(costB[i]+costl2[i],ans);
        ans = min(costB2[i]+costl[i],ans);
    }
    cout << ans << endl;
}