////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <time.h>
//#include <iostream>
//
//using namespace std;
//
//// Уметь использовать что-то из send, recv, bcast, reduce
//// Maксимум массива  (3 балла)
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    int size, rank, totalMax;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    //размер массива
//    int N = 10;
//    int x[N];
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
//    MPI_Bcast(x, N, MPI_INT, 0 , MPI_COMM_WORLD);
//
//    int k = N / size;
//    int i1 = rank * k;
//    int i2 = (rank + 1) * k;
//    if(rank == size - 1)
//        i2 = N;
//    printf("rank = %d, i1 = %d, i2 = %d\n", rank, i1, i2);
//
//    int max = INT_MIN;
//    for (int i = i1; i < i2; i++)
//    {
//        if (x[i] > max)
//        {
//            max = x[i];
//        }
//    }
//
//    printf("max = %d\n", max);
//
//    //все процессы посылают число и на руте собирается результат
//    //если массивы, то они будут собираться поэлементно
//    MPI_Reduce(&max, &totalMax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
//
//    if (!rank)
//        printf("totalMax = %d\n", totalMax);
//
////    if (!rank)
////    {
////        MPI_Status st;
////        printf("Hello from %d out of %d!\n", rank, size);
////
////        for (int i = 1; i < size; i++)
////        {
////            MPI_Recv(&recv, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
////            printf("Max is %d for %d rank!\n", recv, i);
////        }
////    }
////    else
////    {
////        printf("Hello from %d out of %d!\n", rank, size);
////        for (int i = 0; i < N; i++)
////        {
////            if (x[i] > max)
////            {
////                max = x[i];
////            }
////        }
////        MPI_Send(&max, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
////        printf("Sending max %d to rank 0 from rank %d\n", max, rank);
////    }
//
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}