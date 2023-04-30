#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    string R;
    ll L = S.length() - 1;
    ll AC = 0;
    ll FC = 0;
    while(S[L] == 'a'){
        L--;
        AC ++;
    }
    L = 0;
    while(S[L] == 'a'){
        L++;
        FC ++;
    }
  if(FC > AC){cout << "No" << endl; 
              return 0;
             }
    S = S.substr(FC,S.length() - FC - AC);
    R = S;
    reverse(R.begin(),R.end());
    if(S == R){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
}