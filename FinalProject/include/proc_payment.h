#ifndef PROC_PAYMENT_H
#define PROC_PAYMENT_H
#include"helper_functions.h"
#include"GlobalsAndStructures.h"

typedef struct PaymentData
{
	char cTypeOfLine[TYPE_OF_LINE_MAX_LEN + 1];
	char cExternalReference[EXTERNAL_REF_MAX_LEN + 1];
	char cPaymentDate[DATE_MAX_LEN + 1];
	char cPaymentSum[SUM_MAX_LEN + 1];
	char cPaymentMethod[PAYMENT_METHOD_MAX_LEN + 1];
	char cPaymentCurrency[CURRENCY_MAX_LEN + 1];
}PaymentData;

int isPaymentInfoFormatValid(const char* line);
int doesLineEndWithSemicolon(const char* line);
int isPaymentInfoDataValid(const PaymentData* paymentData);

//PRO*C functions
void sql_insert_row_in_table_payment_by_external_referance(const PaymentData* linePayment, char* inv_number);
int line_processing_payment(const PaymentData* linePayment, FILE*  fp_incorrect_output);





#endif

