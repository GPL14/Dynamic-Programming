#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    FILE* fptr;
    fptr = fopen("A1.1_Students.csv", "r");
    FILE* newf = fopen("CSE22015_OUT1.1.csv","w+");

    if (!fptr)
        printf("File open unsuccessful\n");

    else {
        printf("studentsMarks.csv file created");
        char content[1000];

        int sum = 0, i = 0, col = 0;

        float marks_1[60], marks_2[60], marks_3[60], marks_4[60];
        float pNum[60], Mean_marks[60];

        while (fgets(content, 1000, fptr)) {
            col = 0;
            char* value = strtok(content, ", ");
            while (value) {
                if (col == 1) {
                    sum += atoi(value);
                    marks_1[i] = atoi(value);
                }
                if (col == 2) {
                    sum += atoi(value);
                    marks_2[i] = atoi(value);
                }
                if (col == 3) {
                    sum += atoi(value);
                    marks_3[i] = atoi(value);
                }
                if (col == 4) {
                    sum += atoi(value);
                    marks_4[i] = atoi(value);
                }
                value = strtok(NULL, ", ");
                col++;
            }
            Mean_marks[i] = (float)sum/4;
            sum = 0;
            i++;
        }

        int count = 0;
        fprintf(newf, "S_id, Mean, Percentage, Standard Deviation, Percentile \n");
        count++;

        int a, b, below;
        for(a = 0; a < 60; a++){
            below = 0;
            for(b = 0; b < 60 ; b++){
                if(Mean_marks[b] <= Mean_marks[a])
                    below++;
            }
            pNum[a] = (float)(below * 100) /60;
        }
        float variance[60];
        int k;
        for( k = 0; k < 60; k++){
            variance[k] = 0;
        }
        while (count <= 60) {
            col = 0;

            variance[count - 1] += pow((float)marks_1[count - 1] - Mean_marks[count - 1], 2);
            variance[count - 1] += pow((float)marks_2[count - 1] - Mean_marks[count - 1], 2);
            variance[count - 1] += pow((float)marks_3[count - 1] - Mean_marks[count - 1], 2);
            variance[count - 1] += pow((float)marks_4[count - 1] - Mean_marks[count - 1], 2);
            fprintf(newf, "%d, %f, %f, %f, %f\n", count, Mean_marks[count - 1], Mean_marks[count - 1] * 2, sqrt(variance[count - 1]/4), (float)(pNum[count - 1] ));
            count++;
        }
            count++;
    }
    fclose(fptr);
    fclose(newf);
    return 0;
}
