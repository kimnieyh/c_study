#include<stdio.h>

void main () {
    short birthday;
    short *ptr ; // 포인터 변수 선언
    ptr = &birthday; // birthday주소를 ptr 변수에 대입

    // %p 형식은 메모리 주소를 16진수로 출력함
    printf("birthday 변수의 주소는 %p 입니다.\n",ptr); 
    *ptr = 0x0412;

    printf("birthday = %d (0x%04X)\n",birthday,birthday);
}