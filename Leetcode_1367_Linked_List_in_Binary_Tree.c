/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct ListNode* head, struct TreeNode* root){
    if (!head) return true;
    if (!root) return false;
    return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if (!head) return true;
    if (!root) return false;
    return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}