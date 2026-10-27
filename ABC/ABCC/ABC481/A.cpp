#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int A,B;
    cin >> A >> B;
    A+=B;
    if(A/10 != 0){
      
      cout << 2<< endl;
    }else{
      
    cout << 1 << endl;
    }
}