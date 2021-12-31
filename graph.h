#ifndef GRAPH_

    #define GRAPH_
        typedef struct GRAPH_NODE_ *pnode;

        typedef struct edge_ {
            int weight;
            pnode endpoint;
            struct edge_ *next;
        } edge, *pedge;

        typedef struct GRAPH_NODE_ {
            int node_num;
            struct node* next;
            pedge edges;
            struct node* nextH;
            int visit;
            float dist;
        } node, *pnode;


        pnode create_node(int);
        void add_first(pnode *, int);
        void add_last(pnode *, int);
        void delete(pnode*);
        void print_list(pnode);
        void remove_node(pnode*, int);


        void build_graph_cmd(pnode *head);
        void insert_node_cmd(pnode *head);
        void delete_node_cmd(pnode *head, int id);
        void printGraph_cmd(pnode head); //for self debug
        void deleteGraph_cmd(pnode* head);
        void shortsPath_cmd(pnode head);
        void TSP_cmd(pnode head);

        pnode newNode(int id);
        pnode search(pnode *head, int id);
        void addEdge(pedge *p_src, int w, pnode *p_dest);

    #endif
