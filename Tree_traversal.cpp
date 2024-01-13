#include <bits/stdc++.h>
using namespace std;

class library {
private:
    struct Node {
        string id;
        string name, author, publisher;
        Node* next;
    };

public:
    Node* head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void Delete();
    void showAll();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void clearList();
};

void library::menu() {
    bool exitMenu = false;
    while (!exitMenu) {
        int choice;
        cout << "\n\n\t\t\t=========================================";
        cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
        cout << "\n\n\t\t\t=========================================";
        cout << "\n\n 1. Insert new Record";
        cout << "\n\n 2. Search Record";
        cout << "\n\n 3. Update Record";
        cout << "\n\n 4. Delete Record";
        cout << "\n\n 5. Show all Record";
        cout << "\n\n 6. Exit";
        cout << "\n\n Enter Your Choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            insert();
            break;

        case 2:
            search();
            break;

        case 3:
            update();
            break;

        case 4:
            Delete();
            break;

        case 5:
            showAll();
            break;

        case 6:
            exitMenu = true;
            break;

        default:
            cout << "\n\n Invalid choice..Please Try Again...";
        };
    }
}

void library::insert() {
    string NewId;
    Node* newNode = new Node();
    cout << "\n\n Book ID : ";
    cin>>NewId;
    if(head!=NULL){
      Node* temp = head;
      while(temp!=NULL){
         if(temp->id == NewId){
            int Newid;
            cout<<"\n Book with this id is Already Exist. Please Enter New Id : ";
            cin>>Newid;
            NewId = Newid;
            temp = head;
         }
         else{
            temp=temp->next;
         }
      }
    }
    newNode->id = NewId;
    cin.ignore();
    cout << "\n Book Name : ";
    getline(cin, newNode->name);
    cout << "\n Author Name : ";
    getline(cin, newNode->author);
    cout << "\n Publisher Name : ";
    getline(cin, newNode->publisher);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        };
        temp->next = newNode;
    }
    cout<<"\n\n\t\t <-Book Added.->";
    saveToFile("library_data.txt");
}

void library::search() {
    string keyword;
    cout << "\n\n Enter Key : ";
    cin >> keyword;
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->id == keyword || temp->name == keyword || temp->author == keyword || temp->publisher == keyword) {
        cout<<"\n\n{"<<++count<<".";
        cout<<"\n   id: "<<temp->id;
        cout<<"\n   Book Name:"<<temp->name;
        cout<<"\n   Author: "<<temp->author;
        cout<<"\n   Publisher: "<<temp->publisher<<"}";
        }
        temp = temp->next;
    }
    if (count == 0) {
        cout <<"\n Not Found!";
    }
}

void library::update() {
    int choice;
    cout << "\n\n Search by - ";
    cout << "\n\t 1. Book id";
    cout << "\n\t 2. Book name";
    cout<<"\n Enter Choice : ";
    cin >> choice;

    string ID;
    string NewName;
    int count=0;
    Node* temp = head;

    switch (choice) {
    case 1:
        cout << "\n\n Enter Book id : ";
        cin >> ID;
        temp = head;
        while (temp != NULL) {
            if (temp->id == ID) {
               ++count;
                string Name, Author, Publisher;
                cout << "\n 1. Change Book name : ";
                cin.ignore();
                getline(cin, Name);
                cout << "\n 2. Change Book author : ";
                getline(cin, Author);
                cout << "\n 3. Change Book publisher : ";
                getline(cin, Publisher);
                if (!Name.empty()) {
                    temp->name = Name;
                }
                if (!Author.empty()) {
                    temp->author = Author;
                }
                if (!Publisher.empty()) {
                    temp->publisher = Publisher;
                }
            }
            temp = temp->next;
        }
        if(count==0){
         cout<<"\n\n Book Not Found!";
        }
        break;

    case 2:
        cout << "\n\n Enter Book name : ";
        getline(cin, NewName);
        temp = head;
        while (temp != NULL) {
            if (temp->name == NewName) {
               ++count;
                string Name, Author, Publisher;
                cout << "\n 1. Change Book name : ";
                cin.ignore();
                getline(cin, Name);
                cout << "\n 2. Change Book author : ";
                getline(cin, Author);
                cout << "\n 3. Change Book publisher : ";
                getline(cin, Publisher);

                if (!Name.empty()) {
                    temp->name = Name;
                }
                if (!Author.empty()) {
                    temp->author = Author;
                }
                if (!Publisher.empty()) {
                    temp->publisher = Publisher;
                }
            cout<<"Updated : "<<temp->id<<", "<<temp->name;
            }
            temp = temp->next;
        }
        if(count==0){
         cout<<"\n\n Book Not Found!";
        }
        break;

    default:
    cout<<"Invalid Choice...Please Try Again...";
        break;
    }
}

