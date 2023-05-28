#ifndef READLINES_H
#define READLINES_H
#include"proc_customers.h"
#include"proc_invoices.h"
#include"proc_payment.h"
#include<stdio.h>

void readLineCustomer(FILE* fp_input, FILE*  fp_incorrect_output, FILE* fp_correct_output, CustomerData* customer, char* buffer);

void readLineInvoice(FILE* fp_input, FILE*  fp_incorrect_output, FILE* fp_correct_output, InvoiceData* invoice, char* buffer);

void readLinePayment(FILE* fp_input, FILE*  fp_incorrect_output, FILE* fp_correct_output, PaymentData* payment, char* buffer);

void readLines(FILE* fp_input, FILE*  fp_incorrect_output, FILE* fp_correct_output);


#endif

