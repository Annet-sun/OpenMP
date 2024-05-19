#include <iostream>
#include <windows.h>
#include<omp.h>
using namespace std;
//--------------------����� � ���������� ����������. ������������� ������� � ����������, ����������� ���������� ����� �� ������������� ����--------------------------------------------


//------------------------------------------------------������� 1-------------------------------------------------------------------------------
//�������� ��������� ��� ������ ����� �������� ���� �������������, ���������� ������� ����� �
//������� �Hello World�.��������� ��������� � 8 ��������.������ �� ����� ��������� ? ������ ?
//
//int main() {
//    omp_set_num_threads(8);
//    /*#pragma omp parallel num_threads(8)*/
//    #pragma omp parallel
//    {
//        int thread_num = omp_get_thread_num();
//        int threads_count = omp_get_num_threads();
//        printf("Hello world, thread number %d, threads: %d\n", thread_num, threads_count);
//    }
//}

//------------------------------------------------------������� 2-------------------------------------------------------------------------------
//�������� ���������, � ������� ���������� ��� ������������ �������, ���������� �������
//������� �� ��������� ��������� #pragma omp parallel if (�), ���� �������� �������� ����� �����
//������ 1, ������������ ������� �����������, ����� �� �����������.����� ����� ����� ������
//�������� ������ ������ 3, ����� ������ � ������ 1. ������ ������������ �������� ����������
//���������� ����� � ����� ������ ����, ��������� ������ �� �����.��������� � ������������
//������ ���������.
//
//int main() {
//
//    int threads = 3;
//    
//#pragma omp parallel num_threads(threads) if (threads>1)
//    {
//        int thread_num = omp_get_thread_num();
//        int threads_count = omp_get_num_threads();
//        printf("thread number %d, threads: %d\n", thread_num, threads_count);
//       
//    }
//
//    threads = 1;
//#pragma omp parallel num_threads(threads) if (threads>1)
//    {
//        int thread_num = omp_get_thread_num();
//        int threads_count = omp_get_num_threads();
//        printf("thread number %d, threads: %d\n", thread_num, threads_count);
//
//    }
//}

//------------------------------------------------------������� 3-------------------------------------------------------------------------------
//�������� ���������, � ������� �������� � ��������� ��������� �������� �������������
//���������� : a � b, ���������� ��� ������������ �������, ������ � � ������ ����� 2, ������ � �
//������ ����� 4. ��� ������ ������� ���������� a � b �������� �����������, � ������� �������
//private � firstprivate ��������������, ������ ������� ���������� ����� ���� � ���������
//���������� �������� ���������� �� ��� ��������.������ �� ����� �������� ���������� �� ����� �
//������������ �������, ������ ������������ ������� � ����� ������ �� ������������ �������.���
//������ ������� ���������� a �������� �����, ���������� b �������� ����������, � �������
//������� private, ���������� ����� ���� � ��������� ���������� �������� ���������� �� ���
//��������.������ �� ����� �������� ���������� �� ����� � ������������ �������, ������
//������������ ������� � ����� ������ �� ������������ �������

//int main() {
//    int a = 0;
//    int b = 0;
//    printf("1) a=%d b=%d\n", a, b);
//
//    int threads = 4;
//#pragma omp parallel num_threads(threads)  private(a) firstprivate(b)
//    {
//        a = 0;
//        int thread_num = omp_get_thread_num();
//        a += thread_num;
//        b += thread_num;
//        printf("thread number %d, a=%d b=%d\n", thread_num, a, b);
//       
//    }
//    printf("2) a=%d b=%d\n", a, b);
//
//#pragma omp parallel num_threads(threads) shared(a) private(b)
//    {
//        b = 0;
//        int thread_num = omp_get_thread_num();
//        a -= thread_num;
//        b -= thread_num;
//        printf("thread number %d, a=%d b=%d\n", thread_num, a, b);
//
//    }
//    printf("3) a=%d b=%d\n", a, b);
//}

// ------------------------------------------------------������� 4------------------------------------------------------------------------------ -
//�������� ���������, � ������� �������� � ��������� ��������� �������� �������������
//�������� a[10] � b[10], ���������� ������������ �������, ���������� ����� ������ ������ 2,
//�������� ��� ��� �������� ����(����� 0) � ���� � ������� 1. �������� ���� ������ ���������
//����� min �������� ��������� ������� a, ���� � ������� 1 - ����� max �������� ��������� �������
//b.��������� ������ �� �����.

