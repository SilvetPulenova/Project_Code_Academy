#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H
#include<stdio.h>

#define BUFSIZE 96


typedef enum
{
  e_file_manager=1,
  e_file_manager_err,
  e_read_lines,
  e_read_lines_err,
  e_report,
  e_report_err,
  e_add_interest,
  e_add_interest_err,
  e_process_overpayments,
  e_process_overpayments_err
}file_name;

inline void log_err(const char* cMessage , file_name file);
inline void log_msg(const char* cMessage , file_name file);

//
char* cTrim(char* cString);
int return_customerId(char* external_ref);
void convert_date(char date_str[], char formatted_date[]); 
void sql_error(char* msg);
void openFile(FILE** fp, char* fileName, char* mode);
char *my_itoa(int num, char *str);
void exec_commit();

void open_log_files();
void close_log_files();

//Validation date
int iConvertDateDayToInt(const char* cInvoiceDate);
int iConvertDateMonthToInt(const char* cInvoiceDate);
int iConvertDateYearToInt(const char* cInvoiceDate);
int isDateDayValid(int iDateDay);
int isDateMonthValid(int iDateMonth);
int isDateYearValid(int iDateYear);
int isDateValid(char* cInvoiceDate);


#endif
