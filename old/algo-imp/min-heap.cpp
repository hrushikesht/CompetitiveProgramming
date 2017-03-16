#include <bits/stdc++.h>
#include <unordered_map>

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};


class minHeapSort
{
private:
    int a[100010];
    int len;

    void minHeapify(int x,int pseudo_len);
    void buildHeap(int size);

public:
    void heapSort();
    void insert(int *arr,int size);
    void printList();
};

void minHeapSort::insert(int *arr,int size)
{
    len = size;

    for(int i=0;i<len;++i)
    {
        a[i]=arr[i];
    }
}

void minHeapSort::printList()
{
    std::cout<<"List : ";
    for(int i=0;i<len;++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

void minHeapSort::minHeapify(int x,int pseudo_len)
{
    int l=left(x);
    int r=right(x);

    int smallest=x;

    if(l<pseudo_len and a[l]<a[x])
    {
        smallest=l;
    }

    if(r<pseudo_len and a[r]<a[smallest])
    {
        smallest=r;
    }

    if(smallest!=x)
    {
        int temp=a[smallest];
        a[smallest]=a[x];
        a[x]=temp;

        minHeapify(smallest,pseudo_len);
    }
}

void minHeapSort::buildHeap(int size)
{
    for(int i=len/2;i>=0;--i)
    {
        minHeapify(i,len);
    }
}

void minHeapSort::heapSort()
{
    buildHeap(len);

    int pseudo_len=len;

    for(int i=0;i<len-1;++i)
    {
        int temp=a[0];
        a[0]=a[pseudo_len-1];
        a[pseudo_len-1]=temp;

        pseudo_len-=1;

        minHeapify(0,pseudo_len);
    }
}


int main()
{
    minHeapSort x;

    int b[]={1,5,9,7,4,5,8,9,6,7};

    x.insert(b,10);
    x.printList();

    x.heapSort();
    x.printList();
}