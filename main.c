//tetris_2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>                                                                                                              //getch()
#include <windows.h>                                                                                                            //For Sleep(1000);
#include <time.h>                                                                                                               //srand(time(NULL));

#define Height 12
#define Width 10
#define TimeSleep 50

char char_glass = '.';
char char_border = 'o';
char char_figure = 'x';
int Tracker = 0;

int UpperBound = 0;
int LowerBound = Height - 1;
int LeftBorder = 0;
int RightBorder = Width - 1;
int LocationFigure = Width / 2;

int Id_Square = 200;
int Id_Stick = 100;

struct STRACT_FIGURE {
    int* x = NULL;
    int* y = NULL;
} Str_Figure;

void PrintTraker();

void ShowGame(char InputGlass[][Width]);                                                                                        //Отображаем массив Стакана

int FillingGlass(char InputGlass[][Width]);                                                                                     //Заполнение glass

int InputFiguries(char InputGlass[][Width], char Figure[][Width], int NumbFigure, int* X, int* Y);                              //Занесение фигуры в glass

int Control_Figure(char InputGlass[][Width], int NumbFigure, int* X, int* Y);

int FallingFigure_Stick(char InputGlass[][Width], int NumbFigure, int* X, int* Y);

int DeleteLines(char InputGlass[][Width]);

int main() {
    srand(time(NULL));

    char Glass[Height][Width] = {};
    FillingGlass(Glass);

    char Square[Height][Width] = {};                                                                                             //Фигура Квадрат
    char Stick[Height][Width] = {};                                                                                              //Фигура Палка

    int position_X = (Width / 2) - 2;
    int position_Y = 1;
    Str_Figure.x = &position_X;                                                                                                  //Берем позицию x
    Str_Figure.y = &position_Y;                                                                                                  //Берем позицию y

    int NumberFigure = 0;
    int Value_Change_Figure = 0;
    int Random_Fig = 0;

    char b = ' ';
    printf("TETRIS\n");
    printf("------\n");
    printf("Info: \"A\", \"D\" for control || \"S\" for falling || \"Esc\" for exit\n");
    b = _getch();
    system("cls");
    printf("Are you ready?\n");
    b = _getch();
    system("cls");
    printf("Good luck!\n");
    b = _getch();
    system("cls");

    while (1) {
        if (Value_Change_Figure == 5) {
            system("cls");          
        }

        Random_Fig = 1 + rand()%(2 - 1 + 1) ;                                                                                   // [A;B]   A + rand() % (B - A + 1)
        if (Random_Fig == 1) {
            NumberFigure = Id_Stick;    
            *Str_Figure.x = (Width / 2) - 2;                                                                             
            *Str_Figure.y = 1;                                                                                         
            InputFiguries(Glass, Stick, NumberFigure, Str_Figure.x, Str_Figure.y);
        }
        if (Random_Fig == 2) {
            NumberFigure = Id_Square;
            *Str_Figure.x = (Width / 2) - 1;                                                                                    // Обнуляем показатели Структуры
            *Str_Figure.y = 1;                                                                                                  // Обнуляем показатели Структуры
            Value_Change_Figure = InputFiguries(Glass, Square, NumberFigure, Str_Figure.x, Str_Figure.y);                       //Измеряем именно квадрат, т. к. он может заспавниться на чарах

            if (Value_Change_Figure == 27) { 
                system("cls");
                ShowGame(Glass);
                PrintTraker();
                printf("Game Over!\n");
                return 0;
            }
        }
        ShowGame(Glass);
        PrintTraker();

        while (1) {                                                                                                             //While УПРАВЛЕНИЯ ФИГУРЫ               
            Value_Change_Figure = Control_Figure(Glass, NumberFigure, Str_Figure.x, Str_Figure.y);                              //УПРАВЛЕНИЕ ФИГУРОЙ + Отслеживаем значения для Падения или Выхода из игры

            if (Value_Change_Figure == 27) {                                                                                    //Нажимаем клавишу esc в switch/case
                system("cls");
                ShowGame(Glass);
                PrintTraker();
                printf("Game Over!\n");
                return 0;
            }
            if (Value_Change_Figure == 3) {                                                                                     //Нажимаем клавишу esc в switch/case              
                break;
            }
            
            system("cls");
            ShowGame(Glass);            
            PrintTraker();
        }

        if (Value_Change_Figure != 27 || Value_Change_Figure == 3) {                                                            //Можем ронять фигуру, если не равно esc ли равно 3
            while (1) {           
                Value_Change_Figure = FallingFigure_Stick(Glass, NumberFigure, Str_Figure.x, Str_Figure.y);                     //ПАДЕНИЕ ФИГУРЫ И ЗАПИСЬ ЗНАЧЕНИЯ

                if (Value_Change_Figure == 5) {  
                    if (NumberFigure != Id_Stick) {
                    DeleteLines(Glass);
                    }
                    DeleteLines(Glass);
                    Tracker++;
                    break;
                }           
            }
        }
    }
    return 0;
}

