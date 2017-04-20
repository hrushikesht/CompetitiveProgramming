#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <tuple>

#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int>
#define pii pair< pair<int,int>,int >
#define tiii tuple<int,int,int>
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

map< tiiii ,long double> M;

long double getScore(long double r,long double b,long double p,long double score){

	
	// cout<<endl;

	// double ans=0;
	auto it=M.find(mt(r,b,p,score));
	// if(M[mt(r,b,p,score)]) return M[mt(r,b,p,score)];

	if(it!=M.end()) return M[mt(r,b,p,score)];


	if(r==0){
		M[mt(r,b,p,score)]=1.0*score+b-p;
		return score+b-p;
	}

	if(b==0){
		M[mt(r,b,p,score)]=1.0*score+p;
		return score+p;
	}

	if(r+b == p){
		M[mt(r,b,p,score)]=1.0*score+r;
		return score+r;
	}

	if(p==0){
		M[mt(r,b,p,score)]=1.0*score+b;
		return score+b;
	}


	if(r>=b){
		long double s1=getScore(r-1,b,p-1,score+1);
		long double s2=getScore(r,b-1,p-1,score);
		long double temp=(r*s1 + b*s2)/(r+b);
		M[mt(r,b,p,score)]=temp;

		// DEBUG(r);
		// DEBUG(b);
		// DEBUG(p);
		// DEBUG(s1);
		// DEBUG(s2);
		// DEBUG(score);
		// DEBUG(temp);


		return temp;
	}
	else{
		long double s1=getScore(r-1,b,p,score);
		long double s2=getScore(r,b-1,p,score+1);
		long double temp=(r*s1 + b*s2)/(r+b);
		M[mt(r,b,p,score)]=temp;

		// DEBUG(r);
		// DEBUG(b);
		// DEBUG(p);
		// DEBUG(s1);
		// DEBUG(s2);
		// DEBUG(score);
		// DEBUG(temp);

		return temp;
	
	}

}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;

    while(t--){

    	M.clear();

	    ll r,b,p; cin>>r>>b>>p;

	    cout<<setprecision(10)<<fixed;
	    cout<<getScore((long double)r,(long double)b,(long double)p,(long double)0.0)<<endl;

	}
}