class Solution {
public:
    string removeDuplicateLetters(string s) {
   stack<char> charStack;

    // Frequency array
    vector<int> count(26, 0); 

    // Boolean array to track whether a character is in the stack
     vector<bool> inStack(26, false);
    
    // Count the occurrences of each character in the string
    for (char c : s) {
        count[c - 'a']++;  }

     // Decrement the count of the current character
    for (char c : s) {
        count[c - 'a']--;
        
        // If the character is already in the stack, skip it    
        if (inStack[c - 'a']) {
                continue; 
                          }
            
        // Pop characters from the stack as long as the current character is smaller
        // and there are more occurrences of the character at the top of the stack
        while (!charStack.empty() && c < charStack.top() && count[charStack.top() - 'a'] > 0) {
                inStack[charStack.top() - 'a'] = false;
                charStack.pop();
            }
            
        // Push the current character onto the stack
            charStack.push(c);
            inStack[c - 'a'] = true;
                      }
    
    // Construct the result string by popping characters from the stack
    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }
    
    return result;
   }
};