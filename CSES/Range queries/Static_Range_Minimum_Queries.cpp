/*BY-------VAMSHI*/
#include <bits/stdc++.h>
using namespace std;
#define int                         long long
#define vi                          vector<int>
#define vvi                         vector<vector<int>> 
#define rep(i, a, b)                for(int i = a; i < b; i++)
#define repr(i,a,b)                 for(int i=a;i>=b;i--)
#define endl                        "\n"
#define ff                          first
#define ss                          second
#define cy                          cout << "YES" << endl
#define cn                          cout << "NO" << endl
#define si                          set<int>
#define sc                          set<char>
#define sti                         stack<int>
#define stc                         stack<char>
#define mii                         map<int,int> 
#define mci                         map<char,int>
#define pb                          push_back
#define pp                          pop_back
#define msi                         map<string, int>
#define mis                         map<int, string>
#define in                          insert
#define M                           1000000007
#define pi                          3.14159265358979323846
#define prec(x)                     cout << fixed << setprecision(x)
#define bpc(x)                      __builtin_popcountll(x)
#define ull                         unsigned long long
#define all(x)                      x.begin(), x.end()
#define read(a, n)                  rep(i, 0, n)    cin >> a[i]
#define print(a, n)                 rep(i, 0, n)    cout << a[i] << " "; cout << endl
vector<int>prime;
set<int>prime_set;
void fastio()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
/*------------------------------------------------FUNCTIONS------------------------------------------------*/
//Modular Operations 
 
int madd(int a,int b) 
{
    return (a+b)%M;
}
int msub(int a,int b)
{
    return (((a-b)%M)+M)%M;
}
int mmul(int a,int b)
{
    return ((a%M)*(b%M))%M;
}
int mpow(int base,int exp) 
{
    int res = 1;
    while(exp) 
    {
        if(exp%2==1)
        {
            res = (res*base)%M;
        }
        exp>>=1;
        base=(base*base)%M;
    }
    return res;
}
int minv(int base)
{
    return mpow(base,M-2);
}
int mdiv(int a,int b)
{
    return mmul(a,minv(b));
}
 
//Function of converting a number into its binary string
string tobinary(int n)
{
    string s="";
    int x=64;
    while(x--)
    {
        if(n&1)
        {
            s+="1";
        }
        else
        {
                s+="0";
        }
        n>>=1;
    }
    while(s[s.size()-1]=='0')
    {
        s.pop_back();
    }
    reverse(s.begin(),s.end());
    return s;
}
 
//Function of converting a binary string into a number
int todecimal(string s)
{
    int ans=0;
    reverse(s.begin(),s.end());
    int p=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ans+=p;
        }
        p*=2;
    }
    return ans;
}
 
//Function for creating a vector of prime numbers
void primes(int n)
{
    prime.assign(n+1,1);
    for (int p=2;p*p<=n;p++) 
    {
        if(prime[p]) 
        {
            for (int i=p*p;i<=n;i+=p)
            {
                prime[i]=0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            prime_set.insert(i);
        }
    }
}
 
//Conditional sorting in vector of pairs
bool sortcon(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return(a.second>b.second);
    }
    return a.first<b.first;
}
 #ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
 
void deb(int t) {cerr << t;}
void deb(string t) {cerr << t;}
void deb(char t) {cerr << t;}
void deb(double t) {cerr << t;}
void deb(ull t) {cerr << t;}
 
template <class T, class V> void deb(pair <T, V> p) {cerr << "{"; deb(p.ff); cerr << ","; deb(p.ss); cerr << "}";}
template <class T> void deb(vector <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(set <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T> void deb(multiset <T> v) {cerr << "[ "; for (T i : v) {deb(i); cerr << " ";} cerr << "]";}
template <class T, class V> void deb(map <T, V> v) {cerr << "[ "; for (auto i : v) {deb(i); cerr << " ";} cerr << "]";}
//*----------------------------------------MAINCODE----------------------------------------------*//
struct segtree
{
    int size;
    vi mins;
    void init(int n){ 
        size=1;
        while(size<n) size*=2;
        mins.assign(2*size,0);
        
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            mins[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        mins[x]=min(mins[2*x+1],mins[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int get(int l,int r,int x,int lx,int rx){
        if(lx>=r||l>=rx) return INT_MAX;
        if(lx>=l&&rx<=r) return mins[x];
        int m=(lx+rx)/2;
        int s1=get(l,r,2*x+1,lx,m);
        int s2=get(l,r,2*x+2,m,rx);
        return min(s1,s2);
        
    }
    int get(int l,int r){
        return get(l,r,0,0,size);
    }
};
void sol(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    segtree st;
    st.init(n);
    rep(i,0,n) {
        int v;
        cin>>v;
        st.set(i,v);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.get(l-1,r)<<endl;
    }
}
int32_t main(){
    fastio();
    int T  = 1;
    while(T--){
        sol();
    }
    return 0;
}