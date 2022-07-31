void trace(int index,int rem)
{
    if(index==n)
    {
        return ;
    }
    int take =0 ;
    int leave =0 ;
    if(rem>=vv[index])
    {
        take =vec[index].second+dp(index+1,rem-vv[index]) ;
    }
    leave =dp(index+1,rem) ;
    if(take==dp(index,rem))
    {
        tra.push_back({vec[index].first,vec[index].second}) ;
        trace(index+1,rem-vv[index]);
    }
    else
        trace(index+1,rem) ;


}