#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int *arr;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *obj=(ParkingSystem*)malloc(sizeof(ParkingSystem));
    obj->arr=(int*)calloc(3,sizeof(int));
    obj->arr[0]=big;
    obj->arr[1]=medium;
    obj->arr[2]=small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
  if(obj->arr[carType-1]==0){
      return false;
  }else{
      obj->arr[carType-1]--;
  }
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj->arr);
    free(obj);
}

int main(){
    ParkingSystem *obj=parkingSystemCreate(5,5,0);
    printf("%d\n",parkingSystemAddCar(obj,3));
    printf("%d\n",parkingSystemAddCar(obj,1));
    printf("%d\n",parkingSystemAddCar(obj,2));
    parkingSystemFree(obj);
}