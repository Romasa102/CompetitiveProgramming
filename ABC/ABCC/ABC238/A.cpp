#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    if(pow(2,N) > pow(N,2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}