//int main() {
//    int a[10]; // ���������� ������� a
//    int b[10]; // ���������� ������� b
//
//    printf(" a = {");
//    // ���������� ��������� �������� ��� ������� a
//    for (int i = 0; i < 10; ++i) {
//        a[i] = i + 1; // ���������� �������� �������� ������� a
//        printf(" %d", a[i]);
//    }
//    printf(" }\nb = {");
//
//    // ���������� ��������� �������� ��� ������� b
//    for (int i = 0; i < 10; ++i) {
//        b[i] = (i + 1) * 2; // ���������� �������� �������� ������� b
//        printf(" %d", b[i]);
//    }
//    printf(" }\n");
//
//    int max = a[9];
//    int min = b[0];
//
//    int threads = 2;
//#pragma omp parallel num_threads(threads)  
//    {
//        int thread_num = omp_get_thread_num();
//        if (thread_num == 0)
//        {
//            for (int i = 0; i < 10; i++)
//            {
//                if (min > a[i]) {
//                    min = a[i];
//                }
//            }
//        }
//        else if (thread_num == 1)
//        {
//            for (int i = 0; i < 10; i++)
//            {
//                if (max < b[i]) {
//                    max = b[i];
//                }
//            }
//        }
//    }
//    printf("min in a  =% d \nmax in b = %d", min, max);
//}

// ------------------------------------------------------������� 5------------------------------------------------------------------------------ -
//�������� ���������, � ������� �������� � ��������� ��������� �������� ��������� ����������
//������� d[6][8], ��� ������������� �������� ������������ ��������� ��������� �����.���������
//����������� ��������� sections�section, ���������� ��� ������ ��� ���������� ���������
//�������� :
// * ������ ������ ��������� ���������� �������� ��������������� �������� ���������
//���������� �������,
// * ������ ������ ��������� ���������� ������������ � ������������� �������� ���������
//���������� �������,
// * ������ ������ ��������� ���������� ���������� ��������� �������, �������� ��������
//������� ������ 3.
//� ������ ������ ���������� � ������ �� ����� ����� ����������� ���� � ��������� ����������
//����������.

//
//#include <cstdlib> // ��� ������� rand
//#include <ctime>   // ��� ������� time
//
//int main() {
//    // ��������� seed ��� ��������� ��������� �����
//    srand(time(nullptr));
//
//    int d[6][8]; // ���������� ���������� ������� d
//
//    printf("d[6][8]:\n");
//    // ���������� ��������� �������� ��� ��������� ������� d
//    for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            d[i][j] = rand() % 100; // ��������� ���������� ����� �� 0 �� 99
//            std::cout << d[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//
//    int threads = 10;
//
//    int n;
//    double average = 0.0;
//    int min, max;
//    int kol_kratn_3=0;
//#pragma omp parallel num_threads(threads) shared(d) 
//    {
//        n = omp_get_thread_num();
//#pragma omp sections
//        {
// #pragma omp section 
//            {// ���������� �������� ���������������
//                printf("First section, thread_num = %d\n", n);
//                int sum = 0;
//                for (int i = 0; i < 6; ++i) {
//                    for (int j = 0; j < 8; ++j) {
//                        sum += d[i][j];
//                    }
//                }
//
//                average = sum/ (6 * 8);
//                printf("Arithmetic mean = %.2f\n\n", average);
//            }
//#pragma omp section 
//            {//���������� ������������ � �������������
//                printf("Two section, thread_num = %d\n", n);
//                min = d[0][0];
//                max = d[0][0];
//                for (int i = 0; i < 6; ++i) {
//                    for (int j = 0; j < 8; ++j) {
//                        if (max < d[i][j]) max = d[i][j];
//                        if (min > d[i][j])  min = d[i][j];
//                    }
//                }
//                printf("Min = %d; Max = %d\n\n", min, max);
//            }
//#pragma omp section 
//            {//���������� ���������� ��������� �������, �������� �������� ������� ������ 3.
//                printf("Three section, thread_num = %d\n", n);
//                for (int i = 0; i < 6; ++i) {
//                    for (int j = 0; j < 8; ++j) {
//                        if  (d[i][j]%3==0) kol_kratn_3++;
//                    }
//                }
//                printf("The number of elements is a multiple of 3 = %d\n\n", kol_kratn_3);
//            }
//        }
//    }
 /*   printf("Arithmetic mean = %.2f\n",average);
    printf("Min = %d; Max = %d\n", min, max);
    printf("The number of elements is a multiple of 3 = %d\n", kol_kratn_3);*/
