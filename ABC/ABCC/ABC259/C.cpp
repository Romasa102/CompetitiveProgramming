#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S,T;
    cin >> S >> T;
    ll j = 0;
    char conNum = S[0];
    ll continuousC = 0;
    rep(i,T.size()){
        if(T[i]!=S[i-j]){
            j++;
            if(continuousC <= 1){
                cout << "No" << endl;
                return 0;
            } 
            if(T[i]!=S[i-j]){
                cout << "No" << endl;
                return 0;
            }
        }
        if(S[i-j] == conNum){
            continuousC++;
        }else{
            continuousC = 0;
            conNum = S[i-j];
        }
        cout << S[i-j] << T[i] << "   ";
        cout << conNum << continuousC << endl;
    }
    cout << "Yes" << endl;
}