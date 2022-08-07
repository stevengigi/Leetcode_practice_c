

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void merge(int *nums,int low,int mid,int high){
    int leftsize=mid-low+1;
    int rightsize=high-mid;
    int arr1[leftsize];
    int arr2[rightsize];
    for(int i=0;i<leftsize;i++){
        arr1[i]=nums[low+i];
    }
    for(int j=0;j<rightsize;j++){
        arr2[j]=nums[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<leftsize && j<rightsize){
        if(arr1[i]<arr2[j]){
            nums[k]=arr1[i];
            i++;
        }else{
            nums[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<leftsize){
        nums[k]=arr1[i];
        i++;
        k++;
    }
    while(j<rightsize){
        nums[k]=arr2[j];
        j++;
        k++;
    }
}

void mergesort(int *nums,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    mergesort(nums,0,numsSize-1);
    for(int i=0;i<numsSize;i++){
        printf(" %d ",nums[i]);
    }
    int threesum=0;
    int left;
    int right;
    *returnSize=0;
    int **res=(int**)malloc(sizeof(int*)*(numsSize)*numsSize);
    //
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        left=i+1;
        right=numsSize-1;
        while(left<right){
            threesum=nums[i]+nums[left]+nums[right];
            if(threesum > 0){
                right--;
            }else if(threesum < 0){
                left++;
            }else{
                count++;
                res[count-1]=(int*)malloc(sizeof(int)*3);
                res[count-1][0]=nums[i];
                res[count-1][1]=nums[left];
                res[count-1][2]=nums[right];
                left++;
                while(left<right &&nums[left]==nums[left-1]){
                    left++;
                }

            }
        }
    }
    *returnColumnSizes=(int*)malloc(sizeof(int)*count);
    for(int i=0;i<count;i++){
        (*returnColumnSizes)[i]=3;
    }
    *returnSize=count;
    return res;
}





