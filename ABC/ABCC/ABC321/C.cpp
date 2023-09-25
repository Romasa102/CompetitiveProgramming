#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K;
    cin >> K;
    vector<ll> alltto;
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    rep(i,10){
        Q.push(i);
        alltto.push_back(i);
    }
    while(!Q.empty()){
        ll now = Q.top();
        Q.pop();
        ll O = now;
        ll digit = 0;
        while(O > 9){
            O/=10;
            digit++;
        }
        cout<< " highest digits  of " << now  << " is"  << O  << " and the digit is " << digit<< endl;
        digit++;
        ll ans = 0;
        repp(i,O+1,10){
            ans = i*pow(10,digit) + now;
            Q.push(ans);
            alltto.push_back(ans);
        }
    }
    sort(alltto.begin(),alltto.end());
    rep(i,alltto.size()){
        cout << alltto[i] << " " << endl;
    }
    cout << alltto[K] << endl;
}