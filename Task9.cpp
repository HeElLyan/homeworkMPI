////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
//// Инвертировать массив (6 баллов)
//// Перевернуть массив.
//// Работа процессов должна быть сбалансирована.
//// Можно использовать как и Scatterv, Gatherv, так и  Send, Recv.
//
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    int N = 10;
//    int x[N], nProc, rank, size;
//    int *xProc, *result, *rev_xProc;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    if (!rank) {
//        for (int i = 0; i < N; i++) {
//            x[i] = rand() % 100;
//            printf(" %d ", x[i]);
//        }
//        printf("\n");
//    }
//
//    //кол во эл-в для каждого процесса
//    int* sendcounts = new int[size];
//    //индексы
//    int* displs = new int[size];
//    int* revdispls = new int[size];
//
//    int rest = N;
//    int k = rest / size;
//    //текущий процесс
//    sendcounts[0] = k;
//    displs[0] = 0;
//    revdispls[0] = N - k;
//
//    for (int i = 1; i < size; i++)
//    {
//        //сколько эл-в осталось
//        rest -= k;
//        k = rest / (size - i);
//        sendcounts[i] = k;
//        displs[i] = displs[i - 1] + sendcounts[i - 1];
//        revdispls[i] = revdispls[i - 1] - sendcounts[i];
//    }
//
////    printf("rank = %d, sendcounts = %d, displs = %d\n", rank, sendcounts[rank], displs[rank]);
//
//    nProc = sendcounts[rank];
//    xProc = new int[nProc];
//
//    MPI_Scatterv(x, sendcounts, displs, MPI_INT, xProc, nProc, MPI_INT, 0, MPI_COMM_WORLD);
//
//    rev_xProc = new int[nProc];
//    for(int i = 0; i < nProc; i++) {
//        rev_xProc[i] = xProc[nProc - i - 1];
//    }
//
//    result = new int[N];
//
//    MPI_Gatherv(rev_xProc, nProc, MPI_INT, result, sendcounts, revdispls, MPI_INT, 0, MPI_COMM_WORLD);
//
//    if(!rank) {
//        printf("\n");
//        for(int i = 0; i < N; i++)
//            printf(" %d ", result[i]);
//    }
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}