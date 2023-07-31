#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    string S[N];
    rep(i,N){
        cin >> S[i];
    }
    rep(i,N){
        rep(j,M){
            if(N-i>=9&&M-j>=9){
                bool possibility = true;
                rep(h,9){
                    rep(w,9){
                        if(h<=2&&w<=2){
                            if(S[i+h][j+w] == '.'){
                                possibility = false;
                            }
                        }
                        if(h==3&&w<=3){
                            if(S[i+h][j+w] == '#'){
                                possibility = false;
                            }
                        }
                        if(w==3&&h<=3){
                            if(S[i+h][j+w] == '#'){
                                possibility = false;
                            }
                        }
                        if(h>=6&&w>=6){
                            if(S[i+h][j+w] == '.'){
                                possibility = false;
                            }
                        }
                        if(h==5&&w>=5){
                            if(S[i+h][j+w] == '#'){
                                possibility = false;
                            }
                        }
                        if(w==5&&h>=5){
                            if(S[i+h][j+w] == '#'){
                                possibility = false;
                            }
                        }
                    }
                }
                if(possibility)cout << i+1<< " " << j+1 << endl;
            }
        }
    }
}