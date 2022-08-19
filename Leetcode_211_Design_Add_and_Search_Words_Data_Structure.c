#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct trie_node{
    struct trie_node *dic[26];
    bool res;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj=(WordDictionary*)calloc(1,sizeof(WordDictionary));
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    while(*word){
        if(obj->dic[(*word)-'a']==NULL){
            obj->dic[(*word)-'a']=(WordDictionary*)calloc(1,sizeof(WordDictionary));
        }
        obj=obj->dic[(*word)-'a'];
        word++;
    }
    obj->res=true;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
   while(*word) {
        if( (*word) =='.') {
            for(int i =0;i<26;i++) {
                if(!obj->dic[i]) continue;
                bool a = wordDictionarySearch(obj->dic[i],word+1);
                if(a) return true;
            }
            return false;
        }
        else if(!obj->dic[(*word)-'a']) return false;
        obj = obj->dic[(*word)-'a'];
        word++;
    }
    if(obj->res) return true;
    else return false;

}

void wordDictionaryFree(WordDictionary* obj) {
    for(int i=0;i<26;i++){
        if(obj->dic[i]==NULL) continue;
        free(obj->dic[i]);
    }
    free(obj);
}

int main(){
    WordDictionary *obj=wordDictionaryCreate();
    wordDictionaryAddWord(obj,"abc");
    wordDictionaryAddWord(obj,"bcc");
    wordDictionaryAddWord(obj,"bac");
    wordDictionaryAddWord(obj,"bde");
    printf("%d",wordDictionarySearch(obj,"bd."));
    wordDictionaryFree(obj);
}