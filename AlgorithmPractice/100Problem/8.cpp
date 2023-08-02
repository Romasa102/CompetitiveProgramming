#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> Enter(N);
    vector<ll> Exit(N);
    rep(i,N){
        cin >> Enter[i] >> Exit[i];
    }
    sort(Enter.begin(),Enter.end());
    sort(Exit.begin(),Exit.end());
    ll FinalEnter;
    ll FinalExit;
    if(N%2==0){
        FinalEnter = (Enter[N/2-1]+Enter[N/2])/2;
        FinalExit = (Exit[N/2-1]+Exit[N/2])/2;
    }else{
        FinalEnter = Enter[(N+1)/2-1];
        FinalExit = Exit[(N+1)/2-1];
    }
    ll ans = 0;
    rep(i,N){
        ans += abs(Enter[i] - FinalEnter);
        ans += abs(Exit[i] - Enter[i]);
        ans += abs(Exit[i]- FinalExit);
    }
    cout << ans << endl;
}