class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n + 1, 1);
        vector<int> suff(n + 1, 1);
        vector<int>ans(n,0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i];
        }
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 1; i--)
        {
            suff[i] = suff[i + 1] * nums[i];
        }
        for(int i=0;i<n;i++){
            int a=1;
            int b=1;
            if(i>=1){
                a=pre[i-1];
            }
            if(i<=n-1){
                b=suff[i+1];
            }
            ans[i]=a*b;
        }
        for(int i=0;i<n;i++){
            cout<<pre[i]<<" ";
        }cout<<endl;  
         for(int i=n-1;i>=0;i--){
            cout<<suff[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
};