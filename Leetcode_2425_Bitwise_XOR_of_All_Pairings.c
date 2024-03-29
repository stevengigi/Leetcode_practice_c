

int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // both even
    if(nums1Size%2==0 && nums2Size%2==0){
        return 0;
    }
    int x1=0,x2=0;
    for(int i=0;i<nums1Size;i++){
        x1^=nums1[i];
    }
    for(int i=0;i<nums2Size;i++){
        x2^=nums2[i];
    }

    return (nums1Size %2 *x2) ^ (nums2Size %2 *x1);

}