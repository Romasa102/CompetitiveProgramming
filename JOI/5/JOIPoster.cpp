#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll K;
    cin >> N >> K;
    while(N>=0){
        if(N == 0){
            cout << 'J';
            break;
        }
        if(K>pow(2,N-1)){
            rep(i,pow(2,N-1)){
                cout << 'I';
            }
        }else{
            rep(i,pow(2,N-1)){
                cout << 'J';
            }
            rep(i,pow(2,N-1)){
                cout << 'O';
            }
            break;
        }
        K-=pow(2,N-1);
        N--;
    }
    cout << endl;
}