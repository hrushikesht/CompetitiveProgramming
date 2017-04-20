#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

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
inline bool sortPairSecond( std::pair< ll,ll > p1, std::pair< ll,ll > p2){ return p1.S>p2.S;}

#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////



int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--)
    {
        ll n; cin>>n;

        vector<ll> blank;

        string s; cin>>s;
        ll start=0;

        if(s[0] == s[n-1])
        {
            start=n-1;

            FORD(i,n-2,0)
            {
                if(s[0]==s[i])
                {
                    start--;
                }
                else break;
            }
        }

        // DEBUG(start);

        ll size=0;
        bool curr_flag=true;

        if(s[start] == '1')
        {
            curr_flag=false;
            size=0;
        }

        FOR(i,start,start+n-1)
        {
            // DEBUG(i);
            // DEBUG(s[i%n]);
            // DEBUG(size);
            // DEBUG(curr_flag);

            if(s[i%n] == s[(i+1)%n] )
            {
                if(curr_flag)
                {
                    size++;
                }
            }
            else
            {
                if(curr_flag)
                {
                    blank.pb(size+1);
                    size=0;
                }
                curr_flag=!curr_flag;
            }
            // cout<<endl;
        }

        if(blank.size()!=0)
        {
            // sort(all(blank),sortDown);

            ll maxito=-100;
            ll sum=0;
            for(auto it=blank.begin();it<blank.end();++it)
            {
                // DEBUG(*it);
                maxito=max(maxito,*it);
                sum+=*it;
            }
            cout<<sum-maxito<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}