char * longestCommonPrefix(char ** strs, int strsSize){

    if (strsSize == 0) return "";
	int i = 0;
	for (; i < strlen(strs[0]); i++){
		int j = 1;
		for (;j<strsSize;j++)
			if (strs[j][i] != strs[0][i]) break;
		if (j < strsSize) break;
	}
	strs[0][i] = '\0';
	return strs[0];
}
