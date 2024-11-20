#include"ft_printf.h"

int sum(int count, ...) {
    va_list args;
    int total = 0;

    va_start(args, count);
    int i = 0;
    while(i < count)
    {
        printf("test %d\n", args[0].fp_offset);
        printf("%d\n", va_arg(args, double));
                // total += va_arg(args, int);
        i++;
    }
    va_end(args);
    return total;
}

int main ()
{
    printf("%d",sum(20,1.2,2.3,1.2,1.2,2.3,1.2,1.2,2.3,1.2,1.2,2.3,1.2));
}