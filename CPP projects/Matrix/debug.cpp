#include "include/s21_matrix_oop.h"

// static void FillMx(S21Matrix& matrix){
//     int count = 0;

//     for(auto i = 0; i < matrix.GetRows(); i++){
//         for(auto j = 0; j < matrix.GetCols();j++){
//             matrix(i,j) = ++count;
//         }
//     }    
// }

static void PrintMx(S21Matrix& matrix) {
    for(auto i = 0; i < matrix.GetRows(); i++){
        for(auto j = 0; j < matrix.GetCols();j++){
            cout << matrix(i,j) << " ";
        }
        cout << endl;
    }
}


int main(){
   try{
    S21Matrix matrix1{3, 3};
 
    matrix1(0, 0) = -7.00037610391155;
    matrix1(1, 0) = -6.32839397341013;
    matrix1(2, 0) = 10.222164043691;
    matrix1(0, 1) = -9.82599597726949;
    matrix1(1, 1) = 3.03237457247451;
    matrix1(2, 1) = 0.587724786484614;
    matrix1(0, 2) = 8.27683520526625;
    matrix1(1, 2) = -4.28063526446931;
    matrix1(2, 2) = -6.93227237439714;

    S21Matrix res = matrix1.InverseMatrix();
    
    S21Matrix check = matrix1 * res;

    PrintMx(check);
    
   }
   catch(exception& e){
    cout << e.what() << endl;
   }


  return 0;
}

// noexcept is a compile-time specifier
// [new] returns bad_alloc() exception if it fails
// out_of_range, logic error, invalid argument 
