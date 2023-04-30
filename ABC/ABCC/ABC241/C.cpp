#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rep1(i,n) for(ll i = (n) - 1; i >= 0; --i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N; 
    cin >> N;
    if(N < 6){
        cout << "No" << endl;
        return 0;
    }
    string S[N];
    rep(i,N){
        cin >> S[i];
    }
    bool M[N][N];
    rep(i,N){
        rep(j,N){
            if(S[i][j] == '#'){
                M[i][j] = true;
            }else{
                M[i][j] = false;
            }
        }
    }
    rep(i,N){
        rep(j,N){
            if(M[i][j] == true){
                int count1 = 0;
                int count2 = 0;
                int count3 = 0;
                int count4 = 0;
                int count5 = 0;
                int count6 = 0;
                if(i + 4 <= N){
                    rep(k,5){
                        if(M[i + k][j]) count1++;
                    }
                }
                if(i - 3 >= 0){
                    rep(k,5){
                        if(M[i - k][j]) count4++;
                    }
                }
                if(j + 4 <= N){
                    rep(k,5){
                        if(M[i][j + k]) count2++;
                    }
                }
                
                if(j - 3 >= 0){
                    rep(k,5){
                        if(M[i][j - k]) count5++;
                    }
                }
                if(i + 4 <= N && j + 4 <= N){
                    rep(k,5){
                        if(M[i + k][j + k]) count3++;
                    }
                }
                
                if(i - 3 >= 0 && j - 3 >= 0){
                    rep(k,5){
                        if(M[i - k][j - k]) count6++;
                    }
                }
                if(i + 4 < N){
                    rep(k,6){
                        if(M[i + k][j]) count1++;
                    }
                }
                if(i - 4 >= 0){
                    rep(k,6){
                        if(M[i - k][j]) count4++;
                    }
                }
                if(j + 4 < N){
                    rep(k,6){
                        if(M[i][j + k]) count2++;
                    }
                }
                
                if(j - 4 >= 0){
                    rep(k,6){
                        if(M[i][j - k]) count5++;
                    }
                }
                if(i + 4 < N && j + 4 < N){
                    rep(k,6){
                        if(M[i + k][j + k]) count3++;
                    }
                }
                
                if(i - 4 >= 0 && j - 4 >= 0){
                    rep(k,6){
                        if(M[i - k][j - k]) count6++;
                    }
                }
                if(count1 >= 4 || count2 >= 4 || count3 >= 4|| count4 >= 4 || count5 >= 4 || count6 >= 4 ){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}