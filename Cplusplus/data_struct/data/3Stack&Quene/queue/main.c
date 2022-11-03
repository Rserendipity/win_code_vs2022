#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void test1()
{
    Queue q;
    QueueInit(&q);

    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueuePush(&q, 5);

    printf("size = %d \n", QueueSize(&q));

    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);

    printf("size = %d \n", QueueSize(&q));


    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }

    printf("size = %d \n", QueueSize(&q));


    QueueDestroy(&q);
}

int main()
{
    test1();
    return 0;
}
