#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(i64 i=0;i<(n);i++)
#define FOR(i,a,b) for(i64 i=(a);i<=(b);i++)
#define FORD(i,a,b) for(i64 i=(a);i>=(b);i--)

#define all(v) (v).begin(),(v).end()

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

inline bool sortDown(int x,int y){return x>y;}
inline bool sortPairSecond( std::pair< int,int > p1, std::pair< int,int > p2){ return p1.S>p2.S;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

int que[100010];

int main()
{
    std::ios::sync_with_stdio(false);

    int t; cin>>t;

    while(t--)
    {
        int n; cin>>n;

        bool is_done[100010]={false};
        int time[100010]={0};

        vector<int> boy;

        FOR(i,1,n) 
        {
            cin>>que[i];

            if(que[i]==0)
            {
                boy.pb(i);
            }
        }

        bool flag=true;

        int pass=1;

        while(flag)
        {
            flag=false;

            // DEBUG(pass);
            pass++;

            int index=1;
            for(auto it=boy.end();it>=boy.begin();--it)
            {
                // DEBUG(index);
                // DEBUG(*it);
                while(*it<=n-1 and que[*it+1]==1)
                {
                    flag=true;

                    // cout<<"yo"<<endl;

                    swap(que[*it],que[*it+1]);

                    *it+=1;
                    time[index]++;
                }
                index++;
            }
        }

        int maxi=0;

        FOR(i,1,boy.size())
        {
            maxi=max(maxi,time[i]);
        }   

        cout<<maxi<<endl;
        cout<<endl;

    }
}