#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


void delete_edge_to(pnode *pNode, int num);


pedge creat_edge(int w, pnode *pNode);

void addEdge(pedge *e_src, int w, pnode *p_dest){
    pedge e = creat_edge(w, p_dest);
    if (! *e_src){
        *e_src = e;
        return;
    }
    pedge tmp = *e_src;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = e;
}

pedge creat_edge(int w, pnode *p_dest) {
    pedge e = (pedge) malloc(sizeof(edge));
    if (!e){
        printf("Error: memory error");
        exit(1);
    }
    e->weight = w;
    e->endpoint = *p_dest;
    e->next = NULL;
    return e;
}

void build_graph_cmd(pnode *head) {
    int numOfNoeds;
    if (scanf(" %d", &numOfNoeds)!=1) // digit
        printf("Error: not get value as expected");  //self checks
    printf("\nnum: %d\n", numOfNoeds);
    for (int i = 0; i < numOfNoeds; ++i) {
        add_last(head, i);
    }
}
//

pnode create_node(int id){
    pnode n = (pnode)malloc(sizeof(node));
    if(n) {
        n->node_num = id;
        n->next = NULL;
        n->nextH = NULL;
        n->edges = NULL;
    }
    return n;
}

void add_first(pnode* H, int id){
    pnode n = create_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void add_last(pnode* H, int id){
    pnode n = create_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    pnode tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void delete(pnode* H){
    while(*H){
        pnode tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
}

void printGraph_cmd(pnode H){
    while(H){
        printf("n:%d ", H->node_num);
        pedge e_tmp = H->edges;
        while (e_tmp){
            printf("e:(%d, %d) ", (e_tmp->endpoint->node_num), (e_tmp->weight));
            e_tmp = e_tmp->next;
        }
        printf("-> ");
        H = H->next;
    }
    printf("||\n");
}

//void remove_node(pnode* H, int id){
//    if(!*H)
//        return;
//    if((*H)->node_num == id){
//        pnode tmp = *H;
//        *H = (*H)->next;
//        free(tmp);
//    }
//    pnode tmp = *H;
//    while(tmp->next && tmp->next->node_num != id)
//        tmp = tmp->next;
//    if(!tmp->next)
//        return;
//    pnode tmp2 = tmp->next;
//    tmp->next = tmp->next->next;
//    free(tmp2);
//}


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
        delete_edge_to(head, tmp->node_num);
        free(tmp);
    }
    if (*head)  //Todo: was: head
        printf("\nnot delete!\n");
    printf("\ndelete :)\n");
}

void delete_edge_to(pnode *head, int id) {
    pnode tmp = *head;
    while(tmp){
        //check first edge:
        if (tmp->edges && tmp->edges->endpoint->node_num==id) {
            pedge e = tmp->edges;
            tmp->edges = tmp->edges->next;
            free(e);
            if (!e)
                printf("Error: not delete");
        }
        //check all other edges:
        pedge e = tmp->edges;   //assume that dont have more than 1 edge to id from some node -> Todo: check this
        while (e && e->next && e->next->endpoint != id)
            e = e->next;
        if (e != NULL && e->next!=NULL){
            pedge eTmp = e->next;
            e->next = e->next->next;
            free(eTmp);
        }
        tmp = tmp->next;
    }
}

pnode search(pnode *head, int id){
    pnode tmp = *head;
    while (tmp){
        if (tmp->node_num != id)
            tmp = tmp->next;
        else{
            return tmp;
        }
    }
    return NULL;   //return null if not find
}

void delete_node_cmd(pnode *head, int id){
    pnode tmp = *head;
    if (tmp->node_num == id){
        *head = tmp->next;
        //delete edges from tmp:
        pedge edgeHead = tmp->edges;
        while (edgeHead){
            pedge eTmp = edgeHead;
            edgeHead = edgeHead->next;
            free(eTmp);
        }
        delete_edge_to(head, tmp->node_num);
        free(tmp);
        return;
    }
    pnode tmp2;
    while (tmp && tmp->next) {
        tmp2 = tmp->next;
        if (tmp2->node_num != id)
            tmp = tmp->next;
        else
            break;
    }
    if (tmp == NULL || tmp2 == NULL)
        return; //id not found
    // delet node id:
    tmp->next = tmp2->next;
    //delete edges from tmp:
    pedge edgeHead = tmp2->edges;
    while (edgeHead){
        pedge eTmp = edgeHead;
        edgeHead = edgeHead->next;
        free(eTmp);
    }
    delete_edge_to(head, tmp2->node_num);
    free(tmp2);
    return;
}












