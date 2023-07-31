#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<P> O(N);
    rep(i,N){
        ll a,b;
        cin >> a  >> b;
        O[i].first = a;
        O[i].second = b;
    }
    sort(O.rbegin(),O.rend());
    queue<P> Q;
    ll sum = 0;
    rep(i,N){
        sum += O[i].second;
        Q.push(O[i]);
    }
    if(sum < K){
        cout << 1 << endl;
        return 0;
    }
    ll oldA = Q.front().first+1;
    ll old = 0;
    ll ans = 0;
    ll current = 0;
    while(ans == 0){
        current = Q.front().first;
        while(Q.empty() == false && current == Q.front().first){
            old += Q.front().second;
            Q.pop();
        }
        if(K<old){
            cout << oldA << endl;
            return 0;
        }
        oldA = Q.front().first+1;
    }
}