/* 
 * 시스템 프로그래밍 lab4 과제 실습 2번
 * 파일 이름: hellothread.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hello_thread(void *arg)
{
    printf("Thread: Hello, World!\n");
    return arg;
}

int main() {

    pthread_t tid; // 쓰레드 id 저장
    int status;

    /* 쓰레드 생성 */
    status = pthread_create(&tid, NULL, hello_thread, NULL);

    if(status != 0)
        perror("Create thread");
    
    pthread_exit(NULL); // main 함수를 수행하는 초기 쓰레드만 종료

    return 0;
}