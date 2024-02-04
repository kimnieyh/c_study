#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    /* data */
    int number;
    struct node *p_next;
}NODE;

NODE *p_head = NULL, *p_tail = NULL ,*p;
// insert
void AddNumber(int data){
    // null 이라면 연결리스트에 노드가 없다는 것
    if(p_head == NULL){
        // *p_head 값이 null 이라서 첫 노드가 추가됨. p_head에 새 노드를 저장
        p_head = (NODE *)malloc(sizeof(NODE));
        p_tail = p_head;
        
    }else {
        // 새 노드를 할당
        // -> 를 쓰면 p->age = 23 이라면 (*p).age = 23; 과 같음
        p_tail->p_next = (NODE *)malloc(sizeof(NODE));
        p_tail = p_tail->p_next;
    }
    p_tail->number = data;
    p_tail->p_next = NULL;
}
int node_len(){
    int cnt = 0;
    NODE *cur = p_head;
    
    while(cur->p_next != NULL){
        cnt ++;
        cur = cur->p_next;
    }
    return cnt;
}
NODE read_node_idx(int num){
    int i = 0;
    NODE *cur = p_head;

    if(num < 1 || num > node_len()){
        printf("wrong data\n");
        return(*p);
    }
    while (i < num){
        cur = cur->p_next;
        i++;
    }
    return(*cur);
}
NODE read_node_data(int data){
    NODE *cur = p_head;
    while(cur->number != data && cur->p_next != NULL){
        cur =cur->p_next;
    }
    if(cur->number == data){
        return(*cur);
    }
    printf("wrong data\n");
    return(*cur);
}
void delete_first_node(){
    NODE *cur = p_head->p_next;
    p_head->p_next = cur->p_next;
    cur->p_next = NULL;
    free(cur);
}
//delete one 
void delete_node(int num){
    if (num == 1){
        delete_first_node();
    }else if (num < 1 && num > node_len()){
        printf("wrong range\n");
        return;
    }else{
        int i;
        NODE *prev = p_head;
        i = 0;
        while(i<num-1){

        }
    }
}
// delete all
void delete_all_node(){
    while(NULL != p_head){
        p = p_head;
        p_head = p_head->p_next;
        free(p);
    }
    //p_tail도 null로 바꿈
    p_tail = NULL;
}
void displayNode(){

}
void main(){
    int sum = 0, temp;
    while(1){ //무한 루프
        printf("숫자를 입력하세요 (9999를 누르면 종료) :");
        scanf("%d",&temp);
        if(9999 == temp) break;

        AddNumber(temp);
    }

    p = p_head;
    while(NULL != p){
        if(p!= p_head) printf("+");
        printf("%d",p->number);
        sum = sum + p->number;
        p = p->p_next;
    }
    printf("= %d\n",sum);

    DeleteAllNode();
    
}
