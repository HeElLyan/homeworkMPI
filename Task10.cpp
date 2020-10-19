////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
//// Время передачи для разных Send-oв (6 баллов)
//// Программу тестируем на двух процессах.
//// Используем Send, Ssend, Bsend и Rsend  - передаем какой-либо
//// длинный массив или строку второму процессу, и получаем  обратно.
//// Замеряем время потраченные на эти операции.
//
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    int N = 100;
//    int x[N], rank, size;
//    double startSend, endSend;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    if(!rank)
//    {
//        for (int i = 0; i < N; i++) {
//            x[i] = rand() % 100;
//            printf("%d ", x[i]);
//        }
//
//        startSend = MPI_Wtime();
//        MPI_Send(x, N, MPI_INT, 1, 0, MPI_COMM_WORLD);
//        MPI_Recv(x, N, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        endSend = MPI_Wtime();
//        printf("\nSend time %f\n", endSend-startSend);
//
//        //буферная передача:
//        //сообщение буферизируется в любом случае, операция завершается сразу после буферизации.
//        //Операция - локальная, т.е она зависит от выполнения только на данном процессе.
////        startSend = MPI_Wtime();
////        MPI_Bsend(x, N, MPI_INT, 1, 1, MPI_COMM_WORLD);
////        MPI_Recv(x, N, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
////        endSend = MPI_Wtime();
////        printf("BSend time %f\n", endSend-startSend);
//
//        //синхронная передача:
//        //требует для своего выполнения, чтобы процессор-получатель отправил соответствующее сообщение,
//        //что он начал прием сообщения, и тогда только функция завершает свою работу.
//        MPI_Buffer_attach( x, N );
//        startSend = MPI_Wtime();
//        MPI_Ssend(x, N, MPI_INT, 1, 2, MPI_COMM_WORLD);
//        MPI_Recv(x, N, MPI_INT, 1, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        endSend = MPI_Wtime();
//        printf("SSend time %f\n", endSend-startSend);
//
//        //передача по готовности:
//        //сообщение отправляется в тот момент, когда процесс-получатель уже инициировал
//        //соответствующий прием сообщения. Эта функция позволяет максимально быстро передавать сообщения.
//        startSend = MPI_Wtime();
//        MPI_Rsend(x, N, MPI_INT, 1, 3, MPI_COMM_WORLD);
//        MPI_Recv(x, N, MPI_INT, 1, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        endSend = MPI_Wtime();
//        printf("RSend time %f\n", endSend-startSend);
//    }
//    else
//    {
//        MPI_Recv(x, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        MPI_Send(x, N, MPI_INT, 0, 0, MPI_COMM_WORLD);
//
////        MPI_Recv(x, N, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
////        MPI_Bsend(x, N, MPI_INT, 0, 1, MPI_COMM_WORLD);
//
//        MPI_Recv(x, N, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        MPI_Ssend(x, N, MPI_INT, 0, 2, MPI_COMM_WORLD);
//
//        MPI_Recv(x, N, MPI_INT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        MPI_Rsend(x, N, MPI_INT, 0, 3, MPI_COMM_WORLD);
//    }
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}