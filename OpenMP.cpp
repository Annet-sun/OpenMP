#include <iostream>
#include <windows.h>
#include<omp.h>
using namespace std;
//--------------------Общие и защищенные переменные. Разграничения доступа к переменным, конструкции разделения работ не итерационного типа--------------------------------------------


//------------------------------------------------------Задание 1-------------------------------------------------------------------------------
//Написать программу где каждый поток печатает свой идентификатор, количество потоков всего и
//строчку «Hello World».Запустить программу с 8 потоками.Всегда ли вывод идентичен ? Почему ?
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

//------------------------------------------------------Задание 2-------------------------------------------------------------------------------
//Написать программу, в которой определить две параллельные области, выполнение которых
//зависит от условного оператора #pragma omp parallel if (…), если заданное значение числа нитей
//больше 1, параллельная область выполняется, иначе не выполняется.Число нитей перед первой
//областью задать равным 3, перед второй – равным 1. Внутри параллельных областей определить
//количество нитей и номер каждой нити, результат выдать на экран.Убедиться в правильности
//работы программы.
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

//------------------------------------------------------Задание 3-------------------------------------------------------------------------------
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//переменным : a и b, определить две параллельные области, первая – с числом нитей 2, вторая – с
//числом нитей 4. Для первой области переменные a и b объявить защищенными, с режимом доступа
//private и firstprivate соответственно, внутри области определить номер нити и выполнить
//увеличение значения переменных на эту величину.Выдать на экран значения переменных до входа в
//параллельную область, внутри параллельной области и после выхода из параллельной области.Для
//второй области переменную a объявить общей, переменную b объявить защищенной, с режимом
//доступа private, определить номер нити и выполнить уменьшение значения переменных на эту
//величину.Выдать на экран значения переменных до входа в параллельную область, внутри
//параллельной области и после выхода из параллельной области

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

// ------------------------------------------------------Задание 4------------------------------------------------------------------------------ -
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//массивам a[10] и b[10], определить параллельную область, количество нитей задать равным 2,
//выделить код для основной нити(номер 0) и нити с номером 1. Основная нить должна выполнять
//поиск min значения элементов массива a, нить с номером 1 - поиск max значения элементов массива
//b.Результат выдать на экран.

//int main() {
//    int a[10]; // объявление массива a
//    int b[10]; // объявление массива b
//
//    printf(" a = {");
//    // Присвоение начальных значений для массива a
//    for (int i = 0; i < 10; ++i) {
//        a[i] = i + 1; // присвоение значения элементу массива a
//        printf(" %d", a[i]);
//    }
//    printf(" }\nb = {");
//
//    // Присвоение начальных значений для массива b
//    for (int i = 0; i < 10; ++i) {
//        b[i] = (i + 1) * 2; // присвоение значения элементу массива b
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

// ------------------------------------------------------Задание 5------------------------------------------------------------------------------ -
//Написать программу, в которой объявить и присвоить начальные значения элементам двумерного
//массива d[6][8], для инициализации значений использовать генератор случайных чисел.Используя
//конструкцию директивы sections…section, определить три секции для выполнения следующих
//операций :
// * первая секция выполняет вычисление среднего арифметического значения элементов
//двумерного массива,
// * вторая секция выполняет вычисление минимального и максимального значений элементов
//двумерного массива,
// * третья секция выполняет вычисление количества элементов массива, числовые значения
//которых кратны 3.
//В каждой секции определить и выдать на экран номер исполняющей нити и результат выполнения
//вычислений.

//
//#include <cstdlib> // Для функции rand
//#include <ctime>   // Для функции time
//
//int main() {
//    // Установка seed для генерации случайных чисел
//    srand(time(nullptr));
//
//    int d[6][8]; // Объявление двумерного массива d
//
//    printf("d[6][8]:\n");
//    // Присвоение начальных значений для элементов массива d
//    for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            d[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
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
//            {// Вычисление среднего арифметического
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
//            {//Вычисление минимального и максимального
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
//            {//Вычисление количества элементов массива, числовые значения которых кратны 3.
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


//--------------------------------------------------Конструкции разделения работ итерационного типа--------------------------------------------------------------

// ------------------------------------------------------Задание 6-----------------------------------------------------------------------------------------------
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//массивам a[10] и b[10].Используя конструкцию parallel for и reduction, вычислить средние
//арифметические значения элементов массивов a и b, сравнить полученные значения, результат
//выдать на экран.
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
//         a[i] = i; // присвоение значения элементу массива a
//         printf(" %d", a[i]);
//     }
//     printf(" }\nb = {");
//
//    // Присвоение начальных значений для массива b
//     for (int i = 0; i < N; ++i) {
//         b[i] = 2 * i; // присвоение значения элементу массива b
//         printf(" %d", b[i]);
//     }
//     printf(" }\n");
//
//
//     int threads = 4;
//
//#pragma omp parallel num_threads(threads) shared(a, b, average_a, average_b) private(i, n) 
//    {
//        /* Получим номер текущей нити */
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

