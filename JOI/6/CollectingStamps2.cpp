#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll JCount[N+1];
    ll ICount[N+1];
    JCount[0] = 0;
    ICount[0] = 0;
    ll maxI = 0;
    ll maxOS = 0;
    ll baseA = 0;
    repp(i,1,N+1){
        if(S[i-1] =='J'){
            JCount[i] = JCount[i-1]+1;
        }else{
            JCount[i] = JCount[i-1];
        }
        if(S[i-1] == 'I'){
            ICount[i] = ICount[i-1]+1;
        }else{
            ICount[i] = ICount[i-1];
        }
    }
    maxI = ICount[N];
    rep(i,N+1){
        ICount[i] = maxI - ICount[i];
    }
    repp(i,1,N+1){
        if(S[i-1] == 'O'){
            baseA += ICount[i]*JCount[i];
        }
        maxOS = max(maxOS,ICount[i]*JCount[i]);
    }
    ll ans = baseA + maxOS;
    baseA = 0;
    repp(i,1,N+1){
        if(S[i-1] == 'O'){
            baseA += ICount[i] * (JCount[i]+1);
        }
    }
    ans = max(ans,baseA);
    baseA = 0;
    repp(i,1,N+1){
        if(S[i-1] == 'O'){
            baseA += (ICount[i]+1) * JCount[i];
        }
    }
    ans = max(ans,baseA);
    cout << ans << endl;
}