//}


//--------------------------------------------------����������� ���������� ����� ������������� ����--------------------------------------------------------------

// ------------------------------------------------------������� 6-----------------------------------------------------------------------------------------------
//�������� ���������, � ������� �������� � ��������� ��������� �������� �������������
//�������� a[10] � b[10].��������� ����������� parallel for � reduction, ��������� �������
//�������������� �������� ��������� �������� a � b, �������� ���������� ��������, ���������
//������ �� �����.
//
//int main(int argc, char* argv[])
//{
//    const int N = 10;
//    int a[N], b[N], i, n;
//    double average_a = 0;
//    double average_b = 0;
//  
//     printf("a = {");
//     for (int i = 0; i < N; ++i) {
//         a[i] = i; // ���������� �������� �������� ������� a
//         printf(" %d", a[i]);
//     }
//     printf(" }\nb = {");
//
//    // ���������� ��������� �������� ��� ������� b
//     for (int i = 0; i < N; ++i) {
//         b[i] = 2 * i; // ���������� �������� �������� ������� b
//         printf(" %d", b[i]);
//     }
//     printf(" }\n");
//
//
//     int threads = 4;
//
//#pragma omp parallel num_threads(threads) shared(a, b, average_a, average_b) private(i, n) 
//    {
//        /* ������� ����� ������� ���� */
//        n = omp_get_thread_num();
//#pragma omp for reduction(+:average_a,average_b)
//        for (i = 0; i < N; i++)
//        {
//            average_a += a[i];
//            average_b += b[i];
//            printf("Thread %d added elements with number %d\n",n, i);
//        }
//    }
//     average_a = average_a / N;
//     average_b = average_b / N;
//     printf("Arithmetic mean of a = %.2f\n", average_a);
//     printf("Arithmetic mean of b = %.2f", average_b);
//}

// ------------------------------------------------------������� 7-----------------------------------------------------------------------------------------------
//�������� ���������, � ������� ���������� ��� ������������ �������, ������ �� �������
//�������� ������������ ����������� for ����������� ������������� ��������� ����������
//�������� ����� ����� a[12], b[12] � c[12].����� ����� ����� ������ �������� ������ ������ 3,
//����� ������ � ������ 4. ������ ������������ ������� ��������� ������������� ���������
//�������� a � b � �������������� ������������ ������������� ��������, ������ ������ ��������
//������� ��������������, ������ ������������ ������� ��������� ������������� ��������� �������
//c �� ���������� ������� c[i] = a[i] + b[i], � �������������� ������������� �������������
//��������, ������ ������ �������� ������� ��������������.� ������ ������� ���������� � ������
//�� ����� ���������� �����, ����� ����, ����� ��������, ������� ��� ���������, � ���������
//���������� �����.��������� � ������������ ������ ���������.

//int main(int argc, char* argv[])
//{
//    const int N = 12;
//    int a[N], b[N],c[N], i;
//
//    int threads = 3;
//#pragma omp parallel num_threads(threads)
//    {
//        /* ������� ����� ������� ���� */
//        printf("Current thread = %d Threads count = %d\n", omp_get_thread_num(), omp_get_num_threads());
//
//#pragma omp for schedule(static, 4)
//        for (int i = 0; i < 12; i++) {
//            a[i] = rand();
//            printf("a[%d] = %d\n", i, a[i]);
//            b[i] = rand();
//            printf("b[%d] = %d\n", i, b[i]);
//        }
//    }
//
//    printf("\nTwo Parallel\n\n");
//    threads = 4;
//#pragma omp parallel num_threads(threads)
//    {
//        /* ������� ����� ������� ���� */
//        printf("Current thread = %d Threads count = %d\n", omp_get_thread_num(), omp_get_num_threads());
//
//#pragma omp for schedule(dynamic, 3)
//        for (int i = 0; i < 12; i++) {
//            c[i] = a[i] + b[i];
//            printf("c[%d] = %d\n", i, b[i]);
//        }
//    }
//}

// ------------------------------------------------------������� 8-----------------------------------------------------------------------------------------------
//��������� ����������� OpenMP, �������� ��������� ��������� ������� �� ������.������ ���
//������� � �������� �������� �����������.�������� ��������� ���������� ���������������� �
//������������ ��������.�������� ����� ������ ���������������� � ������������ ��������.

