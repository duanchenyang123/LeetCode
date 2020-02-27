typedef struct {
    int *data;
    int head, tail;
    int size, cnt;
} myQueue;

myQueue* myQueueCreat(int  size) {
    myQueue *q = (myQueue*)malloc(sizeof(myQueue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->head = 0;
    q->tail = 0;
    q->size = size;
    q->cnt = 0;
    return q;
}

void myQueuePush(myQueue *obj, int x) {
    if (obj == NULL) return ;
    if (obj->cnt == obj->size) return ;
    obj->data[obj->tail++] = x;
    if (obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt += 1;
    return ;
}

int myQueuePop(myQueue *obj) {
    if (obj == NULL) return 0;
    if (obj->cnt == 0) return 0;   
    obj->head += 1;
    if (obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
}

int myQueueFront(myQueue *obj) {
    return obj->data[obj->head];
}

int myQueueEmpty(myQueue *obj) {
    return obj->cnt == 0;
}

void myQueueClear(myQueue *obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}




typedef struct {
    myQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size = 1024;
    MyStack * s = (MyStack*)malloc(sizeof(MyStack));
    s->q1 = myQueueCreat(size);
    s->q2 = myQueueCreat(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!myQueueEmpty(obj->q1)) {
        myQueuePush(obj->q1, x);
    } else {
        myQueuePush(obj->q2, x);
    }
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    myQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    myQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element = myQueueFront(p);
    myQueuePop(p);
    while (!myQueueEmpty(p)) {
        myQueuePush(q, element);
        element = myQueueFront(p);
        myQueuePop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    myQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    myQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while (!myQueueEmpty(p)) {
        element = myQueueFront(p);
        myQueuePop(p);
        myQueuePush(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return myQueueEmpty(obj->q1) && myQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) return ;
    myQueueClear(obj->q1);
    myQueueClear(obj->q2);
    free(obj);
    return ;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
