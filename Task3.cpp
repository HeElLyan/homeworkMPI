////
//// Created by He Elvina on 29.09.2020.
////
//
//#include <mpi.h>
//#include <iostream>
//
//using namespace std;
//
////Вычисление числа Пи методом Монте-Карло (3 баллов)
////Метод Монте-Карло для получения Пи,
////понимается как генерирование случайной последовательности точек
////из квадрата со сторонами 2 и центром в центре координат.
////Доля точек попавших в круг с радиусом один умноженная на 4 должна
////стремиться к числу Пи. Распараллеливание заключается
////в сбалансированном распределении итераций по процессам.
//
//int main()
//{
//    MPI_Init(NULL, NULL);
//
//    srand(time(0));
//
//    int rank, size, proc_id;
//
//    int iter_num = 10000;
//    double x, y, z, pi;
//    int all_points_count, points_count;
//
//    MPI_Status st;
//
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    //подсчет точек в круге
//    points_count = 0;
//    for (int i = 0; i < iter_num; i++)
//    {
//        x = ((double) rand() / (RAND_MAX));
//        y = ((double) rand() / (RAND_MAX));
//        z = x * x + y * y;
//        if (z <= 1) points_count++;
//    }
//
//    if (!rank) {
//        all_points_count = points_count;
//        for (proc_id = 1; proc_id < size; proc_id++) {
//            MPI_Recv(&points_count, 1, MPI_REAL, proc_id, 0, MPI_COMM_WORLD, &st);
//            all_points_count += points_count;
//        }
//        pi = (double) all_points_count / (iter_num * size) * 4;
//        printf("pi = %g \n", pi);
//    } else {
//        printf("rank = %d, points_count = %d\n", rank, points_count);
//        MPI_Send(&points_count, 1, MPI_REAL, 0, 0, MPI_COMM_WORLD);
//    }
//    MPI_Finalize();
//    return EXIT_SUCCESS;
//}