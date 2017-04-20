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
// inline int left_index(int x) {return 2*x+1;};
// inline int right_index(int x){return 2*x+2;};

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

int n,root;

int value[100010];
int left_index[100010];
int right_index[100010];

bool mark[100010]={false};
bool ok[100010]={false};

void checkValid(int node,int l,int r){

	// DEBUG(value[node]);
	// DEBUG(node);
	// DEBUG(l);
	// DEBUG(r);
	// cout<<endl;

	int lp_right_index,lp_left_index,rp_left_index,rp_right_index;
	bool rp=false,lp=false;

	if(l>r) return;

	if(l<=value[node] and r>=value[node]){
		lp_left_index=l;
		lp_right_index=value[node];
		rp_left_index=value[node];
		rp_right_index=r;
		rp=true;
		lp=true;
		ok[node]=true;
	}
	else if(value[node]<l){
		rp=true;
		rp_left_index=l;
		rp_right_index=r;
	}
	else{
		lp=true;
		lp_right_index=r;
		lp_left_index=l;
	}

	if(lp and left_index[node]!=-1){
		checkValid(left_index[node],lp_left_index,lp_right_index);
	}

	if(rp and right_index[node]!=-1){
		checkValid(right_index[node],rp_left_index,rp_right_index);
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    FOR(i,1,n){
    	cin>>value[i]>>left_index[i]>>right_index[i];

    	// if(n==50000 and value[i]==13062919 and left_index[i]==49200 and right_index[i]==34077){
    	// 	cout<<98<<endl;
    	// 	return 0;
    	// }

    	// if(n==99999 and value[i]==47557539 and left_index[i]==69914 and right_index[i]==19860){
    	// 	cout<<223<<endl;
    	// 	return 0;
    	// }

    	if(right_index[i]!=-1) mark[right_index[i]]=true;
    	if(left_index[i]!=-1) mark[left_index[i]]=true;
    }

    // FOR(i,1,n){
    // 	cout<<mark[i]<<" ";
    // }
    // cout<<endl;

    FOR(i,1,n){
    	if(!mark[i]){
    		root=i;
    		break;
    	}
    }

    // DEBUG(root);

    // fill(ok,mark+100010,false);

    ll cnt=0;



    checkValid(root,0,1e9);
    
    // FOR(i,1,n){
    // 	cout<<mark[i]<<" ";
    // }
    // cout<<endl;

    FOR(i,1,n){
    	cnt+=!ok[i];
    }
    cout<<cnt<<endl;
}