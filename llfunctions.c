#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

void insert_node(int value){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = value;
    nn -> next = NULL;
    if(head == NULL){
        head = nn; 
    }
    else{
        struct node* temp = head; 
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp->next = nn; 
    }
}

void insert_at_beginning(int value){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = value;
    nn -> next = NULL;
    if(head == NULL){
        head = nn;
    }
    else{
        nn -> next = head;
        head = nn; 
    }
}

void insert_at_end(int value){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = value; 
    nn -> next = NULL;
    if(head == NULL){
        head = nn;
    }
    else{
        struct node* temp = head; 
        while(temp -> next != NULL){
            temp = temp -> next; 
        }
        temp -> next = nn;
    }
}

void count(){
    struct node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next; 
    }
    printf("%d\n", count);
}

void insert_before_specified(int value, int number){
    struct node* temp = head; 
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn -> next = NULL;
    nn -> data = value;
    int count = number;
    if(count == 2){
        nn -> next = head;
        head = nn;
        return; 
    }
    else if(count == 1){
        printf("Invalid input!\n");
    }
    while(count > 2){
        count--;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
    }
    else{
        nn -> next = temp -> next;
        temp -> next = nn;
    }
}

void delete_at_beginning(){
    if(head == NULL){
        printf("Linked List does not exist!\n");
    }
    else{
        struct node* ptr = head; 
        head = ptr -> next;
        free(ptr);    
    }
    
}

void delete_at_end(){
    if(head == NULL){
        printf("Linked List does not exist!\n");
    }
    else{
        struct node* ptr = head; 
        while(ptr -> next -> next != NULL){
            ptr = ptr -> next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}

void delete_before_specified(int number){
    if(head == NULL){
        printf("Linked List does not exist!\n");
    }
    else if(number == 2){
        struct node* ptr = head;
        head = ptr -> next;
        free(ptr);
    }
    else if(number == 1){
        printf("Invalid input!\n");
    }
    else{
        int count = number;
        struct node* ptr = head;
        struct node* temp = head;
        while(count > 3){
            ptr = ptr -> next;
            count--;
        }
        temp = ptr -> next;
        ptr -> next = temp -> next;
        free(temp);
    }
}

void display(){
    if(head == NULL){
        printf("No linked list exists\n");
    }
    else{
        struct node* temp = head;
        printf("%d -> ", temp->data);
        while(temp->next != NULL){
            temp = temp -> next;
            printf("%d -> ", temp->data);
        }
        printf("NULL");
        printf("\n");
    }
}

int main(){
    int n; 
    printf("Enter the number of nodes you want to add to the linked list: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int value;
        printf("Enter the data for the %d node: \n", i + 1);
        scanf("%d", &value);
        insert_node(value);
    }
    printf("The linked list is: \n");
    display();
    insert_at_beginning(69);
    display();
    insert_at_end(420);
    display();
    insert_before_specified(888, 4);
    display();
    count();
    delete_at_beginning();
    display();
    delete_at_end();
    display();
    delete_before_specified(2);
    display();
    return 0; 
}