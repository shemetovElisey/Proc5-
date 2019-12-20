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
void sumMainDiagonal(UCHAR max, int (*matrix)[i], int *sum)
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
void compMatrix(UCHAR max, int (*fmatrix)[i], int (*smatrix)[i])
{
    int fsum = 0, ssum = 0;
    sumMainDiagonal(max, fmatrix, &fsum); // След первой матрицы
    sumMainDiagonal(max, smatrix, &ssum); // След второй матрицы
    printf_s("Квадрат матрицы с наименьшей диагональю: \n");
    (fsum < ssum) ? (printMatrix(max, fmatrix)) : (printMatrix(max, smatrix));
}

//MARK: - main()
int main()
{
    int A[i][i], B[i][i];
    UCHAR k = 0;
    setlocale(LC_ALL, "Rus");
    printf_s("Введите размерность квадратной матрицы: ");
    scanf_s("%d", &k);
    setMatrix(k, A);                // Первая матрица
    setMatrix(k, B);                // Вторая матрица
    compMatrix(k, A, B);            // Сравниваем главные диагонали двух матриц
    return 0;
}

