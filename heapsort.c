#include<stdio.h>

static int size = 1;

void swap(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void insert(int *heap,int data){
    heap[size] = data;
    int now = size;
    size ++;
    if(size == 1) {
        return;
    }
    while(data > heap[now/2] && now != 1){
        swap(heap + now, heap + now/2);
        // swap((heap + now))
        now = now/2;
    }
}

int delete(int *heap){
    if(size == 1)
        return 0;

    int root = heap[1];
    size --;
    heap[1] = heap[size];

    int idx = 1 ; 
    while(idx * 2 < size){
        int left = idx *2 ;
        int right = idx *2 +1;
        int larger = left;
        if (left < size -1 && heap[left] < heap[right]) {
            larger = right;
        }
        if (heap[idx] > heap[larger]){
            break;
        }
        swap(heap+idx,heap+larger);
        idx = larger;
    }
    return root;
}

int main(){
    int n;
    int *heap;
    scanf("%d",&n);
    heap = (int*)malloc(sizeof(int)*n);
    for (int i = 0 ; i < n ; i++) {
        int x; 
        scanf("%d",&x);
        if (x==0){
            printf("%d\n",delete(heap));
        }else{
            insert(heap,x);
        }
    }

    return 0 ;
}