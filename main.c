#include <stdio.h>
#include "my_mat.h"


//main
int main(){ 
    //create an empty 10x10 neighbouring matrix 
    int user_matrix[10][10] = {};
    //pointers for i,j values in functions B and C
    int i_value=0, j_value=0;
    //user input char for main
    char userinput=0;
    while((userinput) != 'D'){
        // printf("\n");
        // printf("Enter letter: ");
        scanf(" %c", &userinput);
        switch(userinput)
        {
            //recieve and insert values for vertice paths into user_matrix from the user
            //after recieving all values, a helper function in my_mat.c builds the missing paths and minimizes them
            case 'A':
                matrix_insertion(user_matrix);
                printf("\n");
                break;
            
            case 'B':
                scanf(" %d", &i_value);
                scanf(" %d", &j_value);
                if(find_path(user_matrix, i_value, j_value) == 1){
                    printf("True!\n");
                    i_value=0;
                    j_value=0;
                    break;
                }
                else{
                    printf("False!\n");
                    i_value=0;
                    j_value=0;
                    break;
                }

            case 'C':
                scanf(" %d", &i_value);
                scanf(" %d", &j_value);
                printf("%d\n", min_path(user_matrix, i_value, j_value));
                i_value=0;
                j_value=0;
                break;
        }
    }
    return 0;
}



