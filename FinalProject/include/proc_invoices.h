#ifndef PROC_INVOICES_H
#define PROC_INVOICES_H
#include"helper_functions.h"
#include"GlobalsAndStructures.h"

typedef struct InvoiceData
{
	char cTypeOfLine[TYPE_OF_LINE_MAX_LEN + 1];
	char cExternalReference[EXTERNAL_REF_MAX_LEN + 1];
	char cInvoiceDate[DATE_MAX_LEN + 1];
	char cInvoiceSum[SUM_MAX_LEN + 1];
	char cInvoiceCurrency[CURRENCY_MAX_LEN + 1];
}InvoiceData;

int isInvoiceInfoFormatValid(const char* line);
int isInvoiceInfoDataValid(const InvoiceData* invoiceData);

//Pro*C functions
int sql_fetch_invoice_sequence(char* external_ref);
void sql_insert_row_in_table_invoices_by_external_referance(const InvoiceData* lineInvoice);
void fetch_last_invoice_no(char* my_inv_no, int max_seq, int internal_ref);
int line_processing_invoice(const InvoiceData* lineInvoice, FILE* fp_incorrect_output);


#endif
