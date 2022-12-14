#include <iostream>

using namespace std;
int seg_tree[(int)1e5+5] ;
int arr[(int)1e5+5] ;
int lazy[(int)1e5] ;
int n ;
int N =1 ;
void Fix_arr()
{

    while(N<n)
    {
        N*=2 ;
    }
    for(int i=n+1 ; i<=N ; i++)
    {
        arr[i]=0 ;
    }
}
int propagate(int node,int l ,int r)
{
    int left_child =node*2 ;
    int right_child =node*2+1 ;
    int mid = (l+r)>>1 ;
    seg_tree[left_child]+=(mid-l+1)*lazy[node] ;
    seg_tree[right_child]+=(r-mid)*lazy[node] ;
    lazy[left_child]+=lazy[node] ;
    lazy[right_child]+=lazy[node] ;
    lazy[node]= 0 ;
}
void update_point(int i ,int value)
{
    int node = i+N-1 ;
    arr[node] +=value ;
     seg_tree[node]+=value ;
    while(node>1)
    {
       node/=2 ;
        int left_child =node*2 ;
        int right_child =node*2+1 ;
seg_tree[node]=seg_tree[left_child]+seg_tree[right_child] ;
    }
    return  ;
}
void Build(int node,int l,int r)
{
    if(l==r)
    {
        seg_tree[node]=arr[l] ;
        return ;
    }
    int mid =(l+r)>>1 ;
    int left_child = 2*node ;
    int right_child =2*node+1 ;
    Build(left_child,l,mid) ;
    Build(right_child,mid+1,r) ;
    seg_tree[node]=seg_tree[left_child]+seg_tree[right_child] ;
}
int query(int node,int l,int r,int x,int y)
{
    if(l>=x&&r<=y)
    {
        return seg_tree[node] ;
    }
    if(x>r||y<l)
    {
        return 0 ;
    }
    propagate(node,l,r) ;
    int mid =(l+r)>>1 ;
    int left_child = 2*node ;
    int right_child =2*node+1 ;
    int Left_value=query(left_child,l,mid,x,y) ;
    int Right_value = query(right_child,mid+1,r,x,y) ;
    return Left_value+Right_value ;
}
void update_range(int node ,int l,int r,int x,int y,int value )
{
    if(l>=x&&r<=y)
    {
        lazy[node]+=value ;
        seg_tree[node]+=(r-l+1)*value ;
        return ;
    }
    if(x>r||y<l)
    {
        return  ;
    }
    propagate(node,l,r) ;
    int left_child =node*2 ;
    int right_child =node*2+1 ;
    int mid =(l+r)>>1 ;
    update_range(left_child ,l,mid,x,y,value) ;
    update_range(right_child ,mid+1,r,x,y,value) ;
    seg_tree[node]=seg_tree[left_child]+seg_tree[right_child];
}

int main()
{
    cin>>n ;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>arr[i] ;
    }
    Fix_arr() ;
    Build(1,1,N) ;
    int k ;
    cin>> k ;
    for(int i=0 ; i<k ; i++)
    {
        int l,r ,z,point;
        cin>> l>>r>>z>>point ;
        cout<< query(1,1,N,l,r)<<endl ;
        update_point(point,z) ;
         cout<< query(1,1,N,l,r)<<endl ;
    }
}
