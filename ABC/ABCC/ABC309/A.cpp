#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,B;
    cin >> A >> B;
    if((B-A) == 3){
        cout << "Yes" << endl;
        return 0;
    }
    if((B-A) == 1 && A%3 != 0){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}