void PrintTraker() {
    printf("------------------\n");
    printf("Tracker: %.2d\n", Tracker);
}

void ShowGame(char InputGlass[][Width]) {
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            printf("%c", InputGlass[i][j]);
        }
        printf("\n");
    }
    Sleep(TimeSleep);  
}

int FillingGlass(char InputGlass[][Width]) {                                                                                    //Заполнение glass
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            InputGlass[i][j] = '.';
            if (i == UpperBound || i == LowerBound) {
                InputGlass[i][j] = char_border;
            }
            else if (j == LeftBorder || j == RightBorder) {
                InputGlass[i][j] = char_border;
            }
        }
    }
    return 0;
}

int InputFiguries(char InputGlass[][Width], char Figure[][Width], int NumbFigure, int* X, int* Y) {                             //Отрисовка фигур в glass
    if (**InputGlass == NULL || X == NULL || Y == NULL) return -1;

    if (NumbFigure == Id_Stick) {                                                                                               //Отрисовка Stick в glass
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                Figure[i][j] = char_glass;

                if (*X == j && *Y == i && *Y == 1) {                                                                                
                    InputGlass[i][j] = char_figure;
                    InputGlass[i][j + 1] = char_figure;
                    InputGlass[i][j + 2] = char_figure;
                    InputGlass[i][j + 3] = char_figure;

                    Figure[i][j] = char_figure;
                    Figure[i][j + 1] = char_figure;
                    Figure[i][j + 2] = char_figure;
                    Figure[i][j + 3] = char_figure;
                }
            }
        }
    }

    if (NumbFigure == Id_Square) {                                                                                              //Отрисовка Square в glass
       // Если уже есть на месте спавна фигура, то конец игры
        if (InputGlass[*Y + 1][*X] == char_figure || InputGlass[*Y + 1][*X + 1] == char_figure) {
            return 27;
        }

        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                Figure[i][j] = char_glass;

                if (*X == j && *Y == i && *Y == 1) {                                                                                
                    InputGlass[i][j] = char_figure;
                    InputGlass[i][j + 1] = char_figure;
                    InputGlass[i + 1][j] = char_figure;
                    InputGlass[i + 1][j + 1] = char_figure;

                    Figure[i][j] = char_figure;
                    Figure[i][j + 1] = char_figure;
                    Figure[i + 1][j] = char_figure;
                    Figure[i + 1][j + 1] = char_figure;
                }
            }
        }
    }
    return 0;
}

