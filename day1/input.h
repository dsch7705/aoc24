#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


// variadic args should be pointers to input buffers
static void fetch_input(size_t max_count, const char* format, ...)
{
    // init va_list
    int argc = 0;
    void** argv;
    char* cptr = format;
    while (*cptr != '\0')
    {
        if (*cptr == 'i')
            argc++;
        cptr++;
    }
    va_list args;
    va_start(args, argc);

    argv = malloc(sizeof(void*) * argc);
    for (int i = 0; i < argc; i++)
    {
        argv[i] = va_arg(args, void*);
    }


    // open file
    FILE* fptr;
    char line[256];
    errno_t result;

    result = fopen_s(&fptr, "input.txt", "r");
    if (result != 0)
    {
        printf("Could not open input.txt");
        return;
    }

    size_t line_n = 0;
    while (fgets(line, sizeof(line), fptr) != NULL && line_n < max_count)
    {
        char in_buf[64];
        int argi = 0;

        char* line_cptr = line;
        char* format_cptr = format;
        while (*format_cptr != '\0')
        {
            switch (*format_cptr)
            {
            case 'i':
                int in_bufi = 0;
                while (*line_cptr >= '0' && *line_cptr <= '9' && line_cptr - line < sizeof(in_buf) - 1)
                {
                    in_buf[in_bufi] = *line_cptr;
                    line_cptr++;
                    in_bufi++;
                }
                in_buf[in_bufi] = '\0';                
                sscanf_s(in_buf, "%d", (int*)argv[argi] + line_n);

                argi++;
                format_cptr++;
                break;

            default:
                format_cptr++;
                line_cptr++;
                break;

            }
        }

        line_n++;
    }
}