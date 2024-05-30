/*BY-------VAMSHI*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;
//pbds
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int                         long long
#define vi                          vector<int>
#define vvi                         vector<vector<int>> 
#define rep(i,a,b)                  for(int i = a; i < b; i++)
#define repr(i,a,b)                 for(int i=a;i>=b;i--)
#define endl                        "\n"
#define ff                          first
#define ss                          second
#define cy                          cout << "YES" << endl
#define cn                          cout << "NO" << endl
#define si                          set<int>
#define sc                          set<char>
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
//function to generate all prime factors
vector<int> primefact(int n){
    vector<int> v;
    while(n%2==0){
        v.pb(2);
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            v.pb(i);
        }
    }
    if(n>2) v.pb(n);
    return v;
}
//Function to generate all factors of a number 
vector<int> allfact(int n){
    vector<int> v;
    rep(i,1,sqrt(n)+1){
        if((n%i)!=0) continue;
        if((n/i)==i){
            v.pb(i);
        }
        else{
            v.pb(i);
            v.pb(n/i);
        }
    }
    return v;
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
void sol(){
    int n;
    cin>>n;
    int s=0;
    int te=0;
    cout<<0<<endl;
    rep(i,2,n+1){
        int t=i*i;
        int al=t*(t-1)/2;
        s+=te;
        te++;
        al-=8*s;
        cout<<al<<endl;
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