////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
////Maxmin матрицы (5 балла)
////Найти седловую точку матрицы. Распределение данных через scatterv.
////Каждый процесс получает какое-то количество строк матрицы.
////Находит для каждой строки минимум и выбирает из  них максимальный.
////Далее из локальных максимумов выбирает глобальный.
////Проверить совпадают ли maxmin и minmax.
//
//
//int main() {
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    //размер массива
//    int N = 5;
//    //nProc-кол во элементов на каждом процесса
//    int matrix[N*N], nProc, size, rank, totalMinMax;
//    //массив с выбранными данными
//    int* matrixProc;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    //заполняем массив
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                matrix[i * N + j] = rand() % 100;
//                printf("\t%d\t", matrix[i * N + j]);
//            }
//            printf("\n");
//        }
//    }
//
//    //кол во эл-в для каждого процесса
//    int* sendcounts = new int[size];
//    //индексы
//    int* displs = new int[size];
//
//    int rest = N * N;
//    int k = rest / size;
//    //текущий процесс
//    sendcounts[0] = k;
//    displs[0] = 0;
//
//    for (int i = 1; i < size; i++)
//    {
//        //сколько эл-в осталось
//        rest -= k;
//        k = rest / (size - i);
//        sendcounts[i] = k;
//        displs[i] = displs[i - 1] + sendcounts[i - 1];
//    }
//
////    printf("rank = %d, sendcounts = %d, displs = %d\n", rank, sendcounts[rank], displs[rank]);
//
//    nProc = sendcounts[rank];
//    matrixProc = new int[nProc];
//
//    //берет массив, разделяет его на нек-е кол-во эл-в и записывает в новый буфер данные для конкретного процесса
//    MPI_Scatterv(matrix, sendcounts, displs, MPI_INT, matrixProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//
//    int min = INT_MAX;
//    for (int i = 0; i < nProc; i++)
//    {
//        if (matrixProc[i] < min)
//            min = matrixProc[i];
//    }
//
//    printf("min = %d  ", min);
//
//    MPI_Reduce(&min, &totalMinMax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
//
//    if(!rank)
//        printf("\ntotalMinMax = %d\n", totalMinMax);
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}