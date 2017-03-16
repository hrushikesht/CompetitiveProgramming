#include <bits/stdc++.h>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define F first
#define S second
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
// inline bool sortDown(int x,int y){return x>y;}
/////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>

using namespace std;

int main()
{
   fstream file; //object of fstream class
   
   //opening file "sample.txt" in out(write) mode
   // file.open("output.txt",ios::out);
   
   // if(!file)
   // {
       // cout<<"Error in opening file!!!"<<endl;
       // return 0;
   // }
   
   // cout<<"File created successfully."<<endl;
   //write text into file
   // file<<"ABCD.";
   //closing the file
   // file.close();
   
   //again open file in read mode
   file.open("output.txt",ios::in);
   
   if(!file)
   {
       cout<<"Error in opening file!!!"<<endl;
       return 0;
   }   
   
   //read untill end of file is not found.
   char ch; //to read single character
   cout<<"File content: ";
   // int index=0;
   
   while(!file.eof())
   {
   		// cout<<index++<<endl;
       file>>ch; //read single character from file
       // cout<<ch;
       // cout<<typeid(ch).name()<<endl;
       int r1,c1,r2,c2,index=1;
       while(index<5)
       {
       		DEBUG(index);
       		cout<<"ch->"<<	ch<<endl;
       		cout<<index<<endl;
    		if(!isspace(static_cast<unsigned char>(ch)))
    		{
    			switch(index)
    			{
    				case 1:
    					r1=ch-'0';
    					break;
    				case 2:
    					c1=ch-'0';
    					break;
    				case 3:
    					r2=ch-'0';
    					break;
    				case 4:
    					c2=ch-'0';
    					break;
    			}
    			index++;
    		}
    		file>>ch;
    	}
    	cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
   }
   
   file.close(); //close file
   
   return 0;
}