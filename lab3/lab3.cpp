/**
 * Практическое занятие №3. Встроенные массивы. Динамическое выделение памяти.
 * Простейшие алгоритмы сортировки и поиска. Сложные указатели.
 */

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iomanip> //Для setw
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <libintl.h>
#include <string>

using namespace std;

int main()
{
    /**
     * Задание 1. Встроенные массивы.
     */

    /**
     * Задание 1.1.
     *
     * Объявите трехмерный N*M*K массив и сформируйте значения
     * элементов, указанные на иллюстрации ниже, с помощью инициализации при
     * объявлении.
     *
     *                   |--------|     
     *                 / |3  3  3 |     
     *               |---------|3 |
     *             / | 2  2  2 |3 |
     *            |---------|2 |__|
     *            | 1  1  1 |2 | /
     *            | 1  1  1 |__| 
     *            | 1  1  1 | /
     *            |_________|
     */
    const int N = 3;
    const int M = 3;
    const int K = 3;

    int array1[N][M][K] = {
        {
            {1, 1, 1}, {1, 1, 1}, {1, 1, 1}
        },
        {
            {2, 2, 2}, {2, 2, 2}, {2, 2, 2}
        },
        {
            {3, 3, 3}, {3, 3, 2}, {3, 3, 3}
        }
    };

    /**
     * Задание 1.2.
     *
     * Объявите неинициализированный массив и присвойте значения элементам с
     * помощью кода так, чтобы в итоге получился такой же массив, как в задании
     * 1.1.
     */
    {
        int progArray[N][M][K];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < K; k++) {
                    progArray[i][j][k] = i + 1;
                    // cout << setw(4) << progArray[i][j][k];
                }
                // cout << endl;
            }
            // cout << endl;
        }
    }
    /**
     * Задание 1.3.
     *
     * Напишите код, с помощью которого можно найти сумму элементов массива,
     * полученного в задании 1.
     */

    {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < K; k++) {
                    sum += array1[i][j][k];
                }
            }
        }

        // cout << sum << endl;
    }

    /**
     * Задание 1.4.
     *
     * Проинициализируйте массив при объявлении следующим образом:
     *
     *                   |--------|     
     *                 / |3  0  0 |     
     *               |---------|0 |
     *             / | 2  0  0 |0 |
     *            |---------|0 |__|
     *            | 1  0  0 |0 | /
     *            | 0  0  0 |__| 
     *            | 0  0  0 | /
     *            |_________|
     *
     * Как это можно сделать наиболее коротким (в смысле количества кода)
     * образом?
     */
    {
        int array[M][N][K] = {{{1}}, {{2}}, {{3}}};
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         for (int k = 0; k < K; k++) {
        //             cout << setw(4) << array[i][j][k];
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

    }
    /**
     * Задание 1.5. Инициализация массивов строковыми литералами.
     * 
     * Объявите и проинициализируйте строковыми литералами два массива:
     * двухмерный массив и массив указателей. Поясните разницу в использовании
     * элементов таких массивов.
     */

    char charArr[3][2] = {{'a', 'b'}, {'a', 'b'}, {'a', 'b'}};
    

    /**
     * Задание 2. Динамическое выделение памяти.
     */

    /**
     * Задание 2.1.
     *
     * Создайте динамический двухмерный массив с размерностями, вычисляемыми в
     * процессе выполнения программы - N*M, эти размерности можно сформировать
     * случайно в некотором диапазоне или ввести с консоли.
     *
     * Задайте значения элементов помощью генератора случайных чисел. 
     *
     * Найдите сумму элементов.
     *
     * Подсказка 1: для генерации случайных чисел используйте функцию
     * стандартной библиотеки - rand() (<cstdlib>).
     *
     * Подсказка 2: На самом деле те значения, которые создаются генератором
     * случайных чисел являются «псевдослучайными», то есть при двух
     * последовательных запусках приложения Вы получаете две одинаковые
     * последовательности значений.
     *
     * Для того чтобы генерируемые "случайные" значения были разными при каждом
     * запуске приложения используйте функции стандартной библиотеки srand()
     * (<cstdlib>) и time() (<ctime>).
     *
     * Функция srand() осуществляет «привязку» начала генерации к указанному в
     * качестве параметра значению.
     *
     * Функция time() задает эту точку отсчета, считывая текущее время.
     */

    {
        srand(time(NULL));

        int N = rand() % 10 + 1;
        int M = rand() % 10 + 1;

        // Выделение памяти под динамический массив
        int** nums{new int* [N]{}};

        //Выделение памяти под строку динамического массива
        for (int i = 0; i < N; i++) {
            nums[i] = new int[M]{};
        }

        int sum = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                nums[i][j] = rand() % 10;
                sum += nums[i][j];
                // cout << setw(4) << nums[i][j];
            }
            // cout << endl;
        }

        // cout << sum << endl;
        // cout << endl;

        /**
         * Задание 2.2.
         *
         * В сформированном массиве отсортируйте каждую строку по убыванию
         * значений. Используйте сортировку "выбором".
         */

        for (int i = 0; i < N; i++) {
            int min = 0;
            int buf = 0;

            for (int j = 0; j < M; j++) {
                min = j;
                for (int k = j + 1; k < M; k++) min = (nums[i][k] < nums[i][min]) ? k : min;

                if (j != min) swap(nums[i][j], nums[i][min]);
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << setw(4) << nums[i][j];
        //     }
        //     cout << endl;
        // }

        /**
         * Задание 2.3.
         *
         * Объявите одномерный массив размерностью N. 
         *
         * Сформируйте значение i-ого элемента одномерного массива  равным среднему
         * значению элементов i-ой строки двухмерного массива.
         */


        double* arr = new double[N];

        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += nums[i][j];
            }
            arr[i] = sum/static_cast<double>(N);
        }

        // for (int i = 0; i < N; i++) {
        //     cout << ' ' << arr[i];
        // }
        // cout << endl;

        for (int i = 0; i < N; i++) {
            delete[] nums[i];
            nums[i] = nullptr;
        }

        delete[] nums;
        nums = nullptr;

        delete[] arr;
        arr = nullptr;
    }



    /**
     * Задание 2.4. 
     *
     * Убедитесь, что вся выделенная память очищена.
     *
     * Чтобы убедиться в этом, скомпилируйте программу с включенной проверкой
     * утечек памяти - с ключом `-fsanitize=address`:
     *
     * `gcc <ваши обычные флаги> -fsanitize=address lab3.cpp`
     *
     * Если после выполнении программы выдаются сообщения об утечках, это
     * означает, что где-то не удалена выделенная память.
     */

    /**
     * Задание 3.
     */

    /**
     * Задание 3.1. Онлайн-упорядочивание.
     *
     * Напишите фрагмент кода, который вводит N целых чисел с помощью потока
     * ввода в объявленный Вами встроенный одномерный массив, каждый раз
     * упорядочивая полученное значение по возрастанию.
     *
     * Дайте оценку количества сравнений и перестановок при вводе всех чисел
     * относительно N.
     *
     * Постарайтесь, чтобы и сравнений, и перестановок было не больше, чем
     * k*N^2, где k - некоторое число.
     */

    {
        // int N = min(rand() % 10 + 4, 7);
        // int* arr = new int[N]{};

        // for (int i = 0; i < N; i++) {
        //     cin >> arr[i];

        //     int* arrSort = new int[N]; 

        //     for (int j = 0; j < N; j++) arrSort[j] = arr[j];

        //     int min = 0;

        //     for (int j = 0; j < N; j++) {
        //         min = j;
        //         for (int k = j + 1; k < N; k++) min = (arrSort[k] < arrSort[min]) ? k : min;

        //         if (j != min) swap(arrSort[j], arrSort[min]);
        //     }

        //     for (int j = 0; j < N; j++) {
        //         cout << ' ' << arrSort[j];
        //     }
        //     cout << endl;

        //     delete[] arrSort;
        //     arrSort = nullptr;
        // }

        // delete[] arr;
        // arr = nullptr;
    }

    /**
     * Задание 3.2. Простой поиск.
     *
     * Модифицируйте предыдущее задание следующим образом:очередное значение
     * вводится в массив только при условии, что там еще такого нет (то есть
     * дубли игнорируются).
     */

    {
        // int N = min(rand() % 10 + 4, 7);
        // int* arr = new int[N];

        // for (int j = 0; j < N; j++) arr[j] = 0; 

        // for (int i = 0; i < N; i++) {
        //     int value;
        //     cin >> value;
        //     bool isUnic = true;
        //     for (int j = 0; j < N; j++) {
        //         if (arr[j] == value) {
        //             isUnic = false;
        //             break;
        //         }
        //     } 
        //     arr[i] = isUnic ? value : 0;
        //     if (!isUnic) i--;

        //     int** arrSort = new int*[N]; 

        //     for (int j = 0; j < N; j++) arrSort[j] = &arr[j];

        //     int min = 0;
        //     int buf = 0;

        //     for (int j = 0; j < N; j++) {
        //         min = j;
        //         for (int k = j + 1; k < N; k++) min = (*arrSort[k] < *arrSort[min]) ? k : min;

        //         if (j != min) swap(arrSort[j], arrSort[min]);
        //     }

        //     for (int j = 0; j < N; j++) {
        //         cout << ' ' << *arrSort[j];
        //     }
        //     cout << endl;

        //     delete[] arrSort;
        //     arrSort = nullptr;
        // }

        // delete[] arr;
        // arr = nullptr;
    }
     
    /**
     * Задание 4. Сортировка строк.
     *
     * С помощью данной заготовки напишите программу, которая:
     *
     * 1. вводит строки с клавиатуры с помощью cin>>... в объявленный Вами
     *    двухмерный встроенный массив 5*80 элементов типа char; признаком конца
     *    ввода является символ * (то есть строка - "*") или заполнение массива
     *    (больше свободных строк нет);
     * 2. сортирует строки в алфовитном порядке и выводит на экран.
     *
     * Пояснение: крайне не рекомендуется для сортировки сложных объектов
     * физически перемещать их в памяти. Намного эффективнее завести массив
     * указателей на соответствующие строки и перемещать только указатели.
     *
     * Подсказка: для лексиграфического сравнения строк пользуйтесь функцией
     * стандартной библиотеки strcmp(...), заголовочный файл <cstring>.
     */

    // {
    //     /** Определите необходимые значения как константы */

    //     const char STOP_STRING = '*';  //признак "прекратить ввод"
    //     const int M = 80; //максимальный размер одной строки
    //     const int N = 10; //максимальное количество строк в массиве

    //     /** 
    //      * Объявите двухмерный массив с именем cBuffer типа char и размерностью
    //      * N*M.
    //      */

    //     char cBuffer[N][M] = {}; 

    //     /**
    //      * Объявите массив (с именем cPointers) указателей на строки
    //      * размерностью N.
    //      */

    //     char* cPointers[N];

    //     /** 
    //      * Цикл ввода строк:
    //      * 1. выведите приглашение для ввода; 
    //      * 2. пока не введена строка STOP_STRING или не заполнен весь массив; 
    //      */

    //     int strIndex = N - 1;

    //     for (int nIndex = 0; nIndex < N; nIndex++) {
    //         /** ввод строки в массив cBuffer: */
    //         cin >> cBuffer[nIndex];
                                    
    //         /** если введена строка - признак окончания, то выйти из цикла */

    //         if (cBuffer[nIndex][0] == STOP_STRING) {
    //             strIndex = nIndex - 1;
    //             break;
    //         }

    //         /** Присвойте элементу массива cPointers с индексом nIndex */
    //         cPointers[nIndex] = cBuffer[nIndex]; 
            

    //         /** указатель на строку с номером nIndex в массиве cBuffer */

    //     }


    //     /** Выдать диагностику о том, что прием строк завершен.*/

    //     cout << "Lines addition ended!" << endl;

    //     /**
    //      * Теперь сортируем строки.
    //      *
    //      * Необходимо использовать сортировку строк по методу "всплывающего
    //      * пузырька" в порядке возрастания. 
    //      *
    //      * На каждой итерации - промежуточная печать отсортированных строк.
    //      */

    //     for (int i = 0; i < strIndex; i++) {
    //         for (int j = 0; j < strIndex; j++) {
    //             if (strcmp(cPointers[j], cPointers[j+1]) > 0) {
    //                 swap(cPointers[j], cPointers[j+1]);
    //             }
    //         }
    //         for (int k = 0; k < strIndex + 1; k++) {
    //             for (int s = 0; s < M; s++) {
    //                 cout << *(cPointers[k] + s);
    //             }
    //             cout << endl;
    //         }
    //         cout << endl;
    //     }

    // }

