#include <bits/stdc++.h>

int arr[10010];

// Including a comparison operator in User-Defined Structs
struct P{
    int x,y;

    //Notice the strict syntax
    //We need to give only the other element as a parameter
    bool operator<(const P &p){
        if(x != p.x) return x<p.x;
        return y<p.y;
    }
}


// Compact Implementation of Binary Search

int n=100; //number of elements in array
int k=1;
int x=10; // Element to be found

for(int b=(n>>1);b>=1;b=(b>>1)){
    while(k+b<=n and arr[k+b]<=x) k+=b;
}
//check k
if(arr[k]==x){} //found


//Use of above method to find the max(min) value of a function
int k=-1; // the domain of the function is assumed to be [0,z]
int z=LLONG_MAX //upper bound of the domain

for(int b=z;b>=1;b=(b>>1)){
    // Here we increment k as long as derivative at k is positive(-ve)
    // As k moves closer and closer, finally we get k to be maximun
    // integer where derivative is +ve(-ve)
    while(f(k+b)<f(k+b+1)) k+=b;
}

int ans=k+1;

int main(){

}