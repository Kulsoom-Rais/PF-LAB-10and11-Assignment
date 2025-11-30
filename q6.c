#include <stdio.h>
#include <string.h>

struct Salary {
    float basicPay;
    float bonuses;
    float deductions;
};

struct Employee {
    int id;
    char name[50];
    struct Salary salary;
};

float calculateNetSalary(struct Employee emp);
void displayEmployee(struct Employee emp);

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); 

    struct Employee employees[n];

  int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &employees[i].id);
        getchar();

        printf("Enter Name: ");
        fgets(employees[i].name, 50, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Enter Basic Pay: ");
        scanf("%f", &employees[i].salary.basicPay);

        printf("Enter Bonuses: ");
        scanf("%f", &employees[i].salary.bonuses);

        printf("Enter Deductions: ");
        scanf("%f", &employees[i].salary.deductions);
        getchar(); 
    }


    printf("\n===== Employee Salary Details =====\n");
 
    for (i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }

    return 0;
}


float calculateNetSalary(struct Employee emp) {
    return emp.salary.basicPay + emp.salary.bonuses - emp.salary.deductions;
}


void displayEmployee(struct Employee emp) {
    printf("\nEmployee ID   : %d\n", emp.id);
    printf("Name          : %s\n", emp.name);
    printf("Basic Pay     : %.2f\n", emp.salary.basicPay);
    printf("Bonuses       : %.2f\n", emp.salary.bonuses);
    printf("Deductions    : %.2f\n", emp.salary.deductions);
    printf("Net Salary    : %.2f\n", calculateNetSalary(emp));
    printf("-------------------------------\n");
}

