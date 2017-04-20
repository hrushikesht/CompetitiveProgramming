#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout<<#x<<":> "<<x<<endl;

string text = "ababacababc";
string pattern = "ababac";

int F[100010];

void kmpFailure(){
	F[0] = F[1] = 0;

	for(int i=2; i<=pattern.size();++i){
		int j=F[i-1];

		while(1){
			if(pattern[j] == pattern[i-1]){
				F[i]=j+1; break;
			}
			if(j==0){
				F[i]=0;
				break;
			}
			j=F[j];
		}
	}
}

void kmpMatch(){
	kmpFailure();

	int i,j;
	i = 0;
	j = 0;

	for(int k=0;k<=pattern.size();++k){
		cout<<F[k]<<" ";
	}
	cout<<endl;

	while(1){
		if(j==text.size()-1) break;

		if(text[i] == pattern[i]){
			i++;
			j++;
			if(i==pattern.size()) cout<<"match found at j = "<<j<<endl;
		}
		else if(i>0){
			i=F[i];
		}
		else j++;
	}
}

int main(){
	kmpMatch();
}