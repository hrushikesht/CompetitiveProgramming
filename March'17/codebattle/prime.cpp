#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <limits.h>
#include <iterator>

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

ll arr[100010];
ll test_case[10];
vector<ll> ans;

void cal(ll n,ll *prime){

    FOR(i,2,LLONG_MAX){

        if(ans.size()>=n){
            break;
        }

        FOR(j,0,14){
            if(!(i%prime[j])){
                ans.pb(i);
                break;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;
    ll test=t;
    ll maxito=-1;

    ll prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    FOR(i,1,t){
        cin>>test_case[i];
        maxito=max(test_case[i],maxito);
    }

    cal(maxito,prime);

    // for(vector<ll>::iterator it=ans.begin();it<ans.end();++it){
    //     cout<<*it<<endl;
    // }

    FOR(i,1,test){
        cout<<ans[test_case[i]-1]<<endl;
    }


}