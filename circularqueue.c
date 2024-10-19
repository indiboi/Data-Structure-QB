#include<stdio.h>
#define MAX 5
int front = -1, rear = -1; 
int queue[MAX];

int isEmpty(){
    return front == -1 && rear == -1;
}

int isFull(){
    return (front == 0 && rear == MAX - 1) || (rear == front - 1);
}

void enqueue(int ele){
    if(isFull()){
        printf("Queue is full!\n");
    }
    else if(isEmpty()){
        front = 0; 
        rear = 0;
        queue[rear] = ele;
        printf("%d has been enqueued\n", ele);
    }
    else{
        rear = (rear + 1) % MAX;
        queue[rear] = ele;
        printf("%d has been enqueued\n", ele);
    }
    
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
    }
    else if(front == rear){
        printf("%d dequeued from the queue\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("%d dequeued from the queue\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void Front(){
    printf("%d\n", queue[front]);
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty!\n");
    }
    else{
        int i = front;
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main(){
    int choice; 
    printf("\tMENU\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int ele;
                printf("Enter an element to be enqueued: \n");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                Front();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong input, try again!");
                break;
        }
        
    }while(choice != 5);
    return 0;
}