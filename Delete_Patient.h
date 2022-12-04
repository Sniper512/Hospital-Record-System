#include <stdio.h>
#include <string.h>
#define size 30
extern unsigned int total_record;
struct person
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};
void DeletePatient()
{
    FILE *fp = NULL;
    FILE *ptr = NULL;
    int check = 0;
    struct person patient;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        fp = fopen("Copyfile.txt", "a+");
        if (fp == NULL)
        {
            printf("Could not open file.");
        }
        else
        {
            char id[size];
            printf("Enter Patient id: ");
            scanf("%s", id);
            char holder[size];
            while (fread(&patient, sizeof(struct person), 1, ptr))
            {
                if (strcmp(patient.id, id) != 0)
                {
                    fwrite(&patient, sizeof(struct person), 1, fp);
                }
                else if (strcmp(patient.id, id) == 0)
                {
                    check = 1;
                }
            }
        }

        fclose(ptr);
        fclose(fp);
        if (check == 0)
        {
            printf("Record Does Not Exist.\n");
        }
        else
        {
            remove("Patient_Records.txt");
            rename("Copyfile.txt", "Patient_Records.txt");
            printf("Deletion Done Succssefully.\n");
            total_record--;
            write_total_records();
        }
    }
}