int Control_Figure(char InputGlass[][Width], int NumbFigure, int* X, int* Y) {
    if (**InputGlass == NULL || X == NULL || Y == NULL) return -1;

    int c = _getch();
    if (NumbFigure == Id_Stick) {       //Stick Control
        switch (c) {
        case 'D':
        case 'd':
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    if (InputGlass[*Y][*X] == InputGlass[i][j] && InputGlass[*Y][*X + 4] != char_border) {
                        InputGlass[*Y][*X] = char_glass;
                        InputGlass[*Y][*X + 4] = char_figure;
                        *X = *X + 1;
                        return 0;
                    }
                }
            }
            break;

        case 'A':
        case 'a':
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    if (InputGlass[i][j] == char_figure && i == 1 && *X != 1) {
                        InputGlass[i][j + 3] = char_glass;
                        InputGlass[i][j - 1] = char_figure;
                        *X = *X - 1;
                        return 0;
                    }
                }
            }
            break;

        case 27:                                                                                                                //"esc" for exit
            return 27;
            break;

        case 'S':
        case 's':                                                                                                               //"s" for falling
            if (InputGlass[*Y + 1][*X] == char_figure || InputGlass[*Y + 1][*X + 1] == char_figure || InputGlass[*Y + 1][*X + 2] == char_figure || InputGlass[*Y + 1][*X + 3] == char_figure) {
                return 27;                                                                                                      //Выход, если достигли верха для Палки
            }
            return 3;                                                                                                           //Разрешение на падение
            break;

        default:
            printf("Press \"A\" or \"D\" || Press \"ESC\" for exit\n");
        }
    }

    if (NumbFigure == Id_Square) {       //Square Control
        switch (c) {
        case 'D':
        case 'd':
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    if (InputGlass[*Y][*X] == InputGlass[i][j] && InputGlass[*Y + 1][*X + 2] != char_figure && InputGlass[*Y][*X + 2] != char_border) {
                        InputGlass[*Y][*X] = char_glass;
                        InputGlass[*Y + 1][*X] = char_glass;

                        InputGlass[*Y][*X + 2] = char_figure;
                        InputGlass[*Y + 1][*X + 2] = char_figure;
                        *X = *X + 1;
                        return 0;
                    }
                }
            }
            break;

        case 'A':
        case 'a':
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    if (InputGlass[*Y][*X] == InputGlass[i][j] && InputGlass[*Y + 1][*X - 1] != char_figure && i == *Y && *X != 1) {
                        InputGlass[*Y][*X + 1] = char_glass;
                        InputGlass[*Y + 1][*X + 1] = char_glass;

                        InputGlass[*Y][*X - 1] = char_figure;
                        InputGlass[*Y + 1][*X - 1] = char_figure;
                        *X = *X - 1;
                        return 0;
                    }
                }
            }
            break;

        case 27:                                                                                                                //"esc" for exit
            return 27;
            break;

        case 'S':
        case 's':                                                                                                               //"s" for falling
            if (InputGlass[*Y + 2][*X] == char_figure || InputGlass[*Y + 2][*X + 1] == char_figure) {
                return 27;                                                                                                      //Выход, если достигли верха для Квадрата
            }
            return 3;                                                                                                           //Разрешение на падение
            break;

        default:
            printf("Press \"A\" or \"D\" || Press \"ESC\" for exit\n");
        }
    }
}

