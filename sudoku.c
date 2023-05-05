#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    
    
    for(int f=0;f<9;f++){
    
      int arrayFila[10];
      int arrayCol[10];
      

         for(int c=0;c<9;c++){
             
            if(n->sudo[f][c]!=0){
                if(arrayFila[n->sudo[f][c]]==1){
                    return 0;
                }else{
                    arrayFila[c]=1;
                }
            }

             if(n->sudo[c][f]!=0){
                if(arrayCol[n->sudo[c][f]]==1){
                    return 0;
                }else{
                    arrayCol[c]=1;
                }
            }
        }  
        int k=4,p; 
    for(p=0;p<9;p++){
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        printf("%d ",n->sudo[i][j]);
        if(p%3 == 2) printf("\n");
    }
    }
    
    
    return 1;
}


List* get_adj_nodes(Node* n){
    
    List* list=createList();

    for(int f=0;f<9;f++){

        for(int c=0;c<9;c++){

            if(n->sudo[f][c]==0){

                for(int j=1;j<=9;j++){

                    Node *nodoNuevo=copy(n);
                    nodoNuevo->sudo[f][c]=j;
                    pushBack(list,nodoNuevo);

                }
            }
        
        }
    }

    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/