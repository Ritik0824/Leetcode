class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i=0, j=1e9, n=citations.size(), ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            int cnt=lower_bound(citations.begin(), citations.end(), mid)-citations.begin();
            if(n-cnt>=mid){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};