#include <iostream>

void array2D(int (*ptr2D)[3], int total_row, int total_column)
{
    int row_position = 0;
    int tmp_row = 0;
    int column_max_index = total_column - 1;
    std::cout << "2D array output:" << std::endl << std::endl;
    for (int row_num = 0; row_num < total_row; ++ row_num){
        for (int column_num = 0; column_num < total_column; ++ column_num){
            row_position = row_num + 1;
            if (row_position != tmp_row){
                std::cout << "Row " << row_position << ":" << std::endl;
            }
            tmp_row = row_position;
            
            if (column_num == column_max_index){
                std::cout << *(*(ptr2D + row_num) + column_num) << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << *(*(ptr2D + row_num) + column_num) << ", ";
            }
        }      
    }
}

void array3D(int (*ptr3D)[3][3], int total_depth, int total_row, int total_column)
{
    int depth_position = 0;
    int tmp_depth = 0;
    int row_max_index = total_row - 1;
    int column_max_index = total_column - 1;
    std::cout << "3D array output:" << std::endl << std::endl;
    for (int depth_num = 0; depth_num < total_depth; ++ depth_num){
        depth_position = depth_num + 1;
        if (depth_position != tmp_depth){
            std::cout << "Depth " << depth_position << ":" << std::endl;
        }
        tmp_depth = depth_position;

        for (int row_num = 0; row_num < total_row; ++ row_num){
            for(int column_num = 0; column_num < total_column; ++ column_num){
                if (column_num == column_max_index){
                    std::cout << *(*(*(ptr3D + depth_num) + row_num) + column_num) << std::endl;
                } else{
                    std::cout << *(*(*(ptr3D + depth_num) + row_num) + column_num) << ", ";
                }
            }
            if (row_num == row_max_index){
                std::cout << std::endl;
            }
        }
    }
}

int main()
{
    int arr2D[2][3] = {
        {1,2,3}, 
        {4,5,6}
    };

    int arr2D_row = sizeof(arr2D) / sizeof(arr2D[0]);
    int arr2D_column = sizeof(arr2D[0]) / sizeof(arr2D[0][0]);

    int arr3D[2][3][3] = {
        {
            {1,2,3}, 
            {4,5,6}, 
            {7,8,9}
        }, 
        {
            {10,11,12}, 
            {13,14,15}, 
            {16,17,18}
        }
    };

    int arr3D_depth = sizeof(arr3D) / sizeof(arr3D[0]);
    int arr3D_row = sizeof(arr3D[0]) / sizeof(arr3D[0][0]);
    int arr3D_column = sizeof(arr3D[0][0]) / sizeof(arr3D[0][0][0]);

    array2D(arr2D, arr2D_row, arr2D_column);

    array3D(arr3D, arr3D_depth, arr3D_row, arr3D_column);
    return 0;
}