#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char * addStrings(char * num1, char * num2){
    int size1=strlen(num1);
    int size2=strlen(num2);
    printf("size1 : %d\n",size1);
    printf("size2 : %d\n",size2);
    int carry=0;
    int digit=0;
    int size3=(size1>size2)?size1:size2;
    printf("size3 : %d\n",size3);
    // if(num1[0]+num2[0]>'0'+'0'+9 && size1==size2){
    //     size3++;
    // }
    int end3=size3+1;
    printf("end3 : %d\n",end3);
    char *res=(char*)malloc(sizeof(char)*end3);

    while(size1 !=0 || size2!=0 ){
        digit = (size1 == 0 ? 0 : num1[--size1] - '0')
		      + (size2 == 0 ? 0 : num2[--size2] - '0')+carry;
		carry=digit/10;
        digit=digit%10;
        printf("digit : %d\n",digit);
		res[--size3] = (char)('0' + digit);
    }
    if (carry>0) {
		if (size3 == 0) {
            end3++;
			res = realloc(res, end3);
			memmove(&res[1], &res[0], (end3 - 2));
		}
		res[0] = '1';
	}

    res[end3 - 1] = '\0';
    int i=0;
    // while(res[i]!='\0'){
    //     printf(" %c ",res[i]);
    // }
    return res;

}
int main(){
    char c[4]="123";
    char cc[4]="999";
    printf("%s\n",addStrings(c,cc));
}