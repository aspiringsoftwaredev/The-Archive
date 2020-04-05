#include <iostream>
#include <iomanip>
#include "Account.h"

int main()
{
    Account A;
    int choice;
    std::cout<<"***Password Keeper***\n";
    while(true)
    {
        std::cout<<"\nSelect one option below: ";
        std::cout<<"\n1. Add a username and its password";
        std::cout<<"\n2. Search a username";
	std::cout<<"\n3. Show all data";
        std::cout<<"\nEnter your choice: ";
        std::cin>>choice;

        switch(choice)
        {
        case 1:
            A.write_rec();
            A.rec_number();
            break;

        case 2:
            A.search_rec();
            break;

	case 3:
	    A.display_all_data();
	    break;

        default:
            return 0;
        }

    }
}
