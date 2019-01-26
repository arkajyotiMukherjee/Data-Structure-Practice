#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* node;

node top = NULL;

bool IsEmpty(){
    return top == NULL? true : false;
}

void Push(int data){
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

void Pop(){
    if(IsEmpty())
        printf("Stack Underflow\n");

    node temp = top;
    top = top->next;
    free(temp);
}

int Peak(){
    if(IsEmpty())
        printf("Stack Underflow\n");

    return top->data;
}

void Print(){
    if(IsEmpty())
        printf("Stack is empty\n");
    node p = top;
    for(; p->next != NULL; p=p->next)
        printf("%d\t",p->data);
    printf("%d\n",p->data);

}

bool ArePair(char open, char close);
bool IsBalanced(char exp[]);

void main(){
    char exp[50];
    printf("Enter the expression\n");
    scanf("%s", &exp);
    
    if(IsBalanced(exp))
        printf("balanced\n");
    else
        printf("not balanced\n");

}

bool ArePair(char open, char close){
    if(open == '(' && close == ')')
        return true;
    else if(open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    return false;
}

bool IsBalanced(char exp[]){
    for(int i = 0; i< strlen(exp); i++){

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            Push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){

            if(IsEmpty() || !ArePair(Peak(), exp[i]))
                return false;
            else
                Pop();
        }
    }

    return IsEmpty()? true : false;
}