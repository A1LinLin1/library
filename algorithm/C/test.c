#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int QElemType;

//链式队列结构体
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
}LinkQueue;

//初始化链式队列
Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front) {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

//判断链式队列是否为空
Status QueueEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//获取链式队列长度
int QueueLength(LinkQueue Q) {
    int i = 0;
    QueuePtr p = Q.front;
    while(Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

//链式队列入队
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

//链式队列出队
Status DeQueue(LinkQueue *Q, QElemType *e) {
    QueuePtr p;
    if(Q->front == Q->rear) {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

//获取链式队列头元素
Status GetHead(LinkQueue Q, QElemType *e) {
    QueuePtr p;
    if(Q.front == Q.rear) {
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}

int main() {
    LinkQueue Q;
    QElemType e;
    if(InitQueue(&Q)) {
        printf("链式队列初始化成功！\n");
    }
    printf("链式队列是否为空：%d\n", QueueEmpty(Q));
    printf("链式队列长度：%d\n", QueueLength(Q));
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    printf("链式队列长度：%d\n", QueueLength(Q));
    DeQueue(&Q, &e);
    printf("链式队列出队元素：%d\n", e);
    printf("链式队列长度：%d\n", QueueLength(Q));
    GetHead(Q, &e);
    printf("链式队列头元素：%d\n", e);
    printf("链式队列长度：%d\n", QueueLength(Q));
    return 0;
}
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef int QElemType;
typedef int TElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front) {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e) {
    QueuePtr p;
    if (Q->front == Q->rear) {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

Status QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status ClearQueue(LinkQueue *Q) {
    QueuePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

int QueueLength(LinkQueue Q) {
    int i = 0;
    QueuePtr p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q, QElemType *e) {
    QueuePtr p;
    if (Q.front == Q.rear) {
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}

int main() {
    LinkQueue Q;
    QElemType e;
    if (InitQueue(&Q) == OK) {
        EnQueue(&Q, 1);
        EnQueue(&Q, 2);
        EnQueue(&Q, 3);
        printf("队列长度为: %d\n", QueueLength(Q));
        GetHead(Q, &e);
        printf("队头元素为: %d\n", e);
        DeQueue(&Q, &e);
        printf("出队元素为: %d\n", e);
        printf("队列长度为: %d\n", QueueLength(Q));
        DestroyQueue(&Q);
    }
    return 0;
}
