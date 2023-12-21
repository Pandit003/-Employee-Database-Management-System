#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void delete();
void menu();
FILE *fp;
struct date
{
    int day, month, year;
};
struct employee
{
    char name[20];
    int age;
    int emp_id;
    float salary;
    struct date dob;
    struct date joining;
} e, check;
 int wait()
{
    int i, j;
    for (i = 0; i <= 10; i++)
    {
        for (j = 0; j <= 100000000; j++)
        {
            if (j == 100000000)
            {
                printf("-");
            }
        }
    }
}
void ask()
{
    int a;
    printf("\nenter 1 for menu and 0 for exit=");
    scanf("%d", &a);
    if (a == 1)
    {
        menu();
    }
}
void info()
{
    int d;
    char another = 'y';
    fp = fopen("emp.dat", "a+");
    while (another == 'y')
    {
    name:
        printf("\nenter your name=");
        scanf("%s", &e.name);
        // scanf("%[^\n]",&e.name);
        fflush(stdin);
    emp_id:
        printf("\nenter your 5 dig emp_id=");
        scanf("%d", &check.emp_id);
        if (check.emp_id<9999 || check.emp_id>99999)
        {
            printf("\nenter the valid emp_id....");
            goto emp_id;
        } 
        while (fscanf(fp, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, &e.emp_id, &e.age, &e.dob.day, &e.dob.month, &e.dob.year, &e.joining.day, &e.joining.month, &e.joining.year, &e.salary) != EOF)
        {
            if (check.emp_id == e.emp_id)
            {
                printf("\nEmployee already exist");
                goto name;
            }
        }
        e.emp_id = check.emp_id;
        printf("\nenter your age=");
        scanf("%d", &e.age);
        printf("\nenter the date of birth(dd/mm/yyyy)=");
        scanf("%d/%d/%d", &e.dob.day, &e.dob.month, &e.dob.year);
        printf("\nenter the joining date(dd/mm/yyyy)=");
        scanf("%d/%d/%d", &e.joining.day, &e.joining.month, &e.joining.year);
        printf("\nenter your salary=");
        scanf("%f", &e.salary);
        fprintf(fp, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, e.emp_id, e.age, e.dob.day, e.dob.month, e.dob.year, e.joining.day, e.joining.month, e.joining.year, e.salary);
        fputs("\n", fp);
        printf("\nData recorded");
        wait();
        printf("\nwant to add another record then press y or n=");
        fflush(stdin);
        scanf("%c", &another);
    }
    fclose(fp);
    ask();
}
void show()
{
    int test = 0;
    fp = fopen("emp.dat", "r");
    while (fscanf(fp, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, &e.emp_id, &e.age, &e.dob.day, &e.dob.month, &e.dob.year, &e.joining.day, &e.joining.month, &e.joining.year, &e.salary) != EOF)
    {
        printf("%s   %d   %d   %d/%d/%d   %d/%d/%d   %f\n", e.name, e.emp_id, e.age, e.dob.day, e.dob.month, e.dob.year, e.joining.day, e.joining.month, e.joining.year, e.salary);
        test++;
    }
    if (test == 0)
    {
        printf("\nFile is empty");
    }

    fclose(fp);
    ask();
}
void modify()
{
    FILE *fp, *ft;
    fp = fopen("emp.dat", "r");
    ft = fopen("new.dat", "a+");
    printf("\nenter your emp_id=");
    scanf("%d", &check.emp_id);
    while (fscanf(fp, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, &e.emp_id, &e.age, &e.dob.day, &e.dob.month, &e.dob.year, &e.joining.day, &e.joining.month, &e.joining.year, &e.salary) != EOF)
    {
        if (check.emp_id == e.emp_id)
        {
            printf("\nenter your updated name=");
            scanf("%s", e.name);
        emp_id:
            printf("\nenter your 5 dig emp_id=");
            scanf("%d", &e.emp_id);
            if ((int)(log10(e.emp_id) + 1) != 5)
            {
                printf("\nenter the valid emp_id....");
                goto emp_id;
            }
            printf("\nenter your age=");
            scanf("%d", &e.age);
            printf("\nenter the date of birth(dd/mm/yyyy)=");
            scanf("%d/%d/%d", &e.dob.day, &e.dob.month, &e.dob.year);
            printf("\nenter the joining date(dd/mm/yyyy)=");
            scanf("%d/%d/%d", &e.joining.day, &e.joining.month, &e.joining.year);
            printf("\nenter your salary=");
            scanf("%f", &e.salary);
            fprintf(ft, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, e.emp_id, e.age, e.dob.day, e.dob.month, e.dob.year, e.joining.day, e.joining.month, e.joining.year, e.salary);
            fputs("\n", fp);
            printf("\nData recorded");
            wait();
        }
        else
            fprintf(ft, "%s   %d   %d   %d/%d/%d   %d/%d/%d   %f", e.name, e.emp_id, e.age, e.dob.day, e.dob.month, e.dob.year, e.joining.day, e.joining.month, e.joining.year, e.salary);
    }
    fclose(fp);
    fclose(ft);
    remove("emp.dat");
    rename("new.dat", "emp.dat");
    ask();
}
void menu()
{
    int a, b;
    printf("\n1: Enter employee info\n2: Modify existing record\n3: Show record\n4: Delete \n5: Exit \n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        info();
        break;
    case 2:
        modify();
        break;
    case 3:
        show();
        break;
    case 4:
        delete ();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("\nenter the valid choice");
        printf("\nenter 1 for menu and 0 for exit=");
        scanf("%d", &b);
        if (b == 1)
        {
            menu();
        }
        break;
    }
}
void delete()
{
    int pwd;
    // remove("emp.dat");
    // main();
    // ask();
    printf("\nenter the password=");
    scanf("%d", &pwd);
    if (pwd == 123)
    {
        remove("emp.dat");
        printf("record deleted");
    }
    else
    {
        printf("\nincorrect passowrd.....");
        menu();
    }
}
int main()
{
    int pwd, c;
    printf("\nenter the password=");
    scanf("%d", &pwd);
    if (pwd == 123)
    {
        menu();
    }
    else
    {
        printf("\nincorrect passowrd.....");
    }
    printf("\nenter 1 for menu and 0 for exit=");
    scanf("%d", &c);
    if (c == 1)
    {
        main();
    }
    return 0;
}
