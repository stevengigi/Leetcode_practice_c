// ex : [1 , 1 , 3 , 3 , 5 ,7]
// 1 ^ 1 ^ 3 ^ 3 ^ 5 ^ 7 = 5 ^ 7 = 0101 ^ 0111 = 0010 =2 =r
// ~(0010 - 1 ) = 1110  = ~(r-1)
// mask(r & ~(r-1)) = 1110 * 0010 = 0010 (represent 5,7 difference(the first bit))
// if arr[i] & mask == 0 (represent dividing two part with xx1x and xx0x)
// =>  1 1 5 => xx0x => 3^3^5=5
// => 3 3 7 => xx1x => 1^1^7=7
// if we find 5 in fisrt , we can use 5^mask(5^7)=7. find another single number

int* singleNumber(int* nums, int numsSize, int* returnSize){
    *returnSize=2;
    int *res=(int*)malloc(sizeof(int)*2);
    uint32_t mask=0x00;
    uint32_t xor=0x00;
    for(int i=0;i<numsSize;i++){
        xor ^=nums[i];
    }

    mask=xor&(~(xor-1));

    uint32_t temp=0;
    for(int i=0;i<numsSize;i++){
        // printf("mask : %d | nums : %d  mask & nums : %d\n ",mask,nums[i],nums[i]&mask);
        if((mask & nums[i])==0){
            // printf("coming in\n");
            temp^=nums[i];
        }
    }

    res[0]=temp;
    res[1]=xor^temp;
    return res;
}