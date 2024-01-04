#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    ll N;cin >> N;
    ll a[N],t[N];rep(i,N)cin >> a[i] >> t[i];
    priority_queue<ll,vector<ll>,greater<ll>> waiting;//seniority
    priority_queue<P,vector<P>,greater<P>> NArvd;//time, seniority
    rep(i,N)NArvd.push({a[i],i});
    ll cur = 0;
    ll finishT[N];
    while(!NArvd.empty()||!waiting.empty()){
        //current time is when the seat is open;
        //if the waitlist is empty we have to fill some.
        //or else just get the people who are supposed to arrive.
        while(!NArvd.empty()&&NArvd.top().first<=cur){
            waiting.push(NArvd.top().second);
            NArvd.pop();
        }
        if(waiting.empty()){
            cur = NArvd.top().first;
            while(!NArvd.empty()&&NArvd.top().first<=cur){
                waiting.push(NArvd.top().second);
                NArvd.pop();
            }
        }
        //get the people on the top of the waitlist and add t[i] to the current;
        cur+=t[waiting.top()];
        finishT[waiting.top()]=cur;
        waiting.pop();
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans,finishT[i]-a[i]-t[i]);
    }
    cout << ans << endl;
}