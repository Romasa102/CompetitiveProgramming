#include <bits/stdc++.h>
using namespace std;

template<class T> int sgn(T x){return (x>0)-(x<0);}
template<class T> struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0):x(x),y(y){}
    bool operator<(P p) const {return tie(x,y)<tie(p.x,p.y);}
    bool operator==(P p) const {return tie(x,y)==tie(p.x,p.y);}
    P operator+ (P p)  const{return P(x+p.x,y+p.y);}
    P operator- (P p)  const{return P(x-p.x,y-p.y);}
    P operator* (T d)  const{return P(x*d,y*d);}
    P operator/ (T d)  const{return P(x/d,y/d);}
    T dot (P p)const{return x*p.x+y*p.y;}
    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b){return (a-*this).cross(b-*this);}
    T dist2()const {return x*x+y*y;}
    double dist()const{return sqrt(double(dist2()));}
    double angle() const {return atan2(y,x);}
    P unit()const{return *this/dist();}
    P perp()const{return P(-y,x);}
    P normal()const{return perp().unit();}
    P rotate(double a)const{
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
    }
    friend ostream& operator<<(ostream&os,P p){
        return os<<'('<<p.x<<','<<p.y<<')';
    }
};

typedef Point<double> P;
double segdist(P s,P e,P p){
    if(s==e)return (p-s).dist();
    auto d=(e-s).dist2(),t=min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P>bool onSegment(P s,P e,P p){
    return p.cross(s,e)==0&&(s-p).dot(e-p)<=0;
}

template<class P> bool inPolygon(vector<P>&p,P a, bool strict =false){
    int cnt=0,n=p.size();
    for(int i=0;i<n;i++){
        P q = p[(i+1)%n];
        if(segdist(p[i],q,a)<=1e-6)return !strict;
        cnt^=((a.y<p[i].y)-(a.y<q.y))*a.cross(p[i],q)>0;
    }
    return cnt;
}
using ll=long long;

int main(){
    vector<int>n(3);
    vector<vector<P>>v(3);
    vector<vector<int>>w(3);
    for(int i=0;i<3;i++){
        cin>>n[i];
        v[i].resize(n[i]);
        for(int j=0;j<n[i];j++){
            cin>>v[i][j].x>>v[i][j].y;
            if(i==0){
                w[0].push_back(v[i][j].x);
                w[1].push_back(v[i][j].y);
            }else if(i==1){
                w[2].push_back(v[i][j].x);
                w[1].push_back(v[i][j].y);
            }else{
                w[0].push_back(v[i][j].x);
                w[2].push_back(v[i][j].y);
            }
        }
    }
    for(int i=0;i<3;i++){
        sort(w[i].begin(),w[i].end());
        w[i].erase(unique(w[i].begin(),w[i].end()),w[i].end());
    }
    ll ans=0;
    for(int i=0;i<w[0].size()-1;i++){
        for(int j=0;j<w[1].size()-1;j++){
            for(int k=0;k<w[2].size()-1;k++){
                if(inPolygon(v[0],P((((double)w[0][i]+w[0][i+1])/2),((double)w[1][j]+w[1][j+1])/2))
                &&inPolygon(v[1],P((((double)w[2][k]+w[2][k+1])/2),((double)w[1][j]+w[1][j+1])/2))
                &&inPolygon(v[2],P((((double)w[0][i]+w[0][i+1])/2),((double)w[2][k]+w[2][k+1])/2))){
                    ans+=(ll)(w[0][i+1]-w[0][i])*(w[1][j+1]-w[1][j])*(w[2][k+1]-w[2][k]);
                }
            }
        }
    }
    cout<<ans<<'\n';
}