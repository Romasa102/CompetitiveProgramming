#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    int N;
    cin >> N;
    ll H[N + 10];
    rep(i,N){
        cin >> H[i];
    }
    ll a,b;
    ll ans = 0;
    while(true){
        if(ans == N - 1){
            break;
        }
        a = H[ans];
        b = H[ans + 1];
        if(a < b){
            ans ++;
        }else{
            break;
        }
    }
    cout << H[ans] << endl;
}