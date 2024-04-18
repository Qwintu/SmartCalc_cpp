#ifndef SRC_CALC_LIB_H_
#define SRC_CALC_LIB_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.141592653589793

/*!
 *  стек с операндами.
 */
typedef struct {
  double stack_dbl[256];
  int stack_dbl_count;
} stack_dbl;

/*!
 *  стек с операторами и скобками.
 */
typedef struct {
  char stack_char[256];
  int stack_char_count;
} stack_char;

/**
 *  Оснавная ф-ция для рассчета поступившего в виде строки выражения.
 *  \param[in] string Строка с рассчетным выражением
 *  \param[in] x переменная х для расчета выражений с 'x'
 *  \return Значение выражения в формате double
 */
double calc_input_string(const char *string, double x);

/**
 *  Находит число в строке.
 *  \param[out] string строка в которой ищется число
 *  \param[out] i кол-во цифр в найденном числе
 *  \return Число в формате double
 */
double parse_number(const char *string, int *i);

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
 *  Проверяет является ли символ цифрой
 */
int isNumber(char c);

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
 *  Находит в выражении названия функций и записывает в стек соответствующий ей
 * символ. \param[in] c первый символ названия ф-ции \param[in] next_c второй
 * символ названия ф-ции \param[in] i длинна названия ф-ции \return Код
 * саписываемого в стек символа
 */
int parse_func(char c, char next_c, int *i);

/**
 *  Переводит число из градусов в радианы.
 */
double grad_to_rad(double a);

/**
 *  Переводит число из радиан в градусы.
 */
double rad_to_grad(double a);

/**
 *  Проверяет корректность расстановки скобок в выражении при нажатии кнопки "="
 * или "plot". \param[in] str указатель на строку с проверяемым выражением
 */
int is_brackets_correct(const char *str);

/**
 *  Проверяет выражение на некоторые ошибки при нажатии кнопки "=" или "plot".
 *  \param[in] string указатель на строку с проверяемым выражением
 */
int check_errors_in_sterng(const char *string);

/**
 *  Ф-ция ищет точку в строке.
 */
int is_dot(const char *string);

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

/**
 *  Ф-ция рассчета месячного Аннуитетного платежа.
 *  \param[in] balance_after_paymen - остаток кредита от которого рассчитывается
 * месячный платеж \param[in] interest_rate - годовая процентная ставка по
 * кредиту \param[in] months - сколько месяцев осталось до погашения кредита
 *  \return Размер месячного аннуитетного платежа
 */
double ann_payment(double balance_after_payment, double interest_rate,
                   int months);

/**
 *  Ф-ция рассчета процентов для месячного дифференцированного платежа.
 *  \param[in] balance_after_paymen - остаток кредита от которого рассчитывается
 * месячный процент \param[in] interest_rate - годовая процентная ставка по
 * кредиту \param[in] months - сколько месяцев осталось до погашения кредита
 *  \return Сумма процентов в месячном платеже
 */
double diff_payment_percents(double balance_after_payment,
                             double interest_rate);

/**
 *  Ф-ция рассчета процентов депозита.
 *  \param[in] dep_amount - размер депозита на начало периода
 *  \param[in] dep_interest_rate - годовая процентная ставка по депозиту
 *  \param[in] dep_days - рассчетный период в днях
 *  \param[in] months - рассчетный период в месяцах
 *  \param[in] calculation_type - вид рассчета процентов. 1 - с помесячной
 * капитализацией, 2 - без капитализации \return Сумма процентов за рассчетный
 * период.
 */
double calc_deposit_persents(double dep_amount, double dep_interest_rate,
                             int dep_days, int months, int calculation_type);

#endif  // SRC_CALC_LIB_H_