void library::Delete(){
   int choice;
    cout << "\n\n Search by - ";
    cout << "\n\t 1. Book id";
    cout << "\n\t 2. Book name";
    cout<<"\n Enter Choice : ";
    cin>>choice;
   
    string ID;
    string Name;
    int count=0;
    Node* temp = head;

    switch(choice){
      case 1:
      cout<<"\n\n Enter Book ID : ";
      cin.ignore();
      cin>>ID;
      temp = head;

      while(temp!=NULL && temp->id == ID){
         ++count;
         head = head->next;
         cout<<"\n\n Deleted : "<<temp->id<<", "<<temp->name;
         temp = temp->next;
      }
      while(temp!=NULL && temp->next!=NULL){
         if(temp->next->id == ID){
            ++count;
            cout<<"\n\n Deleted : "<<temp->next->id<<", "<<temp->next->name;
            temp->next = temp->next->next;
         }
         temp = temp->next;
      }
      if(count==0){
         cout<<"\n\n Book Not Found!";
      }
      break;

      case 2:
      cout<<"\n\n Enter Book Name : ";
      getline(cin,Name);
      temp = head;
      while(temp->name == Name){
         ++count;
         head = head->next;
         cout<<"\n\n Deleted : "<<temp->id<<", "<<temp->name;
         temp = temp->next;
      }
      while(temp!=NULL && temp->next!=NULL){
         if(temp->next->name == Name){
            ++count;
            cout<<"\n\n Deleted : "<<temp->next->id<<", "<<temp->next->name;
            temp->next = temp->next->next;
         }
         temp = temp->next;
      }
      if(count==0){
         cout<<"\n\n Book Not Found!";
      }
      break;
      default:
      cout<<"\n\n Invalid Choice...Please Try Again...";
      break;
    }
}

void library::showAll(){
    cout << "\n\n\t\t\t=========================================";
    cout << "\n\n\t\t\t========LIBRARY MANAGEMENT SYSTEM========";
    cout << "\n\n\t\t\t=========================================";
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
      cout<<"\n\n{"<<++count<<".";
      cout<<"\n   id: "<<temp->id;
      cout<<"\n   Book Name:"<<temp->name;
      cout<<"\n   Author: "<<temp->author;
      cout<<"\n   Publisher: "<<temp->publisher<<"}";

      temp = temp->next;
    }
    if(count==0){
        cout<<"\n\n No Book Added Yet!";
    }
    }

void library::clearList() {
    head = NULL;
}

// Save the linked list data to a file
void library::saveToFile(const string& filename) {
    // Open the file for writing, truncate if it already exists
    ofstream outFile(filename, ios::trunc);

    // Check if the file is successfully opened
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    // Traverse the linked list and write each node's data to the file
    Node* temp = head;
    while (temp != NULL) {
        outFile << temp->id << ',' << temp->name << ',' << temp->author << ',' << temp->publisher << '\n';
        temp = temp->next;
    }

    // Close the file
    outFile.close();
}

// Load data from a file to reconstruct the linked list
void library::loadFromFile(const string& filename) {
    // Open the file for reading
    ifstream inFile(filename);

    // Check if the file is successfully opened
    if (!inFile.is_open()) {
        cout << "File does not exist. Creating a new one.\n";
        return;
    }

    // Clear existing linked list
    clearList();

    // Variables to store node data
    string id;
    string name, author, publisher;
    string line;

    // Read each line from the file
    while (getline(inFile, line)) {
        // Use stringstream to parse the line into individual data components
        istringstream iss(line);

        // Extract data and create a new node
        if (iss >> id >> ws && getline(iss, name, ',') && getline(iss, author, ',') && getline(iss, publisher)) {
            Node* newNode = new Node();
            newNode->id = id;
            newNode->name = name;
            newNode->author = author;
            newNode->publisher = publisher;
            newNode->next = nullptr;

            // Insert the new node into the linked list
            if (head == NULL) {
                head = newNode;
            }
            else {
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    // Close the file
    inFile.close();
}


int main() {
    library obj;
    obj.loadFromFile("library_data.txt");
    obj.menu();
    return 0;
}

