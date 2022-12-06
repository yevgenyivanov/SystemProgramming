#include <stdio.h>
#include "my_mat.h"
int path_generation(int[10][10]);
int matrix_insertion(int[10][10]);
int find_path(int[10][10], int, int);
int min_path(int[10][10], int, int);


int path_generation(int user_matrix[10][10]){ //helper function that generates the paths in user_matrix
    for(int i=0; i<10; i++){
        //Go over all vertices in the graph, as the source of comparison
        for(int j=0; j<10; j++){
            //Go over all destination vertices in the graph
            //from the the vertice at i
            for(int k=0; k<10; k++){
                
                if(j!=k //not same vertice
                 && user_matrix[j][i] != 0 //path from j to i exists (or i!=j)
                 && user_matrix[i][k] !=0 //path from i to k exists (or i!=k)
                 ){

                    // if the path exists between j to i and i to k, but eqauls zero from j to k
                    // create the path to be the sum of paths of usermatrix[j][i]+usermatrix[i][k]
                    if(user_matrix[j][k] == 0){
                    
                        user_matrix[j][k] = user_matrix[j][i] + user_matrix[i][k];

                    }
                    
                    //Shortest path calculation is as follows:
                    //If the path from j to k is longer than the combination of the paths between
                    // j to i and i to k, update to the lower value
                    if(user_matrix[j][k] > user_matrix[j][i] + user_matrix[i][k]){
                        user_matrix[j][k] = user_matrix[j][i] + user_matrix[i][k];
                    }
                    
                }
            }
        }
    }


    return 0;
}


//Function A

int matrix_insertion(int user_matrix[10][10]){ //function recieves values from user to input into the matrix
    int user_num=0;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            scanf("%d", &user_num);
            user_matrix[i][j] = user_num;
        }
    }
    // //printing the matrix before path generation
    // printf("Before generation: \n");
    // for(int i=0; i<10;i++){
    //     printf("Row %d: ", i);
    //     for(int j=0; j<10; j++){
    //         printf("%d ", user_matrix[i][j]);
    //     }
    //     printf("\n");
    // }


    path_generation(user_matrix);//find and generate missing paths in user_matrix by using the previous helper function
 
 
    //printing the matrix after path generation
    // printf("After generation: \n");
    // for(int i=0; i<10;i++){
    //     printf("Row %d: ", i);
    //     for(int j=0; j<10; j++){
    //         printf("%d ", user_matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;

}


int find_path(int user_matrix[10][10], int i, int j){ //Funtion B 
    if (user_matrix[i][j] != 0){
        return 1;
    }
    else return 0;
}



int min_path(int user_matrix[10][10], int i, int j){ //Function C
    if(user_matrix[i][j] != 0){
        return user_matrix[i][j];
    }
    else return -1;
}
