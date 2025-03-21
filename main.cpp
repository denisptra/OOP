#include <iostream>
#include <string>

class Payment
{
protected:
    std::string id;
    double amount;
    std::string date;
    std::string status;

public:
    Payment(std::string id, double amount, std::string date, std::string status)
        : id(id), amount(amount), date(date), status(status) {}

    virtual void processPayment()
    {
        std::cout << "Processing payment of amount: " << amount << std::endl;
    }

    virtual void validatePayment()
    {
        std::cout << "Validating payment with ID: " << id << std::endl;
    }

    virtual void refundPayment()
    {
        std::cout << "Refunding payment with ID: " << id << std::endl;
    }
};

class CreditCardPayment : public Payment
{
private:
    std::string cardNumber;
    std::string expiryDate;
    std::string cvv;

public:
    CreditCardPayment(std::string id, double amount, std::string date, std::string status, std::string cardNumber, std::string expiryDate, std::string cvv)
        : Payment(id, amount, date, status), cardNumber(cardNumber), expiryDate(expiryDate), cvv(cvv) {}

    void processPayment() override
    {
        std::cout << "Processing credit card payment of amount: " << amount << std::endl;
    }

    void validatePayment() override
    {
        std::cout << "Validating credit card payment with card number: " << cardNumber << std::endl;
    }

    void refundPayment() override
    {
        std::cout << "Refunding credit card payment with card number: " << cardNumber << std::endl;
    }
};

class BankTransfer : public Payment
{
private:
    std::string accountNumber;
    std::string bankName;
    std::string transferCode;

public:
    BankTransfer(std::string id, double amount, std::string date, std::string status, std::string accountNumber, std::string bankName, std::string transferCode)
        : Payment(id, amount, date, status), accountNumber(accountNumber), bankName(bankName), transferCode(transferCode) {}

    void processPayment() override
    {
        std::cout << "Processing bank transfer payment of amount: " << amount << std::endl;
    }

    void validatePayment() override
    {
        std::cout << "Validating bank transfer payment with account number: " << accountNumber << std::endl;
    }

    void refundPayment() override
    {
        std::cout << "Refunding bank transfer payment with account number: " << accountNumber << std::endl;
    }
};

class DigitalWallet : public Payment
{
private:
    std::string walletId;
    std::string provider;
    std::string phoneNumber;

public:
    DigitalWallet(std::string id, double amount, std::string date, std::string status, std::string walletId, std::string provider, std::string phoneNumber)
        : Payment(id, amount, date, status), walletId(walletId), provider(provider), phoneNumber(phoneNumber) {}

    void processPayment() override
    {
        std::cout << "Processing digital wallet payment of amount: " << amount << std::endl;
    }

    void validatePayment() override
    {
        std::cout << "Validating digital wallet payment with wallet ID: " << walletId << std::endl;
    }

    void refundPayment() override
    {
        std::cout << "Refunding digital wallet payment with wallet ID: " << walletId << std::endl;
    }
};

int main()
{
    Payment *creditCardPayment = new CreditCardPayment("1", 100.0, "2025-03-19", "Pending", "1234567890123456", "12/25", "123");
    Payment *bankTransfer = new BankTransfer("2", 200.0, "2025-03-19", "Pending", "9876543210", "Bank ABC", "TRF123");
    Payment *digitalWallet = new DigitalWallet("3", 300.0, "2025-03-19", "Pending", "WALLET123", "Provider XYZ", "08123456789");

    creditCardPayment->processPayment();
    creditCardPayment->validatePayment();
    creditCardPayment->refundPayment();

    bankTransfer->processPayment();
    bankTransfer->validatePayment();
    bankTransfer->refundPayment();

    digitalWallet->processPayment();
    digitalWallet->validatePayment();
    digitalWallet->refundPayment();

    delete creditCardPayment;
    delete bankTransfer;
    delete digitalWallet;

    return 0;
}