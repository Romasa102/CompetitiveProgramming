#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll cumS[60][60];
int calc_sum(int x1, int y1, int x2, int y2)
{
    return cumS[x2+1][y2+1] + cumS[x1][y1] - cumS[x1][y2 + 1] - cumS[x2 + 1][y1];
}

int main(){
    ll H,W;
    cin >>H >> W;
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    repp(i,1,H+1){
        repp(j,1,W+1){
            cumS[i][j]=cumS[i-1][j]+cumS[i][j-1]-cumS[i-1][j-1]+A[i-1][j-1];
        }
    }
    //rep(i,H)rep(j,W)cumS[i + 1][j + 1] = cumS[i][j + 1] + A[i][j];
    //rep(i,H)rep(j,W)cumS[i + 1][j + 1] += cumS[i + 1][j];
    ll ans =0;
    rep(i,H){
        rep(j,W){
            ll defaultN = calc_sum(0, 0, i, j);
            vector<ll> horizontalL;
            vector<ll> verticalL;
            horizontalL.push_back(-1);
            verticalL.push_back(-1);
            rep(k,H){
                if(calc_sum(horizontalL.back()+1,0,k,j)==defaultN){
                    horizontalL.push_back(k);
                }
            }
            rep(k,W){
                if(calc_sum(0,verticalL.back()+1,i,k)==defaultN){
                    verticalL.push_back(k);
                }
            }
            if (horizontalL.back() != H - 1 || verticalL.back() != W - 1)continue;
            bool worked = true;
            rep(k,horizontalL.size()-1){
                rep(l,verticalL.size()-1){
                    if (calc_sum(horizontalL[k] + 1, verticalL[l] + 1, horizontalL[k + 1], verticalL[l + 1]) != defaultN)
                    {
                        worked=false;
                    }
                }
            }
            if(worked)ans++;
        }
    }
    cout << ans-1 << endl;
}