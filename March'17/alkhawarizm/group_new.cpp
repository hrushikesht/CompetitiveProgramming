#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int>
#define tiii tuple<int,int,int> >
#define tiiii tuple<int,int,int,int>
#define pl pair<ll> pl
#define vpi vector< pair<int,int> >>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple

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

ll n;
ll arr[1000010];
set<ll> s;

vector<int> prime;


void sieve(ll N)
{
    bool check[N]={false};

    FOR(i,2,N)
    {
        if(check[i]==true)
            continue;
        prime.pb(i);
        for(ll j=i*i;j<=N;j+=i)
        {
            check[j]=true;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt","r",stdin);

    cin>>n;

    ll maxito=-1;
    FOR(i,1,n){
    	cin>>arr[i];
    	maxito=max(maxito,arr[i]);
    }

    sieve(maxito+5);
    sort(arr+1,arr+n+1);

    ll groups=0;

    FORD(i,n,1){
    	ll old_size=s.size();

    	ll temp=arr[i];

    	ll index=0;
    	ll c=0;
    	while(prime[index]<= arr[i] and temp!=1){

			if(!(temp%prime[index])){
            
                s.insert(prime[index]);
            	c++;
                while(!(temp%prime[index])){
                    temp/=prime[index];
                }
            }
            index++;
    	}

    	if((old_size+c) == (s.size())){
    		groups++;
    	}
    }

    cout<<groups<<endl;
    return 0;

}