// ------------------------------------------------------Задание 7-----------------------------------------------------------------------------------------------
//Написать программу, в которой определить две параллельные области, каждая из которых
//содержит итерационную конструкцию for выполняющую инициализацию элементов одномерных
//массивов целых чисел a[12], b[12] и c[12].Число нитей перед первой областью задать равным 3,
//перед второй – равным 4. Первая параллельная область выполняет инициализацию элементов
//массивов a и b с использованием статического распределения итераций, размер порции итераций
//выбрать самостоятельно, вторая параллельная область выполняет инициализацию элементов массива
//c по следующему правилу c[i] = a[i] + b[i], с использованием динамического распределения
//итераций, размер порции итераций выбрать самостоятельно.В каждой области определить и выдать
//на экран количество нитей, номер нити, номер итерации, которые она выполняет, и результат
//выполнения цикла.Убедиться в правильности работы программы.

//int main(int argc, char* argv[])
//{
//    const int N = 12;
//    int a[N], b[N],c[N], i;
//
//    int threads = 3;
//#pragma omp parallel num_threads(threads)
//    {
//        /* Получим номер текущей нити */
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
//        /* Получим номер текущей нити */
//        printf("Current thread = %d Threads count = %d\n", omp_get_thread_num(), omp_get_num_threads());
//
//#pragma omp for schedule(dynamic, 3)
//        for (int i = 0; i < 12; i++) {
//            c[i] = a[i] + b[i];
//            printf("c[%d] = %d\n", i, b[i]);
//        }
//    }
//}

// ------------------------------------------------------Задание 8-----------------------------------------------------------------------------------------------
//Используя возможности OpenMP, написать программу умножения матрицы на вектор.Память для
//матрицы и векторов выделять динамически.Сравнить результат выполнения последовательной и
//параллельной программ.Сравнить время работы последовательной и параллельных программ.

//int main() {
//
//    int m = 10000;
//    int n = 10000;
//
//    // Выделение памяти под матрицу
//    int** matrix = new int* [m];
//    for (int i = 0; i < m; ++i) {
//        matrix[i] = new int[n];
//    }
//
//    //элементы матрицы
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
//    // вектор для умножения
//    int* vector = new int[n];
//    for (int i = 0; i < n; ++i) {
//        vector[i] = rand() % 10 + 1;
//        /*printf("%d ", vector[i]);*/
//    }
//
//    double start = omp_get_wtime();
//    // Умножение матрицы на вектор
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
//    // Освобождение памяти
//    for (int i = 0; i < m; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    delete[] vector;
//    delete[] result;
//
//    return 0;
//}

//------------------------------------------------------Операции синхронизации работ--------------------------------------------------------------------------

// ------------------------------------------------------Задание 9-----------------------------------------------------------------------------------------------
//Написать программу, в которой объявить и присвоить начальные значения элементам двумерного
//массива d[6][8], для инициализации значений использовать генератор случайных чисел.Используя
//конструкцию директив omp parallel for и omp critical, определить минимальное и максимальное
//значения элементов двумерного массива.Количество нитей задать самостоятельно.Результат выдать
//на экран.

//
//#include <cstdlib> // Для функции rand
//#include <ctime>   // Для функции time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // Установка seed для генерации случайных чисел
//    srand(time(nullptr));
//
//    int d[6][8]; // Объявление двумерного массива d
//
//    printf("d[6][8]:\n");
//    // Присвоение начальных значений для элементов массива d
//    for (int i = 0; i < 6; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            d[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
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
//        //Вычисление минимального и максимального
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
//           // printf("min Нить %d\n", n);
//            }
//            if (max_d < max) {
//                max_d = max;
//                //printf("max Нить %d\n\n", n);
//            }
//            
//        }
//        /*printf("Min = %d; Max = %d\n\n", min, max);*/
//   
//    }
//
//    printf("Min = %d; Max = %d\n", min_d, max_d);
//}


// ------------------------------------------------------Задание 10-----------------------------------------------------------------------------------------------
//Написать программу, в которой объявить и присвоить начальные значения массиву целых чисел
//a[30], для инициализации значений использовать генератор случайных чисел.Используя
//конструкции omp parallel for и omp atomic, вычислить количество элементов массива, числовые
//значения которых кратны 9. Количество нитей задать самостоятельно.Результат выдать на экран.

