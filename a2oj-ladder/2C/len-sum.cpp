#include <bits/stdc++.h>

#define ll long long int

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()

using namespace std;
///////////////////////////////////////////////////////

int m,s;
int dig[110];
int rev_dig[110];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>m>>s;

    int old_s=s;

    if(s==0 and m==1){
    	cout<<"0 0"<<endl;
    	return 0;
    }

    if(9*m<s or s==0){
    	cout<<"-1 -1"<<endl;
    }
    else{
    	int index=1;
    	while(s>0){
    		if(s>8){
    			dig[index++]=9;
    			s-=9;
    		}
    		else{
    			dig[index++]=s;
    			FOR(i,index,m){
    				dig[i]=0;
    			}
    			break;
    		}
    	}

    	//minimum digits
    	rev_dig[1]=1;
    	s=old_s;
    	s-=1;
    	index=m;
    	while(s>0){
    		if(s>8){
    			rev_dig[index--]=9;
    			s-=9;
    		}
    		else{
    			if(index!=1){
    				rev_dig[index--]=s;
    				FOR(i,2,index) rev_dig[i]=0;
    			}
    			else rev_dig[1]+=s;
    			break;
    		}
    	}

    	FOR(i,1,m) cout<<rev_dig[i];
    	cout<<" ";
    	FOR(i,1,m) cout<<dig[i];
    	cout<<endl;
    }
}
