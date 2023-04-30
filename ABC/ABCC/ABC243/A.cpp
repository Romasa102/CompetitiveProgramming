#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,A,B,C;
    ll v;
    cin >> N >> A >> B >> C;
    while(N > 0){
        v = 0;
        N -= A;
        if(N < 0){
            break;
        }
        v = 1;
        N -= B;
        if(N < 0){
            break;
        }
        v = 2;
        N -= C;
        if(N < 0){
            break;
        }
    }
    if(v == 0){
        cout << "F" << endl;
    }else if(v == 1){
        cout << "M" << endl;
    }else if(v == 2){
        cout << "T" << endl;
    }
}