/*
    /**
     * Задание 5. Динамические строки.
     *
     * Реализуйте задание №4, используя не встроенные, а динамические массивы
     * (массив?). Так как строки могут быть разной длины, эффективным решением
     * было бы отводить под каждую строку ровно столько байтов, сколько
     * требуется для ее хранения.
     *
     * Реализуйте это задание так, чтобы пользователь мог ввести строку любой
     * длины (которая помещается в память компьютера - читайте: неограниченной
     * длины).
     *
     * При этом необходимые параметры (количество строк) сформируйте с помощью
     * потока ввода.
     */

    {
        // int nStringNumber;
        // cin >> nStringNumber;

        // const char STOP_STRING = '*';

        // char** buffer = { new char*[nStringNumber]{} };
        // char** pointers = new char*[nStringNumber];
        // int* sizes = new int[nStringNumber];

        // int strIndex = nStringNumber - 1;
        // int maxSize = 0;


        // /** Цикл ввода строк: */

        // for (int nIndex = 0; nIndex < nStringNumber; nIndex++) {

        //     string str;
        //     cin >> str;

        //     int size = str.size();
        //     sizes[nIndex] = size;

        //     buffer[nIndex] = new char[size]{};
        //     for (int j = 0; j < size; j++) buffer[nIndex][j] = str[j];

                                    
        //     if (buffer[nIndex][0] == STOP_STRING) {
        //         strIndex = nIndex - 1;
        //         break;
        //     }

        //     pointers[nIndex] = buffer[nIndex]; 
        // }

        // /** 
        //  * Цикл сортировки строк по методу "всплывающего пузырька" в порядке
        //  * возрастания кода первого символа.
        //  */

        // for (int i = 0; i < strIndex; i++) {
        //     for (int j = 0; j < strIndex; j++) {
        //         if (strcmp(pointers[j], pointers[j+1]) > 0) {
        //             swap(pointers[j], pointers[j+1]);
        //             swap(sizes[j], sizes[j+1]);
        //         }
        //     }
        // }

        // for (int k = 0; k < strIndex + 1; k++) {
        //     for (int s = 0; s < sizes[k]; s++) {
        //         cout << *(pointers[k] + s);
        //     }
        //     cout << endl;
        // }

        // /** Освобождение занятой памяти */


        // delete[] buffer;
        // buffer = nullptr;

        // delete[] pointers;
        // pointers = nullptr;

        // delete [] sizes;
        // sizes = nullptr;
    }

    /** 
     * Задание 6. Работа со строками.
     *
     * Реализуйте следующую программу. Пользователь вводит строку (любого
     * размера), после чего пользователю выводится на консоль следующее
     * изображение, где его ввод помещен в "speech bubble":
     *
     *  _____________________________________
     * / Here user input is shown. This line \ 
     * \ must be at most 40 characters long. /
     *  ------------------------------------
     *     \
     *      \
     *        /\_/\  (
     *       ( ^.^ ) _)
     *         \"/  (
     *       ( | | )
     *      (__d b__)
     *
     *  При этом длина строки в "облачке" должна быть не более 40 символов, при
     *  этом слова должны переноситься аккуратно. Это означет, что не должно
     *  быть переносов в центре слова (если только это слово не больше 40
     *  символов).
     *
     *  Дизайн облачка и ASCII-арт допустимо поменять по усмотрению.
     *
     *  Подсказка: обратите внимание на конкатенацию строковых литералов в
     *  языке С, это позволит задавать подобные рисунки так, чтобы они
     *  адекватно выглядели в коде.
     */
  
    {
        // const int SPACE = 32;
        // const int LINE_WIDTH = 40;

        // string text;
        // getline(cin,text);
        // int size = text.size();

        // int* spaces = new int[size];
        // int countSpaces = 0;
        // int iSpases = 0;

        // char** worlds = { new char*[size]{} };
        // for (int i = 0; i < size; i++) {
        //     worlds[i] = new char[size]{};
        // }

        // int l = 0;
        // int wSize = 0;
        // int wCounter = 0;
        // for (int r = 0; r < size; r++) {
        //     if (text[r] != SPACE) {
        //         wSize++;
        //         worlds[wCounter][wSize - 1] = text[r];
        //     } else {
        //         while (l != r) {
        //             if (text[l] == SPACE) spaces[wCounter]++;
        //             l++;
        //         }
        //         wCounter++;
        //         wSize = 0;
        //     }
        // }
        
        // spaces[wCounter] = 1;
        // int numLines = size;

        // char** lines = { new char*[numLines]{} };
        // for (int i = 0; i < numLines; i++) {
        //     lines[i] = new char[LINE_WIDTH]{};
        // }

        // int currentLineLengh = 0;
        // int line = 0;

        // for (int i = 0; i < wCounter + 1; i++) {
        //     int worldSize = strlen(worlds[i]);
        //     int spacesCount  = spaces[i];

        //     if (spacesCount) {
        //         lines[line][currentLineLengh] = ' ';
        //         currentLineLengh++;
        //     }

        //     if (worldSize + currentLineLengh > LINE_WIDTH && worldSize <= LINE_WIDTH) {
        //         line++;
        //         currentLineLengh = 0;
        //     }

        //     int k = 0;
        //     for (int j = 0; j < worldSize; j++) {
        //         if (currentLineLengh + k == LINE_WIDTH) {
        //             line++;
        //             currentLineLengh = 0;
        //             k = 0;
        //         }  
        //         lines[line][currentLineLengh + k] = worlds[i][j];
        //         k++;
        //     }
        //     currentLineLengh += k;
        // }

        // for (int i = 0; i < size; i++) {
        //     if (lines[i][0] == 0) {
        //         numLines = i;
        //         break;
        //     }
        // }

        // cout << ' ';
        // for (int i = 0; i < LINE_WIDTH + 2; i++) cout << '-';
        // cout << endl;
        // for (int i = 0; i < numLines; i++) {
        //     if (i == 0 && numLines != 1) cout << "/ ";
        //     else if (i > 0 && i < numLines - 1 || numLines == 1) cout << "| ";
        //     else cout << "\\ ";

        //     for (int j = 0; j < LINE_WIDTH; j++) (lines[i][j] != 0) ? cout << lines[i][j] : cout << ' ';

        //     if (i == 0 && numLines != 1) cout << " \\";
        //     else if (i > 0 && i < numLines - 1 || numLines == 1) cout << " |";
        //     else cout << " /";

        //     cout << endl;
        // }
        // cout << ' ';
        // for (int i = 0; i < LINE_WIDTH + 2; i++) cout << '-';
        // cout << endl;
        // cout << "     \\" << endl;
        // cout << "      \\" << endl;
        // cout << "        /\\_/\\  (" << endl;
        // cout << "       ( ^.^ ) _)" << endl;
        // cout << "         \"/  (" << endl;
        // cout << "       ( | | )" << endl;
        // cout << "      (__d b__)" << endl;


        // delete[] spaces;
        // spaces = nullptr;

        // delete[] worlds;
        // worlds = nullptr;

        // for (int i = 0; i < size; i++) {
        //     delete[] worlds[i];
        //     worlds[i] = nullptr;
        // }

        // delete[] lines;
        // lines = nullptr;

        // for (int i = 0; i < size; i++) {
        //     delete[] lines[i];
        //     lines[i] = nullptr;
        // }
    }


    /** 
     * Задание 7. Сложные указатели.
     *
     * Объявление и использование указателей на многомерные массивы.
     * Проинициализируйте трехмерный массив double dArray[4][3][3] так, как
     * показано на рисунке и напишите фрагмент кода, который меняет местами
     * значения элементов четных и нечетных слоев:
     *
     *  было:                |--------|     
     *                     / |4  4  4 |     
     *                   |--------| 4 | 
     *                 / |3  3  3 | 4 | 
     *               |---------|3 |   |
     *             / | 2  2  2 |3 | /
     *            |---------|2 |__|
     *            | 1  1  1 |2 | /
     *            | 1  1  1 |__| 
     *            | 1  1  1 | /
     *            |_________|
     *
     *  стало:               |--------|     
     *                     / |3  3  3 |     
     *                   |--------| 3 | 
     *                 / |4  4  4 | 3 | 
     *               |---------|4 |   |
     *             / | 1  1  1 |4 | /
     *            |---------|1 |__|
     *            | 2  2  2 |1 | /
     *            | 2  2  2 |__| 
     *            | 2  2  2 | /
     *            |_________|
     */

    {

        double dArray[4][3][3];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    dArray[i][j][k] = i + 1;
                }
            }
        }

        for(int i=0; i < 4; i += 2)
        {

            /** 
             * Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА
             * РАВЕНСТВА!!! 
             */

            double (*ptr)[3] = dArray[i];
            double (*ptrNext)[3] = dArray[i+1];

            /** переставляем местами элементы i-того и i+1-ого слоев */

            
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(ptr[j][k], ptrNext[j][k]);
                }
            }
        }

        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         for (int k = 0; k < 3; k++) {
        //             cout << dArray[i][j][k] << ' ';
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
    }
    
    /**
     * Задание 7.
     */

    /**
     * Задание 7.1.
     *
     * Объявите двухмерный встроенный массив элементов типа char.
     *
     * Сформируйте значения элементов массива с помощью генератора случайных
     * чисел таким образом, чтобы в массиве были только символы '*' и '_'.
     *
     * В каждой строке "сдвиньте звездочки" в начало строки, например:
     * было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
     * стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
     * и распечатайте массив по строкам.
     *
     * При этом оцените количество операций, которое требуется для обработки
     * одной строки относительно длины этой строки.
     *
     * Постарайтесь решить эту задачу так, чтобы требовалось не более k*N 
     * операций, где N - длина строки, k - некое фиксированное число.
     */
    
    {
        const int ROWS = 10;
        const int COLUMS = 10;

        char arr[ROWS][COLUMS];
        char arrValues[2] = {'*', '_'};

        srand(time(NULL));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMS; j++) {
                arr[i][j] = arrValues[rand() % 2];
            }
        }

        for (int i = 0; i < ROWS; i++) {
            int numStar = 0;

            for (int j = 0; j < COLUMS; j++) if (arr[i][j] == '*') numStar++;

            for (int j = 0; j < COLUMS; j++) { 
                arr[i][j] = (numStar > 0) ? '*' : '_';
                numStar--;
            } 
         }

        // for (int i = 0; i < ROWS; i++) {
        //     for (int j = 0; j < COLUMS; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    /**
     * Задание 7.2.
     *
     * Модифицируйте предыдущее задание следующим способом: После заполнения
     * массива с помощью генератора случайных чисел "сдвиньте" звездочки по
     * столбцам вниз и распечатайте результат.
     */

    {
        const int ROWS = 10;
        const int COLUMS = 10;

        char arr[ROWS][COLUMS];
        char arrValues[2] = {'*', '_'};

        srand(time(NULL));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMS; j++) {
                arr[i][j] = arrValues[rand() % 2];
            }
        }

        for (int j = 0; j < COLUMS; j++) {
            int numStarsInColumns = 0;

            for (int i = 0; i < ROWS; i++) if (arr[i][j] == '*') numStarsInColumns++;

            for (int i = 0; i < ROWS; i++) { 
                arr[i][j] = (numStarsInColumns > 0) ? '_' : '*';
                numStarsInColumns--;
            } 
        }

        // for (int i = 0; i < ROWS; i++) {
        //     for (int j = 0; j < COLUMS; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
