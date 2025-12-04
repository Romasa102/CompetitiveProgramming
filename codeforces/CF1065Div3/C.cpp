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
    rep(_,t){
        ll N;
        cin >> N;
        ll A[N],B[N];
        rep(i,N)cin >> A[i];
        rep(i,N)cin >> B[i];
        ll Ascore = 0;
        ll Mscore = 0;
        bool AnumO = 0;
        bool BnumO = 0;
        rep(i,N){
            if(A[i] == 1)AnumO = !AnumO;
            if(B[i] == 1)BnumO = !BnumO;
        }
        rep(i,N){
            if(A[i] != B[i]){
                if(i%2){
                    Mscore++;
                    Ascore = 0;
                }else{
                    Ascore++;
                    Mscore = 0;
                }
            }
        }
        if(AnumO == BnumO){
            cout << "Tie" << endl;
            continue;
        }
        if(Ascore == Mscore){
            if(AnumO){
                cout << "Ajisai" << endl;
            }else{
                cout << "Mai" << endl;
            }
        }
        else if(Ascore > Mscore){
            cout << "Ajisai" << endl;
        }else{
            cout << "Mai" << endl;
        }
    }
}