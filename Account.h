#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    char username[50];
    char password[30];

public:
    void read_data();
    void show_data();
    void write_rec();
    void rec_number();
    void search_rec();
};

#endif // ACCOUNT_H
