

bool threeConsecutiveOdds(int* arr, int arrSize){
    int res=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i]%2){
            res++;
        }else{
            res=0;
        }
        if(res==3){
            return true;
        }
    }
    return false;
}