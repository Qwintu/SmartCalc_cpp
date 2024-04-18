/*!
 *  @file calc_lib.h
 */
#include "calc_lib.h"

double calc_input_string(const char *string, double x) {
  char c;  ///<  символ строки, который обрабатаваем
  int open_parenthese_flag = 0;
  double value = 0;
  double to_stack_value = 0;
  stack_dbl stack_dbl = {0};  ///<  инициализация стэка с операндами
  stack_char stack_char = {0};  ///<  инициализация стэка с операторами

  /*!
   * Основной цикл парсинга входной строки выражения
   */
  for (int i = 0; string[i] != '\0'; i++) {
    c = parse_func(string[i], string[i + 1], &i);
    if (isNumber(c)) {
      to_stack_value = parse_number(string, &i);
      push_stack_dbl(&stack_dbl, to_stack_value);
      open_parenthese_flag = 0;
    } else {
      if ((c == '-' || c == '+') &&
          open_parenthese_flag ==
              1) {  ///< проверяем унарный + и - передскобкой
        push_stack_dbl(&stack_dbl, 0);
        push_stack_char(&stack_char, c);
        open_parenthese_flag = 0;
        continue;
      }

      if (is_empty_stack_dbl(&stack_dbl) && is_empty_stack_char(&stack_char) &&
          (c == '-' ||
           c == '+')) {  ///< проверяем унарный + и - в начале строки
        push_stack_dbl(&stack_dbl, 0);
        push_stack_char(&stack_char, c);
        continue;
      }
      if (c == 'x') {
        push_stack_dbl(&stack_dbl, x);
        open_parenthese_flag = 0;
        continue;
      }

      if (c == '(') {
        push_stack_char(&stack_char, c);
        open_parenthese_flag = 1;
        continue;
      }

      if (is_empty_stack_char(&stack_char)) {
        push_stack_char(&stack_char, c);
        continue;
      }

      if (take_priority(c) > take_priority(top_stack_char(&stack_char))) {
        if (c == ')') {
          while (top_stack_char(&stack_char) != '(') {
            double res = calc_top_stack_binary(&stack_char, &stack_dbl);
            push_stack_dbl(&stack_dbl, res);
          }
          pop_stack_char(&stack_char);  ///< убирает после расчета ( из стека
          if (!is_empty_stack_char(&stack_char)) {
            if (strchr(
                    "sctoiaqng",
                    top_stack_char(&stack_char))) {  ///< если далее идет ф-ция,
                                                     ///< то рассчитываем ее
              double res_un = calc_top_stack_unaru(&stack_char, &stack_dbl);
              open_parenthese_flag = 0;
              push_stack_dbl(&stack_dbl, res_un);
            }
          }
        } else {
          push_stack_char(&stack_char, c);
        }
        continue;
      }

      if (take_priority(c) <= take_priority(top_stack_char(&stack_char))) {
        while (take_priority(c) <= take_priority(top_stack_char(&stack_char)) &&
               top_stack_char(&stack_char) != '(' &&
               !is_empty_stack_char(&stack_char)) {
          double res = calc_top_stack_binary(&stack_char, &stack_dbl);
          push_stack_dbl(&stack_dbl, res);
        }
        push_stack_char(&stack_char, c);
        if (top_stack_char(&stack_char) == ')')
          pop_stack_char(&stack_char);  // при унапной операции убираем )
        if (top_stack_char(&stack_char) ==
            '(') {  // вариает когда в скобке одно число без арифм действий,
                    // sin(30)
          pop_stack_char(&stack_char);
          if (!is_empty_stack_char(&stack_char)) {
            if (strchr("sctoiaqng", top_stack_char(&stack_char)) !=
                NULL) {  // если далее идет ф-ция, то рассчитываем ее
              double res_un = calc_top_stack_unaru(&stack_char, &stack_dbl);
              open_parenthese_flag = 0;
              push_stack_dbl(&stack_dbl, res_un);
            }
          }
        }
      }
    }
  }
  while (!is_empty_stack_char(&stack_char)) {
    push_stack_dbl(
        &stack_dbl,
        calc_top_stack_binary(
            &stack_char, &stack_dbl));  // тут рассчитываем 2 последних значения
  }
  value = top_stack_dbl(&stack_dbl);
  return value;
}

