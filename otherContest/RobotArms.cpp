#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P XL[N];
    rep(i,N)cin >> XL[i].first >> XL[i].second;
    P SE[N];
    rep(i,N){
        SE[i].first=XL[i].first+XL[i].second;
        SE[i].second=XL[i].first-XL[i].second;
    }
    sort(SE,SE+N);
    ll counter = 1;
    ll latest = SE[0].first;
    repp(i,1,N){
        if(SE[i].second>=latest){
            latest=SE[i].first;
            counter++;
        }
    }
    cout << counter << endl;
}