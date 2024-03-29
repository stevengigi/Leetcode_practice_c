int characterReplacement(char * s, int k){
    int count[26] = {0};
    int maxChar = 0, len = strlen(s), maxLen = 0;

    for(int right = 0, left = 0; right < len; right++) {
        maxChar = fmax(maxChar, ++count[s[right] - 'A']);

        // keep the window within k
        while((right - left + 1) - maxChar > k) {
            --count[s[left] - 'A'];
            left ++;
        }
        maxLen = fmax(maxLen, right - left + 1);
    }
    return maxLen;
}