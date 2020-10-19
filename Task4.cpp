////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
////Среднее арифметическое среди положительных чисел массива (3 баллов)
////Распределение данных через scatterv. Два mpi_reduce подряд не использовать.
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    //размер массива
//    int N = 20;
//    //nProc-кол во элементов на каждом процесса
//    int x[N], nProc, size, rank, totalAverage;
//    //массив с выбранными данными
//    int* aProc;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    //заполняем массив
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            x[i] = rand() % 100;
//            printf("x[%d] = %d\n", i, x[i]);
//        }
//    }
//
//    //кол во данных для каждого процесса
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
//        //сколько эл осталось
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
//
//    MPI_Scatterv(x, sendcounts, displs, MPI_INT, aProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//
//    int sum = 0;
//    for (int i = 0; i < nProc; i++)
//    {
//        if(aProc[i] > 0)
//            sum += aProc[i];
//    }
//
//    int aver = sum / nProc;
//
//    MPI_Reduce(&aver, &totalAverage, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if(!rank)
//        printf("totalAverage = %d\n", totalAverage);
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}