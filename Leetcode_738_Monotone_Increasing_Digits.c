int muchdigit(int n){
    int size=0;
    while(n!=0){
        n/=10;
        size++;
    }
    return size;
}
int monotoneIncreasingDigits(int n){
    int size=muchdigit(n);
    int start=0;
    int arr[10]={0};
    for(int i=0;i<size;i++){
        int temp=pow(10,size-i-1);
        arr[i]=n/temp;
        n%=temp;
        printf(" %d ",arr[i]);
    }
    for(int i=1;i<size;i++){
        if(arr[i]==arr[i-1]){
            continue;
        }else if(arr[i] >= arr[i-1]){
            start=i;
        }else if(arr[i] < arr[i-1]){
            arr[start]--;
            for(int j=start+1;j<size;j++){
                arr[j]=9;
            }
            break;
        }
    }
    int res=0;
    for(int i=0;i<size;i++){
        res=res*10+arr[i];
    }
    return res;
}