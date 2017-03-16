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

    FOR(p,1,t)
    {

        string  so[110];
        char sc[110][110];
        ll length[110];

        ll n; cin>>n;

        vector< pair<char*,int> > names;

        // DEBUG(n);  
        FOR(i,0,n)
        {
            // DEBUG(i);
            std::getline(std::cin,so[i]);
            // cout<<"got first output"<<endl;
            // cout<<so[i]<<endl;
            // cout<<endl;
        }


        FOR(i,0,105)
        {
            FOR(j,0,105)
            {
                sc[i][j]='\0';
            }
        }


        FOR(i,1,n)
        {
            // DEBUG(i);
            int index=0,j=0;
            ll len=so[i].size();
            // DEBUG(so[i].size());


            while(j<len)
            {
                // DEBUG(i);
                // DEBUG(j);
                // DEBUG(so[i][j]);
                if(so[i][j]!=' ')
                {
                    sc[i][index]=so[i][j];
                    index++;
                }
                j++;
            }
            
        }

        ll maxito=-1;
        FOR(i,1,n)
        {
            // DEBUG(i);
            set<char> s;
            ll j=0;

            while(sc[i][j]!='\0')
            {
                // DEBUG(sc[i][j]);
                s.insert(sc[i][j]);
                j++;
            }

            length[i]=s.size();

            ll temp=s.size();
            maxito=max(maxito,temp);
        }

        // DEBUG(maxito);

        FOR(i,1,n)
        {
            // DEBUG(length[i]);
            // DEBUG(maxito);

            if(length[i] == maxito)
            {
                names.pb(mp(sc[i],i));
            }
        }

        string soka=so[names[0].S];
        ll stored=0;


        FOR(i,0,names.size()-1)
        {
            // DEBUG(i);
            string temp=so[names[i].S];
            if( soka > temp)
            {
                soka=so[names[i].S];
            }

            // DEBUG(soka)
        }

        // DEBUG(names.size());

        // sort(all(names));

        // DEBUG(names.at(0).F);
        // DEBUG(names.at(1).F);

        cout<<"Case #"<<p<<": "<<soka<<endl;
        // cout<<endl;
    }
}