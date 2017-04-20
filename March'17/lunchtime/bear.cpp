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
#define vpi vector< pair<int,int> >

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



char grid[60][60];
bool visited[65][65]={false};
vpi adj[2510];
ll n,curr;

void collect(ll x,ll y){
	visited[x][y]=true;

	adj[curr].pb(mp(x,y));

	if(grid[x-1][y]=='?' and !visited[x-1][y]){
		collect(x-1,y);
	}

	if(grid[x+1][y]=='?' and !visited[x+1][y]){
		collect(x+1,y);
	}

	if(grid[x][y+1]=='?' and !visited[x][y+1]){
		collect(x,y+1);
	}

	if(grid[x][y-1]=='?' and !visited[x][y-1]){
		collect(x,y-1);
	}
}

bool checkHood(ll x,ll y,char c){
	if(grid[x-1][y]==c or grid[x+1][y]==c or grid[x][y+1]==c or grid[x][y-1]==c){
		return true;
	}
	return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt","r",stdin);

    ll t; cin>>t;

    FOR(i,0,50){
    	grid[0][i]='.';
    	grid[i][0]='.';
    }

    while(t--){

    	curr=1;

    	FOR(i,1,60){
    		FOR(j,1,60){
    			visited[i][j]=false;
    		}
    	}

    	bool found_ques=false;

    	cin>>n;
    	FOR(i,1,n){
    		FOR(j,1,n){
    			cin>>grid[i][j];
    			if(grid[i][j]=='?'){
    				found_ques=true;
    			}
    		}
    	}

    	FOR(i,0,n+1){
    		grid[i][n+1]='.';
    		grid[n+1][i]='.';
    	}

    	ll ans=1;

    	FOR(i,1,n){
    		FOR(j,1,n){

    			if(grid[i][j]=='G'){
    				if(grid[i][j+1]=='G'){
    					ans=0;
    				}
    				if(grid[i+1][j]=='G'){
    					ans=0;
    				}
    			}

    			if(grid[i][j]=='P'){
    				if(grid[i][j+1]=='B'){
    					ans=0;
    				}
    				if(grid[i+1][j]=='B'){
    					ans=0;
    				}
    			}

    			if(grid[i][j]=='B'){
    				if(grid[i][j+1]=='P'){
    					ans=0;
    				}
    				if(grid[i+1][j]=='P'){
    					ans=0;
    				}
    			}

    			if(grid[i][j]=='?' and !visited[i][j]){
    				collect(i,j);
    				curr++;
    			}
    		}
    	}


    	FOR(i,1,curr-1){

    		bool is_brown=false;
    		bool is_polar=false;
    		bool is_grizzly=false;

    		for(auto u:adj[i]){
    			ll x,y;
    			x = u.F;
    			y = u.S;

    			is_brown=(is_brown | checkHood(x,y,'B'));
    			is_polar=(is_polar | checkHood(x,y,'P'));
    			is_grizzly=(is_grizzly | checkHood(x,y,'G'));
    		}

    		if(is_grizzly){
    			ans=ans*0;
    		}
    		else if(is_brown and is_polar){
    			ans=ans*0;
    		}
    		else if(!is_brown and !is_polar){
    			if(adj[i].size()==1){
    				ans=(ans*3)%mod;
    			}
    			else{
    				ans=(ans*2)%mod;
    			}
    		}
    	}

    	FOR(i,1,curr){
    		adj[i].clear();
    	}

    	cout<<ans<<endl;
    }
}