#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll JC[N];
    ll OC[N];
    ll IC[N];
    map<ll,ll> Jpos;
    map<ll,ll> Opos;
    map<ll,ll> Ipos;
    rep(i,N){
        JC[i] = 0;
        OC[i] = 0;
        IC[i] = 0;
    }
    rep(i,N){
        if(i!=0){
            JC[i] = JC[i-1];
            OC[i] = OC[i-1];
            IC[i] = IC[i-1];
        }
        if(S[i] == 'J'){
            Jpos[JC[i]]=i;
            JC[i]++;
        }
        if(S[i] == 'O'){
            Opos[OC[i]]=i;
            OC[i]++;
        }
        if(S[i] == 'I'){
            Ipos[IC[i]]=i;
            IC[i]++;
        }
    }
    ll ans = 1LL<<50;
    rep(i,Jpos.size()){
        ll startPos = Jpos[i];
        if(i+K-1>=Jpos.size())break;
        ll lastJ = Jpos[i+K-1];
        ll firstOC = OC[lastJ];
        if(firstOC+K-1 >= Opos.size())break;
        ll lastO = Opos[firstOC+K-1];
        ll firstIC = IC[lastO];
        if(firstIC+K-1>=Ipos.size())break;
        ll lastI = Ipos[firstIC+K-1];
        ans = min(ans,lastI-startPos+1-3*K);
    }
    if(ans == 1LL<<50){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}