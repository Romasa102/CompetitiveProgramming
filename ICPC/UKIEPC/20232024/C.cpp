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
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
int main(){
    ll n,p;
    cin >> n >> p;
    double a[n];
    rep(i,n)cin >> a[i];
    
    double dp[n][n][p+1]; 
    double ans = 0;
    //dp [how far u checked] [what was the last point u were at] [how many point used]
    rep(startP,n){
    //iterate startP since there is a chance that the starting point wont be included in the final list
        rep(i,n)rep(j,n)rep(k,p+1)dp[i][j][k]=-1;
        //dp[0][startP][1] = 0;
        dp[0][0][1] = 0;

        repp(i,1,n){
            rep(j,i){
                repp(k,1,p+1){
                    ll Jnorm = j+startP;if(Jnorm>=n)Jnorm-=n;
                    ll Inorm = i+startP;if(Inorm>=n)Inorm-=n;
                    double angPrev = a[Jnorm] - a[startP]; if(angPrev < 0)angPrev+=360;
                    double angNow = a[Inorm] - a[startP]; if(angNow < 0)angNow+=360;
                    double arcS = sin(((angNow-angPrev) * PI)/180) / 2;
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                    dp[i][i][k+1] = max(dp[i][i][k+1], dp[i-1][j][k] + arcS);
                }
            }
        }
        rep(j,n){
            ll Jnorm = j+startP;if(Jnorm>=n)Jnorm-=n;
            double angPrev = a[Jnorm] - a[startP]; if(angPrev < 0)angPrev+=360;
            double angNow = 360;
            double arcS = sin(((angNow-angPrev) * PI)/180) / 2;
            ans = max(ans, dp[n-1][j][p] + arcS);
        }
    }
    cout << fixed << showpoint;
    cout << setprecision(12);
    cout << ans  * 1000 * 1000<< endl;
}