#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define i64 long long int

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
using namespace std;
/////////////////////////////////////////////////////////////////////

// bool is_done[100000][100000]={false};
vector< vector<bool> > is_done (100010,vector<bool> (100010,false));
vector< pair<int,int> > G[100010];
vector< pair<int,int> > edges;


int main()
{
	std::ios::sync_with_stdio(false);

	int n,e; cin>>n>>e;

	FOR(i,1,e)
	{
		int a,b; cin>>a>>b;
		edges.pb(mp(a,b));
		G[a].pb(mp(b,1));
		G[b].pb(mp(a,0));
	}

	FOR(i,1,n)
	{

		DEBUG(i);

		if((G[i].size()!=0) and ((G[i].size()&1)==0))
		{

			int half = G[i].size()>>1;
			int out=0,in=0;

			for(auto it=G[i].begin();it<G[i].end();++it)
			{
				DEBUG(it->F);
				DEBUG(it->S);

				if(is_done.at(i).at(it->F))
				{
					out++;
				}
				else if(is_done.at(it->F).at(i))
				{
					in++;
				}
				else
				{
					int flag=it->S;
					
					if(out<half)
					{
					    if(it->S == 1)
					   { 
					        out++;
					        is_done.at(i).at(it->F)=true;
					        continue;
					   }
					}
				    
				    if(in<half and (it->S == 0))
					{
					    in++;
					    is_done.at(it->F).at(i)=true;
					    continue;
					}
					
					if(out<half and (it->S == 0))
					{
						out++;
					    auto index= find(edges.begin(),edges.end(),mp(it->F,i));
					    
					    if(index==edges.end())
					    {
					    	cout<<"You are wrong"<<endl;
					    	return 0;
					    }

					    is_done.at(it->F).at(i)=true;
					    is_done.at(i).at(it->F)=true;
						
						index->F = i;
						index->S = it->F;

						DEBUG(index->F);
						DEBUG(index->S);

						it->S= 0;

						auto it2 = find(G[it->F].begin(),G[it->F].end(),mp(i,1));
						it2->S=0;
					}
					else
					{
						in++;
						auto index= find(edges.begin(),edges.end(),mp(i,it->F));
					    
					    if(index==edges.end())
					    {
					    	cout<<"You are wrong"<<endl;
					    	return 0;
					    }
						
						index->F = it->F;
						index->S = i;

						is_done.at(it->F).at(i)=true;
					    is_done.at(i).at(it->F)=true;

						DEBUG(index->F);
						DEBUG(index->S);

						it->S= 1;

						auto it2 = find(G[it->F].begin(),G[it->F].end(),mp(i,0));
						it2->S=1;
					}
					
				}
			}

			DEBUG(half);
			DEBUG(in);
			DEBUG(out);
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;
	for(auto it=edges.begin();it<edges.end();++it)
	{
		cout<<it->F<<" "<<it->S<<endl;
	}
	return 0;

}