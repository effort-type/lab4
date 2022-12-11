/* 
 * 시스템 프로그래밍 lab4 과제 실습 2번
 * 파일 이름: hellothreads.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *hello_thread(void *arg)
{
    printf("Thread %d: Hello, World!\n", arg);
    return arg;
}

int main()
{
    pthread_t tid[NUM_THREADS];
    int i, status;

    /* 쓰레드 생성 */
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&tid[i], NULL, hello_thread, (void*) i);

        if(status != 0){
            fprintf(stderr, "Create thread %d: %d", i, status);
            exit(1);
        }
    }

    pthread_exit(NULL);

    return 0;
}