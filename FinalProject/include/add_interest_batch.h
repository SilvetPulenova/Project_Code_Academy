#ifndef ADD_INTEREST_BATCH_H
#define ADD_INTEREST_BATCH_H
#include<stdio.h>
#include<time.h>

typedef struct Invoices
{
   char m_PK_inoice_no[50];
   double m_inv_amount;
   double m_inv_amount_due;
   char m_issue_dt[11];
   char m_due_dt[11];
   int m_customer_id;
   int m_seq;
   char m_original_invoice_no[60];
}Invoices;

void add_interest(char* external_ref);
void insert_interest_invoice(Invoices* invoice);
void removeSymbol(char* str, char* new_str, char symbol);
void addDays(char m_due_dt[], int daysToAdd);
int sql_fetch_invoice_sequence_by_customer_id(int customer_id);





#endif