//int main() {
//
//    int m = 10000;
//    int n = 10000;
//
//    // ��������� ������ ��� �������
//    int** matrix = new int* [m];
//    for (int i = 0; i < m; ++i) {
//        matrix[i] = new int[n];
//    }
//
//    //�������� �������
//    printf(" matrix = {");
//    for (int i = 0; i < m; ++i) {
//      /*  printf("\n");*/
//        for (int j = 0; j < n; ++j) {
//            matrix[i][j] = rand() % 10 + 1;
//           /* printf("%d ", matrix[i][j]);*/
//        }
//        
//    }
//    printf("} \nvector = {");
//    // ������ ��� ���������
//    int* vector = new int[n];
//    for (int i = 0; i < n; ++i) {
//        vector[i] = rand() % 10 + 1;
//        /*printf("%d ", vector[i]);*/
//    }
//
//    double start = omp_get_wtime();
//    // ��������� ������� �� ������
//    int* result = new int[m];
//    for (int i = 0; i < m; ++i) {
//        result[i] = 0;
//        for (int j = 0; j < n; ++j) {
//            result[i] += matrix[i][j] * vector[j];
//        }
//    }
//    double end = omp_get_wtime();
//    printf("}\nTime posled %f", end - start);
//
//    //printf("\nresult = {");
//    //for (int i = 0; i < m; ++i) {
//    //    printf("%d ", result[i]);
//    //}
//    //printf("}");
//
//
//   /* int threads = omp_get_max_threads();
//    omp_set_num_threads(threads);*/
//    //int threads = 20;
//    int* result2 = new int[m];
//    start = omp_get_wtime();
////#pragma omp for schedule(dynamic, 50)
//#pragma omp parallel for  
//        for (int i = 0; i < m; ++i) {
//            result2[i] = 0;
//            for (int j = 0; j < n; ++j) {
//                result2[i] += matrix[i][j] * vector[j];
//            }
//        }
//    end = omp_get_wtime();
//    printf("\nTime parallel %f\n", end - start);
//    printf("result = {");
//    //for (int i = 0; i < m; ++i) {
//    //    printf("%d ", result2[i]);
//    //}
//    //printf("}");
//
//    // ������������ ������
//    for (int i = 0; i < m; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    delete[] vector;
//    delete[] result;
//
//    return 0;
//}

//------------------------------------------------------�������� ������������� �����--------------------------------------------------------------------------

// ------------------------------------------------------������� 9-----------------------------------------------------------------------------------------------
//�������� ���������, � ������� �������� � ��������� ��������� �������� ��������� ����������
//������� d[6][8], ��� ������������� �������� ������������ ��������� ��������� �����.���������
//����������� �������� omp parallel for � omp critical, ���������� ����������� � ������������
//�������� ��������� ���������� �������.���������� ����� ������ ��������������.��������� ������
//�� �����.

//
//#include <cstdlib> // ��� ������� rand
//#include <ctime>   // ��� ������� time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // ��������� seed ��� ��������� ��������� �����
//    srand(time(nullptr));
//
//    int d[6][8]; // ���������� ���������� ������� d
//
//    printf("d[6][8]:\n");
//    // ���������� ��������� �������� ��� ��������� ������� d
//    for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            d[i][j] = rand() % 100; // ��������� ���������� ����� �� 0 �� 99
//            std::cout << d[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//
//    int threads = 6;
//
//    int n;
//    int min_d = d[0][0];
//    int max_d = d[0][0];
//
//
//#pragma omp parallel num_threads(threads)
//    {
//        n = omp_get_thread_num();
//       //printf("thread_num = %d\n", n);
//        //���������� ������������ � �������������
// 
//        int min = d[0][0];
//        int max = d[0][0];
//#pragma omp parallel for 
//        for (int i = 0; i < 6; ++i) {
//            for (int j = 0; j < 8; ++j) {
//                if (max < d[i][j]) max = d[i][j];{}
//                if (min > d[i][j])  min = d[i][j];
//            }
//        }
//#pragma omp critical 
//        {
//            if (min_d > min) {
//                min_d = min;
//           // printf("min ���� %d\n", n);
//            }
//            if (max_d < max) {
//                max_d = max;
//                //printf("max ���� %d\n\n", n);
//            }
//            
//        }
//        /*printf("Min = %d; Max = %d\n\n", min, max);*/
//   
//    }
//
//    printf("Min = %d; Max = %d\n", min_d, max_d);
//}


