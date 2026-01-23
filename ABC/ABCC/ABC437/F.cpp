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
vector<ll> segTmx;
vector<ll> segTMx;
vector<ll> segTmy;
vector<ll> segTMy;
ll segTS = 1;
ll INF = 1LL<<45;
void update(bool minC, bool isX, ll pos, ll x){
    ll k = pos+segTS;
    if(minC){
        if(isX){
            segTmx[k]=x;
        }else{
            segTmy[k]=x;
        }
    }else{
        if(isX){
            segTMx[k]=x;
        }else{
            segTMy[k]=x;
        }
    }
    while(k>1){
        k/=2;
        segTmx[k]=min(segTmx[k*2],segTmx[k*2+1]);
        segTmy[k]=min(segTmy[k*2],segTmy[k*2+1]);
        segTMx[k]=max(segTMx[k*2],segTMx[k*2+1]);
        segTMy[k]=max(segTMy[k*2],segTMy[k*2+1]);
    }
}
ll searchmx(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l <= st && en <= r)return segTmx[node];
    if(en < l  || r < st)return INF;
    return min(searchmx(l,r,st,(st+en)/2,node*2),searchmx(l,r,(st+en)/2+1,en,node*2+1));
}
ll searchmy(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l <= st && en <= r)return segTmy[node];
    if(en < l  || r < st)return INF;
    return min(searchmy(l,r,st,(st+en)/2,node*2),searchmy(l,r,(st+en)/2+1,en,node*2+1));
}
ll searchMx(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l <= st && en <= r)return segTMx[node];
    if(en < l  || r < st)return -INF;
    return max(searchMx(l,r,st,(st+en)/2,node*2),searchMx(l,r,(st+en)/2+1,en,node*2+1));
}
ll searchMy(ll l,ll r,ll st = 0,ll en = segTS-1,ll node = 1){
    if(l <= st && en <= r)return segTMy[node];
    if(en < l  || r < st)return -INF;
    return max(searchMy(l,r,st,(st+en)/2,node*2),searchMy(l,r,(st+en)/2+1,en,node*2+1));
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    while(segTS<N)segTS*=2;
    segTmx.resize(segTS*2,INF);
    segTMx.resize(segTS*2,-INF);
    segTmy.resize(segTS*2,INF);
    segTMy.resize(segTS*2,-INF);
    ll X[N],Y[N];
    rep(i,N){
        cin >> X[i] >> Y[i];
        ll tempX,tempY;
        tempX = X[i]-Y[i];
        tempY = X[i]+Y[i];
        update(true,true,i,tempX);
        update(true,false,i,tempY);
        update(false,true,i,tempX);
        update(false,false,i,tempY);
    }
    rep(_,Q){
        ll task;
        cin >> task;
        if(task == 1){
            ll pos,x,y;
            cin >> pos >> x >> y;
            ll tempX,tempY;
            pos--;
            tempX = x-y;
            tempY = x+y;
            update(true,true,pos,tempX);
            update(true,false,pos,tempY);
            update(false,true,pos,tempX);
            update(false,false,pos,tempY);
        }else{
            ll l,r,x,y;
            cin >> l >> r >> x >> y;
            l--;r--;
            ll tempX,tempY;
            tempX = x-y;
            tempY = x+y; 
            ll minDx = searchmx(l,r);
            ll minDy = searchmy(l,r);
            ll maxDx = searchMx(l,r);
            ll maxDy = searchMy(l,r);
            //cout << minDx << " " << maxDx << " " << minDy << " " << maxDy << "   ";
            //cout << " ans: ";
            cout << max({tempX-minDx,maxDx-tempX,maxDy-tempY,tempY-minDy}) << endl;
        }
    }
}