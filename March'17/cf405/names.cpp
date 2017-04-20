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

ll n,k;
char names[55][3];
bool is_ok[100]={false};
ll status[100];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;

    FOR(i,1,n-k+1){
    	string s; cin>>s;
    	if(s=="YES"){
    		is_ok[i]=true;
    	}
    }

    FOR(i,1,26){
    	names[i][0]=(char)('A');
    	names[i][1]=(char)((int)'a' + i-1);
    	names[i][2]='\0';
    }

    FOR(i,27,52){
    	names[i][0]='B';
    	names[i][1]=(char)((int)'a'+i-27);
    	names[i][2]='\0';
    }

    // FOR(i,1,52){
    // 	cout<<names[i]<<endl;
    // }

    // ll curr_left=1;
    // ll curr_right=k;
    ll new_indx;

    if(is_ok[1]){
    	FOR(i,1,k){
    		cout<<names[i]<<" ";
    		status[i]=i;
    	}
        new_indx=k+1;
    }
    else{
    	FOR(i,1,k-1){
    		cout<<names[i]<<" ";
    		status[i]=i;
    	}
    	cout<<names[1]<<" ";
    	status[k]=1;
        new_indx=k;
    }

    // FOR(i,1,n-k+1){
    //     cout<<is_ok[i]<<" ";
    // }
    // cout<<endl;

    FOR(i,2,n-k+1){
    	if(is_ok[i]){
            if(is_ok[i-1]){
                status[i+k-1]=status[i-1];
                cout<<names[status[i-1]]<<" ";
            }
            else{
                status[i+k-1]=new_indx;
                new_indx++;
                // DEBUG(status[i+k-1]);
                // DEBUG(names[status[i+k-1]]);
                cout<<names[status[i+k-1]]<<" ";
            }
        }
        else{
            if(is_ok[i-1]){
                status[i+k-1]=status[i];
                cout<<names[status[i]]<<" ";
            }
            else{
                status[i+k-1]=status[i];
                cout<<names[status[i]]<<" ";
            }
        }
    }
    cout<<endl;
}