// ------------------------------------------------------������� 10-----------------------------------------------------------------------------------------------
//�������� ���������, � ������� �������� � ��������� ��������� �������� ������� ����� �����
//a[30], ��� ������������� �������� ������������ ��������� ��������� �����.���������
//����������� omp parallel for � omp atomic, ��������� ���������� ��������� �������, ��������
//�������� ������� ������ 9. ���������� ����� ������ ��������������.��������� ������ �� �����.

//#include <cstdlib> // ��� ������� rand
//#include <ctime>   // ��� ������� time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // ��������� seed ��� ��������� ��������� �����
//    srand(time(nullptr));
//
//    int a[30];
//
//    printf("a[30]:\n");
//    // ���������� ��������� �������� ��� ��������� ������� a
//    for (int i = 0; i < 30; ++i) {
//        a[i] = rand() % 100; // ��������� ���������� ����� �� 0 �� 99
//        std::cout << a[i] << " ";
//    }
//    std::cout << std::endl;
//
//    int threads = 3;
//
//    int n;
//    int kol_kratn_9 = 0;
//
//    omp_set_num_threads(10);
//
//#pragma omp parallel for schedule(static, 3)
//        for (int i = 0; i < 30; ++i) {
//            if (a[i] % 9 == 0) {
//#pragma omp atomic
//                kol_kratn_9++;
//                printf("%d\n", a[i]);
//            }
//        }
//  
//    printf("���������� ��������� �������, �������� �������� ������� ������ 9 ����� %d\n", kol_kratn_9);
//}


// ------------------------------------------------------������� 11-----------------------------------------------------------------------------------------------
//�������� ���������, � �������, �������� � ��������� ���������� ���������� ������ �����
//�����.��������� ����������� OpenMP, ����� ������������ �������� �������� ��������� �������,
//������� 7. ����� ������� � ���������� ������� ���������� ��������������.��������� ������ ��
//�����.��� ������������� �������� �������� ��������� ������������ �������� �����������
//������

//#include <cstdlib> // ��� ������� rand
//#include <ctime>   // ��� ������� time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // ��������� seed ��� ��������� ��������� �����
//    srand(time(nullptr));
//    int const n = 50;
//    int a[n]; // ���������� �������
//
//    printf("Array a:\n");
//    // ���������� ��������� ��������
//    for (int i = 0; i < n; ++i) {
//        a[i] = rand() % 100; // ��������� ���������� ����� �� 0 �� 99
//        std::cout << a[i] << " ";
//    }
//    std::cout << std::endl;
//
//    int threads = 10;
//
//    int nit;
//    int max_kratn_7 = a[0];
//
//
//#pragma omp parallel num_threads(threads)
//    {
//        nit = omp_get_thread_num();
//       //printf("thread_num = %d\n", n)
//     
//        int max = a[0];
//#pragma omp parallel for 
//        for (int i = 0; i < n; ++i) {
//            if (a[i] % 7 == 0 && max < a[i]) max = a[i];
//        }
//#pragma omp critical 
//        {
//            if (max_kratn_7 < max) {
//                max_kratn_7 = max;
//                //printf("max ���� %d\n\n", n);
//            }
//            
//        }
//    }
//
//    printf("������������ �������� �������� ��������� �������, ������� 7 ����� %d\n", max_kratn_7);
//}


//------------------------------------------------------������� 12-------------------------------------------------------------------------------
//������������� ������ 1 ���, ��� �� ������ ������������� ���� �������������� � ��������
//�������.���������� ��� ������� 5 �������� �������.������������ ����� ��� ����� ������.
#include <windows.h> 
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    int const n = 8;
//    omp_set_num_threads(n);
////    printf("������ ����� ����� CRITICAL\n");
////    /*#pragma omp parallel num_threads(8)*/
////    int number = n-1;
////#pragma omp parallel 
////    {
////        int thread_num = omp_get_thread_num();
////        int threads_count = omp_get_num_threads();
////        while (number>-1) {
////#pragma omp barrier
////            if (number == thread_num) {
////#pragma omp critical
////                {
////                    int thread_num = omp_get_thread_num();
////                    printf("Hello world, thread number %d, threads: %d\n", thread_num, threads_count);
////                    number=number-1;
////                }
////             }
////        }
////        
////    }
////
////    printf("������ ����� ����� ORDERED\n");
////    int i, threads_count;
////	int array_thread[n];
////#pragma omp parallel shared(array_thread) private(threads_count,i) 
////	{
////        threads_count = omp_get_num_threads();
////#pragma omp for
////		for (i = 0; i < threads_count; i++) {
////			array_thread[i] = omp_get_thread_num();
////		}
////#pragma omp for ordered
////		for (i = threads_count - 1; i >= 0; i--) {
////#pragma omp ordered
////			{
////				printf("Hello world, thread number %d, threads: %d\n", array_thread[i], threads_count);
////			}
////		}
////	}
////
//}


