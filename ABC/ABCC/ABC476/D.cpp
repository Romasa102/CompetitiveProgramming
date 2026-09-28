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
    ll N,M,K;
    cin >> N >> M >> K;
    ll X,Y;
    cin >> X >> Y;
    ll A[N],B[M];
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];

    //Y
    ll totalCost = K*Y+X;
    sort(A,A+N);
    sort(B,B+M);
    ll cumSA[N+1];
    cumSA[0] = 0;
    rep(i,N){
        cumSA[i+1] = cumSA[i]+A[i];
    }
    ll cumSB[M+1];
    cumSB[0]=0;
    ll maxMB = M;
    ll numKUse;
    rep(i,M){
        numKUse += B[i]/K;
        if(B[i]%K!=0)numKUse++;
        if(numKUse > Y){
            maxMB = min(maxMB,i);
            break;
        }
        cumSB[i+1] = cumSB[i]+B[i];
    }
    ll ans = 0;
    rep(i,maxMB+1){
        ll costLeft = totalCost - cumSB[i];
        ll numBB = (upper_bound(cumSA,cumSA+N+1,costLeft)-cumSA);
        if(numBB>0)numBB--;
        ans = max(ans, numBB+i);
    }
    cout << ans << endl;
}