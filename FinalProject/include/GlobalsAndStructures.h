#ifndef GLOBALSANDSTRUCTURES_H
#define GLOBALSANDSTRUCTURES_H

#define CUSTOMER_TYPE_LINE "01"
#define INVOICE_TYPE_LINE "02"
#define PAYMENT_TYPE_LINE "03"

#define FIELDS_IN_PAYMENT_LINE 5
#define FIELDS_IN_INVOICE_LINE 4
#define MAX_LINE_LENGTH 350

#define TYPE_OF_LINE_MAX_LEN 2
#define INTERNAL_REF_MAX_LEN 20
#define EXTERNAL_REF_MAX_LEN 60
#define FIRST_NAME_MAX_LEN 60
#define LAST_NAME_MAX_LEN 60
#define GENDER_MAX_LEN 1
#define CITY_MAX_LEN 50
#define COUNTRY_MAX_LEN 30
#define COSTUMER_LIMIT_MAX_LEN 10
#define EMAIL_MAX_LEN 50
#define DATE_MAX_LEN 8
#define SUM_MAX_LEN 13
#define CURRENCY_MAX_LEN 3
#define PAYMENT_METHOD_MAX_LEN 10
#define NAME_MAX_LEN 60
#define CUSTOMER_LIMIT_MAX_LEN 10

#define LEN_FILE_NAME 18
#define DATE_SIZE 9
#define TIME_SIZE 7
#define EXTENTION_LEN 5
#define FILE_NAME 100


typedef enum {
	NoEmptyOptionalFields,
	EmptyInternalReference,
	EmptyCity,
	EmptyInternalReferenceAndCity
}OptionalFields;

typedef enum {
	TypeOfLine = 1,
	InternalReference,
	ExternalReference,
	FirstName,
	LastName,
	Gender,
	City,
	Country,
	CustomerLimit,
	Email,
}CustomerDataFields;



#endif
