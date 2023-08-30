#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >>N;
    deque<ll> Taros;
    map<ll,bool> Taro;
    deque<ll> Hana;
    rep(i,N){
        ll A;
        cin >> A;
        Taro[A] = true;
        Taros.push_back(A);
    }
    repp(i,1,2*N+1){
        if(Taro.find(i) == Taro.end()){
            Hana.push_back(i);
        }
    }
    sort(Taros.begin(),Taros.end());
    sort(Hana.begin(),Hana.end());
    ll current = Taros.front();
    while(Taros.size() && Hana.size()){
        rep(i,N){

        }
    }
}