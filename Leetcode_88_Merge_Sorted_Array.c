

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(m==0){
        for(int i=0;i<n;i++){
            nums1[i]=nums2[i];
        }
        return;
    }
    if(n==0){
        return;
    }
    int res[nums1Size];
    for(int i=0;i<nums1Size;i++){
            res[i]=nums1[i];
    }
    int index1=0;
    int index2=0;
    int i=0;
    while(m!=0 && n!=0){
        if(n!=0 && res[index1] >= nums2[index2]){
            nums1[i++]=nums2[index2++];
            n--;
        }else if(m!=0 && res[index1] < nums2[index2]){
            nums1[i++]=res[index1++];
            m--;
        }
    }
    while(n!=0){
        nums1[i++]=nums2[index2++];
        n--;
    }
    while(m!=0){
        nums1[i++]=res[index1++];
        m--;
    }
}