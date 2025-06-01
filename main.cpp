#include <iostream>
#include <string>
using namespace std;

class Data {
public:
    string name, address, disease, gender, description;
    int specialRoomNo, age;
};

class Node {
public:
    Data data;
    Node* next;
};


Node* insertFront(Node* head, Data data)
{
    Node* temp = new Node;
    temp->data = data;

    temp->next = head;
    head = temp;
    return head;

}//end of insertFront Function

//============================================

Node* append(Node* head, Data data) {

    Node* temp = new Node;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    Node* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;

    clog << "Append completed" << endl;

    return head;

}//end of append function


//========================================


void changeNode(Node* head, Data data, Data newData)
{
    while (head != NULL)
    {
        if (head->data.name == data.name)
        {
            head->data = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function


void changeNode(Node* head, string data, string newData)
{
    while (head != NULL)
    {
        if (head->data.name == data)
        {
            head->data.name = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function



//=======================================


void printLinkedList(Node* head)
{
    if (head == NULL)
    {
        cout << "Head is null" << endl;
        return;
    }

    while (head->next != NULL)
    {
        cout << "Name: " << head->data.name << ", Address: " << head->data.address
             << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
             << ", Description: " << head->data.description << ", Age: " << head->data.age
             << ", Specialist No: " << head->data.specialRoomNo << endl;
        head = head->next;
    }
    cout << "Name: " << head->data.name << ", Address: " << head->data.address
         << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
         << ", Description: " << head->data.description << ", Age: " << head->data.age
         << ", Specialist No: " << head->data.specialRoomNo << endl;

}//end of printLinkedList function

//========================================



int listLength(Node* head) {
    int temp = 0;

    if (head == NULL)
    {
        cout << "Node is empty" << endl;
        return 0;
    }

    while (head->next != NULL)
    {
        ++temp;
        head = head->next;
    }

    return temp + 1;
}//end of the listLength function

//============================================


void delElement(Node* head, int loc)
{
    Node* temp = new Node;

    temp = head;

    if (head == NULL) {

        cout << "Nod is null" << endl;
        return;
    }


    for (int i = 1; i <= loc; ++i)
    {
        temp = temp->next;
        if (i < loc) {
            head = head->next;
        }//end of if statement

    }//end of for statement

    head->next = temp->next;

}//end of delElement function

//===========================================


Node* searchList(Node* head, string p) {

    if (head == NULL)
    {
        cout << "Node is empty returning null" << endl;
        return NULL;
    }

    int pos = 1;

    while (head->next != NULL && head->data.name != p)
    {
        head = head->next;
        ++pos;
    }

    cout << "Element found at location " << pos << endl;

    return head;

}//end of searchList function





//=======================================================================


Data inputPatients()
{
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;

    cout << "Enter Patient Name: ";
    cin.ignore();//clearing buffer
    getline(cin, name);

    cout << "Enter Patient Address: ";
    getline(cin, address);

    cout << "Enter Patient Disease: ";
    getline(cin, disease);

    cout << "Enter Patient Gender: ";
    getline(cin, gender);

    cout << "Enter Disease Description: ";
    getline(cin, description);

    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;

    cout << "Enter Patient Age: ";
    cin >> age;

    p.name = name;
    p.address = address;
    p.gender = gender;
    p.description = description;
    p.specialRoomNo = specialRoomNo;
    p.age = age;

    clog << "Completed input operation" << endl;

    return p;

}//end of inputPatients function

//============================================================================






int main()
{

    Node* head = NULL;
    Data patient;
    string nameToSearch;
    string oldName, newName;

    int op;

    cout << "\nCTRL + Z-To exit\n1-Add Patient\n2-Delete Patient\n3-Search by Name\n4-List Length"
         << "\n5-print List\n6-Change Patient Name\n7-Insert new at front" << endl;
    while (cin >> op)
    {

        switch (op) {
            case 1:
                cout << "Enter Patient Details Below" << endl;
                patient = inputPatients();
                head = append(head, patient);
                break;

            case 2:

                if (listLength(head) < 2)
                {
                    cout << "Length is less then two.\nTerminating program" << endl;
                    exit(1);
                }
                else {
                    cout << "Enter location where you want to delete a patient, at least three patients must be in list? ";
                    int l;
                    cin >> l;
                    delElement(head, l - 1);
                }//end of else of case 2
                break;

            case 3:
                cout << "Enter name to search patient: ";
                cin.ignore();
                getline(cin, nameToSearch);
                searchList(head, nameToSearch);
                break;

            case 4:

                cout << "You have " << listLength(head) << " Patients in your Hospital." << endl;

                break;

            case 5:
                printLinkedList(head);
                break;

            case 6:
                cin.ignore();
                cout << "Enter old name ";
                getline(cin, oldName);
                cout << "Enter New Name ";
                getline(cin, newName);

                changeNode(head, oldName, newName);
                break;

            case 7:
                patient = inputPatients();
                head = insertFront(head, patient);
                break;

            default:
                cout << "Wrong option Selected" << endl;
        }

        cout << "CTRL + Z-To exit\n1-Add Patient\n2-Del Patient\n3-Search by Name\n4-List Length"
             << "\n5-print List\n6-Change Patient Name\n7-Insert new at front" << endl;
    }

}