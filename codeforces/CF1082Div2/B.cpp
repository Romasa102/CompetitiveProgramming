#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string S;
        cin >> S;
        ll state = 1;
        if(n%2==1)state = 2;
        bool satisfy = true;
        ll numA = 0;
        ll numB = 0;
        ll numUnk = 0;
        rep(i,n){
            if(S[i]=='a')numA++;
            if(S[i]=='b')numB++;
            if(S[i]=='?')numUnk++;
            if(state == 0){
                if(S[i]!='b' && S[i] != '?')satisfy=false;
                state = 1;
                continue;
            }
            if(state == 2){
                if(S[i]!='a' && S[i] != '?')satisfy=false;
                state = 1;
                continue;
            }
            if(state == 1){
                if(S[i]=='a')state=0;
                if(S[i]=='b')state=2;
                if(S[i]=='?')state=3;
                continue;
            }
            if(state == 3){
                state = 1;
            }
        }
        ll needA = (n + 1) / 2;
        ll needB = n / 2;
        if(numA > needA || numB > needB) satisfy = false;
        if(numA + numUnk < needA) satisfy = false;
        if(satisfy){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}