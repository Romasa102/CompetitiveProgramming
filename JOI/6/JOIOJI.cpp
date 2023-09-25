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
    ll Jcount[N+1];
    ll Ocount[N+1];
    ll Icount[N+1];
    ll difJO[N+1];
    ll difOI[N+1];
    map<P,ll> minJOI;
    ll ans = 0;
    minJOI[{0,0}] = 0;
    Jcount[0] = 0;
    Ocount[0] = 0;
    Icount[0] = 0;
    rep(i,N){
        if(S[i] == 'J') Jcount[i+1] = Jcount[i] + 1;
        else Jcount[i+1] = Jcount[i];
        if(S[i] == 'O') Ocount[i+1] = Ocount[i] + 1;
        else Ocount[i+1] = Ocount[i];
        if(S[i] == 'I') Icount[i+1] = Icount[i] + 1;
        else Icount[i+1] = Icount[i];
        difJO[i+1] = Jcount[i+1]-Ocount[i+1];
        difOI[i+1] = Ocount[i+1]-Icount[i+1];

        if(minJOI.find({difJO[i+1],difOI[i+1]}) == minJOI.end()){
            minJOI[{difJO[i+1],difOI[i+1]}] = i+1;
        }else{
            ans = max(ans,i+1-minJOI[{difJO[i+1],difOI[i+1]}]);
        }
    }
    cout << ans << endl;
}