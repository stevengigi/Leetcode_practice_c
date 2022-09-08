void dfs(struct TreeNode* root, char* res, int* idx) {
    if (!root) return;
    (*idx) += sprintf(res + (*idx), "%d", root->val);
    if (root->left) {
        res[(*idx)++] =' (';
        dfs(root->left, res, idx);
        res[(*idx)++]=')';
    } else if (!(root->left) && root->right) {
        res[(*idx)++] = '(';
        res[(*idx)++] = ')';
    }
    if (root->right) {
        res[(*idx)++] = '(';
        dfs(root->right, res, idx);
        res[(*idx)++] = ')';
    }
}

char* tree2str(struct TreeNode* root) {
    if (!root) return "";
    char* res = (char*) malloc(100000 * sizeof(char));
    int idx = 0;
    idx += sprintf(res, "%d", root->val);
    if (root->left) {
        res[idx++] = '(';
        dfs(root->left, res, &idx);
        res[idx++] = ')';
    } else if (!(root->left) && root->right) {
        res[idx++] = '(';
        res[idx++] = ')';
    }
    if (root->right) {
        res[idx++] = '(';
        dfs(root->right, res, &idx);
        res[idx++] = ')';
    }
    res[idx++] = '\0';
    return res;
}