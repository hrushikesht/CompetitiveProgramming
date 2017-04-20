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
inline bool sortDownByLen( std::pair< ll,ll > p1, std::pair< ll,ll > p2 ){ return p1.S-p1.F > p2.S-p2.F;}

#define MOD 1000000007
using namespace std;
/////////////////////////////////////////////////////////////////////



int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    while(t--)
    {
        // DEBUG(t);
        ll n,k; cin>>n>>k;
        vector< ll > interval;

        string s; cin>>s;

        ll start=1,end=1;

        FOR(i,1,s.size()-1)
        {
            if(s[i] == s[i-1])
            {
                end++;
            }
            else
            {
                // DEBUG(i);
                interval.pb(end-start+1);
                start=i+1;
                end=i+1;
            }
        }
        interval.pb(end-start+1);
        sort(all(interval),sortDown);

        // for(auto it=interval.begin();it<interval.end();++it)
        // {
        //     cout<<*it<<endl;
        // }

        //check 01
        ll req01=0;
        REP(i,s.size())
        {
            if(i&1)
            {
                if(s[i]=='0')
                {
                    req01++;
                }
            }
            else
            {
                if(s[i]=='1')
                {
                    req01++;
                }
            }
        }

        //check 10
        ll req10=0;
        REP(i,s.size())
        {
            if(i&1)
            {
                if(s[i]=='1')
                {
                    req10++;
                }
            }
            else
            {
                if(s[i]=='0')
                {
                    req10++;
                }
            }
        }

        // DEBUG(req10);
        // DEBUG(req01);

        if(min(req01,req10)<=k)
        {
            cout<<1<<endl;
        }
        else
        {
            ll hi,lo;
            hi=interval.at(0);
            lo=2;

            while(hi-lo > 1)
            {
                ll mid=(hi+lo)/2;
                ll cost=0;

                for(auto it=interval.begin();it<interval.end();++it)
                {
                    ll quo=(*it)/(mid+1);
                    cost+=quo;
                }

                // DEBUG(mid);
                // DEBUG(cost);

                if(cost>k)
                {
                    lo=mid;
                }
                else
                {
                    hi=mid;
                }
            }

            ll cost=0;
            for(auto it=interval.begin();it<interval.end();++it)
            {
                ll quo=(*it)/(lo+1);
                cost+=quo;
            }

            if(cost<=k)
            {
                cout<<lo<<endl;
            }
            else
            {
                cout<<hi<<endl;
            }
            
        }
    }
}