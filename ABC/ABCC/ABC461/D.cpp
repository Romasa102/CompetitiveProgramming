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
    ll H,W,K;
    cin >> H >> W >> K;
    string S[H];
    rep(i,H)cin >> S[i];
    ll totalSum[H+1][W+1];
    rep(i,H+1){
        rep(j,W+1){
            totalSum[i][j]=0;
        }
    }
    rep(i,H){
        rep(j,W){
            totalSum[i+1][j+1]=totalSum[i][j+1] + totalSum[i+1][j] - totalSum[i][j] + (S[i][j]-'0');
        }
    }
    ll ans = 0;
    ll ans2 = 0;
    ll dp[H][W];
    rep(i,H+1){
        repp(m,i+1,H+1){
            ll right = 0;
            rep(left,W+1){
                while(right<W+1){
                    ll curS = (totalSum[m][right] - totalSum[i][right] - totalSum[m][left] + totalSum[i][left]);
                    if(curS<=K){
                        right++;
                    }else if(curS>K)break;
                }
                ans+=right-left-1;
                if (right == left) right++;
            }


            right = 0;
            rep(left,W+1){
                while(right<W+1){
                    ll curS = (totalSum[m][right] - totalSum[i][right] - totalSum[m][left] + totalSum[i][left]);
                    if(curS<=K-1){
                        right++;
                    }else if(curS>(K-1))break;
                }
                ans2+=right-left-1;
                if (right == left) right++;
            }
        }
    }
    if(K==0){
        cout << ans<< endl;
    }else{
        cout << ans - ans2<< endl;
    }
}