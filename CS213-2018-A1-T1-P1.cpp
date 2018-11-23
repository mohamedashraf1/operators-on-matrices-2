// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    matrix mat3;//create a new matrix to save the result
     int arr[mat1.row*mat1.col];
    if (mat1.col==mat2.col && mat1.row==mat2.row){ //check that they are the same dimensions
    for (int i = 0 ; i <= mat1.col*mat1.row ; i++){ //loop for the whole array
        arr[i]=mat1.data[i]+mat2.data[i]; //make the calculation and save the result in the new matrix
    }
    }
    else{
        cout<<"rows and columns must be equal to add them"<<endl;
    }
    createMatrix(mat1.row , mat1.col ,arr ,mat3 );
    return mat3;
}
matrix operator-  (matrix mat1, matrix mat2) // Sub if same dimensions
{
    matrix mat3;//create a new matrix to save the result
     int arr[mat1.row*mat1.col];
    if (mat1.col==mat2.col && mat1.row==mat2.row){ //check that they are the same dimensions
    for (int i = 0 ; i <= mat1.col*mat1.row ; i++){ //loop for the whole array
        arr[i]=mat1.data[i]-mat2.data[i]; //make the calculation and save the result in the new matrix
    }
    }
    else{
        cout<<"rows and columns must be equal to add them"<<endl;
    }
    createMatrix(mat1.row , mat1.col ,arr ,mat3 );
    return mat3;
}
matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    int arr[mat1.col*mat1.row];
    matrix mat3;//create a new matrix to save the result
    if (mat1.col==mat2.row){//check that col1 == row2
        for (int i = 0 ; i < mat1.row ; i++){
            for (int j = 0 ; j < mat2.col ; j++){
                for (int k = 0 ; k < mat1.col ; k++){

                    arr[i * mat3.col + j] += mat1.data[i * mat1.col + k] * mat2.data[k * mat2.col + j];
                }
            }
        }
        createMatrix( mat1.row,mat1.col,arr,mat3);
    }
    else
        cout<<"rows and columns must be equal to add them"<<endl;
    return mat3;

}
matrix operator+  (matrix mat1, int scalar)  // Add a scalar
{
   matrix mat3;//create a new matrix to save the result
    int arr[mat1.row*mat1.col];
    for (int i = 0 ; i <= mat1.col*mat1.row ; i++){//loop for the whole array
        arr[i]=mat1.data[i]+scalar;//make the calculation and save the result in the new matrix
    }
    createMatrix( mat1.row,mat1.col,arr,mat3);
    return mat3;

}
matrix operator-  (matrix mat1, int scalar)  // Subtract a scalar
{
    matrix mat3;//create a new matrix to save the result
    int arr[mat1.row*mat1.col];
    for (int i = 0 ; i <= mat1.col*mat1.row ; i++){//loop for the whole array
        arr[i]=mat1.data[i]-scalar;//make the calculation and save the result in the new matrix
    }
    createMatrix( mat1.row,mat1.col,arr,mat3);
    return mat3;

}
matrix operator*  (matrix mat1, int scalar)  // Multiple by scalar
{
    matrix mat3;//create a new matrix to save the result
    int arr[mat1.row*mat1.col];
    for (int i = 0 ; i <= mat1.col*mat1.row ; i++){//loop for the whole array
        arr[i]=mat1.data[i]*scalar;//make the calculation and save the result in the new matrix
    }
    createMatrix( mat1.row,mat1.col,arr,mat3);
    return mat3;
}

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2) // add mat2 to mat1 and change mat1
{
    if(mat1.row==mat2.row && mat1.col==mat2.col){
        for(int i=0 ; i<mat1.row*mat1.col ; i++){
            mat1.data[i]+=mat2.data[i];
        }
    }
    else{
        cout<<"they can not add "<<endl;
    }
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2) //subtract mat2 to mat1 and change mat1

    {
        if(mat1.row==mat2.row && mat1.col==mat2.col){
        for(int i=0 ; i<mat1.row*mat1.col ; i++){
            mat1.data[i]-=mat2.data[i];
        }
    }
    else{
        cout<<"they can not subtract "<<endl;
    }
    return mat1;
}


matrix operator+= (matrix& mat, int scalar)   // change mat & return new matrix
{
    for(int i=0 ; i<mat.row*mat.col ; i++){
        mat.data[i]+=scalar;
    }
    return mat;
}

