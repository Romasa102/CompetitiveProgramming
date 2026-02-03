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
        ll N,C;
        cin >> N >> C;
        string S[N];
        rep(i,N)cin >> S[i];
        vector<vector<bool>> canGo(N,vector<bool>(N,false));
        vector<ll> fstWall(N,-1);
        for(ll i= N-1;i>=0;i--){
            rep(j,N){
                if(S[i][j]=='#'){
                    fstWall[j] = max(fstWall[j],i);
                }
            }
        }
        canGo[N-1][C-1]=true;
        for(ll i= N-2;i>=0;i--){
            rep(j,N){
                bool a=false;
                bool b=false;
                bool c=false;
                if((j-1)>=0)a=canGo[i+1][j-1];
                b = canGo[i+1][j];
                if((j+1)<N)c=canGo[i+1][j+1];
                if(S[i][j]=='.')canGo[i][j]=(a||b||c);
                if(fstWall[j]==i && (a||b||c)==true && S[i][j]=='#'){
                    for(ll k = i;k>=0;k--){
                        canGo[k][j]=true;
                    }
                }
            }
        }
       // rep(i,N){
       //     rep(j,N){
       //         cout << canGo[i][j];
       //     }cout << endl;
        //}
        rep(i,N){
            cout << canGo[0][i];
        }cout << endl;
    }
}