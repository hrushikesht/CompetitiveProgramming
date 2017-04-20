#include <bits/stdc++.h>

// Following implementation is used for ranged sum queries
// This uses BIT

const int N=100010;

int tree[N];

void updateBIT(int n,int index,int val){
	
	while(index<=n){
		tree[index]+=val;
		index+=(index & (-index));
	}
}



void constructBIT(int *arr){

	for(int i=0;i<=n;i++0){
		tree[i]=0;
	}

	for(int i=1;i<=n;i++){
		updateBIT(n,i,arr[i]);
	}
}

int getSum()



int main(){
	int a[]={0,1,8,7,4,5,9,6,5,4,1,5,4,8,6,4,1};
	int n = 16;
	constructBIT(a);
}