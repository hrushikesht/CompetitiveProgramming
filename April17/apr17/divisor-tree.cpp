#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<ll>
#define vl vector<ll>
#define pi pair<ll,ll>
#define tiii tuple<ll,ll,ll> >
#define tiiii tuple<ll,ll,ll,ll>
#define vpi vector< pair<ll,ll> >

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

ll a,b,n;

vector<int> prime;

// struct compare{
// 	bool operator()(pi p1,pi p2){
// 		return p1.F>p1.
// 	}
// };

void sieve(int n)
{
	bool check[n]={false};
	FOR(i,2,n)
	{
		if(check[i]==true)
			continue;
		prime.pb(i);
		for(int j=i;j<=n;j+=i)
		{
			check[j]=true;
		}
	}
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    n = max(a,b);

    sieve(n);

    // FOR(i,1,10){
    // 	cout<<prime[i]<<" ";
    // }
    // cout<<endl;
    
    ll final_sum=0;
    FOR(i,a,b){
    	// ll factors[prime.size()];
    	// fill(factors,factors+prime.size(),0)
    	vector< pair<ll,ll> > heap;
    	ll ans=0;

    	ll temp=i;

    	ll index=0,k;
    	while(temp!=1){
    		k=0;
    		while(temp%prime[index]==0){
    			// DEBUG(prime[index]);
    			temp/=prime[index];
    			k++;
    		}
    		// DEBUG(prime[index]);
    		// DEBUG(k);
    		// factors[index++]=k;
    		if(k!=0) heap.pb(mp(k,prime[index]));
    		index++;
    	}

    	make_heap(all(heap));

    	// cout<<"no"<<endl;
    	// for(auto u:heap){
    	// 	DEBUG(u.F);
    	// 	DEBUG(u.S);
    	// }
    	// cout<<"yo"<<endl;    	

    	pair<ll,ll> x;
    	ll temp_sum=1;
    	while(!heap.empty()){
    		temp_sum=1;
    		for(auto u:heap){
    			temp_sum*=(u.F+1);
    		}

    		x=heap.front();
    		pop_heap(all(heap));
    		heap.pop_back();
    		// DEBUG(x.F);
    		// DEBUG(x.S);
    		if(x.F!=1){
    			heap.push_back(mp(x.F-1,x.S));
    			push_heap(all(heap));
    		}
    		ans+=temp_sum;
    	}
    	// DEBUG(ans);
    	final_sum += ans;
    	// cout<<endl;
    }
    cout<<final_sum<<endl;
}

