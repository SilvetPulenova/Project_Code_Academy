CREATE OR REPLACE TRIGGER Trigger_PAYMENTS
AFTER INSERT ON PAYMENTS
FOR EACH ROW
DECLARE
    v_invoice_id VARCHAR2(50);
    v_payment_id VARCHAR2(60);
    v_payment_dt DATE;
    v_payment_amount NUMBER(10,2);
    v_payment_method VARCHAR2(10);
    v_currency VARCHAR2(3);
    v_fg_processed VARCHAR2(1);
    v_iban VARCHAR2(60);
    v_bank_name VARCHAR2(100);
    v_created_by VARCHAR2(50);
    v_free_text VARCHAR2(1000);
    v_invoice_amount NUMBER(10,2);
    v_overpayment NUMBER(10,2);
BEGIN
    v_payment_id := :new.PAYMENT_ID;
    v_invoice_id := :new.INVOICE_NO;
    v_payment_dt := :new.PAYMENT_DT;
    v_payment_method := :new.PAYMENT_METHOD;
    v_currency:= :new.CURRENCY;
    v_fg_processed := :new.FG_PROCESSED;
    v_iban := :new.IBAN;
    v_bank_name := :new.BANK_NAME;
    v_created_by := :new.CREATED_BY;
    v_free_text := :new.FREE_TEXT;
    v_payment_amount := :new.AMOUNT;
    SELECT AMOUNT INTO v_invoice_amount FROM INVOICES WHERE INV_NO = v_invoice_id;
    v_overpayment:=v_payment_amount - v_invoice_amount;
    IF v_overpayment>0 THEN
       INSERT INTO over_payments (invoice_no, payment_id, payment_dt, amount, payment_method, currency, fg_processed, iban,
       bank_name, created_by, free_text, original_payment_id)
        VALUES (NULL, v_payment_id, v_payment_dt, v_overpayment, v_payment_method, v_currency, v_fg_processed, v_iban, v_bank_name,
        v_created_by, v_free_text, v_payment_id);
    ELSE
        UPDATE INVOICES SET AMOUNT_DUE = -v_overpayment WHERE INV_NO = v_invoice_id;
    END IF;
END;
/


