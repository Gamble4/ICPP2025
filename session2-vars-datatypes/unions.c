#include<stdio.h>
#include<complex.h>

union myunion
{
    float f;
    int i;
};

// enums allow us to idnetify strings with certain integers, great for switch statements!
enum state
{
    SOLID = 1, 
    LIQUID = 2,
    GAS = 3
} state, *state_ptr;


#define BARYONS 0
#define DARK_MATTER 1

struct Material
{
    int Z;
    float weight;
    enum state state;
    int matter_type;
};


struct CONFIG
{
    const int resolution;
    const int target_fps;
    const char* config_file;
} CONFIG, *CONFIG_PTR = &CONFIG;
// this makes senses (to me), when you only intend to use this struct ONCE
// and need it for every run of the program 

typedef struct Vec3
{
    double x, y, z;
} Vec3;


int main()
{
    union myunion myU;
    myU.f = 1.0;

    union myunion* ptr_myU = &myU;
    printf("%f \n", ptr_myU->f);

    struct Material mat, *mat_ptr = &mat;

    struct Material iron = {.Z=12, .matter_type=BARYONS, .state=SOLID, .weight=100};
    
    mat_ptr->state = GAS;
    mat_ptr->weight = 10.23;
    mat_ptr->Z = 7;
    mat_ptr->matter_type = BARYONS;

    
    printf("%d \n", mat_ptr->matter_type);

    switch (mat_ptr->matter_type)
    {
        case BARYONS: break;
        case DARK_MATTER: break;
    }
   
    switch (mat_ptr->state) // <- switch wants an integer identifier, enums great !!
    {
        case LIQUID: printf("material is liquid \n"); break;
        case SOLID:  printf("material is solid \n");break;
        case GAS:  printf("material is gaseous \n");break;
    }

    printf("%d \n", iron.state);
    
    myU.f = 1.2;

    struct Vec3 v1 = {1., 2., 3.};
    struct Vec3 v2 = {1., 2., 6.};

    struct Vec3* arr[] = {&v1, &v2};

    int a = 4, *a_ptr = &a;
   

    printf("%f \n", (float) a);
    printf(" 1/4: %f \n",  1 / (float) (*a_ptr));

    #define MYSTR "hello"

    enum state other_state;
    other_state = SOLID;
    
    complex double myc = 1 + I * 3;
    double re = creal(myc);

    printf("%f \n", arr[1]->z);

    return 0;
}
