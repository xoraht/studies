#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct date {
    int year;
    int month;
    int day;
};

struct location {
    string streetName;
    string streetNumber;
    string city;
    string postalCode;
};

struct student {
    string name;
    string surname;
    string idCardNumber;
    date birthDate;
    location address;
};

date readDateFromUser();
location readLocationFromUser();
student readStudentFromUser();
void printDate(const date& d);
void printLocation(const location& loc);
void printStudentDetails(const student& s);
void appendDateToFile(const date& d, const string& filename);
void appendLocationToFile(const location& l, const string& filename);
void appendStudentToFile(const student& s, const string& filename);
int compareDates(const date& d1, const date& d2);
int loadStudentsFromFile(student students[], const string& filename);
void sortStudentsByField(student students[], int count, const string& field);
void printStudentsFromCity(student students[], int count, const string& city);

int main()
{
    //Zadanie_1//readDateFromUser();
    
    //Zadanie_2//readLocationFromUser();
    
    //Zadanie_3//readStudentFromUser();
    
    //Zadanie_4//printDate({2001, 03, 04});
    
    //Zadanie_5//printLocation({"Bydgoska", "102a", "Torun", "87-100"});
    
    //Zadanie_6//printStudentDetails({"Tomasz", "Wronkowski", "ABC123", {2001, 03, 04}, {"Bydgoska", "102a", "Torun", "87-100"}});
    
    //Zadanie_7//appendDateToFile({2001, 03, 04}, "plik.txt");
    
    //Zadanie_8//appendLocationToFile({"Bydgoska", "102a", "Torun", "87-100"}, "plik.txt");
    
    //Zadanie_9//appendStudentToFile({"Tomasz", "Wronkowski", "ABC123", {2001, 03, 04}, {"Bydgoska", "102a", "Torun", "87-100"}}, "plik.txt");
    
    //Zadanie_10//cout << compareDates({2001, 03, 04}, {2001, 10, 01});
    
    //Zadanie_11+
    //(ex. plik.txt) => Jan Kowalski ABC123456 15 5 2000 Kwiatowa 10 Warszawa 00-001
    /*student students[] = {
        {"Jan", "Kowalski", "ABC123456", {2000, 5, 15}, {"Kwiatowa", "10", "Warszawa", "00-001"}},
        {"Anna", "Nowak", "DEF654321", {1998, 10, 10}, {"Rozana", "5", "Krakow", "30-002"}},
        {"Piotr", "Zielinski", "GHI789012", {1999, 3, 20}, {"Lipowa", "7", "Torun", "50-003"}},
        {"Katarzyna", "Wisniewska", "JKL345678", {1997, 7, 25}, {"Dluga", "12", "Poznan", "60-004"}},
        {"Michal", "Wojcik", "MNO901234", {2001, 1, 5}, {"Krotka", "3", "Gdansk", "80-005"}},
        {"Agnieszka", "Kowalczyk", "PQR567890", {2002, 6, 30}, {"Lesna", "18", "Warszawa", "00-006"}},
        {"Tomasz", "Kaminski", "STU123890", {1996, 12, 15}, {"Polna", "25", "Krakow", "30-007"}},
        {"Joanna", "Lewandowska", "VWX345012", {2000, 9, 10}, {"Sloneczna", "8", "Torun", "50-008"}},
        {"Pawel", "Zielinski", "YZA678345", {1995, 3, 22}, {"Zielona", "14", "Poznan", "60-009"}},
        {"Ewa", "Kozlowska", "BCD901234", {1999, 11, 5}, {"Cicha", "22", "Gdansk", "80-010"}}
    };/
    
    //Zadanie_11//student students[100]; cout << loadStudentsFromFile(students, "plik.txt");
    
    //Zadanie_12
    /*sortStudentsByField(students, sizeof(students) / sizeof(students[0]), "name");
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        cout << students[i].name << " " << students[i].surname << endl;
    }*/
    
    //Zadanie_13//printStudentsFromCity(students, sizeof(students) / sizeof(students[0]), "Torun");
    return 0;
}

date readDateFromUser() {
    date userDate;
    char dash;
    cout << "Podaj datę w formacie DD-MM-RRRR: ";
    cin >> userDate.day >> dash >> userDate.month >> dash >> userDate.year;
    return userDate;
}

location readLocationFromUser() {
    location userLocation;
    cout << "Podaj nazwę ulicy: ";
    cin >> userLocation.streetName;
    cout << "Podaj numer ulicy: ";
    cin >> userLocation.streetNumber;
    cout << "Podaj miasto: ";
    cin >> userLocation.city;
    cout << "Podaj kod pocztowy: ";
    cin >> userLocation.postalCode;
    return userLocation;
}

