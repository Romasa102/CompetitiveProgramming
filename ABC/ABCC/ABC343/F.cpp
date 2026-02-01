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
ll segTS = 1;
vector<pair<P,P>> segT;
void update(ll pos,ll x){
    ll k = segTS+pos;
    segT[k]={{x,1},{0,0}};
    while(k>1){
        k/=2;
        auto leftT = segT[k*2];
        auto rightT = segT[k*2+1];
        P bL = leftT.first;
        P SbL = leftT.second;
        P bR = rightT.first;
        P SbR = rightT.second;
        P biggest = {0,0};
        P Sbiggest = {0,0};
        if(bL.first==bR.first){
            biggest={bL.first,bL.second+bR.second};
            if(SbL.first==SbR.first){
                Sbiggest={SbL.first,SbL.second+SbR.second};
            }else if(SbL.first>SbR.first){
                Sbiggest=SbL;
            }else{
                Sbiggest=SbR;
            }
        }else if(bL.first>bR.first){
            biggest=bL;
            if(SbL.first==bR.first){
                Sbiggest={SbL.first,SbL.second+bR.second};
            }else if(SbL.first>bR.first){
                Sbiggest=SbL;
            }else{
                Sbiggest=bR;
            }
        }else{
            biggest=bR;
            if(SbR.first==bL.first){
                Sbiggest={SbR.first,SbR.second+bL.second};
            }else if(SbR.first>bL.first){
                Sbiggest=SbR;
            }else{
                Sbiggest=bL;
            }
        }
        segT[k]={biggest,Sbiggest};
    }
}
pair<P,P> getMSM(ll l,ll r,ll st = 0, ll en = segTS-1, ll node = 1){
    if(l<=st&&en<=r)return segT[node];
    if(en<l||r<st)return {{0,0},{0,0}};
    auto leftT = getMSM(l,r,st,(st+en)/2,node*2); 
    auto rightT = getMSM(l,r,(st+en)/2+1,en,node*2+1);
    P bL = leftT.first;
    P SbL = leftT.second;
    P bR = rightT.first;
    P SbR = rightT.second;
    P biggest = {0,0};
    P Sbiggest = {0,0};
    if(bL.first==bR.first){
        biggest={bL.first,bL.second+bR.second};
        if(SbL.first==SbR.first){
            Sbiggest={SbL.first,SbL.second+SbR.second};
        }else if(SbL.first>SbR.first){
            Sbiggest=SbL;
        }else{
            Sbiggest=SbR;
        }
    }else if(bL.first>bR.first){
        biggest=bL;
        if(SbL.first==bR.first){
            Sbiggest={SbL.first,SbL.second+bR.second};
        }else if(SbL.first>bR.first){
            Sbiggest=SbL;
        }else{
            Sbiggest=bR;
        }
    }else{
        biggest=bR;
        if(SbR.first==bL.first){
            Sbiggest={SbR.first,SbR.second+bL.second};
        }else if(SbR.first>bL.first){
            Sbiggest=SbR;
        }else{
            Sbiggest=bL;
        }
    }
    return {biggest,Sbiggest};
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    while(segTS<N)segTS*=2;

    segT.resize(segTS*2,{{0,0},{0,0}});
    ll A[N];
    rep(i,N){
        cin >> A[i];
        update(i,A[i]);
    }
    rep(i,segTS*2){
        auto cur = segT[i];
    //    cout << cur.first.first << " "  << cur.first.second << "  " << cur.second.first << "  " << cur.second.second << endl;
    }
    //cout << "its it " << endl;
    while(Q--){
        ll task = 0;
        cin >> task;
        if(task==1){
            ll p,x;
            cin >> p >> x;
            update(p-1,x);
        }else{
            ll l,r;
            cin >> l >> r;
            auto cur = getMSM(l-1,r-1);
           cout << cur.second.second << endl;
        }
    }
}