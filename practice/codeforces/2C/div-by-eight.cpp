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

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    int n=s.size();

    REP(i,n){
    	if(s[i]=='0' or s[i]=='8'){
    		cout<<"YES"<<endl;
    		cout<<s[i]<<endl;
    		return 0;
    	}
    	FOR(j,i+1,n-1){

    		if(!(((int)s[j])&1)){
    			int x = ((int)s[i])*10+((int)s[j]);
    			if(x%8==0 and s[i]!='0'){
    				cout<<"YES"<<endl;
    				cout<<s[i]<<s[j]<<endl;
    				return 0;
    			}
    		}

    		FOR(k,j+1,n-1){
    			if(((int)s[k])&1) continue;

    			int num=((int)s[i]-'0')*100+((int)s[j]-'0')*10+((int)s[k]);
    			if(num%8==0 and (int)s[i]!='0'){
    				cout<<"YES"<<endl;
    				cout<<s[i]<<s[j]<<s[k]<<endl;
    				return 0;
    			}
    		}
    	}
    }
    cout<<"NO"<<endl;
    return 0;
}
