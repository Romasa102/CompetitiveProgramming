#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,P;
    cin >> N >> P;
    vector<ll> h(N+1);
    h[0] = 0;
    repp(i,1,N)cin >> h[i];
    map<ll,ll> cum;
    ll currentCumulativeSum = 1;
    ll currentChange = 0;
    repp(i,1,N){
        currentCumulativeSum+=currentChange;
        if(cum.find(i) != cum.end()){
            currentCumulativeSum+=cum[i];
        }
        ll end = upper_bound(h.begin(),h.end(),h[i-1]+P)-h.begin();
        cout << end << " ";
        cum[i+2] += currentCumulativeSum;
        cum[end] -= currentCumulativeSum;
        cout << currentCumulativeSum << endl;
    }
    //cout << currentCumulativeSum << endl;
}