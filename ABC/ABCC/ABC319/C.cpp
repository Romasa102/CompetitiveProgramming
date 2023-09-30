#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M[9];
    rep(i,9){
        cin >> M[i];
    }
    vector<ll> Num = {1,2,3,4,5,6,7,8,9};
    double ans = 0;
    do{
        vector<ll> row1,row2,row3;
        vector<ll> col1,col2,col3;
        vector<ll> dia1,dia2;
        rep(i,9){
            if((Num[i]-1)/3 == 0){
                row1.push_back(M[Num[i]-1]);
            }
            if((Num[i]-1)/3 == 1){
                row2.push_back(M[Num[i]-1]);
            }
            if((Num[i]-1)/3 == 2){
                row3.push_back(M[Num[i]-1]);
            }
            if(Num[i]%3 == 1){
                col1.push_back(M[Num[i]-1]);
            }
            if(Num[i]%3 == 2){
                col2.push_back(M[Num[i]-1]);
            }
            if(Num[i]%3 == 0){
                col3.push_back(M[Num[i]-1]);
            }
            if(Num[i] == 1 || Num[i] == 5 || Num[i] == 9){
                dia1.push_back(M[Num[i]-1]);
            }
            if(Num[i] == 3 || Num[i] == 5 || Num[i] == 7){
                dia2.push_back(M[Num[i]-1]);
            }
        }
        if(row1[0] == row1[1] && row1[1] != row1[2]){
            continue;
        }
        if(row2[0] == row2[1] && row2[1] != row2[2]){
            continue;
        }
        if(row3[0] == row3[1] && row3[1] != row3[2]){
            continue;
        }
        if(col1[0] == col1[1] && col1[1] != col1[2]){
            continue;
        }
        if(col2[0] == col2[1] && col2[1] != col2[2]){
            continue;
        }
        if(col3[0] == col3[1] && col3[1] != col3[2]){
            continue;
        }
        if(dia1[0] == dia1[1] && dia1[1] != dia1[2]){
            continue;
        }
        if(dia2[0] == dia2[1] && dia2[1] != dia2[2]){
            continue;
        }
        ans++;
    }while(next_permutation(Num.begin(),Num.end()));
    double all = 362880;
    cout << fixed << setprecision(10) << ans / all << endl;
}