#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define GRADE 3
#define HEAD 30

void err_print(char err[]);
void line_cut();

void err_print(char err[])
{
   printf("\n오류 message: %s\n", err);
   line_cut();
}

void line_cut()
{
   printf("-------------------------\n");
}
