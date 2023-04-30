#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B,K;
    cin >> A >> B >>K;
    ll counter = 0;
    while(A<B){
        counter++;
        A*=K;
    }
    cout << counter << endl;
}