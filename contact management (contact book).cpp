#include <iostream>
#include <cstring>
using namespace std;

class Contact
{
public:
    string name;
    string phone_number;
    Contact *next;
    Contact *prev;
    Contact()
    {
        name = "";
        phone_number = "";
        next = NULL;
        prev = NULL;
    }
    Contact(string p, string n)
    {
        name = n;
        phone_number = p;
        next = NULL;
        prev = NULL;
    }
};
class ContactBook
{
public:
    Contact *head;
    ContactBook()
    {
        head = NULL;
    }
    ContactBook(Contact *n)
    {
        head = NULL;
    }
    Contact *ContactExists(string n)
    {
        Contact *temp = NULL;
        Contact *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->name == n)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }
    void InsertContact(Contact *c)
    {
        if (ContactExists(c->name) != NULL)
        {
            cout << "Contact Already exists with name : " << c->name << ". Append another Contact with different Key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = c;
                cout << "Contact Appended as Head Contact" << endl;
            }
            else
            {
                Contact *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = c;
                c->prev = ptr;
                cout << "Contact Appended" << endl;
            }
        }
    }
    void prependContact(Contact *c)
    {
        if (ContactExists(c->name) != NULL)
        {
            cout << "Contact Already exists with name : " << c->name << ". Append another Contact with different name" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = c;
                cout << "Contact Prepended as Head Contact" << endl;
            }
            else
            {
                head->prev = c;
                c->next = head;
                head = c;
                cout << "Contact Prepended" << endl;
            }
        }
    }
    void DeleteContact(string n)
    {
        Contact *ptr = ContactExists(n);
        if (ptr == NULL)
        {
            cout << "No Contact exists wih name : " << n << endl;
        }
        else
        {

            if (head->name == n)
            {
                head = head->next;
                cout << "Contact UNLINKED with name : " << n << endl;
            }
            else
            {
                Contact *nextContact = ptr->next;
                Contact *prevContact = ptr->prev;
                // deleting at the end
                if (nextContact == NULL)
                {

                    prevContact->next = NULL;
                    cout << "Contact Deleted at the END" << endl;
                }

                // deleting in between
                else
                {
                    prevContact->next = nextContact;
                    nextContact->prev = prevContact;
                    cout << "Contact Deleted in Between" << endl;
                }
            }
        }
    }
    void updateContactByName(string n, string p)
    {

        Contact *ptr = ContactExists(n);
        if (ptr != NULL)
        {
            ptr->name = n;
            ptr->phone_number = p;
            cout << "Contact Updated Successfully" << endl;
        }
        else
        {
            cout << "Contact Doesn't exist with name : " << n << endl;
        }
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Contacts in Doubly Linked List";
        }
        else
        {
            cout << endl
                 << "CONTACT BOOK\n"
                 << endl;
            Contact *temp = head;
            Contact *temp2;
            string var, c_name;

            while (temp->next != NULL)
            {
                temp2 = temp->next;
                while (temp2 != NULL)
                {
                    if (temp->name > temp2->name)
                    {
                        c_name = temp->name;
                        temp->name = temp2->name;
                        temp2->name = c_name;

                        var = temp->phone_number;
                        temp->phone_number = temp2->phone_number;
                        temp2->phone_number = var;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }

            Contact *temp3 = head;
            while (temp3 != NULL)
            {
                cout << "Name : " << temp3->name << endl;
                cout << "Phone number : " << temp3->phone_number << endl;
                cout << endl;
                temp3 = temp3->next;
            }
        }
    }
};

int main()
{
    ContactBook d;
    int option;
    string Name, PhoneNumber;

    while (true)
    {
        cout << "enter option" << endl;
        cout << "enter 1 to add contact " << endl;
        cout << "enter 2 to prepend contact " << endl;
        cout << "enter 3 to delete contact " << endl;
        cout << "enter 4 to update contact " << endl;
        cout << "enter 5 to print contact " << endl;
        cout << "enter 0 to exit" << endl;
        cin >> option;
        Contact *n1 = new Contact();
        if (option == 1)
        {
            cout << "Enter name : " << endl;
            cin >> Name;
            cout << "Enter phone number : " << endl;
            cin >> PhoneNumber;
            n1->name = Name;
            n1->phone_number = PhoneNumber;
            d.InsertContact(n1);
        }
        if (option == 2)
        {
            cout<<"enter name: "<<endl;
            cin>>Name;
            cout<<"enter phone no: "<<endl;
            cin>>PhoneNumber;
            n1->name=Name;
            n1->phone_number=PhoneNumber;
            d.prependContact(n1);
            
        }
        if (option == 3)
        {
            cout<<"enter name: "<<endl;
            cin>>Name;
            n1->name=Name;
            d.DeleteContact(n1->name);
        }
        if (option == 4)
        {
            cout<<"enter name: "<<endl;
            cin>>Name;
            cout<<"phone number: "<<endl;
            cin>>PhoneNumber;
            n1->name=Name;
            n1->phone_number=PhoneNumber;
            d.updateContactByName(n1->name, n1->phone_number);
        }
        if (option == 5)
        {
            d.printList();
        }
        if (option == 0)
        {
            break;
        }
    }

    return 0;
}