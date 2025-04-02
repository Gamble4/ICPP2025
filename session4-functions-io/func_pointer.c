#include<stdio.h>

int add_one_P(int*);
int add_one(int);

void print_SOLID() {printf("solid \n");}
void print_LIQUID(){printf("liquid \n");}

void (*pS)() = &print_SOLID;
void (*pL)() = &print_LIQUID;


typedef enum State
{
    SOLID,
    LIQUID,
    GAS
} State;


typedef struct Material
{
    const char* name;
    int state;
    void (*print_func)();
}Material;


void print_State(Material *material)
{
    printf("name: %s", material->name);
    material->print_func();
}

int (*add_one_fp)(int) = &add_one;


int main() {
    int x = 1;
    //this is not the function parameter x
    add_one_P(&x);
    add_one_fp(x);
    //pass the value of x as argument
    printf("%d\n", x);
    //x was not modified
    x = add_one_fp(x);
    //modifying x by return assignment
    printf("%d\n", x);

    Material iron = {.name="iron", .state=SOLID, .print_func=pS};
    print_State(&iron);
    
    return 0;
}

int add_one(int x) {
//mandatory function definition
return ++x;
// this is not variable x declared in main()
}

int add_one_P(int *x) {
    //mandatory function definition
    return (*x)++;
    // this is not variable x declared in main()
    }
