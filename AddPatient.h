#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define size 30
extern unsigned int total_record;
struct Patient
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};



struct Patient input(struct Patient patient)
{
    int validation = 1;
    while (validation)
    {
        printf("Enter Patient id (Any integer): ");
        gets(patient.id);
        spaces(patient.id);
        int check = id_checker(patient.id);
        if (check == 0)
        {
            printf("Wrong input of ID. ID can only be an integer. Try again\n");
            continue;
        }
        else if (check == 2)
        {
            printf("ID already Exists. Input Record again.\n");
            continue;
        }
        printf("Enter Patient name (In alphabets): ");
        gets(patient.name);
        spaces(patient.name);
        check = name_checker(patient.name);
        if (check == 0)
        {
            printf("Wrong input of Name. Name can only be a String. Try again\n");
            continue;
        }
        printf("Enter Patient cnic (Format : nnnnn-nnnnnnn-n): ");
        gets(patient.cnic);
        spaces(patient.cnic);
        check = cnic_checker(patient.cnic);
        if (check == 0)
        {
            printf("Wrong input of CNIC. Please follow the format of CNIC. Try again\n");
            continue;
        }
        printf("Enter Patient Phone (Format :03**-*******) 11 digits: ");
        gets(patient.phone);
        spaces(patient.phone);
        check = phoneNumber_checker(patient.phone);
        if (check == 0)
        {
            printf("Wrong input of Phone Number. Phone Number must be of exact 11 digits and in correct Format. Try again\n");
            continue;
        }
        printf("Enter Patient's disease (String- No digits allowed): ");
        gets(patient.disease);
        spaces(patient.disease);
        check=disease_checker(patient.disease);
        if (check == 0)
        {
            printf("Wrong input of diesease. Disease must be in alphabets.Try again\n");
            continue;
        }
        printf("Enter if patient is admitted (Yes or No only): ");
        gets(patient.isadmitted);
        spaces(patient.isadmitted);
        check=admit_check(patient.isadmitted);
        if (check == 0)
        {
            printf("Wrong input admit check. Answer in Yes or No only.Try again\n");
            continue;
        }
        validation = 0;
    }
    return patient;
}

void AddPatient()
{
    FILE *ptr = NULL;
    struct Patient patient;
    ptr = fopen("Patient_Records.txt", "a");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        patient = input(patient);
        fwrite(&patient, sizeof(struct Patient), 1, ptr);
        fclose(ptr);
        printf("Patient Record added Successfully.\n");
        total_record++;
        write_total_records();
    }
}