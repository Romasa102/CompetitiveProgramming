#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    bool M[10][10];
    string S;
    rep(i,10){
        cin >> S;
        rep(j,10){
            if(S[j] == '#'){
                M[i][j] = true;
            }else{
                M[i][j] = false;
            }
        }
    }
    rep(i,10){
        rep(j,10){
            cout << M[i][j];
        }
        cout << endl;
    }
    ll A,B,C,D;
    bool flg = false;
    rep(i,10){
        rep(j,10){
            if(M[i][j] == true){
                A = i;
                C = j;
                break;
                flg = true;
            }
        }
        if(flg == true){
            break;
        }
    }
    flg = false;
    rep(i,10){
        rep(j,10){
            if(M[10-i][10-j] = true){
                B = i;
                D = j;
                break;
                flg = true;
            }
        }
        if(flg ==  true){
            break;
        }
    }
    cout << A  <<  " "<< B << endl << C << " " << D;
}