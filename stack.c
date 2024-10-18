#include<stdio.h>
#define MAX 10
int top = -1; 
int stack[MAX];

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void push(int data){
    if(!isFull()){
        stack[++top] = data;
        printf("%d has been pushed\n", data);
    }
    else{
        printf("Stack overflow!\n");
    }
}

void peek(){
    if(!isEmpty()){
        printf("%d\n", stack[top]);
    }
    else{
        printf("Stack is empty!\n");
    }
}

void display(){
    if(!isEmpty()){
        int temp = top;
        while(temp >= 0){
            printf("%d ", stack[temp--]);
        }
        printf("\n");    
    }
    else{
        printf("Stack is Empty!\n");   
    }
}

void pop(){
    if(!isEmpty()){
        printf("%d has been popped\n", stack[top--]);
    }
    else{
        printf("Stack underflow!\n");
    }
}

int main(){
    int choice; 
    printf("\tMENU\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int ele;
                printf("Enter an element to be pushed: \n");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
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