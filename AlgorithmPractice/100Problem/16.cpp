#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> Pn(N);
    vector<ll> Q(N);
    vector<ll> num(N);
    rep(i,N){
        num[i] = i+1;
        cin >> Pn[i];
    }
    rep(i,N){
        cin >> Q[i];
    }
    ll counterP = 0;
    ll counterQ = 0;
    ll counter = 0;
    do{
        bool sameToP = true;
        bool sameToQ = true;
        rep(i,N){
            if(num[i] != Pn[i]){
                sameToP = false;
            }
            if(num[i] != Q[i]){
                sameToQ = false;
            }
        }
        if(sameToP)counterP = counter;
        if(sameToQ)counterQ = counter;
        counter++;
    }while(next_permutation(num.begin(),num.end()));
    cout << abs(counterP - counterQ) << endl;
}