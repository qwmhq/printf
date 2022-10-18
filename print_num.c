#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>


void _printf3(char *,...);              //Our printf function
char* convert(unsigned int, int);       //Convert integer number into octal, hex, etc.
int _puts(char *str);
int _putchar(char c);


int main()
{
    int age = 123;
    _printf3(" My age is %x", age, "\n");
    return 0;
}

int util_d(unsigned int i)
{
         if(i<0)
         {
                i = -i;
                _putchar('-');
         }
         _puts(convert(i,10));
}

int util_o(unsigned int i)
{
         _puts(convert(i,8));;
}


int util_x(unsigned int i)
{
        _puts(convert(i,16));
}

void _printf3(char* format,...)
{
    const char *p;
    unsigned int i;
    char *s;

    //Module 1: Initializing Myprintf's arguments
    va_list arg;
    va_start(arg, format);

    for(p = format; *p != '\0'; p++)
    {
        while( *p != '%' )
        {
            _putchar(*p);
            p++;
        }

        p++;

        //Module 2: Fetching and executing arguments
        switch(*p)
        {
           case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        util_d(i);
                        break;

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
		       util_o(i);
                        break;

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        util_x(i);
                        break;
        }
    }

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg);
}

char *convert(unsigned int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);

    return(ptr);
}




int _putchar(char buf)
{
        return (write(1, &buf, 1));
}

int _puts(char *str)
{
        register int i;
        for (i = 0; str[i] != '\0';  i++)
                _putchar(str[i]);
        return i;
}
