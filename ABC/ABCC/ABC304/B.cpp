#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll cache = N;
    ll counter = 0;
    if(N < 1000){
        cout << N << endl;
        return 0;
    }
    while(cache >= 10){
        cache /= 10;
        counter++;
    }
    ll k = pow(10,counter-2);
    N -= N%k;
    cout << N << endl;
}