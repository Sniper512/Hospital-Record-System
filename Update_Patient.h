#include <stdio.h>
#include <string.h>
#define size 30

struct client
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};

struct client input_update(struct client patient)
{
    int validation = 1;
    while (validation)
    {
        printf("Enter Patient new id (Any integer): ");
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
        printf("Enter Patient new name (In alphabets): ");
        gets(patient.name);
        spaces(patient.name);
        check = name_checker(patient.name);
        if (check == 0)
        {
            printf("Wrong input of Name. Name can only be a String. Try again\n");
            continue;
        }
        printf("Enter Patient new CNIC number (Format : nnnnn-nnnnnnn-n): ");
        gets(patient.cnic);
        spaces(patient.cnic);
        check = cnic_checker(patient.cnic);
        if (check == 0)
        {
            printf("Wrong input of CNIC. Please follow the format of CNIC. Try again\n");
            continue;
        }
        printf("Enter Patient new Phone number (Format :03*********) (11 digits): ");
        gets(patient.phone);
        spaces(patient.phone);
        check = phoneNumber_checker(patient.phone);
        if (check == 0)
        {
            printf("Wrong input of Phone Number. Phone Number must be of exact 11 digits. Try again\n");
            continue;
        }
        printf("Enter Patient's new disease (String- No digits allowed): ");
        gets(patient.disease);
        spaces(patient.disease);
        check = disease_checker(patient.disease);
        if (check == 0)
        {
            printf("Wrong input of diesease. Disease must be in alphabets.Try again\n");
            continue;
        }
        printf("Enter if patient is admitted (Yes or No only): ");
        gets(patient.isadmitted);
        spaces(patient.isadmitted);
        check = admit_check(patient.isadmitted);
        if (check == 0)
        {
            printf("Wrong input admit check. Answer in Yes or No only.Try again\n");
            continue;
        }
        validation = 0;
    }
    return patient;
}

void updatePatient()
{
    FILE *fp = NULL;
    FILE *ptr = NULL;
    struct client patient;
    struct client update;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        FILE *fp = fopen("Copy.txt", "w");
        char id[size];
        printf("Enter id of the patient you want to update: ");
        gets(id);
        char holder[size];
        int checker = 0;
        while (fread(&patient, sizeof(struct client), 1, ptr))
        {
            if (strcmp(patient.id, id) != 0)
            {
                fwrite(&patient, sizeof(struct client), 1, fp);
            }
            else if (strcmp(patient.id, id) == 0)
            {
                checker = 1;
            }
        }
        if (checker == 0)
        {
            printf("Record not found\n");
        }
        else
        {
            update = input_update(update);
            fwrite(&update, sizeof(struct client), 1, fp);
            fclose(ptr);
            fclose(fp);
            remove("Patient_Records.txt");
            rename("Copy.txt", "Patient_Records.txt");
            printf("Record updated Succssefully.\n");
        }
    }
}