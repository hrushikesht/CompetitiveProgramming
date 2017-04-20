#include <bits/stdc++.h>

using namespace std;

string text = "abaababab";
string pattern = "aba";

int Z[100010];

void zAlgo(){
	string concat = pattern + "$" + text;

	int L,R;
	L = R = 0;

	for(int i=1;i<concat.size();++i){

		if(i>R){

			L = R = i;

			while(R<concat.size() and concat[R-L] == concat[R]){
				R++;
			}
			R--;
			Z[i]=R-L+1;
		}
		else{
			int k=i-L;

			if(Z[k] < R-i+1){
				Z[i]=Z[k];
			}
			else{
				L=i;
				while(R<concat.size() and concat[R-L] == concat[R]){
					R++;
				}
				Z[i]=R-L;
				R--;
			}
		}
	}
}

int main(){

	zAlgo();

	for(int i=0;i<=text.size()+pattern.size()+1;++i){
		cout<<Z[i]<<" ";
	}
	cout<<endl;

	for(int i=1;i<=text.size()+pattern.size();++i){
		if(Z[i]==pattern.size()){
			cout<<"Pattern found at : "<<i-pattern.size()-1<<endl;
		}
	}

}