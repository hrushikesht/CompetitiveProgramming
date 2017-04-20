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

ll n,q;
ll start_node,curr,tree_height,curr_height;
string route;

ll power[65];

void pre(){
	power[0]=1;

	FOR(i,1,63){
		power[i]=2*power[i-1];
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    pre();

    cin>>n>>q;

    ll x = n+1;

    tree_height=0;

    while(!(x>>1 & 1)){
    	x = x>>1;
    	tree_height++;
    }


    // DEBUG(tree_height);


    FOR(j,1,q){

    	// DEBUG(j);

    	cin>>start_node;
    	cin>>route;

    	ll x_temp = start_node;

    	curr = start_node;
    	curr_height = tree_height;

    	while(!(x_temp&1)){
    		x_temp = x_temp>>1;
    		curr_height--;
    	}



    	ll len = route.size();

        // DEBUG(curr_height);
    	REP(i,len){
            // DEBUG(i);

            // cout<<"curr before :"<<curr_height<<endl;

    		if(route[i] == 'R'){
                if(tree_height-curr_height-1 >=0 ){
        			ll temp = curr + power[tree_height-curr_height-1];
        			if(temp<power[tree_height+1] and temp>0){
        				curr = temp;
        				curr_height++;
        			}
                }
    		}
    		else if(route[i] == 'L'){
                if(tree_height-curr_height-1 >=0){
        			ll temp = curr - power[tree_height-curr_height-1];
        			if(temp<power[tree_height+1] and temp>0){
        				curr = temp;
        				curr_height++;
        			}
                }
            }
    		else{
    			ll bro_temp = curr;

    			ll two_pow=0;
    			while(!(bro_temp&1)){
    				bro_temp = bro_temp>>1;
    				two_pow++;
    			}

    			bro_temp = curr/power[two_pow];
    			// DEBUG(bro_temp);

    			// DEBUG(curr);
    			// DEBUG(tree_height);
    			// DEBUG(curr_height);

    			ll temp;
    			if((bro_temp+1)%4 == 0){
    				// cout<<"hi2"<<endl;
    				temp = curr - power[tree_height-curr_height];
    			}
    			else{
    				// cout<<"hi"<<endl;
    				temp = curr + power[tree_height-curr_height];
    			}

    			// DEBUG(temp);

    			if(temp<power[tree_height+1] and temp>0){
    				curr = temp;
    				curr_height--;
    			}
    		}
            // DEBUG(curr_height);
    		// DEBUG(curr);
    		// cout<<endl;
    	}
    	cout<<curr<<endl;
    }

}