#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    vector<ll> O;
    vector<ll> E;
    rep(i,N){
        cin >> A[i];
        if(A[i]%2 == 0){
            E.push_back(A[i]);
        }else{
            O.push_back(A[i]);
        }
    }
    if(E.size() <= 1 && O.size() <= 1){
        cout << -1 << endl;
        return 0;
    }
    sort(O.begin(),O.end());
    sort(E.begin(),E.end());
    if(E.size() <= 1){
        cout << O[O.size()-1]+O[O.size()-2] << endl;
        return 0;
    }
    if(O.size() <= 1){
        cout << E[E.size()-1]+E[E.size()-2] << endl;
        return 0;
    }
    if(O[O.size()-1]+O[O.size()-2] >= E[E.size()-1]+E[E.size()-2]){
        cout << O[O.size()-1]+O[O.size()-2] << endl;
    }else{
        cout << E[E.size()-1]+E[E.size()-2] << endl;
    }
}