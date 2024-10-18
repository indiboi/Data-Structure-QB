#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

int isFull(){
    return rear == MAX - 1;
}

int isEmpty(){
    return rear == -1 && front == -1; 
}

void enqueue(int ele){
    if(isEmpty()){
        front = 0;
        rear = 0;
        queue[rear] = ele;
        printf("%d has been enqueued\n", ele);
    }
    else if(isFull()){
        printf("Queue is full!\n");
    }
    else{
        queue[++rear] = ele;
        printf("%d has been enqueued\n", ele);
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
    }
    else if(front > rear){
        front = -1;
        rear = -1;
    }
    else{
        printf("%d has be dequeued\n", queue[front++]);
    }
}

void Front(){
    if(!isEmpty())
        printf("%d", queue[front]);
    else
        printf("Queue is empty\n");
}

void display(){
    if(!isEmpty()){
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else{
        printf("Queue is Empty!\n");
    }
}

void size(){
    if(!isEmpty())
        printf("%d\n", rear - front + 1);
    else
        printf("Queue does not exist\n");
}

int main(){
    int choice; 
    printf("\tMENU\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front\n");
    printf("4. Display\n");
    printf("5. Size\n");
    printf("6. Exit\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int ele;
                printf("Enter an element to be pushed: \n");
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
                size();
                break;
            case 6: 
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong input, try again!");
                break;
        }
        
    }while(choice != 6);
    return 0;
}