double calc_top_stack_unaru(stack_char *stack_char, stack_dbl *stack_dbl) {
  double a = pop_stack_dbl(stack_dbl);
  char stack_c = pop_stack_char(stack_char);
  double res = 0;

  switch (stack_c) {
    case 'c':
      a = grad_to_rad(a);
      res = cos(a);
      break;
    case 's':
      a = grad_to_rad(a);
      res = sin(a);
      break;
    case 't':
      a = grad_to_rad(a);
      res = tan(a);
      break;
    case 'o':
      // a = grad_to_rad(a);
      res = acos(a);
      res = rad_to_grad(res);
      break;
    case 'i':
      // a = grad_to_rad(a);
      res = asin(a);
      res = rad_to_grad(res);
      break;
    case 'a':
      // a = grad_to_rad(a);
      res = atan(a);
      res = rad_to_grad(res);
      break;
    case 'q':
      res = sqrt(a);
      break;
    case 'n':
      res = log(a);
      break;
    case 'g':
      res = log10(a);
      break;
    default:
      break;
  }
  return res;
}

int parse_func(char ch, char next_c, int *i) {
  char *numbs_string = "0123456789.+-*/:()";
  if (!strchr(numbs_string, ch)) {  // если не цифра или знак меняем с и
                                    // прибавляем i, иначе просто перезаписываем
    switch (ch) {
      case 'c':
        *i += 2;
        break;
      case 't':
        *i += 2;
        break;
      case 'm':
        *i += 2;
        break;
      case 's':
        if (next_c == 'i') {
          ch = 's';
          *i += 2;
        } else {
          ch = 'q';
          *i += 3;
        }
        break;
      case 'a':
        if (next_c == 'c') {
          ch = 'o';
          *i += 3;
        } else if (next_c == 's') {
          ch = 'i';
          *i += 3;
        } else if (next_c == 't') {
          ch = 'a';
          *i += 3;
        }
        break;
      case 'l':
        if (next_c == 'n') {
          ch = 'n';
          *i += 1;
        } else if (next_c == 'o') {
          ch = 'g';
          *i += 2;
        }
        break;
      default:
        break;
    }
  }
  return ch;
}

double calc_top_stack_binary(stack_char *stack_char, stack_dbl *stack_dbl) {
  double b = pop_stack_dbl(stack_dbl);
  double a = pop_stack_dbl(stack_dbl);
  char stack_c = pop_stack_char(stack_char);
  double res = 0;

  switch (stack_c) {
    case '+':
      res = a + b;
      break;
    case '-':
      res = a - b;
      break;
    case '*':
      res = a * b;
      break;
    case '/':
      res = a / b;
      break;
    case '^':
      res = pow(a, b);
      break;
    case 'm':
      res = fmod(a, b);
      break;
    default:
      break;
  }
  return res;
}

int take_priority(char c) {
  int priority_val = 0;
  if (c == '+' || c == '-') priority_val = 1;
  if (c == '*' || c == '/') priority_val = 2;
  // если совпадает strchr(numbs_string, c)
  if (strchr("sctoiaqngm", c)) priority_val = 6;
  if (c == '^') priority_val = 4;
  if (c == '(' || c == ')') priority_val = 6;
  return priority_val;
}

double parse_number(const char *string, int *i) {
  double parsed_value = 0;
  char temp_value[256] = {'\0'};
  char *digits = "0123456789.";
  char *begin = (char *)string + *i;

  size_t len_numb =
      strspn(begin, digits);  // Вычисляет длину начального сегмента str1,
                              // который полностью состоит из символов str2.
  for (size_t j = 0; j < len_numb; j++) {
    temp_value[j] = *(begin + j);
    *i += 1;
  }
  *i -= 1;
  parsed_value = atof(temp_value);
  return parsed_value;
}

// возвращает 1 если скобки стоят правильно, 0 - ошибка
// правда 1 (или любое число), 0 - ложь
int is_brackets_correct(const char *str) {
  int open_par = 0;
  int close_par = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(') open_par++;
    if (str[i] == ')') close_par++;
    if (open_par < close_par) return 0;
  }
  return open_par == close_par ? 1 : 0;
}

// возвращает 1 если точка есть, 0 - ошибка, точки нет
// правда 1 (или любое число), 0 - ложь
int is_dot(const char *string) {
  int error_code = 0;
  int str_len = strlen(string);
  for (; str_len >= 0; str_len--) {
    if (!strchr("0123456789", string[str_len])) {
      if (string[str_len] == '.') error_code = 1;
      break;
    };
  }
  return error_code;
}

// возвращает 1 если скобки стоят правильно, 0 - ошибка
// правда 1 (или любое число), 0 - ложь
int check_errors_in_sterng(const char *string) {
  int error_code = 1;
  char patt[8][5] = {"(*", "(/", "d/", "d*", "d+", "d-", "^-", "^/"};
  for (int i = 0; i < 8; i++) {
    if (strstr(string, patt[i]) != NULL) error_code = 0;
  }
  if (strlen(string) == 1) {
    if (strchr("+-*/", string[0])) error_code = 0;
  }
  if (string[0] == '/' || string[0] == '*') error_code = 0;
  return error_code;
}

