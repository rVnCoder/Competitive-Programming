#include<bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
struct segtree
{
    int size;
    vi xors;
    void init(int n){ 
        size=1;
        while(size<n) size*=2;
        xors.assign(2*size,0);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            xors[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        xors[x]=xors[2*x+1]^xors[2*x+2];
    }
    void bulid(vi &a,int x , int lx ,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                xors[x]=a[lx]; 
            }
            return;
        }
        int m=(lx+rx)/2;
        bulid(a,2*x+1,lx,m);
        bulid(a,2*x+2,m,rx);
        xors[x]=xors[2*x+1]^xors[2*x+2];
    }
    void bulid(vi &a){
        bulid(a,0,0,size);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int calc(int l,int r,int x,int lx,int rx){
        if(lx>=r||l>=rx) return 0;
        if(lx>=l&&rx<=r) return xors[x];
        int m=(lx+rx)/2;
        int s1=calc(l,r,2*x+1,lx,m);
        int s2=calc(l,r,2*x+2,m,rx);
        return s1^s2;
    }
    int calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};

int32_t main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    segtree st;
    st.init(n);
    vi a(n);
    rep(i,0,n) cin>>a[i];
    st.bulid(a);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.calc(l-1,r)<<endl;
    }
}