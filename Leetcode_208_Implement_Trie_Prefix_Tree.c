#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define idx(c) (c - 'a')

typedef struct Trie{
    int count;
    struct Trie *child[26];
} Trie;

Trie* trieCreate() {
    Trie *t = (Trie *)malloc(sizeof(Trie));
    t->count = 0;
    for (int i = 0; i < 26; ++i)
        t->child[i] = NULL;
    return t;
}

void trieInsert(Trie* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])]){
            obj->child[idx(word[i])] = trieCreate();
        }
        obj = obj->child[idx(word[i])];
    }
    ++obj->count;
}

bool trieSearch(Trie* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])])
            return false;
        obj = obj->child[idx(word[i])];
    }

    return obj->count;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    for (int i = 0, len = strlen(prefix); i < len; ++i){
        if (!obj->child[idx(prefix[i])])
            return false;
        obj = obj->child[idx(prefix[i])];
    }
    return true;
}

void trieFree(Trie* obj) {

    free(obj);
}

int main(){
    Trie *obj=trieCreate();
    trieInsert(obj,"abc");
    trieInsert(obj,"abc");
    printf("%d",trieSearch(obj,"abc"));
}