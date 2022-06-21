// Leetcode 1427-Perform String Shifts

//You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
//
//direction can be 0 (for left shift) or 1 (for right shift).
//amount is the amount by which string s is to be shifted.
//A left shift by 1 means remove the first character of s and append it to the end.
//Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//Brutal force O(n^3)
char* StringShift(char* ,int**,int ,int *);
//Brutal force-> Simplify Method O(n)
char* StringShift2(char* ,int**,int ,int *);
//reverse O(n)
char* StringShift3(char* ,int**,int ,int *);
void reverse(char*,int,int);

int main() {
	char s[8]="abcdefg";
	char s2[8]="abcdefg";
	char s3[8]="abcdefg";
    int shift[][2]={{1,1},{1,1},{0,2},{1,3}};
    int shiftsize=sizeof(shift)/sizeof(shift[0]);
    printf("shiftsize:%d\n",shiftsize);
	int* p[shiftsize];
    for(int i=0;i<shiftsize;i++){
    	p[i]=shift[i]; //p=[&shift[0],&shift[1],&shift[2],.....&shift[shiftsize]]
//    	printf("p    :%p\n",p[i]);
//    	printf("shift:%p\n",shift[i]);
	}

	//[2,2,2,2,...]
	int shiftcol[shiftsize];
	for(int i=0;i<shiftsize;i++){
    	shiftcol[i]=2;
	}

    printf("s:%s\n",StringShift(s,p,shiftsize,shiftcol));
	printf("s:%s\n",StringShift2(s2,p,shiftsize,shiftcol));
	printf("s:%s\n",StringShift3(s3,p,shiftsize,shiftcol));
//    system("pause");
//    return 0;
}

//Method1
//Brutal force
char* StringShift(char* s,int **shift,int shiftsize,int *shiftcol){

	for(int i=0;i<shiftsize;i++){
		int direction=shift[i][0];
		int amount=shift[i][1];
		int len=strlen(s);
		//0=leftshift
		if(direction==0){
			for(int j=0;j<amount;j++){
				char temp=s[0];
				for(int k=0;k<len-1;k++){
					s[k]=s[k+1];
				}
				s[len-1]=temp;
			}
		}

		//1=rightshift
		if(direction==1){
			for(int j=0;j<amount;j++){
				char temp=s[len-1];
				for(int k=len-1;k>0;k--){
					s[k]=s[k-1];
				}
				s[0]=temp;
			}
		}
	}

	return s;
}

//Method2
//Brutal force-> Simplify Method
char* StringShift2(char* s,int **shift,int shiftsize,int *shiftcol){
	int totalamount=0;
	int len=strlen(s);
	//0=leftshift 1=rightshift
	//rightshift=leftshift(len(s)-rightshift_amount)
	//�Τ@�T�w������
	for(int i=0;i<shiftsize;i++){
		int direction=shift[i][0];
		int amount=shift[i][1];
		amount=amount%len;
		if(direction==1)
			totalamount=totalamount+len-amount;
		else
			totalamount+=amount;
	}
	totalamount =totalamount % len;
	char t[len+1];
	for(int i=0;i<len;i++){
		t[i]=s[i];
	}
	for(int i=0;i<len;i++){
		s[i]=t[(totalamount+i)%len];
	}
	return s;
}


//Method3
//reverse(�蹳)
void reverse(char*s,int start,int end){
	end--;
	while(start<end){
	char temp=s[start];
	s[start]=s[end];
	s[end]=temp;
	end--;
	start++;
	}
}
char* StringShift3(char* s,int **shift,int shiftsize,int *shiftcol){
	int totalamount=0;
	int len=strlen(s);
	//0=leftshift 1=rightshift
	//rightshift=leftshift(len(s)-rightshift_amount)
	//�Τ@�T�w������
	for(int i=0;i<shiftsize;i++){
		int direction=shift[i][0];
		int amount=shift[i][1];
		amount=amount%len;
		if(direction==1)
			totalamount=totalamount+len-amount;
		else
			totalamount+=amount;
	}
	totalamount =totalamount % len;
	reverse(s,0,totalamount);   //[0,totalamount)
	reverse(s,totalamount,len); //[totalamount,len)
	reverse(s,0,len);			//[0,len)
	return s;
}
