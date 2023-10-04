class Solution {
private:
    int check(vector<int>& weights, int cap){
        int day = 1;
        int load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > cap){
                day++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(),weights.end());
        int sum = 0;
        int hi = accumulate(weights.begin(),weights.end(),sum);

        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(weights,mid) <= days){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};