#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)

#define all(v) (v).begin(),(v).end()

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const ll INF = 1<<29;
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { ll res = 0; while(n && ++res) n-=n&(-n); return res; }

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

inline bool sortDown(ll x,ll y){return x>y;}
inline bool sortPairSecondInc( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S<p2.S;}
inline bool sortPairSecondDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}
inline bool sortPairFirstDec( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.F>p2.F;}

inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}


const int mod = 1000000007;
const int N = 4e5+5;
const int ifact_n_minus_1 = 977041169;
using namespace std;
/////////////////////////////////////////////////////////////////////

char str[N];
ll fact[N];
ll ifact[N];
ll x,y;
ll ans;

void preCal(){

    fact[0]=1;
    FOR(i,1,N-1){
        fact[i]=(1LL*fact[i-1]*i)%mod;
    }

    ifact[N-1]=ifact_n_minus_1;
    FORD(i,N-2,0){
        ifact[i]=(1LL*ifact[i+1]*(i+1LL))%mod;
    }
}

ll ncr(ll n,ll r){
    if(r>=0 and r<=n){
        ll res=fact[n];
        res=(1LL*res*ifact[r])%mod;
        res=(1LL*res*ifact[n-r])%mod;
        return res;
    }
    else{
        return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    preCal();

    scanf("%s",str+1);

    ll n=strlen(str+1);
    x=0;
    y=0;
    ans=0;

    FOR(i,1,n){
        y+=(str[i]==')');
    }

    FOR(i,1,n){
        y-=(str[i]==')');

        if(str[i]=='('){
            ans+=ncr(x+y,y-1);
            if(ans>mod){
                ans-=mod;
            }
        }
        x+=(str[i]=='(');
    }
    cout<<ans<<endl;
}