#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    bool O[N][N];
    rep(i,N){
        rep(j,N){
            O[i][j] = false;
        }
    }
    ll one,two = 0;
    rep(i,M){
        cin >> one >> two;
        O[one][two] = true;
        O[two][one] = true;
    }
    ll counter = 0;
    for(int i = 0;i < N-2;i++){
        for(int j = i+1;j<N-1;j++){
            for(int k = j+1;k<N;k++){
                if(O[i][j]&&O[j][k]&&O[i][k]){
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
}