matrix operator-= (matrix& mat, int scalar)   // change mat & return new matrix
{
    for(int i=0 ; i<mat.row*mat.col ; i++){
        mat.data[i]-=scalar;
    }
    return mat;
}
void   operator++ (matrix& mat)   	// Add 1 to each element ++mat
{

for(int i=0 ; i<mat.row*mat.col ; i++){
    mat.data[i]=mat.data[i]+1;
}
}
void   operator-- (matrix& mat)    	// Sub 1 from each element --mat
{
    for(int i=0 ; i<mat.row*mat.col ; i++){
        mat.data[i]=mat.data[i]-1;
    }
}
istream& operator>> (istream& in, matrix& mat)
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input
       {
           cout<<"enter the row and col :";
           in>>mat.row >> mat.col ;
           mat.data = new int[mat.row*mat.col];
           cout<<"enter the matrix data :";
           for(int i=0 ; i<mat.row*mat.col ; i++){
                in>>mat.data[i];

           }

           return in;
       }

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat)
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
	       {
	           int c=0;
	           for(int i=0 ; i<mat.row*mat.col ; i++){
                if(c==mat.col){
                    cout<<endl;
                    c=0;
                }
                    out<<mat.data[i]<<" ";
                    c++;
	           }
	           return out;
	       }
bool   operator== (matrix mat1, matrix mat2)	// True if identical
{
     for(int i=0;i<(mat1.row*mat1.col);i++){
        return(mat1.data[i]==mat2.data[i]);

}
}
bool   operator!= (matrix mat1, matrix mat2) 	// True if not same
{
    for(int i=0;i<(mat1.row*mat1.col);i++){
        return(mat1.data[i]!=mat2.data[i]);
}
}
bool   isSquare   (matrix mat)  // True if square matrix
{
    return(mat.col==mat.row);
}
bool   isSymetric (matrix mat)  // True if square and symmetric
{
    int sum1=0,sum2=0,x=0,y=0;
    int summ1[mat.row],summ2[mat.row];
    if(mat.col==mat.row){
            for(int i=0;i<mat.row;i++){
                for(int j=0;j<mat.col;j++){
                sum1+=mat.data[i*mat.col+j];


                }
                summ1[x]=sum1;
                sum1=0;
                x++;

            }
              for(int i=0;i<mat.col;i++){

                for(int j=0;j<mat.row;j++){
                        sum2+=mat.data[j*mat.row+i];

                }
                 summ2[y]=sum2;
                sum2=0;
                y++;
              }
              for(int k=0;k<mat.row;k++){
                return(summ1[k]==summ2[k]);
              }


    }

}
bool   isIdentity (matrix mat)  // True if square and identity
{
    bool check=true;
    if(mat.col!=mat.row){
            check=false;


    }
    else if(mat.col==mat.row){
        for(int i=0;i<mat.row;i++){
            for(int j=0;j<mat.col;j++){
                if(i==j&&mat.data[i*mat.col+j]!=1)
                    check=false;
                else if(i!=j&&mat.data[i*mat.col+j]!=0)
                    check=false;
            }
        }
    }
    return check;

}
matrix transpose(matrix mat)    // Return new matrix with the transpose
{
     matrix mat1;
    int arr[mat.row*mat.col];

     for(int i=0;i<mat.col;i++){
        for(int j=0;j<mat.row;j++){
            arr[i*mat.row+j]=mat.data[j*mat.col+i];




        }
    }
    createMatrix(mat.col,mat.row,arr,mat1);

    return mat1;
}

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3 ,mat4,mat5,mat6;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);

 //The next code will not work until you write the functions
 /*
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  */


  cout << (mat1 + mat3) << endl<<endl;
  cout << (mat3 + mat3) << endl << endl;
  cout<< (mat3 - mat3 )  <<endl<<endl;
  cout << (mat3 * mat3) <<endl<<endl;
  cout<< (mat3 + 1)<<endl<<endl;
  cout<< (mat3 += 1)<<endl<<endl;
  cout<< (mat3 += mat1)<<endl<<endl;
  cout<< (mat3 -= mat1)<<endl<<endl;
  ++mat3;
  cout<< (mat3)<<endl<<endl;
  /*


  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}
