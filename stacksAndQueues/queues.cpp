    #include <iostream>
    using namespace std;

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

    int main() {
        circularQueue q;
        initQueue(&q, 5); // tamaño de la cola
    
        element e1 = {10};
        element e2 = {20};
        element e3 = {30};
    
        enqueue(&q, e1);
        enqueue(&q, e2);
        enqueue(&q, e3);
    
        cout << "Front: " << front(&q).value << endl;
    
        dequeue(&q);
        cout << "Front after dequeue: " << front(&q).value << endl;
    
        element e4 = {40};
        enqueue(&q, e4);
    
        // Mostrar todos los elementos en orden
        cout << "Queue contents: ";
        int i = (q.front + 1) % q.maxSize;
        while (i != (q.rear + 1) % q.maxSize) {
            cout << q.list[i].value << " ";
            i = (i + 1) % q.maxSize;
        }
        cout << endl;
    
        return 0;
    }