student readStudentFromUser() {
    student userStudent;
    cout << "Podaj imie: ";
    cin >> userStudent.name;
    cout << "Podaj nazwisko: ";
    cin >> userStudent.surname;
    cout << "Podaj numer dowodu osobistego: ";
    cin >> userStudent.idCardNumber;
    cout << "Podaj date urodzenia:" << endl;
    userStudent.birthDate = readDateFromUser();
    cout << "Podaj adres:" << endl;
    userStudent.address = readLocationFromUser();
    return userStudent;
}

void printDate(const date& d) {
    cout << "Data urodzenia: " << d.day << "-" << d.month << "-" << d.year << endl;
}

void printLocation(const location& l) {
    cout << "Adres: " << l.streetName << " " << l.streetNumber << ", " << l.city << " " << l.postalCode << endl;
}

void printStudentDetails(const student& s) {
    cout << "Imie: " << s.name << endl;
    cout << "Nazwisko: " << s.surname << endl;
    cout << "Numer dowodu osobistego: " << s.idCardNumber << endl;
    printDate(s.birthDate);
    printLocation(s.address);
}

void appendDateToFile(const date& d, const string& filename) {
    ofstream file;
    file.open(filename, ios::app);
    file << d.day << "-" << d.month << "-" << d.year << endl;
    file.close();
}

void appendLocationToFile(const location& l, const string& filename) {
    ofstream file;
    file.open(filename, ios::app);
    file << l.streetName << " " << l.streetNumber << ", " << l.city << " " << l.postalCode << endl;
    file.close();
}

void appendStudentToFile(const student& s, const string& filename) {
    ofstream file;
    file.open(filename, ios::app);
    file << s.name << endl;
    file << s.surname << endl;
    file << s.idCardNumber << endl;
    appendDateToFile(s.birthDate, filename);
    appendLocationToFile(s.address, filename);
}

int compareDates(const date& d1, const date& d2) {
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    } else {
        if (d1.month < d2.month) {
            return -1;
        } else if (d1.month > d2.month) {
            return 1;
        } else {
            if (d1.day < d2.day) {
                return -1;
            } else if (d1.day > d2.day) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int loadStudentsFromFile(student students[], const string& filename) {
    ifstream file(filename);
    int i = 0;
    while (file >> students[i].name >> students[i].surname 
           >> students[i].idCardNumber >> students[i].birthDate.day 
           >> students[i].birthDate.month >> students[i].birthDate.year 
           >> students[i].address.streetName >> students[i].address.streetNumber 
           >> students[i].address.city >> students[i].address.postalCode) {
        i++;
    }
    file.close();
    return i;
}

void sortStudentsByField(student students[], int count, const string& field) {
    if (field == "name") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.name < b.name;
        });
    } else if (field == "surname") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.surname < b.surname;
        });
    } else if (field == "idCardNumber") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.idCardNumber < b.idCardNumber;
        });
    } else if (field == "birthDate") {
        sort(students, students + count, [](const student &a, const student &b) {
            if (a.birthDate.year != b.birthDate.year)
                return a.birthDate.year < b.birthDate.year;
            if (a.birthDate.month != b.birthDate.month)
                return a.birthDate.month < b.birthDate.month;
            return a.birthDate.day < b.birthDate.day;
        });
    } else if (field == "streetName") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.address.streetName < b.address.streetName;
        });
    } else if (field == "streetNumber") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.address.streetNumber < b.address.streetNumber;
        });
    } else if (field == "city") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.address.city < b.address.city;
        });
    } else if (field == "postalCode") {
        sort(students, students + count, [](const student &a, const student &b) {
            return a.address.postalCode < b.address.postalCode;
        });
    }
}

void printStudentsFromCity(student students[], int count, const string& city) {
    for (int i = 0; i < count; ++i) {
        if (students[i].address.city == city) {
            cout << "Imię: " << students[i].name << ", Nazwisko: " << students[i].surname
                 << ", Numer dowodu osobistego: " << students[i].idCardNumber
                 << ", Data urodzenia: " << students[i].birthDate.day << "-"
                 << students[i].birthDate.month << "-" << students[i].birthDate.year
                 << ", Adres: " << students[i].address.streetName << " " << students[i].address.streetNumber
                 << ", " << students[i].address.city << " " << students[i].address.postalCode << endl;
        }
    }
}