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

ll b,q,l,m;
ll arr[100010];

bool compare(ll x,ll y){
	return abs(x)<abs(y);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>b>>q>>l>>m;

    FOR(i,1,m) cin>>arr[i];

    sort(arr+1,arr+m+1,compare);

    // FOR(i,1,m){
    // 	cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    if(abs(b)>l){
    	cout<<0<<endl;
    	return 0;
    }

    if(b==0){

		if(arr[1]==0){
			cout<<0<<endl;
			return 0;
		}
		else{
			cout<<"inf"<<endl;
			return 0;
		}
    }

    if(q==0){
    	bool is_b=false;
    	bool is_zero=false;

    	FOR(i,1,m){
    		if(arr[i]==b) is_b=true;
    		if(arr[i]==0) is_zero=true;
    	}

    	if(is_zero and is_b){
    		cout<<0<<endl;
    		return 0;
    	}

    	if(is_b and !is_zero){
    		cout<<"inf"<<endl;
    		return 0;
    	}

    	if(is_zero and !is_b){
    		cout<<1<<endl;
    		return 0;
    	}
    	else{
	    	cout<<"inf"<<endl;
	    	return 0;
    	}
    }

    if(q==1){
    	FOR(i,1,m){
    		if(arr[i]==b){
    			cout<<0<<endl;
    			return 0;
    		}
    	}

    	cout<<"inf"<<endl;
    	return 0;
    }

    if(q==-1){
    	bool ok1=false;
    	bool ok2=false;

    	FOR(i,1,m){
    		if(arr[i]==b) ok1=true;
    		if(arr[i]==-b) ok2=true;
    	}

    	if(ok1 and ok2){
    		cout<<0<<endl;
    		return 0;
    	}
    	else{
    		cout<<"inf"<<endl;
    		return 0;
    	}
    }

    ll elem=b;
    ll c=0;
    ll p=1;
    bool found=false;

    while(abs(elem)<=l){
    	found=false;
    	c++;

    	while(p<=m and abs(arr[p])<=abs(elem)){
    		
    		if(arr[p]==elem){
    			found=true;
    			c--;
    			p++;
    			break;
    		}
    		p++;
    	}

    	// DEBUG(c);
    	// DEBUG(p);
    	// DEBUG(elem);
    	elem*=q;
    }


    cout<<c<<endl;
}