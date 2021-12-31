#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void addNode(pnode *head, int id){
    if (id==35)
        printf("---35---");
    pnode p = newNode(id);
    if (!p){
        printf("Error: no memory");
        return;
    }
    if (id==35)
        printf("---35--- %p", p);
    if (! head){
        *head = p;  //Todo: was: p
        return;
    }
    pnode curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = p;
}

void build_graph_cmd(pnode *head){
    printf("is in A");
    if (head != NULL){
        deleteGraph_cmd(head);
    }
    int i;
    int numOfNoeds =100;
//    if (scanf(" %d", &numOfNoeds)!=1) // digit
//        printf("Error: not get value as expected");  //self checks
//    printf("\nnum: %d\n", numOfNoeds);

    head = (pnode*)malloc(sizeof(node));
    if (!head){
        printf("Error: no memory");
        exit(1);
    }
    (*head)->next=NULL;
    (*head)->node_num=0;
    for (int j = 0; j < numOfNoeds; ++j) {
        addNode(head, j+1);
        printf("\n** build ** %d\n",(j+1));
    }
    printf("\n***** end build ****\n");
    printGraph_cmd(*head);
    return;
}



//void addEdge(int w, pedge *pEdge, pnode *pdest) {
//    pedge *pe = pEdge;
//    while (pe)
//        pe = &((*pe)->next);
//    printf("%d", (*pe)->weight);
//}

int search(int dest, pnode *pNode) {

    return 0;
}

pnode newNode(int id) {
    pnode n = (pnode)malloc(sizeof(node));
    if(n) {
        n->node_num = id;
        n->next = NULL;
    }
    return n;
//    if (id==35)
//        printf("\n---35---\n");
//    pnode p = (pnode)malloc(sizeof(node)); //Todo: was:(pnode*)
//    if (!p){
//        printf("Error: no memory");
//        return NULL;
//    }
//    if (id==35)
//        printf("---35--- %p", p);
//    p->node_num = id;
//    p->next = NULL;
//    p->edges = NULL;
////    p->dist = -1;
//    return p;
}

void printGraph_cmd(pnode head){
    while(head){
        printf("%d -> ", head->node_num);
        head = head->next;
    }
    printf("||\n");
    return;
}

void deleteGraph_cmd(pnode* head){
    while(*head){
        pnode tmp = *head;
        *head = (*head)->next;
        //delete edges from tmp:
        pedge edgeHead = tmp->edges;
        while (edgeHead){
            pedge eTmp = edgeHead;
            edgeHead = edgeHead->next;
            free(eTmp);
        }
//        delete_edge_to(tmp);
        free(tmp);
    }
    if (*head)  //Todo: was: head
        printf("not delete!");
    printf("delete :)");
}







//
//
//
//#include <stdlib.h>
//#include <stdio.h>
//#include "graph.h"
//
//pnode create_node(int data){
//    pnode n = (pnode)malloc(sizeof(node));
//    if(n) {
//        n->node_num = data;
//        n->next = NULL;
////        n->nextH = NULL;
//    }
//    return n;
//}
//
//void add_first(pnode* H, int data){
//    pnode n = create_node(data);
//    if(!n){
//        printf("no memory!");
//        return;
//    }
//    n->next = *H;
//    *H = n;
//}
//
//void add_last(pnode* H, int data){
//    pnode n = create_node(data);
//    if(!n){
//        printf("no memory!");
//        return;
//    }
//    if(!*H){
//        *H = n;
//        return;
//    }
//    pnode tmp = *H;
//    while(tmp->next)
//        tmp = tmp->next;
//    tmp->next = n;
//}
//
//void delete(pnode* H){
//    while(*H){
//        pnode tmp = *H;
//        *H = (*H)->next;
//        free(tmp);
//    }
//}
//
//void print_list(pnode H){
//    while(H){
//        printf("%d -> ", H->node_num);
//        H = H->next;
//    }
//    printf("||\n");
//}
//
//void remove_node(pnode* H, int data){
//    if(!*H)
//        return;
//    if((*H)->node_num == data){
//        pnode tmp = *H;
//        *H = (*H)->next;
//        free(tmp);
//    }
//    pnode tmp = *H;
//    while(tmp->next && tmp->next->node_num != data)
//        tmp = tmp->next;
//    if(!tmp->next)
//        return;
//    pnode tmp2 = tmp->next;
//    tmp->next = tmp->next->next;
//    free(tmp2);
//}













