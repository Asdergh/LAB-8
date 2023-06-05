#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void matrix_multiplication(const int ROW,   const int COL){
    FILE* matrix_one = fopen("matrix_one.txt", "r");
    FILE* matrix_two = fopen("matrix_two.txt", "r");
    FILE* matrix_result = fopen("matrix_result.txt", "w");

    int cursor_mat_one = ftell(matrix_one);
    int cursor_mat_two = ftell(matrix_two);
    int tmp_result;
    int tmp_array[100];
    int result_array[100];

    for (int i = 0; i < COL + 2; i ++){
        int iter = 1;
        int tmp_cursor_mat_one = cursor_mat_one;
        int tmp_cursor_mat_two = cursor_mat_two;
        while (iter < COL){

            tmp_cursor_mat_one = cursor_mat_one + 2;
            tmp_cursor_mat_two = cursor_mat_two + 7;
            int m1 = fseek(matrix_one, tmp_cursor_mat_one, SEEK_SET) - '0';
            int m2 = fseek(matrix_two, tmp_cursor_mat_one, SEEK_SET) - '0';
            tmp_result = m1 * m2;
            printf("%i M1 --- %i M2\n", m1, m2);
            tmp_array[i] = tmp_result;
            printf("%i -- tmp_result \n", tmp_result);
            iter ++;
        }
        cursor_mat_one = tmp_cursor_mat_one + 2;
        cursor_mat_two = tmp_cursor_mat_two + 7;
    }
    for (int j = 0; j < sizeof(tmp_result); j ++){
       printf("%i ", tmp_array[j]);
    }
}
void main(){
    matrix_multiplication(3, 3);
}