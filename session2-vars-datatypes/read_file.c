#include <stdio.h>

enum myenum
{
    SIZE = 7
};

struct Datatable
{
    const char* path_datafile;
    float vals[SIZE];

} DATAFILE, *DATAFILE_ptr = &DATAFILE;

int main(int argc, char* argv[])
{
    // 0th argument of argv is the name of the executable itself
    for (int i=0; i<argc; i++)
    {
        printf("%s \n", argv[i]);
    }

    if (argv[1] == NULL)
    {
        printf("no arguements provided, returning -1 \n");
        return -1;
    }
    
    
    FILE* datafile = fopen(DATAFILE_ptr->path_datafile, "rb");
    const size_t ret_code = fread(DATAFILE_ptr->vals, sizeof(DATAFILE_ptr->vals[0]), SIZE, datafile);

    if (ret_code == SIZE)
    {
        printf("Array at %p read successfully, contents:\n", (void*)&DATAFILE_ptr->vals);
        for (int n = 0; n != SIZE; ++n)
            printf("%f ", DATAFILE_ptr->vals[n]);
        putchar('\n');
    }
    else // error handling
    {
        if (feof(datafile))
            printf("Error reading %s: unexpected end of file\n", argv[1]);
        else if (ferror(datafile))
            printf("Error reading %s", argv[1]);
    }
 
    fclose(datafile);
}
