#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HISTORY 100

typedef struct {
    char expression[100];
    double result;
} History;

History history[MAX_HISTORY];
int history_count = 0;

void add_to_history(const char *expression, double result) {
    if (history_count < MAX_HISTORY) {
        strcpy(history[history_count].expression, expression);
        history[history_count].result = result;
        history_count++;
    }
}

void display_history() {
    printf("\nCalculation History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%s = %.2f\n", history[i].expression, history[i].result);
    }
}

void display_table() {
    printf("********************************************\n");
    printf("*  Key   | Function                        *\n");
    printf("********************************************\n");
    printf("*   +    | Addition                        *\n");
    printf("*   -    | Subtraction                     *\n");
    printf("*   *    | Multiplication                  *\n");
    printf("*   /    | Division                        *\n");
    printf("*   %%    | Modulus                         *\n");
    printf("*   ^    | Exponentiation                  *\n");
    printf("*   r    | Square Root                     *\n");
    printf("*   !    | Factorial                       *\n");
    printf("*   s    | Sine                            *\n");
    printf("*   c    | Cosine                          *\n");
    printf("*   t    | Tangent                         *\n");
    printf("*   l    | Logarithm (base 10)             *\n");
    printf("*   n    | Natural Logarithm (ln)          *\n");
    printf("*   p    | Percentage                      *\n");
    printf("*   h    | History                         *\n");
    printf("*   q    | Quit                            *\n");
    printf("********************************************\n");
}

double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    char op;
    double num1, num2, result;
    int num;
    display_table();
    
    while (1) {
        printf("\nEnter an operation: ");
        scanf(" %c", &op);
        
        if (op == 'q') break;
        
        switch (op) {
            case '+': case '-': case '*': case '/': case '%': case '^': case 'p':
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                switch (op) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': result = (num2 != 0) ? num1 / num2 : 0;
                              if (num2 == 0) printf("Error: Division by zero!\n"); break;
                    case '%': result = (int)num1 % (int)num2; break;
                    case '^': result = pow(num1, num2); break;
                    case 'p': result = (num1 * num2) / 100; break;
                }
                break;
            case 'r':
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                break;
            case '!':
                printf("Enter an integer: ");
                scanf("%d", &num);
                result = factorial(num);
                break;
            case 's':
                printf("Enter a number (in degrees): ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                break;
            case 'c':
                printf("Enter a number (in degrees): ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180);
                break;
            case 't':
                printf("Enter a number (in degrees): ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180);
                break;
            case 'l':
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = log10(num1);
                break;
            case 'n':
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = log(num1);
                break;
            case 'h':
                display_history();
                continue;
            default:
                printf("Invalid operation!\n");
                continue;
        }
        char expr[100];
        sprintf(expr, "%.2f %c %.2f", num1, op, num2);
        add_to_history(expr, result);
        printf("Result: %.2f\n", result);
        printf("--------------------------------------------\n");
    }
    return 0;
}