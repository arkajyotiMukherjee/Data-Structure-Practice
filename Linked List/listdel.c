#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *node;

node start = NULL;

void insert(int data){
    node newnode = (node)malloc(sizeof(struct node));
    newnode->data = data;
    node p = start;

    if(start == NULL){
        start = newnode;
        newnode->next = start;
    }

    for(p=start; p->next != start; p=p->next);

    p->next = newnode;
    newnode->next = start;
   
}

void print(){
    node p = NULL;

    for(p=start; p->next != start; p=p->next)
        printf("%d\t",p->data);
    printf("%d\n",p->data);
}

void dellist(int data, int mode){
    node p = start;
    node pre = start;
    node prepre = start;
    if(start == NULL){
        printf("can't dosvill babydoll");
        return NULL;
    }

    while(p->data != data){
        if(p->next == start)
            break;
        prepre = pre;
        pre = p;
        p = p->next;
    }

    // printf("%d\n%d\n%d\n", p->data, data,prepre->data);

    if(p->data == data){
    
        if(mode == 1){
            p = pre;
            pre = prepre;

            if(p == start){
                pre = start;
                while(pre->next->next != start)
                    pre = pre->next;

                free(pre->next);
                pre->next = start;
            }

        }
        else if(mode == 2){
            pre = p;
            p = p->next;
        }
        // printf("%d\n%d\n%d\n", p->data, pre->data,prepre->data);

        if(p == start){
            if(mode != 1){
                pre = start;
                while(pre->next != start)
                    pre = pre->next;
                    
                start = p->next;
                pre->next = start;
                free(p);
            }
        }
        else if(p->next == start){
            pre->next = start;
            free(p);
        }
        else{
            pre->next = p->next;
            free(p);
        }
        
    }
    

}

void main(){
    insert(5);
    insert(4);
    insert(3);
    insert(8);
    insert(1);
    insert(7);
    insert(6);
    insert(9);
    insert(0);
    insert(2);
    print();

    dellist(2, 2);
    dellist(5, 2);
    dellist(7, 2);

    print();
}