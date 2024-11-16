#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin>>N;
    string S;cin>>S;
    ll cS[N];
    cS[0]=S[0]-'0';
    repp(i,1,N){
        cS[i]=cS[i-1]+(i+1)*(S[i]-'0');
    }
    vector<ll> ans(N+2);
    for (int i = N-1; i >= 0; --i) {
        ans[i+1]+=cS[i];
        ans[i]+=ans[i+1]/10;
        ans[i+1]%=10;
    }
    rep(i,N+1){
        if(i == 0 && ans[i] == 0)continue;
        cout << ans[i];
    }cout << endl;
}