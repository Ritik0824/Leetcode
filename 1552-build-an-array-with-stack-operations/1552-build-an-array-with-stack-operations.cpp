class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector <string> str;
        int j = 0;
        for(int i = 1; i <= n; i++){
            //push(i);
            str.push_back("Push");
            

            if(i != target[j]){
                //pop(i);
                str.push_back("Pop");  
                j--;
            }
            j++;
            if(j >= target.size()){
                return str;
            }
        }
        return str;
    }
};