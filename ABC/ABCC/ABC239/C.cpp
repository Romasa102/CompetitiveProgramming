#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    P O,S;
    cin >> O.first >> O.second >> S.first >> S.second;
    ll xdif = abs(O.first - S.first);
    ll ydif = abs(O.second - S.second);
    if(xdif == 0){
        if(ydif == 4 || ydif == 2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(xdif == 1){
        if(ydif == 1 || ydif == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(xdif == 2){
        if(ydif == 4 || ydif == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(xdif == 3){
        if(ydif == 3 || ydif == 1){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(xdif == 4){
        if(ydif == 2 || ydif == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}