double grad_to_rad(double a) { return ((a * PI) / 180); }

double rad_to_grad(double a) { return ((a * 180) / PI); }

void push_stack_dbl(stack_dbl *stack, double value) {
  stack->stack_dbl[stack->stack_dbl_count] = value;
  stack->stack_dbl_count++;
}

void push_stack_char(stack_char *stack, double value) {
  stack->stack_char[stack->stack_char_count] = value;
  stack->stack_char_count++;
}

double pop_stack_dbl(stack_dbl *stack) {
  stack->stack_dbl_count--;
  double value = stack->stack_dbl[stack->stack_dbl_count];
  stack->stack_dbl[stack->stack_dbl_count] = 0;
  return value;
}

char pop_stack_char(stack_char *stack) {
  stack->stack_char_count--;
  double value = stack->stack_char[stack->stack_char_count];
  stack->stack_char[stack->stack_char_count] = '\0';
  return value;
}

int is_empty_stack_dbl(stack_dbl *stack) { return stack->stack_dbl_count == 0; }

int is_empty_stack_char(stack_char *stack) {
  return stack->stack_char_count == 0;
}

double top_stack_dbl(stack_dbl *stack) {
  return stack->stack_dbl[stack->stack_dbl_count - 1];
}
char top_stack_char(stack_char *stack) {
  if (stack->stack_char_count == 0) return 0;
  return stack->stack_char[stack->stack_char_count - 1];
}

// void print_stack_dbl(stack_dbl *stack) {
//   printf("stack dbl N=%d:  ", stack->stack_dbl_count);
//   for (int i = 0; i < stack->stack_dbl_count; i++) {
//     printf("%.2lf ", stack->stack_dbl[i]);
//   }
//   printf("\n");
// }
// void print_stack_char(stack_char *stack) {
//   printf("stack chr N=%d:  ", stack->stack_char_count);
//   for (int i = 0; i < stack->stack_char_count; i++) {
//     printf("%c ", stack->stack_char[i]);
//   }
//   printf("\n");
// }

int isNumber(char c) {
  return ((c > 47 && c < 58) ||
          c == '.');  // 1 - цифра или точка, 0 - не цифра или точка
}

// ________credit calc_______________

double ann_payment(double balance_after_payment, double interest_rate,
                   int months) {
  double month_interest_rate = 0;
  month_interest_rate = interest_rate / (100 * 12);
  double ann_payment = 0;
  double ann_coef = 0;

  ann_coef = (month_interest_rate / (1 - pow((1 + month_interest_rate), -months)));
  ann_payment = balance_after_payment * ann_coef;

  // ___ временная ф-ция для вывода графика платежа в консоль. Потом переписать
  // ее для вывода в программе.

  double temp_balance_after_payment = balance_after_payment;
  double temp_ann_payment = ann_payment;
  double percents = 0;

  percents = temp_balance_after_payment * month_interest_rate;
  temp_balance_after_payment =
      temp_balance_after_payment - (temp_ann_payment - percents);
  printf("month\tmonthly payment\tpercents\t\tbalance_after_payment\n");
  printf("1\t%f\t%f\t\t%f\n", temp_ann_payment, percents,
         temp_balance_after_payment);

  for (int i = 0; i < months - 1; i++) {
    percents = temp_balance_after_payment * month_interest_rate;
    temp_balance_after_payment =
        temp_balance_after_payment - (temp_ann_payment - percents);

    printf("%d\t%f\t%f\t\t%f\n", i + 2, temp_ann_payment, percents,
           temp_balance_after_payment);
  }
  printf("\n\n");

  // ___end временная ф-ция____

  return ann_payment;
}

double diff_payment_percents(double balance_after_payment,
                             double interest_rate) {
  double percents_monthly = 0;
  percents_monthly = (balance_after_payment * (interest_rate / 100)) / 12;
  return percents_monthly;
}

// ________deposit calc_______________
double calc_deposit_persents(double dep_amount, double dep_interest_rate,
                             int dep_days, int months, int calculation_type) {
  double persents = 0;
  double monthly_persents = 0;

  if (calculation_type == 1) {
    for (int i = 0; i < months; i++) {
      monthly_persents = ((dep_amount * (dep_interest_rate / 100)) / 365) * 30.4;
      persents += monthly_persents;
      dep_amount += monthly_persents;
      //            printf("%f \t%f\n", monthly_persents, persents);
    }

  } else if (calculation_type == 2) {
    persents = ((dep_amount * (dep_interest_rate / 100)) / 365) * dep_days;
  }
  return persents;
}
