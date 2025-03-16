#ifndef MY_TOOLS_IMPLEMENTATION

#define MY_ERROR(message) \
        {printf("Error: %s\n in file %s at line %d\n", message, __FILE__, __LINE__);\
         exit(-1);}

#endif // MY_TOOLS_IMPLEMENTATION