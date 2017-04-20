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



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;

    while(t--){
    	ll n,m; cin>>n>>m;
    	string s; cin>>s;

    	ll max_left=0;
    	ll max_up=0;
    	ll  min_left=0;
    	ll min_up=0;
    	ll left=0;
    	ll right=0;
    	ll down=0;
    	ll up=0;

    	REP(i,s.size()){
    		
    		if(s[i]=='L'){
    			left++;
    			
    		}
    		else if(s[i]=='R'){
    			
    			left--;
    		}
    		else if(s[i]=='D'){
    			
    			up--;
    		}
    		else if(s[i]=='U'){
    			up++;
    			
    		}

    		max_left=max(max_left,left);
    		min_left=min(min_left,left);
    		min_up=min(min_up,up);
    		max_up=max(max_up,up);

    		
    	}

    	// DEBUG(max_left);
    	// DEBUG(max_up);
    	// DEBUG(min_left);
    	// DEBUG(min_up);

    	if(max_left-min_left<m and max_up-min_up<n){
    		cout<<"safe"<<endl;
    	}
    	else{
    		cout<<"unsafe"<<endl;
    	}

    }
}