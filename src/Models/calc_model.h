#ifndef CALC_MODEL_H
#define CALC_MODEL_H

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

class CalcModel
{
private:
    double x {0};
    std::string input_string;
    int rad_deg_fl;
    #define PI 3.141592653589793

    /*!
    *  стек с операндами.
    */
    struct stack_dbl {
    double stack_dbl[256] {0};
    int stack_dbl_count = 0;
    };

    /*!
    *  стек с операторами и скобками.
    */
    struct stack_char {
    char stack_char[256] {'\0'};
    int stack_char_count {0};
    };

    /**
     *  Находит в выражении названия функций и записывает в стек соответствующий ей
     * символ. \param[in] c первый символ названия ф-ции \param[in] next_c второй
     * символ названия ф-ции \param[in] i длинна названия ф-ции \return Код
     * саписываемого в стек символа
     */
    int parse_func(char c, char next_c, int *i);


    /**
     *  Находит число в строке.
     *  \param[out] string строка в которой ищется число
     *  \param[out] i кол-во цифр в найденном числе
     *  \return Число в формате double
     */
    double parse_number(std::string string, int *i);

    /**
     *  Записывает число в стэк чисел
     */
    void push_stack_dbl(stack_dbl *stack, double value);

    /**
     *  Записывает символ в стэк символов
     */
    void push_stack_char(stack_char *stack, double value);

    /**
     *  Считывает число из стэка
     */
    double pop_stack_dbl(stack_dbl *stack);

    /**
     *  Считывает символ из стэка
     */
    char pop_stack_char(stack_char *stack);

    /**
     *  Проверяет пустой ли стэк с числами
     */
    int is_empty_stack_dbl(stack_dbl *stack);

    /**
     *  Проверяет пустой ли стэк с символами
     */
    int is_empty_stack_char(stack_char *stack);

    /**
     *  Читает верхнее значение из стэк с числами
     */
    double top_stack_dbl(stack_dbl *stack);

    /**
     *  Читает верхнее значение из стэк с символами
     */
    char top_stack_char(stack_char *stack);

    /**
     *  Проверяет приоритет операций
     *  \param[in] c Символ оператора
     *  \return int с приоритетом операции
     */
    int take_priority(char c);

    /**
     *  Ф-ция рассчета бинарного оператора с вершины стека.
     *  \param[in] stack_char указатель на стек с операторами
     *  \param[in] stack_dbl указатель на стек с операндами
     *  \return Значение выражения в формате double
     */
    double calc_top_stack_binary(stack_char *stack_char, stack_dbl *stack_dbl);

    /**
     *  Ф-ция рассчета унарного оператора с вершины стека.
     *  \param[in] stack_char указатель на стек с операторами
     *  \param[in] stack_dbl указатель на стек с операндами
     *  \return Значение выражения в формате double
     */
    double calc_top_stack_unaru(stack_char *stack_char, stack_dbl *stack_dbl);


    /**
     *  Переводит число из градусов в радианы.
     */
    double grad_to_rad(double a);

    /**
     *  Переводит число из радиан в градусы.
     */
    double rad_to_grad(double a);
    
    /**
     *  Проверяет является ли символ цифрой
     */
    int isNumber(char c);


    /**
     *  Ф-ция печатает стек с операндами.
     *  \param[in] stack_dbl указатель на стек с операндами
     */
    void print_stack_dbl(stack_dbl *stack);

    /**
     *  Ф-ция печатает стек с операторами.
     *  \param[in] stack_char указатель на стек с операторами
     */
    void print_stack_char(stack_char *stack);


public:
    CalcModel() {std::cout << "Calc model constr\n";};
    /**
     *  Оснавная ф-ция для рассчета поступившего в виде строки выражения.
     *  \param[in] string Строка с рассчетным выражением
     *  \param[in] x переменная х для расчета выражений с 'x'
     *  \return Значение выражения в формате double
     */
    double CalcExpression();
    void SetX(double x) { this->x = x;};
    void SetInputString(std::string input_string) { this->input_string = input_string;};
    void SetRadDeg(int rad_deg_fl) { this->rad_deg_fl = rad_deg_fl;};
};

// CalcModel::CalcModel(/* args */);




#endif // CALC_MODEL_H