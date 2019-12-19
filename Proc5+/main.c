/*
14) Используя декомпозицию и механизм подпрограмм написать программу решения задачи:
 в) Даны две квадратные матрицы n-го порядка каждая (n - не превышает 20). Напечатать квадрат той из них, в которой наименьший след (сумма элементов главной диагонали).
*/


#define printf_s printf
#define scanf_s scanf
#define UCHAR int

#include <stdio.h>
#include <locale.h>

const UCHAR i = 20;

//MARK: - Создания матрицы
void setMatrix(UCHAR max, int (*matrix)[i])
{
    for (UCHAR j = 0; j < max; j++)
        for (UCHAR t = 0; t < max; t++)
        {
            printf_s("\nВведите значения матрицы (%d)(%d): ", j + 1, t + 1);
            scanf_s("%d", &matrix[j][t]);
        }
    printf_s("______________________________________\n");
}

//MARK: - Вычисление суммы элементов главной диагонали
void matrixSum(UCHAR max, int (*matrix)[i], int *sum)
{
    for (UCHAR j = 0; j < max; j++)
        *sum += matrix[j][j];
}

//MARK: - Вывод квадрата матрицы
void printMatrix(UCHAR max, int (*matrix)[i])
{
    printf_s("\n-------------\n");
    for (UCHAR i = 0; i < max; i++)
    {
        for (UCHAR j = 0; j < max; j++)
        {
            int g = 0;
            for (UCHAR k = 0; k < max; k++)
                g += matrix[i][k] * matrix[k][j];
            printf_s("| %d ", g);
        }
        printf_s("|\n-------------\n");
    }
}

//MARK: - Сравнение матриц
void matrixComp(UCHAR max, int (*fmatrix)[i], int (*smatrix)[i])
{
    int fsum = 0, ssum = 0;
    matrixSum(max, fmatrix, &fsum); //Считаем сумму элементов главной диагонали первой матрицы
    matrixSum(max, smatrix, &ssum); //Считаем сумму элементов главной диагонали второй матрицы
    printf_s("Квадрат матрицы с наименьшей диагональю: \n");
    
    if (fsum < ssum)
        printMatrix(max, fmatrix);  //Печатаем квадрат первой матрицы
    else
        printMatrix(max, smatrix);  //Печатаем квадрат второй матрицы
}

//MARK: - main()
int main()
{
    int A[i][i], B[i][i];
    UCHAR k = 0;
    setlocale(LC_ALL, "Rus");
    printf_s("Введите размерность квадратной матрицы: ");
    scanf_s("%d", &k);
    setMatrix(k, A);                //Заполняем первую матрицу
    setMatrix(k, B);                //Заполняем вторую матрицу
    matrixComp(k, A, B);            //Сравниваем главные диагонали двух матриц
    return 0;
}

