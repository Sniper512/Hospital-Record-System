#include <stdio.h>
#include <string.h>
#define size 30

struct record
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};

void searchPatient()
{
    struct record patient;
    struct record required;
    FILE *ptr = NULL;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        char id[size];
        printf("Enter id of the patient you want to search: ");
        scanf("%s", id);

        char holder[size];
        int checker = 0;
        while (fread(&patient, sizeof(struct record), 1, ptr))
        {
            if (strcmp(patient.id, id) == 0)
            {
                required = patient;
                checker = 1;
                break;
            }
        }
        if (checker == 1)
        {
            printf("\n-----------------------------------\n");
            printf("The Record of Patient with id %s is: \n", id);
            printf("Patient's Name: %s\n", required.name);
            printf("Patients CNIC: %s\n", required.cnic);
            printf("Patient's Phone number: %s\n", required.phone);
            printf("Patient's disease: %s\n", required.disease);
            printf("Patient is admitted: %s\n", required.isadmitted);
            fclose(ptr);
            printf("\n-----------------------------------\n");
            printf("Record Searched Succssefully.\n");
        }
        else if(checker==0)
        {
            printf("\nSorry! Record not found.\n");
        }
    }
}