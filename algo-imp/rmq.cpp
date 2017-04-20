#include <bits/stdc++.h>

using namespace std;

const int N=100010;

int arr[N+10];
int naiveRMQ_data[N+10][N+10];

//Preprocess O(n^2) Query O(1)
void naiveRMQ(n){

    for(int i=1;i<=n;++i){
        naiveRMQ_data[i][i]=arr[i];

        for(int j=i+1;i<=n;++j){
            if(naiveRMQ_data[i][j-1]<arr[j]){
                naiveRMQ_data[i][j]=naiveRMQ_data[i][j-1];
            }
            else{
                naiveRMQ_data[i][j]=arr[j];
            }
        }
    }
}

void naiveRMQQuery(int l,int r){
    return naiveRMQ_data[l][r];
}

//Preprocess O(n) query(sqrt(n))
void blockRMQ(){

    for(i=0;i<sqrt(N);i++)
}


int main(){

}