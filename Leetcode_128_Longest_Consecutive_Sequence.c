void merge(int *arr,int left,int mid,int right){
    int i,j,k=left;
    int leftarr[mid-left+1];
    int rightarr[right-mid];
    for(i=0;i<mid-left+1;i++)  leftarr[i]=arr[left+i];
    for(j=0;j<right-mid;j++) rightarr[j]=arr[mid+1+j];
    i=0;
    j=0;
    while(j<right-mid && i<mid-left+1){
        if(leftarr[i]>rightarr[j]){
            arr[k]=rightarr[j];
            j++;
        }else{
            arr[k]=leftarr[i];
            i++;
        }
        k++;
    }
    while(i<mid-left+1){
        arr[k++]=leftarr[i++];
    }
    while(j<right-mid){
        arr[k++]=rightarr[j++];
    }

}

void mergesort(int *arr,int left,int right){
    if(left<right){
        int mid=(right-left)/2+left;

        mergesort(arr,left,mid); // [left mid]
        mergesort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}
int max(int a,int b){
    return a>b?a:b;
}
int longestConsecutive(int* nums, int numsSize){
    mergesort(nums,0,numsSize-1);
    printarray(nums,numsSize);
    int index=0;
    int res=0;
    int temp=1;
    while(index<numsSize){
        // temp=0;
        while(index+1<numsSize && nums[index+1]==nums[index]+1){
            // printf(" %d ",nums[index]);
            temp++;
            index++;
        }
        res=max(res,temp);
        if(index+1<numsSize && nums[index]==nums[index+1]){
            index++;
        }
        else{
            temp=1;
            index++;
        }


    }
    return res;
}