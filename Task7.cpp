////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
//// Умножение матрицы на вектор при разделении данных по столбцам (7 баллов - doc7.pdf)
//// На одном процессе заполняется матрица и вектор.
//// Каждый процесс получает несколько столбцов матрицы
//// и столько же элементов вектора. Рассчитывает частичную
//// сумму результирующего вектора.  ci = A i,j * b j
//// для  j-го столбца. Если столбцов несколько, то cj суммируются.
//// Далее все частичные суммы собираются в результат.
//
//
//int main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//
//    srand(time(0));
//
//    int N = 5;
//    int a[N * N], b[N], c[N], rank, size, nProc, nProc_a;
//    int *aProc, *cProc;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                a[i * N + j] = rand() % 100;
//                printf("\t%d\t", a[i * N + j]);
//            }
//            printf("*");
//            b[i] = rand() % 100;
//            printf("\t%d\t", b[i]);
//            printf("\n");
//        }
//        printf("\n");
//    }
//
//    //кол во эл-в для каждого процесса
//    int *sendcounts = new int[size], *sendcounts_c = new int[size];
//    //индексы
//    int *displs = new int[size], *displs_c = new int[size];
//
//    int rest = N;
//    int k = rest / size;
//    //текущий процесс
//    sendcounts[0] = k * N;
//    sendcounts_c[0] = k;
//    displs[0] = 0;
//    displs_c[0] = 0;
//
//    for (int i = 1; i < size; i++)
//    {
//        //сколько эл-в осталось
//        rest -= k;
//        k = rest / (size - i);
//        sendcounts[i] = k * N;
//        sendcounts_c[i] = k;
//        displs[i] = displs[i - 1] + sendcounts[i - 1];
//        displs_c[i] = displs_c[i - 1] + sendcounts_c[i - 1];
//    }
//
////    printf("rank = %d, sendcounts = %d, displs = %d\n", rank, sendcounts[rank], displs[rank]);
//
//    nProc = sendcounts[rank];
//    aProc = new int[nProc];
//    nProc_a = sendcounts_c[rank];
//    cProc = new int[nProc_a];
//
//    //берет массив, разделяет его на нек-е кол-во эл-в и записывает в новый буфер данные для конкретного процесса
//    MPI_Scatterv(a, sendcounts, displs, MPI_INT, aProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//    //создаем копию вектора y для каждого процесса
//    MPI_Bcast(b, N, MPI_INT, 0, MPI_COMM_WORLD);
//
//
//    for (int i = 0; i < nProc / N; i++)
//    {
//        cProc[i] = 0;
//        for (int j = 0; j < N; j++){
//            cProc[i] += aProc[i * N + j] * b[j];
//        }
////        printf("rank %d, cProc =  %d\n", rank, cProc[i]);
//    }
//
//    MPI_Gatherv(cProc, sendcounts_c[rank], MPI_INT, c, sendcounts_c, displs_c, MPI_INT, 0, MPI_COMM_WORLD);
//
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            printf("%d ", c[i]);
//        }
//    }
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}