create or replace PROCEDURE update_invoice_due_date
IS v_credit_limit NUMBER;
BEGIN
   FOR inv_cust IN(
  SELECT  i.issue_date, i.due_date, c.credit_limit, i.inv_no
  FROM invoices i
  INNER JOIN customers c 
  ON i.customer_id = c.customer_id 
  WHERE i.due_date IS NULL
 ) LOOP
IF inv_cust.credit_limit < 5000 
 THEN
 inv_cust.due_date := inv_cust.issue_date + 10;
 UPDATE invoices SET due_date = inv_cust.due_date 
 WHERE inv_no = inv_cust.inv_no;
ELSIF inv_cust.credit_limit >= 5000 AND inv_cust.credit_limit <= 8000
 THEN
 inv_cust.due_date := inv_cust.issue_date + 15;
 UPDATE invoices SET due_date = inv_cust.due_date 
 WHERE inv_no = inv_cust.inv_no;
ELSE
 inv_cust.due_date := inv_cust.issue_date + 20;
 UPDATE invoices SET due_date = inv_cust.due_date 
 WHERE inv_no = inv_cust.inv_no;
 END IF;
END LOOP;
-- COMMIT;
 END;