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