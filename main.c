#include <stdlib.h>
#include <stdio.h>
#include "graph.h"



int main() {
    printf("Hello, World!\n");
    //Get the input:
    pnode head = NULL;
    char c;
    int i = 0;
    int id;
    int dest;
    int w;
    int temp=0;
    while ( (scanf(" %c", &c)) != EOF)
    {
        switch (c)
        {
            case 'A':
            {
                printf("\nin A\n");
                if (head==NULL)
                    build_graph_cmd(&head);
                else{
                    deleteGraph_cmd(&head);
                    build_graph_cmd(&head);
                }
                printGraph_cmd(head);   //Todo: dbs
                break;
            }
            case 'n':
            {
                printf("\nin n\n");
                scanf(" %d", &id);
                pnode n_node = search(&head, id);
                printf("\n\nfind! %d\n", n_node->node_num);
                while (scanf(" %d", &i)==1)   //digit
                {
                    dest = i;
                    scanf(" %d", &w);
                    pnode p_dest = search(&head, dest);
                    if (p_dest==NULL)
                        printf("Error: not found dest of edge");    //Todo: dbs
                    addEdge(&(n_node->edges), w, &p_dest);
                }
                printGraph_cmd(head);   //Todo: dbs
                break;
            }
            case 'B':
            {
                printf("\nin B\n");
                scanf(" %d", &id);
                pnode n_node = search(&head, id);
                if (n_node==NULL) {     //creat new node
                    add_last(&head, id);
                    n_node = search(&head, id);
                }
                else{
                    //delete all edges from n_node:
                    pedge edgeHead = n_node->edges;
                    while (edgeHead){
                        pedge eTmp = edgeHead;
                        edgeHead = edgeHead->next;
                        free(eTmp);
                    }
                    n_node->edges = NULL;
                }

                while (scanf(" %d", &i)==1)   //digit
                {
                    dest = i;
                    scanf(" %d", &w);
                    pnode p_dest = search(&head, dest);
                    if (p_dest==NULL)
                        printf("\nError: not found dest of edge: %d\n", dest);    //Todo: dbs
                    addEdge(&(n_node->edges), w, &p_dest);
                }
                printGraph_cmd(head);   //Todo: dbs
                break;
            }
            case 'D':
            {
                printf("\nin D\n");
                int id;
                scanf(" %d", &id);
                delete_node_cmd(&head, id);
                printGraph_cmd(head);   //Todo: dbs
                break;
            }
            case 'S':
            {
//                shortsPath_cmd(head);
                int src;
                int dest;
                scanf(" %d", &src);
                scanf(" %d", &dest);
                float r = dijkstra(&head, search(&head,src),search(&head,dest));
                printf("%f",r);
                break;
            }
            //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 S 1 3 S 3 1 S 2 3
//            case 'T':
//            {
//                TSP_cmd(head);
//                break;
//            }
//            default:
////                c = getchar();
//                continue;

        }

    }

    return 1;
}











//
//int main(){
//    pnode Head = NULL;
////    printf("is in");
////    print_list(Head);
////    add_first(&Head,2);
////    add_first(&Head,1);
////    add_last(&Head,3);
//    for (int i = 0; i < 10000; ++i) {
//        add_last(&Head,3);
//    }
////    add_last(&Head,4);
//////    remove_node(&Head,4);
//////    remove_node(&Head,6);
//    print_list(Head);
////    delete(&Head);
//    return 0;
//}