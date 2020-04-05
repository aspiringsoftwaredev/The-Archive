#include "Account.h"
#include <bits/stdc++.h>
#include <iomanip>

using std::cout;
using std::cin;

void Account::read_data()
{
    cout<<"\nEnter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
}

void Account::rec_number()
{
    std::ifstream infile;
    infile.open("records.passrec", std::ios::binary);
    if(!infile)
    {
        std::cout<<"\nError in opening. File not found!\n";
        return;
    }
    infile.seekg(0, std::ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n***PLEASE REMEMBER OR TAKE NOTE OF YOUR RECORD NUMBER FOR SEARCHING PURPOSES.***\n"
    <<"YOUR RECORD NUMBER IS: "<<count<<"\n";
}

void Account::show_data()
{
    cout<<"--------------------------------\n";
    cout<<"Username: "<<username<<"\n";
    cout<<"Password: "<<password<<"\n";
    cout<<"--------------------------------\n";
}

void Account::write_rec()
{
    std::ofstream outfile;
    outfile.open("records.passrec", std::ios::binary|std::ios::app);
    read_data();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

void Account::search_rec()
{
    int n;
    std::ifstream infile;
    infile.open("records.passrec", std::ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening. File not found!\n";
        return;
    }
    infile.seekg(0, std::ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file.\n";
    cout<<"\n Enter record number to search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}

void Account::display_all_data()
{
	std::ifstream infile;
	infile.open("records.passrec", std::ios::binary);
	if(!infile)
	{
		cout << "\nError in opening. FIle not found!\n";
		return;
	}
	infile.seekg(0, std::ios::end);
	int count = infile.tellg()/sizeof(*this);
	for (int datum = 0; datum < count; datum++)
	{
		infile.seekg((datum)*sizeof(*this));
		infile.read(reinterpret_cast<char*>(this), sizeof(*this));
		show_data();
	}
}
