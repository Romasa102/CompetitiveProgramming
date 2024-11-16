#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A[4];
    rep(i,4){
        cin >> A[i];
    }
    ll count = 0;
    rep(i,4){
        rep(j,4){
            if(i==j)continue;
            if(A[i] == A[j]){
                count ++;
            }
        }
    }
    if(count==2 || count == 6){
        cout << 1 << endl;
    }else if(count == 4) {
        cout << 2 << endl;
    }
    else if(count == 12){
            cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
}