//#include <cstdlib> // Для функции rand
//#include <ctime>   // Для функции time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // Установка seed для генерации случайных чисел
//    srand(time(nullptr));
//
//    int a[30];
//
//    printf("a[30]:\n");
//    // Присвоение начальных значений для элементов массива a
//    for (int i = 0; i < 30; ++i) {
//        a[i] = rand() % 100; // Генерация случайного числа от 0 до 99
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
//    printf("Количество элементов массива, числовые значения которых кратны 9 равно %d\n", kol_kratn_9);
//}


// ------------------------------------------------------Задание 11-----------------------------------------------------------------------------------------------
//Написать программу, в которой, объявить и заполнить случайными значениями массив целых
//чисел.Используя возможности OpenMP, найти максимальное числовое значение элементов массива,
//кратное 7. Длину массива и количество потоков определить самостоятельно.Результат выдать на
//экран.Для синхронизации числовых значений максимума используется механизм критических
//секций

//#include <cstdlib> // Для функции rand
//#include <ctime>   // Для функции time
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    // Установка seed для генерации случайных чисел
//    srand(time(nullptr));
//    int const n = 50;
//    int a[n]; // Объявление массива
//
//    printf("Array a:\n");
//    // Присвоение начальных значений
//    for (int i = 0; i < n; ++i) {
//        a[i] = rand() % 100; // Генерация случайного числа от 0 до 99
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
//                //printf("max Нить %d\n\n", n);
//            }
//            
//        }
//    }
//
//    printf("Максимальное числовое значение элементов массива, кратное 7 равно %d\n", max_kratn_7);
//}


//------------------------------------------------------Задание 12-------------------------------------------------------------------------------
//Модифицируйте задачу 1 так, что бы потоки распечатывали свои идентификаторы в обратном
//порядке.Существует как минимум 5 способов решения.Постарайтесь найти как можно больше.
#include <windows.h> 
//
//int main() {
//    setlocale(LC_ALL, "rus");
//
//    int const n = 8;
//    omp_set_num_threads(n);
////    printf("Первый метод через CRITICAL\n");
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
////    printf("Второй метод через ORDERED\n");
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
//        printf("Урааа, нить %d\n", thread_num);
//        i--;
//    }
//}

//------------------------------------------------------Произвольные директивы и алгоритмы--------------------------------------------------------------------------

// ------------------------------------------------------Задание 13-----------------------------------------------------------------------------------------------
//На нулевом процессе задан массив целых чисел, который является двоичным представлением десятичного числа.
//Написать параллельную программу вычисления десятичного числа из заданного
//двоичного представления.
//int a[30] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
//Число x может быть представлено в системе с основанием p, как x = a0 * p^(n) + a1 * p^(n - 1)+ a(n - 1) * p^1+ an * p^0, где a0
//... an - цифры в представлении данного числа

//
//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    omp_set_num_threads(8);
//    const int n = 30;
//    int a[n] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
//    double x, sum;
//    int p = 2; //основание
//    int i;
//    sum = 0;
//#pragma omp parallel for private(x) reduction(+:sum)
//    for (i = 0; i < n; i++)
//    {
//        x = a[i] * pow(p, n - i-1);
//        sum = sum + x;
//    }
//    printf("Число = %f\n", sum);
//}

// ------------------------------------------------------Задание 14-----------------------------------------------------------------------------------------------
//Написать параллельную программу возведения числа 210 в квадрат без операции умножения.
//Пояснение: Квадрат натурального числа N равен сумме первых N нечетных чисел.Например, 3^2= 9
//это 1 + 3 + 5 = 9; 5^2 = 25 это 1 + 3 + 5 + 7 + 9 = 25;

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

// ------------------------------------------------------Задание 15-----------------------------------------------------------------------------------------------
//Написать программу, в которой, используя возможности OpenMP, найти все простые числа в заданном 
//с клавиатуры диапазоне.Количество потоков определить самостоятельно.Результат выдать на экран
//
//#include <vector>
//#include <algorithm>
//
//int main(int argc, char* argv[])
//{
//    setlocale(LC_ALL, "rus");
//    int numThreads = omp_get_max_threads();
//    omp_set_num_threads(numThreads);
//    printf("Используется %d потоков.\n", numThreads);
//
//    int start, end;
//    printf("Введите начало диапазона: ");
//    std::cin >> start;
//    printf("Введите конец диапазона: ");
//    std::cin >> end;
//    
//    if (end < start) {
//        printf("Конец диапазона должен быть больше начала.\n");
//        return 1;
//    }
//
//    std::vector<int> primes;
//    bool good = true;
//    int sum = 0;
//    int i;
//    printf("Найденные прослые числа:\n");
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