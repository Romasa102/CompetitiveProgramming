#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A[5];
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    ll sameToA = 0;
    ll difNum;
    ll difNumsame = 0;
    rep(i,5){
        if(A[i] == A[0]){
            sameToA++;
        }else{
            difNum = A[i]; 
        }
    }
    rep(i,5){
        if(A[i] == difNum){
            difNumsame++;
        }
    }
    if(sameToA == 3&&difNumsame == 2){
        cout << "Yes" << endl;
        return 0;
    }else if(sameToA == 2 && difNumsame == 3){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}