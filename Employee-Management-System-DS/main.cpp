#include<bits/stdc++.h>
using namespace std;

struct Employee{
   string name;
   int id;
   double salary;
   string date_of_joining;
   Employee *next;
};
class Employees_Details{
 private:
   Employee *head = NULL;
   int sz;
 public:
   Employees_Details(){
      head = NULL;
      sz = 0;
       }
//Add
void addEmployee(string n, int id, double sl, string dt){
      Employee *new_Employee = new Employee;
      Employee *last = head;
      new_Employee->name = n;
      new_Employee->id = id;
      new_Employee->salary = sl;
      new_Employee->date_of_joining = dt;
   if(head == NULL){
      head = new_Employee;
      new_Employee->next = NULL;
   }
   else{
      while(last->next != NULL){
        last = last->next;
      }
      last->next = new_Employee;
      new_Employee->next = NULL;
   }
   sz++;
   cout<<endl<<"Employee added successfully."<<endl;
}
//Delete
void deleteEmployee(int ID){
 if(head == NULL){
    cout<<endl<<"No employees in the list."<<endl;
    return;
    }
   Employee *current = head;
   Employee *previous = head;
 if(current->id == ID){
    head = current->next;
    delete (current);
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    cout<<"Employee with ID "<<ID<<" deleted successfully."<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    return;
  }
  while(current != NULL && current->id != ID){
    previous = current;
    current = current->next;
  }
 if(current == NULL){
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    cout<<"Employee with ID "<<ID<<" not found."<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
        return;
  }
  previous->next = current->next;
  delete (current);
  sz--;
  cout<<"- - - - - - - - - - - - - - - "<<endl;
  cout<<"Employee with ID "<<ID<<" deleted successfully."<<endl;
  cout<<"- - - - - - - - - - - - - - - "<<endl;
}
//Search with id
void searchEmployee_byId(int ID){
 if(head == NULL){
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    cout<<"No employees in the list."<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    return;
    }
   Employee *current = head;
 while(current != NULL && current->id != ID){
    current = current->next;
  }
  if(current == NULL){
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    cout<<"Employee with ID "<<ID<<" not found."<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
  }
  else{
    cout<<"= = = = = = = = = = = = = = = "<<endl;
    cout<<"Employee found. The Details: "<<endl;
    cout<<"Name: "<<current->name<<"\n"<<"ID: "<<current->id
       <<"\n"<<"Salary: "<<current->salary<<"\n"<<"Date of join: "<<current->date_of_joining<<endl;
    cout<<"= = = = = = = = = = = = = = = "<<endl;
  }

}
//Search with Name
void searchEmployee_byName(string name) {
    if (head == NULL) {
        cout << "- - - - - - - - - - - - - - -" << endl;
        cout << "No employees in the list." << endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
        return;
    }

    Employee* current = head;
    vector<Employee*> foundEmployees;

    while (current != NULL) {
        if (current->name == name) {
            foundEmployees.push_back(current);
        }
        current = current->next;
    }

    if (foundEmployees.empty()) {
        cout << "- - - - - - - - - - - - - - -" << endl;
        cout << "Employee with Name " << name << " not found." << endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
    } else {
        cout << "= = = = = = = = = = = = = = =" << endl;
        cout << "Employees found. The Details: " << endl;
        for (Employee* emp : foundEmployees) {
            cout << "Name: " << emp->name << "\n"
                 << "ID: " << emp->id << "\n"
                 << "Salary: " << emp->salary << "\n"
                 << "Date of join: " << emp->date_of_joining << endl;
            cout << "- - - - - - - - - - - - - - -" << endl;
        }
    }
}
//Update
void updateEmployee(int ID , string n, double sl, string dt){
  Employee *current = head;
 while(current != NULL){
    if(current->id == ID){
      current->name = n;
      current->salary = sl;
      current->date_of_joining = dt;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
    cout<<"Employee details updated successfully."<<endl;
    cout<<"- - - - - - - - - - - - - - - "<<endl;
      return;
    }
    current = current->next;
 }
 cout<<"- - - - - - - - - - - - - - - "<<endl;
 cout<<"Employee with ID "<<ID<<" not found."<<endl;
 cout<<"- - - - - - - - - - - - - - - "<<endl;
}
//Report for Employees with salary in given range
void employees_with_salary_Ingiven_range(double a, double b) {
    if (head == NULL) {
        cout << "- - - - - - - - - - - - - - -" << endl;
        cout << "No employees in the list." << endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
        return;
    }

    Employee* current = head;
    vector<Employee*> Employees_salary;

    while (current != NULL) {
        if (current->salary >= a && current->salary <= b) {
            Employees_salary.push_back(current);
        }
        current = current->next;
    }
    if (Employees_salary.empty()) {
        cout << "- - - - - - - - - - - - - - -" << endl;
        cout << "Employees with Salary in range" << a <<" and "<< b << " not found." << endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
    } else {
        cout << "= = = = = = = = = = = = = = =" << endl;
        cout <<"Employees with Salary in range " << a <<" and "<< b << " are: "<<endl;
        for (Employee* emp : Employees_salary) {
            cout << "Name: " << emp->name << "\n"
                 << "ID: " << emp->id << "\n"
                 << "Salary: " << emp->salary << "\n"
                 << "Date of join: " << emp->date_of_joining << endl;
            cout << "- - - - - - - - - - - - - - -" << endl;
        }
    }
}
//Display
void display(){
   if(head == NULL){
      cout<<"- - - - - - - - - - - - - - - "<<endl;
      cout<<"No employees in the list."<<endl;
      cout<<"- - - - - - - - - - - - - - - "<<endl;
   }
   else{
    Employee *current = head;
      for(int i = 1; i <= sz; i++){
            if(current == NULL){
                break;
            }
       cout<<"= = = = = = = = = = = = = = = "<<endl;
       cout<<"Employee number: "<<i<< ": "<<endl;
       cout<<"Name: "<<current->name<<"\n"<<"ID: "<<current->id
       <<"\n"<<"Salary: "<<current->salary<<"\n"<<"Date of join: "<<current->date_of_joining<<endl;
       current = current->next;
      }
       cout<<"= = = = = = = = = = = = = = = "<<endl;
   }
}
//Sort
void sort_employee(){
    Employee* current = head;
    vector<Employee*>Employees;
    while(current != NULL) {
        Employees.push_back(current);
        current = current->next;
    }
    sort(Employees.begin(), Employees.end(), [](Employee* a, Employee* b) {
            return a->id < b->id;
        });
    if(Employees.empty()) {
        cout << "- - - - - - - - - - - - - - -" << endl;
        cout <<"No employees in the list."<< endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
    } else {
      cout<<"- - - - - - - - - - - - - - - "<<endl;
      cout<<"Employees sorted by ID successfully."<<endl;
      cout<<"- - - - - - - - - - - - - - - "<<endl;

      for(Employee* emp : Employees) {
            cout << "Name: " << emp->name << "\n"
                 << "ID: " << emp->id << "\n"
                 << "Salary: " << emp->salary << "\n"
                 << "Date of join: " << emp->date_of_joining << endl;
            cout << "- - - - - - - - - - - - - - -" << endl;
        }
} }
};
class Admin{
 private:
     Employees_Details& emp;
 public:
     Admin(Employees_Details& emp) : emp(emp) {}

void tasks(){
    int choice;
  do{
    cout << endl;
    cout << "Administrator Mode Menu:" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Update Employee Details" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Search Employee by ID" << endl;
    cout << "5. Search Employee by Name" << endl;
    cout << "6. Display All Employees" << endl;
    cout << "7. Exit Administrator Mode" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch(choice){
    case 1: {
       string name, date_of_joining;
       int id;
       double salary;
       cout << "Enter employee details:" << endl;
       cout << "Name: ";
       cin >> name;
       cout << "ID: ";
       cin >> id;
       cout << "Salary: ";
       cin >> salary;
       cout << "Date of Joining: ";
       cin >> date_of_joining;
       emp.addEmployee(name, id, salary, date_of_joining);
            break; }
    case 2: {
       int id;
       string name, date_of_joining;
       double salary;
       cout << "Enter employee ID to update details: ";
       cin >> id;
       cout << "Enter updated details:" << endl;
       cout << "Name: ";
       cin >> name;
       cout << "Salary: ";
       cin >> salary;
       cout << "Date of Joining: ";
       cin >> date_of_joining;
       emp.updateEmployee(id, name, salary, date_of_joining);
            break; }
    case 3: {
       int id;
       cout << "Enter employee ID to delete: ";
       cin >> id;
       emp.deleteEmployee(id);
            break; }
    case 4: {
       int id;
       cout << "Enter employee ID to search: ";
       cin >> id;
       emp.searchEmployee_byId(id);
       break; }
    case 5: {
       string name;
       cout << "Enter employee name to search: ";
       cin >> name;
       emp.searchEmployee_byName(name);
       break; }
    case 6: {
            emp.display();
            break; }
    case 7: {
       cout << "Exiting Administrator Mode..." << endl << endl;
       break; }
    default: {
       cout << "Invalid choice. Please try again." << endl; }
              } }
  while(choice != 7);
}
};
class GuestMode{
 private:
     Employees_Details& emp;
 public:
     GuestMode(Employees_Details& emp) : emp(emp) {}

void tasks(){
    int choice;
  do{
     cout << endl;
     cout << "Guest Mode Menu:" << endl;
     cout << "1. Search Employee by ID" << endl;
     cout << "2. Search Employee by Name" << endl;
     cout << "3. Report Of All Employees" << endl;
     cout << "4. Report for Employees with salary in given range" <<endl;
     cout << "5. Sort the Employees by ID" << endl;
     cout << "6. Exit Guest Mode" << endl;
     cout << "Enter your choice: ";
     cin >> choice;
     cout << endl;
    switch(choice){
    case 1: {
       int id;
       cout << "Enter employee ID to search: ";
       cin >> id;
       emp.searchEmployee_byId(id);
       break; }
    case 2: {
       string name;
       cout << "Enter employee name to search: ";
       cin >> name;
       emp.searchEmployee_byName(name);
       break; }
    case 3: {
       emp.display();
       break; }
    case 4: {
       int a,b;
       cout << "Enter minimum salary: " << endl;
       cin >> a;
       cout << "Enter maximum salary: " << endl;
       cin >> b;
       emp.employees_with_salary_Ingiven_range(a, b);
       break; }
    case 5: {
        emp.sort_employee();
        break;
              }
    case 6: {
       cout << "Exiting Guest Mode..." << endl;
       break; }
    default: {
       cout << "Invalid choice. Please try again." << endl; }
                  } }
  while(choice != 6);
}
};
int main() {
    Employees_Details emp;
    int mode;
 do {
    cout << "Welcome to Employee Database Management System!" << endl;
    cout << "Select Mode:" << endl;
    cout << "1. Administrator Mode" << endl;
    cout << "2. Guest Mode" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> mode;
    switch (mode) {
        case 1: {
            Admin admin(emp);
            admin.tasks();
            break;
        }
        case 2: {
            GuestMode guest(emp);
            guest.tasks();
            break;
        }
        case 3: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid mode selected. Please try again." << endl;
            break;
        }
    }
} while (mode != 3);

    return 0;
}


