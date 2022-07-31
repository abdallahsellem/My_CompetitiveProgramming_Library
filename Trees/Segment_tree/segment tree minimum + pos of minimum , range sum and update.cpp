#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Nodee{
    int first ;
    int second ;
    int third ;
};
int arr[(int) 4e5 + 5];
int lazy[(int) 4e5+5];
Nodee seg_tree[(int)4e5+5] ;
int n;
/*
void Fix_arr() {

    while (N < n) {
        N *= 2;
    }
    seg_tree.resize(N+1);
}
*/

void propagate(int node, int l, int r) {
    int left_child = node * 2;
    int right_child = node * 2 + 1;
    int mid = (l + r) >> 1;
    seg_tree[left_child].first += (mid - l + 1) * lazy[node];
    seg_tree[right_child].first += (r - mid) * lazy[node];
    seg_tree[left_child].second += lazy[node];
    seg_tree[right_child].second += lazy[node];
    lazy[left_child] += lazy[node];
    lazy[right_child] += lazy[node];
    lazy[node] = 0;
}

void Build(int node, int l, int r) {
    if (l == r) {
        if(arr[l]==1e18)
        {
            seg_tree[node].first = 0;
            seg_tree[node].second = arr[l];
            seg_tree[node].third = l;
        }
        else {
            seg_tree[node].first = arr[l];
            seg_tree[node].second = arr[l];
            seg_tree[node].third = l;
        }
       // cout<<node<<" "<<seg_tree[node].first<<" "<<seg_tree[node].second<<" *** "<<endl ;
        return;
    }
   // cout<<node<<endl ;
    int mid = (l + r) >> 1;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;
    Build(left_child, l, mid);
    Build(right_child, mid + 1, r);
    seg_tree[node].first = seg_tree[left_child].first + seg_tree[right_child].first;
   if(seg_tree[left_child].second<=seg_tree[right_child].second)
   {
       seg_tree[node].second=seg_tree[left_child].second ;
       seg_tree[node].third =seg_tree[left_child].third ;
   }
   else
   {
       seg_tree[node].second=seg_tree[right_child].second ;
       seg_tree[node].third =seg_tree[right_child].third ;
   }
   // cout<<node<<" "<<seg_tree[node].first<<" "<<seg_tree[node].second<<endl ;

}

Nodee query(int node, int l, int r, int x, int y) {
   // cout<<node<<endl ;
    if (l >= x && r <= y) {
        return seg_tree[node];
    }
    if (x > r || y < l) {
        return {0,(int)1e18,-1} ;
    }
   // propagate(node, l, r);
    int mid = (l + r) >> 1;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;
    auto Left_value = query(left_child, l, mid, x, y);
    auto Right_value = query(right_child, mid + 1, r, x, y);
    Nodee temp ;
    temp.first=(Left_value.first + Right_value.first) ;
     if(Left_value.second<=Right_value.second)
     {
         temp.second=Left_value.second ;
         temp.third=Left_value.third ;
     }
     else
     {
         temp.second=Right_value.second ;
         temp.third=Right_value.third ;
     }
     return temp ;
}

void update_range(int node, int l, int r, int x, int y, int value) {
    if (l >= x && r <= y) {
        lazy[node] += value;
        seg_tree[node].first += (r - l + 1) * value;
        seg_tree[node].second += value;
        return;
    }
    if (x > r || y < l) {
        return;
    }
    propagate(node, l, r);
    int left_child = node * 2;
    int right_child = node * 2 + 1;
    int mid = (l + r) >> 1;
    update_range(left_child, l, mid, x, y, value);
    update_range(right_child, mid + 1, r, x, y, value);
    seg_tree[node].first = seg_tree[left_child].first + seg_tree[right_child].first;
    if(seg_tree[left_child].second<=seg_tree[right_child].second)
    {
        seg_tree[node].second=seg_tree[left_child].second ;
        seg_tree[node].third =seg_tree[left_child].third ;
    }
    else
    {
        seg_tree[node].second=seg_tree[right_child].second ;
        seg_tree[node].third =seg_tree[right_child].third ;
    }
}

int32_t main() {
    cin >> n;
    int m ,w ;
    cin>> m>>w ;
    for(int i=0 ;i<=4*n;i++)
    {
        arr[i]=1e18 ;
        seg_tree[i].first =0 ;
        seg_tree[i].second=1e18 ;
    }
    for (int i = 1; i <=n; i++) {
        cin >> arr[i];
    }
   // Fix_arr();
  //  cout<<N<<endl ;
    Build(1, 1, n+1);
  for(int i=0 ;i<m ;i++)
  {
      int pos =query(1,1,n+1,1,n).third ;
      update_range(1,1,n+1,pos,min(pos+w-1,n),1);
  }
  cout<<query(1,1,n+1,1,n).second<<endl ;



}
