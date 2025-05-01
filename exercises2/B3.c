#include "B3_header.h"
#include <stdlib.h>
#include <stdio.h>


int check_scanf_success(int scanf_out)
{
    if (!scanf_out) 
    {
        printf("parsing failed, please only enter doubles \n");
        exit(-1);
    }
    return 1;
}

int check_is_pos(int in)
{
    if (in <= 0)
    {
        printf("please enter positive double for the radius\n");
        exit(-1);
    }
    return 1;
}

int shifting_write_ctc_radline(Circle *circle_to_shift, Circle *circle_fixed, FILE *w_stream)
{
    double ctc_tmp = 0, radline_tmp, fprintf_success;
        
    fprintf(w_stream, "# center to center distance | radical line length\n");
    while (ctc_tmp < circle_to_shift->radius + circle_fixed->radius)
    {        
        circle_to_shift->center.x += circle_to_shift->radius * 0.1; // 10% increase every step in x-Direction

        ctc_tmp = circ_center_to_center(circle_to_shift, circle_fixed);
        radline_tmp = circ_radical_line(circle_to_shift, circle_fixed);
        fprintf_success = fprintf(w_stream, "%lf %lf \n", ctc_tmp, radline_tmp);
        if (!fprintf_success)
        {
            printf("error in writing to file in function 'shifting_write_ctc_radline', exiting");
            exit(fprintf_success);
        }

    }
    return fprintf_success;
}


int main()
{    
    double params[6];
    char nr = '1';
    
    for (int i=0; i<6; i++)
    {
        switch (i%3)
        {
            case 0: 
                printf("Please enter Circle%c parameters: \n", nr);
                printf("x%c: ", nr);
                break;
            case 1: printf("y%c: ", nr); break;
            case 2: printf("r%c: ", nr++); break;
        }

        check_scanf_success(scanf("%lf", params+i));
        
        if(i%3 == 2) check_is_pos(params[i]); // check non 0 radii
    }

    Circle c1 = {{.x=params[0], .y=params[1]}, .radius=params[2]};
    Circle c2 = {{.x=params[3], .y=params[4]}, .radius=params[5]};
    
    printf("--- Input Parameters --- \n");
    printf("Circle1: x1: %lf, y1: %lf, radius1: %lf \n", params[0], params[1], params[2]);
    printf("Circle2: x2: %lf, y2: %lf, radius2: %lf \n", params[3], params[4], params[5]);
    
    printf("--- Areas and Perimeters --- \n");
    printf("Area Circle1:      %lf \n", circ_area(&c1));
    printf("Area Circle2:      %lf \n", circ_area(&c2));
    
    printf("Perimeter Circle1: %lf \n", circ_perimeter(&c1));
    printf("Perimeter Circle2: %lf \n", circ_perimeter(&c2));
    
    printf("--- Other --- \n");
    printf("Center to Center distance:     %lf \n", circ_center_to_center(&c1, &c2));
    printf("Number of intersection points: %d  \n", circ_intersec_points(&c1, &c2));
    printf("Length of radical line:        %lf \n", circ_radical_line(&c1, &c2));   

    
    // update center of smaller circle to that of the larger one, also cover same circle


    const char *filename = "B3-data.txt";
    FILE *fp = fopen(filename, "w");
    
    if (c1.radius <= c2.radius)
    {
        // c1 smaller or equal, shifting c1
        c1.center.x = c2.center.x;
        c1.center.y = c2.center.y;
        shifting_write_ctc_radline(&c1, &c2, fp);
    }
    else     
    {
        // c2 smaller, shifting c2
        c2.center.x = c1.center.x;
        c2.center.y = c1.center.y;
        shifting_write_ctc_radline(&c2, &c1, fp);
    }

    printf("successfully written to '%s'", filename);
    fclose(fp);

}
