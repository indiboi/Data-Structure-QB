#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAX 100

int i, j;

struct stack{
    int top; 
    char stack[MAX];
}s;

int isEmpty(){
    return s.top == -1; 
}

int isFull(){
    return s.top == MAX - 1;
}

void push(char item){
    if(isFull()){
        printf("Stack Overflow\n");
    }
    else{
        s.stack[++s.top] = item;
    }
}

char pop(){
    char a, temp; 
    if(isEmpty()){
        printf("Stack Underflow\n");
    }
    else{
        temp = s.stack[s.top--];
        return temp; 
    }
}

char peek(){
    return s.stack[s.top];
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
    }
    return -1;
}

int isAlphaNum(char a){
    if(a != '(' && a != ')' && a != '[' && a != ']' && a != '{' && a != '}' && a != '+' && a != '-' && a != '*' && a != '/' && a != '^'){
        return 1;    
    }
    else{
        return 0;
    }
}

void infixToPostfix(char expr[]){
    char pexpr[MAX];
    int len = strlen(expr);
    j = -1; 
    for(i = 0; i < len; i++){
        if(isAlphaNum(expr[i])){
            pexpr[++j] = expr[i];
        }
        else if(expr[i]=='('||expr[i]=='{'||expr[i]=='['){
            push(expr[i]);
        }
        else if(expr[i]==')'||expr[i]=='}'||expr[i]==']'){
            if(expr[i]==')'){
                while(!isEmpty() && peek() != '('){
                    pexpr[++j] = pop();
                }
                pop();
            }
            if(expr[i] == '}'){
                while(!isEmpty() && peek() != '{'){
                    pexpr[++j] = pop();
                }
                pop();
            }
            if(expr[i] == ']'){
                while(!isEmpty() && peek() != '['){
                    pexpr[++j] = pop();
                }
                pop();
            }
        }
        else{
            while(!isEmpty() && precedence(expr[i]) <= precedence(peek())){
                pexpr[++j] = pop();
            }
            push(expr[i]);
        }
        
    }
    while(!isEmpty()){
        pexpr[++j] = pop();
    }
    printf("Infix expression is: %s\n", expr);
    printf("Postfix expression is: %s\n", pexpr);
}

int main(){
    char expr[MAX];
    printf("Enter a balanced infix expression:\n");
    scanf("%s", expr);
    infixToPostfix(expr);
    return 0;
}
