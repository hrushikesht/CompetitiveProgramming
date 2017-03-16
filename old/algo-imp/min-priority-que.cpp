#include <bits/stdc++.h>
#include <unordered_map>

#define DEBUG(x) cout<<">"<<#x<<": "<<x<<endl;

inline int parent(int x){return floor((x-1)/2);};
inline int left(int x) {return 2*x+1;};
inline int right(int x){return 2*x+2;};

using namespace std;


class minHeapSort
{

public:
    int a[100010];
    int len;

    void minHeapify(int x,int pseudo_len);
    void buildHeap(int size);

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

class minPriorityQueue :public minHeapSort
{
public:

    void insertQueue(int *arr,int size)
    {
        len = size;

        for(int i=0;i<len;++i)
        {
            a[i]=arr[i];
        }

        buildHeap(size);
    }

    int getMinimum()
    {
        return a[0];
    }

    void removeMin()
    {

        if(len==0)
        {
            cout<<"Error Elements Underflow"<<endl;
        }

        else
        {
            int temp=a[0];
            a[0]=a[len-1];
            a[len-1]=temp;

            len-=1;

            minHeapify(0,len);
        }
    }

    void decreaseKey(int i,int k)
    {
        if(a[i]<k)
        {
            cout<<"Error: Priority already low";
        }
        else
        {
            a[i]=k;
            while( i>=0 and parent(i)>=0 and a[parent(i)]>a[i])
            {
                // DEBUG(i);
                // DEBUG(parent(i));
                // DEBUG(a[i]);
                // DEBUG(a[parent(i)]);
            
                int temp=a[i];
                a[i]=a[parent(i)];
                a[parent(i)]=temp;

                i=parent(i);
            } 
        }
    }

    void insertElement(int k)
    {
        a[len]=1000;
        len++;

        decreaseKey(len-1,k);
    }

};


int main()
{
    minPriorityQueue q;

    int b[]={1,5,9,7,4,5,8,9,6,7};

    q.insertQueue(b,10);
    q.printList();

    q.decreaseKey(3,2);
    q.printList();

    q.insertElement(3);
    q.printList();

    DEBUG(q.getMinimum());
    q.removeMin();
    q.printList();


}