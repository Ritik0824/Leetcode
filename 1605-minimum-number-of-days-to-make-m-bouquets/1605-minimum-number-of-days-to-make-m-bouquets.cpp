class Solution {

private:
    int func(vector<int>& day,int mid,int m, int k){
        int cnt = 0;
        int boq = 0;
        for(int i = 0; i < day.size(); i++){
            if(day[i] <= mid){
                cnt ++;
            }
            else{
                boq += (cnt/k);
                cnt = 0;
            }
        }
        boq += (cnt / k);
        return boq >= m;

    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int lo = *min_element(bloomDay.begin(),bloomDay.end());

        int hi = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = 0;
        long long val = m * 1ll * k * 1ll;
        if(val > n){
            return -1;
        }

        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(func(bloomDay,mid,m,k)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }    
        }
        return ans;


    }
};