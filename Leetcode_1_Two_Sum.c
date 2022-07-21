#include<stdio.h>
#include<stdlib.h>
#define size 1000  //set htable size is 1000
typedef struct node{
    int key;
    int value;
    struct node *next;
}node;



int absolute(int value) { return value >= 0 ? value : -value; }
int hash(int key) { return absolute(key) % size; }

node *new_node(int key, int value) {
  node* n = malloc(sizeof(node));
  if (n == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }
  n->key = key;
  n->value = value;
  n->next = NULL;
  return n;
}

void insert(node **hashtable, int key, int value) {
  int k = hash(key);
  if (hashtable[k] == NULL) {
    node *n = new_node(key, value);
    hashtable[k] = n;
  } else {
    node *n = new_node(key, value);
    node *last = hashtable[k];
    n->next = last;
    hashtable[k] = n;
  }
}

node *find(node *hashtable[], int key) {
  int k = hash(key); //找出table對應的儲存位置

  node *head = hashtable[k];
  while (head != NULL) {
    if (head->key == key)
      return head;
    head = head->next;
  }

  return NULL;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  node *hashtable[size] = {NULL};

  for (int i = 0; i < numsSize; ++i) {
    int complement = target - nums[i];
    node *found = find(hashtable, complement);

    if (found && found->value != i) {
      int *result = malloc(2 * sizeof (int));
      result[0] = found->value;
      result[1] = i;
      *returnSize = 2;
      return result;
    }

    insert(hashtable, nums[i], i);
  }

  *returnSize = 0;
  return NULL;
}
int main(){
    int nums[5]={1,2,3,4,5};
    int *p;
    int returnsize;
    p=twoSum(nums,sizeof(nums)/sizeof(int),8,&returnsize);
    for(int j=0;j<returnsize;j++){
        printf(" %d ",p[j]);
    }
}