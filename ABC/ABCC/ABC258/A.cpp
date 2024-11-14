#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K;
    cin >> K;
    if(K == 0){
        cout << "21:00" << endl;
        return 0;
    }
    if(K==60){
        cout << "22:00" << endl;
        return 0;
    }
    if(K < 60){
        cout << "21:" << K;
    }else{
        K-=60;
        if(K < 10){
            cout << "22:0" << K;
        }else{
            cout << "22:" << K;
        }

    }
}