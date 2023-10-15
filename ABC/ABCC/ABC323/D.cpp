#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P SC[N];
    map<ll,ll> sizeC;
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    rep(i,N){
        cin >> SC[i].first >> SC[i].second;
        sizeC[SC[i].first] = SC[i].second;
        Q.push(SC[i].first);
    }
    ll ans = 0;
    while(!Q.empty()){
        ll cur = Q.top();
        Q.pop();
        if(sizeC[cur] == 0)continue;
        ll newS = sizeC[cur];
        ans += sizeC[cur]%2;
        sizeC[cur] = 0;
        if(newS<2)continue;
        newS/=2;
        cur*=2;
        while(newS != 0){
            if(sizeC.find(cur)!=sizeC.end()){
                newS += sizeC[cur];
                sizeC[cur] = 0;
            }
            if(newS%2 == 1){
                ans+=1;
            }
            newS/=2;
            cur*=2;
        }
        //ans += 1;
        //cout << ans << endl;
    }
    cout << ans << endl;
}