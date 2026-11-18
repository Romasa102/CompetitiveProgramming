#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll check(ll x1,ll y1, ll x2, ll y2,ll a,ll b){
    return (b-y1)*(x2-x1) - (a-x1)*(y2-y1);
}
int sign(ll x){
    if(x>0){
        return 1;
    }else if(x<0){
        return -1;
    }else{
        return 0;
    }
}
bool lineSegmentIntersection(
    ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
    if(sign(check(x1,y1,x2,y2,x3,y3)) * sign(check(x1,y1,x2,y2,x4,y4))<=0 &&
        sign(check(x3,y3,x4,y4,x1,y1)) * sign(check(x3,y3,x4,y4,x2,y2))<=0
    ){
        if(min(x1,x2) <= max(x3,x4) &&
        max(x1,x2) >= min(x3,x4) &&
        min(y1,y2) <= max(y3,y4) &&
        max(y1,y2) >= min(y3,y4) 
        ){
            return true;
        }
    }
    return false;
}
int main(){
    ll N,M;
    cin >> N >> M;
    vector<P> points;
    vector<pair<P,P>> segs;
    rep(_,N){
        ll x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    points.push_back(points[0]);
    rep(i,N){
        segs.push_back({points[i],points[i+1]});
    }
    rep(_,M){
        P point;
        cin >> point.first >> point.second;
        
        P rightPoint;
        rightPoint.first = point.first + 2100100100;
        rightPoint.second = point.second;
        ll flag = 0;
        ll cnt = 0;
        rep(i,N){
            if(lineSegmentIntersection(segs[i].first.first, segs[i].first.second, segs[i].second.first , segs[i].second.second, point.first, point.second,point.first, point.second) == true){
                flag=1;
            }
            
            if((segs[i].first.second > point.second) == (segs[i].second.second > point.second))continue;
            if(lineSegmentIntersection(segs[i].first.first, segs[i].first.second, segs[i].second.first,segs[i].second.second,
                                        point.first,point.second,rightPoint.first,rightPoint.second)==true){
                                            cnt++;
                                        }
        }
        if(flag == 1){
            cout << "BOUNDARY" << endl;
        }
        else if(cnt % 2 == 0){
            cout << "OUTSIDE" << endl;
        }else{
            cout << "INSIDE" << endl;
        }
    }
}