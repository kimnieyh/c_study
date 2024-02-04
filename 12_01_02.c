#include<stdio.h>
#include<string.h>
int GetStringLength(char data[]){
    int count = 0;

    while (data[count]) count++;

    return count;
}
void main()
{
    short student[20] = {3,}; // 3,0,0,0,... 으로 초기화
    // for (int i = 0; i < 20 ; i ++) student[i] = 0;
    student[1] = 10;
    printf("%d %d \n",student[1],student[2]);

    int data_length;
    char data[10] = {'h','a','p','p','y',0,};
    //data_length = GetStringLength(data);
    data_length = strlen(data);
    printf("data length = %d\n",data_length);

    char data2[10] = {'a','b','c',0,};
    char result[16];

    strcpy(result,data2); //data에 저장된 문자열을 result로 복사함
    strcat(result,"def");

    printf("%s + \"def\" = %s\n",data2,result);

}