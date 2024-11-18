#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string N;
    cin >> N;
    ll one = 0;
    ll two = 0;
    ll thr = 0;
    rep(i,6){
        if(N[i] == '1'){
            one ++;
        }
        if(N[i] == '2'){
            two++;
        }
        if(N[i] == '3'){
            thr ++;
        }
    }
    if(one == 1 && two == 2 && thr == 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}