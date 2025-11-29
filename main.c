#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float basic, hra, da, allowance, deduction, net;
};

void input(struct Employee *e) {
    printf("Enter Employee ID: ");
    scanf("%d", &e->id);

    printf("Enter Name: ");
    scanf("%s", e->name);

    printf("Enter Basic Salary: ");
    scanf("%f", &e->basic);

    e->hra = e->basic * 0.20;
    e->da = e->basic * 0.10;

    printf("Enter Other Allowances: ");
    scanf("%f", &e->allowance);

    printf("Enter Deductions: ");
    scanf("%f", &e->deduction);

    e->net = (e->basic + e->hra + e->da + e->allowance) - e->deduction;
}
void display(struct Employee *e) {
    printf("\n============================\n");
    printf("      SALARY SLIP\n");
    printf("============================\n");
    printf("Employee ID     : %d\n", e->id);
    printf("Name            : %s\n", e->name);
    printf("Basic Salary    : %.2f\n", e->basic);
    printf("HRA (20%%)       : %.2f\n", e->hra);
    printf("DA (10%%)        : %.2f\n", e->da);
    printf("Allowances      : %.2f\n", e->allowance);
    printf("Deductions      : %.2f\n", e->deduction);
    printf("----------------------------\n");
    printf("Net Salary      : %.2f\n", e->net);
    printf("============================\n");
}

void summary(struct Employee *emp, int n) {
    float total_net = 0;

    for (int i = 0; i < n; i++) {
        total_net += emp[i].net;
    }

    printf("\n********** COMPANY PAY SUMMARY **********\n");
    printf("Total Employees Paid : %d\n", n);
    printf("Total Net Payout     : %.2f\n", total_net);
    printf("Average Net Salary   : %.2f\n", total_net / n);
    printf("****************************************\n");
}
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);
        input(&emp[i]);
    }