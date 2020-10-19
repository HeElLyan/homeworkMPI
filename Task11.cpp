////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
//// Циклическая передача данных  (6 баллов)
//// В коммуникаторе передаем сообщение от одного
//// процесса другому с нулевого до size-1.
//// Последний процесс отправляет сообщение нулевому.
//// На каждом процессе сообщение изменяется, если это число,
//// то можно прибавлять или умножать на что-то.
//
//int main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//
//    int rank, size;
//    int *sendbuf, *recvbuf;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    sendbuf = new int[1];
//    recvbuf = new int[1];
//
//    if (!rank) {
//        sendbuf[0] = 1;
//        //посылает первому процессу
//        MPI_Send(sendbuf, 1, MPI_INT, rank + 1, rank + 1, MPI_COMM_WORLD);
//    }
//    else
//    {
//        //получают от предыдущего процесса
//        MPI_Recv(recvbuf, 1, MPI_INT, rank - 1, rank, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
//
//        sendbuf[0] = 2 * recvbuf[0];
//
//        if (rank != size - 1)
//            //отправляют следующему процессу
//            MPI_Send(sendbuf, 1, MPI_INT, rank + 1, rank + 1, MPI_COMM_WORLD);
//        else
//            //последний ранк отправляет обратно первому
//            MPI_Send(sendbuf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//    }
//
//    if (!rank) {
//        MPI_Recv(recvbuf, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
//        printf("Result = %d\n", recvbuf[0]);
//    }
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}