//#include <iostream>
//#include <windows.h> 
//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    int n=8;
//    omp_set_num_threads(n);
//    int i = n - 1;
//#pragma omp parallel 
//    {
//        int thread_num = omp_get_thread_num();
//        while (i!= thread_num)
//        {
//        }
//        printf("�����, ���� %d\n", thread_num);
//        i--;
//    }
//}

//------------------------------------------------------������������ ��������� � ���������--------------------------------------------------------------------------

// ------------------------------------------------------������� 13-----------------------------------------------------------------------------------------------
//�� ������� �������� ����� ������ ����� �����, ������� �������� �������� �������������� ����������� �����.
//�������� ������������ ��������� ���������� ����������� ����� �� ���������
//��������� �������������.
//int a[30] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
//����� x ����� ���� ������������ � ������� � ���������� p, ��� x = a0 * p^(n) + a1 * p^(n - 1)+ a(n - 1) * p^1+ an * p^0, ��� a0
//... an - ����� � ������������� ������� �����

//
//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    omp_set_num_threads(8);
//    const int n = 30;
//    int a[n] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
//    double x, sum;
//    int p = 2; //���������
//    int i;
//    sum = 0;
//#pragma omp parallel for private(x) reduction(+:sum)
//    for (i = 0; i < n; i++)
//    {
//        x = a[i] * pow(p, n - i-1);
//        sum = sum + x;
//    }
//    printf("����� = %f\n", sum);
//}

// ------------------------------------------------------������� 14-----------------------------------------------------------------------------------------------
//�������� ������������ ��������� ���������� ����� 210 � ������� ��� �������� ���������.
//���������: ������� ������������ ����� N ����� ����� ������ N �������� �����.��������, 3^2= 9
//��� 1 + 3 + 5 = 9; 5^2 = 25 ��� 1 + 3 + 5 + 7 + 9 = 25;

//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    omp_set_num_threads(8);
//
//    int a = 210;
//    int sum = 0;
//    int i;
//#pragma omp parallel for reduction(+:sum)
//    for (i = 1; i < a+1; i++)
//    {
//        sum = sum + 2*i-1;
//    }
//    printf(" 210^2 = %d\n", sum);
//}

// ------------------------------------------------------������� 15-----------------------------------------------------------------------------------------------
//�������� ���������, � �������, ��������� ����������� OpenMP, ����� ��� ������� ����� � �������� 
//� ���������� ���������.���������� ������� ���������� ��������������.��������� ������ �� �����
//
//#include <vector>
//#include <algorithm>
//
//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    int numThreads = omp_get_max_threads();
//    omp_set_num_threads(numThreads);
//    printf("������������ %d �������.\n", numThreads);
//
//    int start, end;
//    printf("������� ������ ���������: ");
//    std::cin >> start;
//    printf("������� ����� ���������: ");
//    std::cin >> end;
//    
//    if (end < start) {
//        printf("����� ��������� ������ ���� ������ ������.\n");
//        return 1;
//    }
//
//    std::vector<int> primes;
//    bool good = true;
//    int sum = 0;
//    int i;
//    printf("��������� ������� �����:\n");
//#pragma omp parallel for private(good)
//    for (i = start; i <= end; ++i) {
//        good = true;
//        if (i <= 1)  good = false;
//        else {
//            for (int j = 2; j <= sqrt(i); ++j) {
//                if (i % j == 0) {
//                    good = false;
//                    break;
//                }
//            }
//
//        }
//        if (good) {
//            //printf("%d\n", i);
//#pragma omp critical
//            primes.push_back(i);
//        }
//    }
//
//    std::sort(primes.begin(), primes.end());
//    for (int prime : primes) {
//        printf("%d\n", prime);
//    }
//
//}