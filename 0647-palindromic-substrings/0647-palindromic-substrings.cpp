class Solution {
public:
    bool isPalindrome(int left,int right, string s){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
       int ans = 0;
       for(int i = 0; i <s.size(); i++){
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(i,j,s)){
                ans++;
            }
        }
       }
       return ans; 
    }
};