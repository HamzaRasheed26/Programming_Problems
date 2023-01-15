#include <iostream>
#include <conio.h>

using namespace std;

// matrix A
int A[3][3] = {{2, 3, 6},
               {3, 4, 5},
               {6, 5, 9}};

// Matrix B
int B[3][3] = {{1, 0, 0},
               {0, 0, 0},
               {0, 0, -4}};

// Matrix C
int C[3][3];

void InputValueInMatrixA(); // function for taking input values in Matrix A and B
void InputValueInMatrixB();
void print(int D[3][3]);                       // function for displaying matrix values
void sum(int A[3][3], int B[3][3]);            // function for adding two matrix
void subtraction(int A[3][3], int B[3][3]);    // function for subtraction of two matrix
void multiplication(int A[3][3], int B[3][3]); // function for multiplication of two matrix
void scalarMultiplication(int A[3][3]);        // function for sacalar multiplication with matrix
bool isIdentityMatrix(int M[3][3]);            // function for checking property of identity matrix
void transposeMatrix(int M[3][3]);             // function for transposing matrix
bool isDiagonalMatrix(int M[3][3]);            // function for checking property of diagonal matrix
bool isSymmetric(int M[3][3]);                 // function for checking is matrix is symmetric

char menu()
{
    cout << "******************************************" << endl;
    cout << "*            MATRIX CALCULATOR           *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    cout << " 1. Sum " << endl;
    cout << " 2. Subtraction " << endl;
    cout << " 3. Multiplication " << endl;
    cout << " 4. Scalar Multiplication " << endl;
    cout << " 5. Transpose " << endl;
    cout << " 6. Check Properties " << endl;
    cout << " 7. Exit " << endl;
    char op;
    cin >> op;
    return op;
}

main()
{
    while (true)
    {
        system("cls");

        char op;
        op = menu();

        if (op == '1') // sum
        {
            InputValueInMatrixA();
            InputValueInMatrixB();
            print(A);
            print(B);
            sum(A, B);
            print(C);
        }
        else if (op == '2')
        {
            InputValueInMatrixA();
            InputValueInMatrixB();
            print(A);
            print(B);
            subtraction(A, B);
            print(C);
        }
        else if (op == '3')
        {
            InputValueInMatrixA();
            InputValueInMatrixB();
            print(A);
            print(B);
            multiplication(A, B);
            print(C);
        }
        else if (op == '4')
        {
            InputValueInMatrixA();
            print(A);
            scalarMultiplication(A);
            print(C);
        }
        else if (op == '5')
        {
            InputValueInMatrixA();
            print(A);
            transposeMatrix(A);
            cout << " Transpose Matrix" << endl;
            print(C);
        }
        else if (op == '6')
        {
            InputValueInMatrixA();
            print(A);
            if (isIdentityMatrix(A))
            {
                cout << " Identity Matrix " << endl;
            }
            else
            {
                cout << " Not Identity Matrix " << endl;
            }
            if (isDiagonalMatrix(A))
            {
                cout << " Diagonal Matrix " << endl;
            }
            else
            {
                cout << " Not Diagonal Matrix " << endl;
            }

            if (isSymmetric(A))
            {
                cout << " Symmetric Matrix " << endl;
            }
            else
            {
                cout << " Not Symmetric Matrix " << endl;
            }
        }
        else if (op == '7')
        {
            break;
        }
        cout << " Press Any key to continue....";
        getch();
    }

    // InputValueInMatrixA();
    // InputValueInMatrixB();
    // print(A);
    // print(B);
    // sum(A, B);
    // print(C);
    // subtraction(A, B);
    // print(C);
    // multiplication(A, B);
    // print(C);
    // scalarMultiplication(A);
    // print(C);

    // if (isIdentityMatrix(A))
    // {
    //     cout << " Identity Matrix " << endl;
    // }
    // else
    // {
    //     cout << " Not Identity Matrix " << endl;
    // }

    // transposeMatrix(A);
    // cout << " Transpose Matrix" << endl;
    // print(C);

    // if (isDiagonalMatrix(A))
    // {
    //     cout << " Diagonal Matrix " << endl;
    // }
    // else
    // {
    //     cout << " Not Diagonal Matrix " << endl;
    // }

    // if (isSymmetric(A))
    // {
    //     cout << " Symmetric Matrix " << endl;
    // }
    // else
    // {
    //     cout << " Not Symmetric Matrix " << endl;
    // }
}

// function for displaying matrix values
void print(int D[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << "\t" << D[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

// function for taking input values in Matrix A and B
void InputValueInMatrixA()
{
    cout << " Enter the values of Matrix A " << endl;
    for (int x = 0; x < 3; x++) // taking values in matrix A
    {
        for (int y = 0; y < 3; y++)
        {
            cout << " For R" << x + 1 << "C" << y + 1 << " : ";
            cin >> A[x][y];
            cout << endl;
        }
    }
}

void InputValueInMatrixB()
{
    cout << " Enter the values of Matrix B " << endl;
    for (int x = 0; x < 3; x++) // taking values in matrix A
    {
        for (int y = 0; y < 3; y++)
        {
            cout << " For R" << x + 1 << "C" << y + 1 << " : ";
            cin >> B[x][y];
            cout << endl;
        }
    }
}

// function for adding two matrix
void sum(int A[3][3], int B[3][3])
{
    cout << " Addition of Matrices is : " << endl;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            C[x][y] = A[x][y] + B[x][y]; // adding values of matrix A and B
        }
    }
}

// function for subtraction of two matrix
void subtraction(int A[3][3], int B[3][3])
{
    cout << " Subtraction of Matrices is : " << endl;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            C[x][y] = A[x][y] - B[x][y]; // subtracting values of matrix A and B
        }
    }
}

// function for multiplication of two matrix
void multiplication(int A[3][3], int B[3][3])
{
    cout << " Multiplication of Matrices is : " << endl;

    // multiplying rows wiyh coloumns

    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1];
    C[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2];

    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1];
    C[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2];

    C[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0];
    C[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1];
    C[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2];
}

// function for sacalar multiplication with matrix
void scalarMultiplication(int A[3][3])
{
    int num;

    cout << " Enter the you want to multiply with ... : ";
    cin >> num;
    cout << " Scalar Multiplication of Matrix with " << num << " : " << endl;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            C[x][y] = A[x][y] * num; // multiplying matrix with scalar value
        }
    }
}

// function for checking property of identity matrix
bool isIdentityMatrix(int M[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (x == y)
            {
                if (M[x][y] != 1) // if the diagonal values are not equal to 1 than return false
                {
                    return false;
                }
            }
            else
            {
                if (M[x][y] != 0) // if the other values are not equal to 0 than return false
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// function for transposing matrix
void transposeMatrix(int M[3][3])
{

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            C[y][x] = A[x][y]; // giving the values of rows to columns
        }
    }
}

// function for checking property of diagonal matrix
bool isDiagonalMatrix(int M[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (x == y) // skiping the diagonal values
            {
                continue;
            }
            else
            {
                if (M[x][y] != 0) // if the other values are not equal to 0 than return false
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// function for checking is matrix is symmetric
bool isSymmetric(int M[3][3])
{
    transposeMatrix(M); // changing rows into coloumns and saving in matrix C

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (C[x][y] != M[x][y]) // if Matrix C and Matrix M (which is passed from main) are not same at any point return false
            {
                return false;
            }
        }
    }
    return true;
}