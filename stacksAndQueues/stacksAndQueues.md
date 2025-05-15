# Stacks and Queues

## Stacks
Estrucutra de dato de tipo **FIFO** _(First In First Out)_.

``` cpp
    
    struct element{
        int value;
    }

    struct Stack {
        int maxSize;
        element list[maxSize];
        int top = -1;
    }


    // Verifica si una pila está llena
    bool isFull(*Stack s){

        if (size(s->top) == s->maxSize - 1) {return true};

        return false;
    };  

    // Verifica si una pila está vacía
    bool isEmpty(*Stack s){
        if (top == -1) return true;
        return false;
    };

    // Agrega un elemento a la pila
    void push(*Stack s, element e){
        if isFull(s) return;
        
        s->top++;
        s->list[s->top] = e;
    };

    // Elimina un elemento de la pila
    void pop(*Stack s){
        if isEmpty(s) return;

        s->list[s->top] = null;
        s->top--;
    };

    // Obtiene el elemento en el top
    element getTop(*Stack s){
        if isEmpty(s) return null;

        return s->list[s->top];
    }


```

## Queue
Estructura de datos del tipo **LIFO** _(Last In Last Out)_, se pueden realizar con punteros, y listas. 

La forma más eficiente de implementar una **QUEUE** (generalmente), es implementando una **CIRCULAR QUEUE**


``` cpp
    
    struct element{
        int value;
    };

    struct circularQueue {
        int maxSize;
        int front;
        int rear;
        element* list;
    };


    void initQueue(circularQueue* q, int size) {
        q->maxSize = size;
        q->list = new element[size];
        q->front = 0;
        q->rear = 0;
    }

    bool isEmpty(circularQueue* q){
        if (q->rear == q->front) return true;

        return false;
    }

    bool isFull(circularQueue* q){
        if (q->front == ((q->rear + 1) % q->maxSize)) return true;

        return false;
    }

    void enqueue(circularQueue* q, element e){
        
        q->rear = (q->rear + 1) % q->maxSize;
        q->list[q->rear] = e;

    }

    void dequeue(circularQueue* q) {
        if (isEmpty(q)) return;  
        q->front = (q->front + 1) % q->maxSize;
    }

    element front(circularQueue* q){
        if (isEmpty(q)) return  element{ -1 };

        return q->list[(q->front + 1) % q->maxSize];

    }

```
