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

ll arr[100010];
ll twos[100010];

int main()
{
    std::ios::sync_with_stdio(false);

    ll t; cin>>t;

    ll lim = 31000;

    twos[0]=1;
    FOR(i,1,lim)
    {
        twos[i] = (2*twos[i-1])%MOD;
    }

    while(t--)
    {
        ll n; cin>>n;

        FOR(i,1,n) cin>>arr[i];
        vector<ll> pro;

        arr[1]=1;

        ll size=0,ans=1;
        bool flag=false;
        bool stop_flag=false;

        ll prev=1;

        FOR(i,1,n)
        {
            if(arr[i] == -1)
            {
                if(flag)
                {
                    size++;
                }
                else
                {
                    flag=true;
                    size=1;
                    prev=arr[i-1];
                }
            }
            else
            {
                if(flag)
                {
                    // pro.pb(size);
                    // DEBUG(arr[i]);
                    // DEBUG(i);
                    ll x=arr[i];
                    // DEBUG(size);
                    // DEBUG(prev);

                    ll temp_pro=0;

                    if(x==1)
                    {
                        // cout<<"x is one"<<endl;
                        pro.pb(size);
                    }
                    else
                    {
                        if(prev+size+1 == x)
                        {
                            // cout<<"x spans"<<endl;
                            temp_pro+=1;
                            pro.pb(0);
                        }
                        else
                        {
                            // cout<<"we are free"<<endl;
                            if(prev+size+1<=x)
                            {
                                pro.pb(size-x+1);
                            }
                            else
                            {
                                DEBUG(prev);
                                DEBUG(size);
                                DEBUG(i);
                                DEBUG(x);
                                cout<<0<<endl;
                                stop_flag=true;
                                break;
                            }
                        }
                    }

                    size=0;
                    flag=false;
                }
                // cout<<endl;
            }
        }

        if(stop_flag)
        {
            continue;
        }

        // DEBUG(size);

        if(size!=0)
        {
            // DEBUG(size);
            pro.pb(size);
        }

        ll sum=0;

        pro.pb(0);
        for(auto it=pro.begin();it<pro.end();++it)
        {
            // DEBUG(*it);
            sum+=*it;
        }

        
        if(pro.size()!=0)
        {
            // DEBUG(sum);
            if(sum == n) cout<<twos[n-1]<<endl;
            else cout<<twos[sum]<<endl;
        }
    }
}