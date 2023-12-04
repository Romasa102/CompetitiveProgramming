#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll cumS[2000][2000];
ll getSum(ll a,ll b,ll c,ll d){
    return cumS[c][d]-cumS[a][d]-cumS[c][b]+cumS[a][b];//s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    string Sp[N];
    rep(i,N){
        cin >> Sp[i];
    }
    rep(i,N+1)rep(j,N+1)cumS[i][j]=0;
    rep(i,N){
        rep(j,N){
            if(Sp[i][j]=='B'){
                cumS[i+1][j+1]=cumS[i][j+1] + cumS[i+1][j] - cumS[i][j] + 1;
            }else{
                cumS[i+1][j+1]=cumS[i][j+1] + cumS[i+1][j] - cumS[i][j];
            }
        }
    }
    rep(i,Q){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll topY = a%N;
        ll topX = b%N;
        ll bottomY = c%N;
        ll bottomX = d%N;
        ll height= max(0LL,(1+abs(c-a) - (N-topY) - bottomY - 1)/N);
        ll width = max(0LL,(1+abs(d-b) - (N-topX) - bottomX - 1)/N);
        if((c/N)==(a/N))width=-1;
        if((d/N)==(b/N))height=-1;
        if(width==-1&&height==-1){
            cout << getSum(c,d,a,b) << endl;
            continue;
        }
        ll ans =0;
        //left top
        ans += getSum(N,N,topY,topX);
        //right bottom
        ans += getSum(bottomY+1,bottomX+1,0,0);
        if(width!=-1&&height!=-1){
            //left bottom
            ans += getSum(bottomY+1,N,0,topX);
        }
        if(width!=-1&&height!=-1){
            //right top
            ans += getSum(N,bottomX+1,topY,0);
        }
        width=max(width,0LL);
        height=max(height,0LL);
        //inside
        ans += getSum(N,N,0,0)*height*width;
        //side vertical
        ans += height * (getSum(N,N,0,topX)+getSum(N,bottomX+1,0,0));
        //side horizontal
        ans += width * (getSum(N,N,topY,0) + getSum(bottomY+1,N,0,0));

        cout << ans << endl;
    }
}