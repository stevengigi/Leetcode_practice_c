int cmp(const void *a,const void *b){
    char * str1 = *(char**)a;
	char * str2 = *(char**)b;
	static buffer1[24] = { 0 };
	static buffer2[24] = { 0 };

	buffer1[0] = buffer2[0] = 0;

	strcat(buffer1, str1);
	strcat(buffer1, str2);
	strcat(buffer2, str2);
	strcat(buffer2, str1);
	return -1*strcmp(buffer1, buffer2);
}

char * largestNumber(int* nums, int numsSize){
    char **number=(char**)malloc(sizeof(char*)*numsSize);
    for (int i = 0; i < numsSize; i++) {
		number[i] = (char*)malloc(sizeof(char) * 10);
		sprintf(number[i], "%d", nums[i]);
	}
    qsort(number,numsSize,sizeof(char*),cmp);
    if (!strcmp(number[0], "0")) { return "0"; }
    char* ans = malloc(sizeof(char) * 500);
	ans[0] = '\0';
	for (int i = 0; i < numsSize; i++) {
		strcat(ans, number[i]);
	}
	printf("%s", ans);
	return ans;
}