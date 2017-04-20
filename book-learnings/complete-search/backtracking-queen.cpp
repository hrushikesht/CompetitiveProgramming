#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N=16;
int c=0;
ll rec_call=0;
int r1[100010]={0},r2[100010]={0},r3[100010]={0};

void search(int y){
    rec_call++;

    if(y==N){
        c++;
        return;
    }
    else{
        for(int x=0;x<N;++x){
            if(r1[x] or r2[x+y] or r3[x-y+N-1]) continue;
            r1[x] = r2[x+y] = r3[x-y+N-1] = 1;
            search(y+1);
            r1[x] = r2[x+y] = r3[x-y+N-1] = 0;
        }
    }
}

int main(){

    search(0);
    cout<<"Total Possible Positions: "<<c<<endl;
    cout<<"Total Recursive Calls: "<<rec_call<<endl;
}