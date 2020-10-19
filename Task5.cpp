////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
////Скалярное произведение (3 балла)
////Распределение данных через scatterv.
////Есть два массива – надо найти суммы произведений соответствующих координат.
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    //размер массива
//    int N = 5;
//    //nProc-кол во элементов на каждом процесса
//    int a[N], b[N], nProc, size, rank, totalMultipSum;
//    //массив с выбранными данными
//    int* aProc;
//    int* bProc;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    //заполняем массив
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            a[i] = rand() % 10;
//            b[i] = rand() % 10;
//            printf("a[%d] = %d ", i, a[i]);
//            printf("b[%d] = %d ", i, b[i]);
//        }
//    }
//
//    //кол во эл-в для каждого процесса
//    int* sendcounts = new int[size];
//    //индексы
//    int* displs = new int[size];
//
//    int rest = N;
//    int k = rest / size;
//    //текущий процесс
//    sendcounts[0] = k;
//    displs[0] = 0;
//
//    for (int i = 1; i <  size; i++)
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
//    aProc = new int[nProc];
//    bProc = new int[nProc];
//
//    //берет массив a или b разделяет его на нек-е кол-во эл-в и записывает в новый буфер данные для конкретного процесса
//    MPI_Scatterv(a, sendcounts, displs, MPI_INT, aProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//    MPI_Scatterv(b, sendcounts, displs, MPI_INT, bProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//
//    int multipSum = 0;
//    for (int i = 0; i < nProc; i++)
//        multipSum += aProc[i] * bProc[i];
//
//    //складывает все суммы из всех процессов в один
//    MPI_Reduce(&multipSum, &totalMultipSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if(!rank)
//        printf("\ntotalMultipSum = %d\n", totalMultipSum);
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}