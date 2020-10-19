////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
//// Scatter и Gather через Send и Recv(6 баллов)
//// На одном процессе есть массив из n чисел. Выводим его.
//// При помощи send, recv раздаем всем процессам по n/size чисел.
//// Свою часть так же копируем в другой массив  размера n/size.
//// Выводим номер каждого процесса и его часть массива.
//// Далее при помощи send, recv собираем все части массива
//// на каком-либо процессе в новый массив размера n.
//// Выводим его.
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    int N = 10;
//    int x[N], nProc, rank, size;
//    int *sendbuf, *recvbuf;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    nProc = N / size;
//    recvbuf = new int[nProc];
//
//    if (!rank)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            x[i] = rand() % 100;
//            printf("%d  ", x[i]);
//        }
//        printf("\n");
//
//        for (int i = 0; i < size; i++)
//        {
//            sendbuf = new int[nProc];
//            for (int j = 0; j < nProc; j++)
//            {
//                sendbuf[j] = x[j + i * nProc];
//            }
//
//            if (i == 0)
//                recvbuf = sendbuf;
//            else
//                MPI_Send(sendbuf, nProc, MPI_INT, i, i + 10, MPI_COMM_WORLD);
//        }
//    }
//    else{
//        MPI_Recv(recvbuf, nProc, MPI_INT, 0, rank + 10, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//    }
//
//    for (int i = 0; i < nProc; i++)
//        printf("rank %d, recvbuf[%d] = %d\n", rank, i, recvbuf[i]);
//
//    if (!rank)
//    {
//        for (int i = 0; i < nProc; i++)
//            x[i] = recvbuf[i];
//    }
//    else {
//        MPI_Send(recvbuf, nProc, MPI_INT, 0, rank + 100, MPI_COMM_WORLD);
//    }
//    if (!rank)
//    {
//        for (int i = 1; i < size; i++)
//        {
//            MPI_Recv(recvbuf, nProc, MPI_INT, i, i + 100, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
//            for (int j = 0; j < nProc; j++)
//            {
//                x[nProc * i + j] = recvbuf[j];
//            }
//        }
//        printf("Final array: ");
//        for (int i = 0; i < N; i++)
//            printf("%d  ", x[i]);
//    }
//
//    MPI_Barrier(MPI_COMM_WORLD);
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}