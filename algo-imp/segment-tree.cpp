#include <bits/stdc++.h>

#define DEBUG(x) cout<<">"<<#x<<": "<<x<<endl;

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

using namespace std;

int seg[1000];

void build(int *a,int l,int r,int index)
{
    if(l==r)
    {
        seg[index]=a[l];
    }
    else
    {
        int mid=(l+r)/2;

        build(a,l,mid,left(index));
        build(a,mid+1,r,right(index));
        seg[index]=seg[left(index)]+seg[right(index)];
    }
}

void update(int i,int x,int node,int l,int r)
{
    seg[node]+=x;

    if(r-1>=l)
    {
        int mid=(l+r)/2;

        if(i<=mid)
        {
            update(i,x,left(node),l,mid);
        }
        else
        {
            update(i,x,right(node),mid+1,r);
        }
    }
}

int query(int x,int y,int node=0,int l=0,int r=8)
{
    if(x>r or y<l) return 0;
    if(x<=l and y>=r) return seg[node];

    int mid=(l+r)/2;

    DEBUG(l);
    DEBUG(mid);
    DEBUG(r);

    int q1=query(x,y,left(node),l,mid);
    int q2=query(x,y,right(node),mid+1,r);

    
    DEBUG(q1);
    DEBUG(q2);

    return q1+q2;
}

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8};    

    build(a,0,8,0);

    // update(5,2,0,0,8);

    for(int i=0;i<20;i++)
    {
        cout<<i<<" "<<seg[i]<<endl;
    }
    cout<<endl;

    cout<<query(3,5)<<endl;
    cout<<query(4,8)<<endl;

}