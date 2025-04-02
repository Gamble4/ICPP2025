#include <stdio.h>
int main1() {
char filename[129];
float index, value, values[3] = {2, 3, 4};
printf("Enter a file name: ");
scanf( "%128[^\n]c", filename);
FILE* fp = fopen(filename, "w");
for (int i = 0; i < 3; i++) {
fprintf(fp, "%f %f\n", (float)(i + 1), values[i]);
}
fclose(fp);
fp = fopen(filename, "r");
int i = 0;
printf("File contents:\n");
while (!feof(fp)){
fscanf(fp, "%f %f", &index, &value);
if (feof(fp)) break;
printf("%f %f\n", index, value);
}
return 0;
}

int main() {
    float values[3];
    for (int i = 0; i < 3; i++) {
    printf("Enter value %d out of 3: ", i + 1);
    scanf("%f", values+i);
    }
    printf("The sum is: %f\n", values[0] + values[1] + values[2]);
    return 0;
    }