class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // base cases
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);

        // finding middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* Prev = NULL;

        while(fast && fast->next){
            Prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        // creating tree node & dividing list in two parts & recursive calls for leftSubList & rightsubList
        ListNode* Middle = slow;
        Prev->next = NULL;

        TreeNode* root = new TreeNode(Middle->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(Middle->next);

        // return answer 
        return root;
    }
};