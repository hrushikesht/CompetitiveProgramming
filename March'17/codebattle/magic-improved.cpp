#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

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

ll n;
ll arr[100010];
// ll ans[100010];
set<ll> ans;

void solve(ll l,ll r){

    // DEBUG(l);
    // DEBUG(r);

    if(l>r){
        return;
    }

    ll len=r-l+1;
    ll mid= (l+r)/2;
    ll temp=arr[mid];

    ll curr_left=mid;
    ll curr_right=mid;

    if(arr[mid]==0){
        solve(l,curr_left-1);
        solve(curr_right+1,r);
        return;
    }

    ans.insert(temp);

    bool flag=false;
    bool break_flag=false;

    while(curr_right<=r or curr_left>=l){

        // DEBUG(curr_left);
        // DEBUG(curr_right);

        if(flag){
            // cout<<"left"<<endl;
            curr_left--;
            if(curr_left>=l){
                temp = (temp & arr[curr_left]);

                if(temp==0){
                    ans.insert(0);
                    break_flag=true;
                    break;
                }
                else{
                    ans.insert(temp);
                }
            }
            flag=!flag;

        }
        else{
            // cout<<"right"<<endl;
            curr_right++;
            if(curr_right<=r){
                temp = (temp & arr[curr_right]);
                
                if(temp==0){
                    ans.insert(0);
                    break_flag=true;
                    break;
                }
                else{
                    ans.insert(temp);
                }
            }
            flag=!flag;
        }
    }

    
    FOR(i,curr_left,curr_right){
        ll temp=arr[i];
        ans.insert(temp);
        FOR(j,i+1,n){
            temp=(temp&arr[j]);
            ans.insert(temp);
        }
    }

    solve(l,curr_left-1);
    solve(curr_right+1,r);
    
}   


int main(){
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--){
        ans.clear();

        cin>>n;

        FOR(i,1,n){
            cin>>arr[i];
            ans.insert(arr[i]);
        }
        solve(1,n);

        cout<<ans.size()<<endl;
    }   
}