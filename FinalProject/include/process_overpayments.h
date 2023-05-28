#ifndef PROCESS_OVERPAYMENTS_H
#define PROCESS_OVERPAYMENTS_H

//#include"helper_functions.h"
  
 
#define LENGTH_DATA 10
#define PAYMENT_METHOD_LENGTH 50
#define CURRENCY_LENGTH 4
typedef struct Str_over_payments {
    
	char m_invoice_no[50];
	char m_payment_id[60];
	char m_payment_dt[LENGTH_DATA];
	double m_amount;
	char m_payment_method[PAYMENT_METHOD_LENGTH];
	char m_currency[CURRENCY_LENGTH];
	char m_origanl_payment_id[60];
	int m_customer_id;
	
}Str_over_payments;

typedef struct S_Invoices
{
   char m_PK_inoice_no[50];
   double m_inv_amount;
   double m_inv_amount_due;
   char m_issue_dt[10];
   char m_due_dt[10];
   int m_inv_customer_id;
   int m_seq;
}S_Invoices;

typedef struct S_Payments
{ 
  char m_p_invoice_no[50];
  char m_p_payment_id[30];
  double m_p_amount;
  
}S_Payments;

  void process_overpayments(char* external_ref);
  void sql_Commit1();
  void insert_payment_by_invoice(Str_over_payments* payment, char* invoice_no);
  void delete_from_overpayment(char* paymentId);
  //char* cTrim(char* cString);
  //int return_customerId(char* external_ref);
  //void sql_error(char* errorMsg);
  //void sql_Connect(const char* pszConnStr);
  int fetch_inv_number_by_customer_id(int my_customer_id, char* invoice_no);

#endif

