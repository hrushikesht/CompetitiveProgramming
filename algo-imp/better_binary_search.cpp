#include <bits/stdc++.h>

using namespace std;

/*******************************
This binary search is precise when
we know that answer is between 1 and some number B.
Set, mid=sqrt(hi*lo).
If, the answer is less than 1, check for 1 and if 
function is not satisfied, then do normal binary search for
[0,1]
*******************************/

bool check(int x){
	//Enter your monotonic function here.
}

int main(){


    if(check(1)){
    	
    	// Do check for 1 if satisfied
    	// do bs for [1,infi]

        lo=1;
        while(abs(hi-lo)>eps){
            
            mid=sqrt(hi*lo);

            if(check(mid)){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
    }
    else{
        lo=0;
        while(abs(hi-lo)>eps){
            
            mid=(hi+lo)/2;

            if(check(mid)){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
    }   

}