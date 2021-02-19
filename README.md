[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue.svg)](https://bit.ly/cc-by-nc-sa-40)

# Template repository

This is a template repository for programming laboratory works in BSUIR.

# Usage

To compile and run a program use:
```
$ ./build.sh gcc src/<filename>
```

Executable will be started automatically. It can be found in `build/scr/` folder.

# Semester \<2\> lab \<1\>

## Task \<1\>

Найти и вывести целое число в 8 раз меньше заданного, не выполняя деления и не используя операцию взятия остатка от деления.

1. Написать программу для решения задачи №1 с использованием полей бит, (данные вводятся с клавиатуры), скомпилировать, проверить работоспособность программы (1 балл, 10 мин).

## Task \<2\>

Структура содержит информацию о сериалах: количество серий (число), название (указатель), вложенную структуру – дату выхода на экран (строка фиксированной длины) и количество сезонов. Найти сериалы с количеством серий меньше заданного. Удалить сериалы с заданным названием.

1. Для решения задачи №2 организовать структуру (по варианту), в функции main объявить динамический массив структур, проверить выделение памяти и освободить её в конце программы (1 балл, 5 мин).
2. Для решения задачи №2 написать функции для ввода и вывода первых двух полей структуры (+1 балл, 15 мин).
3. Для решения задачи №2 написать функцию поиска в массиве структур по заданному параметру (+2 балла, 10 мин).
4. Для решения задачи №2 написать функцию удаления структур из массива по заданному параметру (+2 балла, 10 мин).
5. Для решения задачи №2 организовать меню для работы с массивом структур и всевозможные проверки на корректность получаемых данных (+3 балла, 25 мин).

# Credits

Written by Alexey Filich.

# License

This repository is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](LICENCE.md).

# Notes

For compiling with SDL2:
```
-lmingw32 -lSDL2main -lSDL2
```

For compiling with ncurses
```
-lncursesw
```

## Description for some `include` files:

- stdarg.h

    Variable arguments with `va_list args; va_start(args, last_variable_in_function); va_arg(args, type)`.

- stdbool.h

    `True` and `false`.

- stdio.h

    `printf`, `scanf`, `NULL`, etc.

- stdlib.h

    Memory: `malloc`, `calloc`, `free`, \
    Random: `rand`, `srand`.

- string.h

    `memset`, `memcpy`, `memmove`.

- time.h

    `time(0)`.
