#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    ll D[N];
    priority_queue<ll> pqr;
    priority_queue<ll,vector<ll>,greater<ll>> pql;
    rep(i,N){
        cin >> D[i];
        D[i] = D[i]%(A+B);
        pqr.push(D[i]);
        pql.push(D[i]);
    }
    rep(i,N){
        ll len = pqr.top()-pql.top();
        pqr.push(pql.top() + A+B);
        pql.pop();
        if(len < A){
            cout <<  "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}