int FallingFigure_Stick(char InputGlass[][Width], int NumbFigure, int* X, int* Y) {
    if (**InputGlass == NULL || X == NULL || Y == NULL) return -1;

    //Falling for Stick
    if (NumbFigure == Id_Stick) {
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                if (*Y == i && *X == j) {
                    InputGlass[*Y][*X + 0] = char_glass;
                    InputGlass[*Y][*X + 1] = char_glass;
                    InputGlass[*Y][*X + 2] = char_glass;
                    InputGlass[*Y][*X + 3] = char_glass;

                    InputGlass[*Y + 1][*X + 0] = char_figure;
                    InputGlass[*Y + 1][*X + 1] = char_figure;
                    InputGlass[*Y + 1][*X + 2] = char_figure;
                    InputGlass[*Y + 1][*X + 3] = char_figure;
                }
            }
        }
        *Y = *Y + 1;

        if (*Y == LowerBound - 1) {                                                                                                 //Выход для смены фигуры, если достигла низа            
            return 5;
        }

        if (InputGlass[*Y + 1][*X] == char_figure || InputGlass[*Y + 1][*X + 1] == char_figure || InputGlass[*Y + 1][*X + 2] == char_figure || InputGlass[*Y + 1][*X + 3] == char_figure) {         //Выход, если соприкосновение /Смотрим есть ли ниже char_figure у фигуры                                                                   //Выход для смены фигуры, если встречается с другой фигурой
            return 5;
        }

        system("cls");
        for (int i = 0; i < Height; i++) {                                                                                          //Фун-ция Show Glass внутри фун-ции Falling
            for (int j = 0; j < Width; j++) {
                printf("%c", InputGlass[i][j]);
            }
            printf("\n");
        }
        PrintTraker();
        Sleep(TimeSleep);                                                                                                                    
        return 0;
    }

    //Falling for Square
    if (NumbFigure == Id_Square) {
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                if (*Y == i && *X == j) {
                    InputGlass[*Y][*X] = char_glass;
                    InputGlass[*Y][*X + 1] = char_glass;

                    InputGlass[*Y + 2][*X] = char_figure;
                    InputGlass[*Y + 2][*X + 1] = char_figure;

                }
            }
        }
        *Y = *Y + 1;

        if (*Y == LowerBound - 2) {                                                                                                 //Выход для смены фигуры, если достигла низа
            return 5;
        }

        if (InputGlass[*Y + 2][*X] == char_figure || InputGlass[*Y + 2][*X + 1] == char_figure) {                                   //Выход, если соприкосновение /Смотрим есть ли ниже char_figure у фигуры                                                                   //Выход для смены фигуры, если встречается с другой фигурой
            return 5;
        }

        system("cls");
        for (int i = 0; i < Height; i++) {                                                                                          //Фун-ция Show Glass внутри фун-ции Falling
            for (int j = 0; j < Width; j++) {
                printf("%c", InputGlass[i][j]);
            }
            printf("\n");
        }
        PrintTraker();
        Sleep(TimeSleep);
        return 0;
    }
}

int DeleteLines(char InputGlass[][Width]) {
    if (**InputGlass == NULL) return -1;

    bool Clean_One_Line = false;
    bool Two_Lines = false;
    int Value_char_Glass = 0;
    int Y = 0;

    for (int i = 1; i < Height; i++) {
        if (Clean_One_Line != false) break; 
        if (InputGlass[i][1] == char_glass || InputGlass[i][1] == char_border)
            continue;

        for (int j = 1; j < Width; j++) {
            if (InputGlass[i][j] == char_glass || InputGlass[i][j + 1] == char_glass || Clean_One_Line == true) {
                break; 
            }

            while (1) {
                if (InputGlass[i][j] == char_glass) {
                    Value_char_Glass = 0;
                    break; 
                }
                if (InputGlass[i][j] == char_figure) {
                    Value_char_Glass++;
                }
                if (Value_char_Glass == Width - 2) {
                    Y = i;
                    Clean_One_Line = true;
                    Value_char_Glass = 0;
                    break; 
                }
                j++;
            }
        }
    }

    if (Clean_One_Line == true) {   
        for (int j = 1; j < RightBorder; j++) {                                                                                 //Очищение строки
            InputGlass[Y][j] = char_glass;
        }

        for (int i = Y; i > 0; i--) {                                                                                           //Перемещение всех верхних char_figure вниз
            for (int j = Width; j > 0; j--) {
                if (InputGlass[i][j] == char_figure) {
                    InputGlass[i][j] = char_glass;
                    InputGlass[i + 1][j] = char_figure;                                                                         //Спускаем на два всё вниз
                }
            }
        }
        return 0;
    }
}
