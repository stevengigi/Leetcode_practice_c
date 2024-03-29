/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* node, int* returnSize, int** returnColumnSizes){
    *returnSize=m;
    *returnColumnSizes=(int*)malloc(sizeof(int)*m);
    int **matrix=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        matrix[i]=(int*)calloc(n,sizeof(int));
        (*returnColumnSizes)[i]=n;
        memset(matrix[i],-1,sizeof(int)*n);
    }
    int rowstart=0;
    int rowend=m-1;
    int colstart=0;
    int colend=n-1;
    struct ListNode* head=node;
    while(head!=NULL){
        // printf("rowstart : %d | rowend : %d | colstart : %d | colend : %d\n",rowstart,rowend,colstart,colend);
        int i=colstart;
        while(head && i<=colend){

            matrix[rowstart][i]=head->val;
            head=head->next;
            i++;
        }
        rowstart++;
        // printf("\n");
        // printf("rowstart : %d | rowend : %d | colstart : %d | colend : %d\n",rowstart,rowend,colstart,colend);
        i=rowstart;
        while(head!=NULL && i<=rowend){

            matrix[i][colend]=head->val;
            head=head->next;
            i++;
        }
        colend--;
        // printf("\n");
        // printf("rowstart : %d | rowend : %d | colstart : %d | colend : %d\n",rowstart,rowend,colstart,colend);
        i=colend;
        while( head!=NULL && i>=colstart){

            matrix[rowend][i]=head->val;
            head=head->next;
            i--;
        }
        rowend--;
        // printf("\n");
         // printf("rowstart : %d | rowend : %d | colstart : %d | colend : %d\n",rowstart,rowend,colstart,colend);
        i=rowend;
        while(head!=NULL && i>=rowstart){

            matrix[i][colstart]=head->val;
            head=head->next;
            i--;
        }
        colstart++;
        // printf("\n");

    }

    return matrix;
}