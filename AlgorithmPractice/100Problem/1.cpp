#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i <= (n); ++i)
using P = pair<ll,ll>;
int main(){
    while(true){
        ll N,X;
        cin >> N >> X;
        if(N==0&&X==0)break;
        ll counter = 0;
        rep(i,1,N){
            if(i>=N-1)continue;
            rep(j,i+1,N){
                if(j>=N)continue;
                rep(k,j+1,N){
                    if(i+j+k==X)counter++;
                }
            }
        }cout << counter << endl;
    }
}