class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& po, long long success) {
        vector<int> v;
        //sorting the potion array
        sort(po.begin(),po.end());

        for(int i=0;i<s.size();i++){
            int count=0;
            int l=0,r=po.size()-1;
            int mid=l + (r-l)/2;
            //Using Binary Search on potion array
            while(l<=r){
                if(s[i]*1ll*po[mid] >= success){//1LL is securely integer overflow
                    count=po.size()-mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
                mid= l + (r-l)/2;
            }
            v.push_back(count);
        }
        
        return v;
    }
};