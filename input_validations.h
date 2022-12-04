#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define size 30
extern unsigned int total_record;
struct valid_struct
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};
void write_total_records()
{
    FILE *fp=NULL;
    fp=fopen("Total_records.txt", "w");
    if(fp==NULL)
    {
        printf("Error in reading file.\n");
    }
    else{
        fprintf(fp,"%u",total_record);
    }
    fclose(fp);
}
void spaces(char array[])
{
    int length = strlen(array);
    for (int i = length + 1; i < 30; i++)
    {
        array[i] =32;
    }
}

int phoneNumber_checker(char array[])
{
    int check = 1;
    if (strlen(array) > 13 || strlen(array) <12)
    {
        return 0;
    }
    for (int i = 0; i < strlen(array) - 1; i++)
    {
        if (i == 0 || i == 1 || i==4)
        {
            if (array[i] != '0' || array[i] != '3' || array[i] != '-');
            {
                check = 0;
            }
        }
        char num = array[i];
        if ((num >= 48 && num <= 57)|| num==45)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
int disease_checker(char array[])
{
    int check=1;
    for(int i=0;i<strlen(array)-1;i++)
    {
        char num= array[i];
        if((num>= 65 && num<=90)||(num>=97 && num<=122) || num==32)
        {
           check=1;
        }
        else{
            check=0;
            break;
        }
    }
    return check;
}
int cnic_checker(char array[])
{
    int check = 1;
    if (strlen(array) > 17)
    {
        return 0;
    }

    for (size_t i = 0; i < strlen(array) - 1; i++)
    {

        if (i == 5 || i == 13)
        {
            if (array[i] != '-') // 34101-3827232-9
            {                    // 012345678912345
                return 0;
            }
        }
        char num = array[i];
        if ((num >= 48 && num <= 57) || num == 45)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
int name_checker(char array[])
{
    int check = 1;
    for (size_t i = 0; i < strlen(array); i++)
    {
        char num = array[i];
        if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122) ||num==32)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
int repeat_check(char id[])
{
    int check = 1;
    struct valid_struct p1;
    FILE *fp = NULL;
    fp = fopen("Patient_Records.txt", "r");
    while (fread(&p1, sizeof(struct valid_struct), 1, fp))
    {
        if (strcmp(p1.id, id) == 0)
        {
            check = 0;
            break;
        }
    }
    fclose(fp);

    return check;
}
int admit_check(char array[])
{
    char str1[]="Yes";
    char str2[]="yes";
    char str3[]="no";
    char str4[]="No";
    if(strcmp(array,str1)==0)
    {
        return 1;
    }
    else if(strcmp(array,str2)==0)
    {
        return 1;
    }
    else if(strcmp(array,str3)==0)
    {
        return 1;
    }
    else if(strcmp(array,str4)==0)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int id_checker(char array[])
{
    int check = 1;
    int repeat = repeat_check(array);
    if (repeat == 0)
    {
        return 2;
    }
    for (size_t i = 0; i < strlen(array); i++)
    {
        char num = array[i];
        if (num >= 48 && num <= 57)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}