char* decodeMessage(char* key, char* message) {
    int idx = 0, klen = strlen(key), mlen = strlen(message);
    char map[26] = {0};
    for (int i = 0; i < klen; i++) {
        if (key[i] == ' ' || map[key[i] - 'a'] != 0) continue;
        map[key[i] - 'a'] = 'a' + (idx++);

    }
    char* ans = (char*) malloc((mlen + 1) * sizeof(char));
    for (int i = 0; i < mlen; i++) {
        if (message[i] == ' ') {
            ans[i] = ' ';
        } else {
            ans[i] = map[message[i] - 'a'];
        }
    }
    ans[mlen] = '\0';
    return ans;
}