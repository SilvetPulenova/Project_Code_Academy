#ifndef PROC_FUNCTIONS_H
#define PROC_FUNCTIONS_H
#include"helper_functions.h"
#include"GlobalsAndStructures.h"


typedef struct CustomerData
{
	char cTypeOfLine[TYPE_OF_LINE_MAX_LEN + 1];
	char cInternalReference[INTERNAL_REF_MAX_LEN + 1];
	char cExternalReference[EXTERNAL_REF_MAX_LEN + 1];
	char cFirstName[FIRST_NAME_MAX_LEN + 1];
	char cLastName[LAST_NAME_MAX_LEN + 1];
	char cGender[GENDER_MAX_LEN + 1];
	char cCity[CITY_MAX_LEN + 1];
	char cCountry[COUNTRY_MAX_LEN + 1];
	char cCustomerLimit[COSTUMER_LIMIT_MAX_LEN + 1];
	char cEmail[EMAIL_MAX_LEN + 1];
}CustomerData;

char* cReadCustomerDataFormFile(FILE* fptr, CustomerData* customer, const char* buffer);
int iIsCustomerInfoFormatValid(const char* cLine);
int iIsCustomerDataValid(const CustomerData* cdptr);
int iIsSecondFiedlEmpty(const char* cLine);

//Pro*C
int sql_find_external_reference(char* ext_ref);
int sql_find_internal_reference(int internal_ref);
int sql_compare_data_customer_in_line_by_internal_referance(const CustomerData* lineCustomer, int internal_ref);
int sql_compare_data_customer_in_line_by_external_referance(const CustomerData* lineCustomer, char* external_ref);
void sql_update_table_customers_by_internal_referance(const CustomerData* lineCustomer, int internal_ref);
void sql_update_table_customers_by_external_referance(const CustomerData* lineCustomer, char* external_ref);
void sql_insert_row_in_table_customers_by_external_referance(const CustomerData* lineCustomer, char* external_ref);

int line_processing_customer(char* buffer, const CustomerData* lineCustomer, FILE*  fp_incorrect_output);


#endif 


