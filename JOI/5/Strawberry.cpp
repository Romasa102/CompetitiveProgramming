#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define revrep(i,n) for(ll i = n-1; i >= 0; --i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P AT[N];
    rep(i,N){
        cin >> AT[i].first >> AT[i].second;
    }
    sort(AT,AT+N);
    ll Now = max(AT[N-1].first,AT[N-1].second);
    revrep(i,N-1){
        Now += AT[i+1].first - AT[i].first;
        Now = max(Now,AT[i].second);
    }
    cout << Now + AT[0].first << endl;
}