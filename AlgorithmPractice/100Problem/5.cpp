#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll currentCost = A * X + B * Y;
    ll smallestCost = currentCost;
    ll counter = 0;
    ll LoopA  = max(X,Y);
    rep(i,LoopA){
        counter++;
        if(X>0&&Y>0){
            currentCost = currentCost - A - B + 2 * C;
            X--;
            Y--;
        }else if(X>0){
            currentCost = currentCost - A + 2 * C;
            X--;
        }else if(Y>0){
            currentCost = currentCost - B + 2  * C;
            Y--;
        }
        smallestCost = min(smallestCost,currentCost);
    }
    cout << smallestCost << endl;
}