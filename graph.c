#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void addNode(pnode *head, int id){
    pnode p = newNode(id);
    if (!p){
        printf("Error: no memory");
        return;
    }
    if (! head){
        head = p;
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
    int numOfNoeds;
    if (scanf(" %d", &numOfNoeds)!=1) // digit
        printf("Error: not get value as expected");  //self checks
    printf("\nnum: %d\n", numOfNoeds);

    head = (pnode*)malloc(sizeof(node));
    if (!head){
        printf("Error: no memory");
        exit(1);
    }
    (*head)->next=NULL;
    (*head)->node_num=0;
    for (int j = 0; j < numOfNoeds; ++j) {
        addNode(head, j+1);
    }
    printGraph_cmd(*head);
    return;
}



void addEdge(int w, pedge *pEdge, pnode *pdest) {
    pedge *pe = pEdge;
    while (pe)
        pe = &((*pe)->next);
    printf("%d", (*pe)->weight);
}

int search(int dest, pnode *pNode) {

    return 0;
}

pnode newNode(int id) {
    pnode p = (pnode*)malloc(sizeof(node));
    if (!p){
        printf("Error: no memory");
        return NULL;
    }
    p->node_num = id;
    p->next = NULL;
    p->edges = NULL;
    p->dist = -1;
    return p;
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
    while(head){
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
    if (head)
        printf("not delete!");
    printf("delete :)");
}

