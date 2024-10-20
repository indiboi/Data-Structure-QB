#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

int isEmpty(){
    return head == NULL;
}

void push(int value){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = value;
    nn -> next = NULL;
    if(isEmpty()){
        head = nn; 
    }
    else{
        nn -> next = head; 
        head = nn;
    }
}

void pop(){
    if(isEmpty()){
        printf("No linked list exists!\n");
    }
    else{
        struct node* ptr = head; 
        head = head -> next;
        free(ptr);
    }
}

void display(){
    if(isEmpty()){
        printf("No stack exists!\n");
    }
    else{
        struct node* temp = head;
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}

void peek(){
    if(isEmpty()){
        printf("No linked list exists! \n");
    }
    else{
        printf("%d\n", head->data);
    }
}

int main(){

}