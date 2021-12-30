#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>

#include "graph.h"

pnode *head = NULL;








int main() {
    printf("Hello, World!\n");
    //Get the input:
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
                build_graph_cmd(head);
//                deleteGraph_cmd(head);
                break;
            }
            case 'n':
            {
                getchar();
                scanf(" %d", &id);
                pnode n_node = newNode(id);

                while (scanf(" %d", &i)==1)   //digit
            {
                int first=1;
                if (first){
                    dest = i;
                    first=0;
                }
                else{
                    w = i;
                    first=1;
                }
                pnode p_dest = search(dest, head);
                if (p_dest==NULL){
                    p_dest = newNode(dest);
                }
                addEdge(w, n_node->edges, p_dest);
            }
                break;
            }
//            case 'B':
//            {
//                insert_node_cmd(&head);
//                break;
//            }
//            case 'D':
//            {
//                delete_node_cmd(&head);
//                break;
//            }
//            case 'S':
//            {
//                shortsPath_cmd(head);
//                break;
//            }
//            case 'T':
//            {
//                TSP_cmd(head);
//                break;
//            }
            default:
//                c = getchar();
                continue;

        }

    }

    return 1;
}






















