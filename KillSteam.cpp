﻿#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

float getValue(string text)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        cout << text;
        float a;
        cin >> a;

        if (cin.fail() || cin.peek() != '\n' || a <= 0)
        {
            cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            else // если всё хорошо, то возвращаем a
                return a;
    }
}

int main()
{
    // Изменение кодировки терминала:
    system("chcp 1251 > nul");
    // Установка цвета фона терминала и цвета текста
    system("color 80");

    cout << endl;

    float volume = getValue(" Укажите размер файла для скачивания : "); // Объявляем и инициализируем переменные вызывая метод getValue() и передавая ему текст
    float speed = getValue(" Какова скорость вашего соединения?: ");
    float result = 0;                                                   // Переменная для записи результата загрузки
    int time = 1;                                                       // Счётчик времени
    int percent = 0;                                                    // Переменная для записи процентов загрузки

    while (result < volume) {                          // Цикл длится пока результат загрузки меньше объёма файла
        result += speed;
        if (result >= volume) {                        // При загрузке в последнюю секунду может загрузиться лишнее, для устранения этого  
            result -= result - volume;                 // из результата вычитаем разницу между результатом и общим объёмом файла.
            percent = ceil(result / (volume / 100.f)); // Т.к. при вычислении процентов в вещественных числах часть процентов имеют десятичный вид то при
        }                                              // полной загрузке округляем вычисленное в верхнюю сторону что бы не потерять последний процент
        else percent = floor(result / (volume / 100)); // при переводе в целочисленное число иначе округляем в меньшую сторону т.к. в промежуточном 
                                                       // варианте это не имеет большого значения
        cout << " Прошло\t" << time << " сек.\tСкачано\t" << result << " Мб\tиз " << volume << " Мб.("<< percent <<"%)" << endl;// Выводим результат
        time++;                                        // Инкрементируем время
    }


    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}