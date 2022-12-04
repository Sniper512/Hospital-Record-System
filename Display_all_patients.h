#include <stdio.h>
#include <string.h>
#define size 30
extern unsigned int total_record;
struct display
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};

void DisplayPatient()
{
    struct display required;
    FILE *ptr = NULL;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("No Record to display.\n");
    }
    else
    {
        int count = 1;
        int check = 0;
        printf("\nTotal Patient Records: %u\n", total_record);
        printf("All the records of all patients is following: \n");
        while (fread(&required, sizeof(struct display), 1, ptr))
        {
            puts("-------------------------------------------\n");
            printf("The Record of Patient %d is: \n\n", count);
            printf("Patient's ID: %s\n", required.id);
            printf("Patient's Name: %s\n", required.name);
            printf("Patients CNIC: %s\n", required.cnic);
            printf("Patient's Phone number: %s\n", required.phone);
            printf("Patient's disease: %s\n", required.disease);
            printf("Patient is admitted: %s\n", required.isadmitted);
            puts("--------------------------------------------\n");
            count++;
            check = 1;
        }

        fclose(ptr);
        if (check == 0)
        {
            printf("Sorry!, No Records to display.\n");
        }
        else
        {
            printf("Record Displayed Succssefully.\n");
        }
    }
}