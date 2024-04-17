#include "Task2.h"
#include <exception>
#include <iostream>

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2024;
}

Date::Date(const unsigned day, const unsigned month, const unsigned year)
{
    isValidDate(day, month, year);
}




void Date::Print() const
{
    std::cout<< this->day << "." << this->month << "." << this->year;
}

bool Date::isLeapYear(unsigned year)
{
    if (year % 4 ==0 || year % 100 == 0)
    {
        if (year != 400)
        {
            return true;
        }
    }
    return false;
}

void Date::isValidDate(unsigned day, unsigned month, unsigned year)
{
    if (month <= 12)
    {
        this->month = month;
    }
    else throw std::invalid_argument("Exception occurred");

    if (day <= 31)
    {
        if (isLeapYear(year))
        {
            if (month == 2)
            {
                if (day <= 29)
                {
                    this->day = day;
                }
                else throw std::invalid_argument("Exception occurred");
            }
        }
        this->day = day;
    }
    else throw std::invalid_argument("Exception occurred");


    if (year >= 2024)
    {
        this->year = year;
    }
    else throw std::invalid_argument("Exception occurred");
}

void Date::SetDay(unsigned Day)
{
    isValidDate(Day,this->month,this->year);    
}

void Date::SetMonth(unsigned Month)
{
    isValidDate(this->day, Month,this->year);    
}

void Date::SetYear(unsigned Year)
{
    isValidDate(this->day, this->month, Year);    
}

unsigned Date::GetDay() const
{
    return day;
}

unsigned Date::GetMonth() const
{
    return month;
}

unsigned Date::GetYear() const
{
    return year;
}

Person::Person()
{
    this->name = new char [1];
    this->age = 1;
    this->id = 0;
}

Person::Person(const Person &other)
{
    copy(other);
}

Person &Person::operator=(const Person &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

void Person::copy(const Person& copy)
{
    name = new char[strlen(copy.name)+1];
    if (name) strcpy(this->name, copy.name);

    this->age = copy.age;
    this->id = copy.id;
}

void Person::clear()
{
    delete[] name;
}

Person::~Person()
{
    clear();
}

void Person::SetName(const char *Name)
{
     if (strlen(Name) < CAPACITY)
    {
        this->name = new char[CAPACITY];
        if (Name) strcpy(this->name, Name);        
    }
}

void Person::SetAge(unsigned Age)
{
    this->age = Age;
}

void Person::SetId(unsigned createdPerson)
{
    this->id = createdPerson;
    createdPerson++;
}

void Person::SetSex(const Sex s)
{
    sex = s;
}

void Person::SetFamilyStatus(const FamilyStatus fs)
{
    fstatus = fs;
}

void Person::SetPersonalStatus(const PersonalStatus ps)
{
    pstatus = ps;
}

const char *Person::GetName() const
{
    return name;
}

unsigned Person::GetAge() const
{
    return age;
}

int Person::GetId() const
{
    return createdPerson;
}

Person::Sex Person::GetSex() const
{
    return sex;
}

Person::FamilyStatus Person::GetFamilyStatus() const
{
    return fstatus;
}

Person::PersonalStatus Person::GetPersonalStatus() const
{
    return pstatus;
}

Table::Table()
{
    Person first;
    this->name = new char[1];
    this->listOfPeople[0] = first;
    this->maxAge = 99;
    this->takenSeats = 1;
}

Table::Table(const Table &other)
{
    copy(other);
}

Table &Table::operator=(const Table &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Table::~Table()
{
    clear();
}

void Table::SetName(const char *Name)
{
    if (strlen(Name) < CAPACITY)
    {
        this->name = new char[CAPACITY];
        if (Name) strcpy(this->name, Name);
    }
}

void Table::SetListOfPeople(const Person * ListOfPeople)
{
    *this->listOfPeople = *ListOfPeople;
}

void Table::SetMaxAge(const int MaxAge)
{
    this->maxAge = MaxAge;
}

void Table::SetTakenSeats(const int TakenSeats)
{
    this->takenSeats = TakenSeats;
}

void Table::clear()
{
    delete [] name;
}

void Table::copy(const Table& copy)
{
    name = new char[strlen(copy.name)+1];
    if(name) strcpy(this->name, copy.name);
    
    for (size_t i = 0; i < CAPACITY; i++)
    {
        this->listOfPeople[i] = copy.listOfPeople[i];
    }

    this->maxAge = copy.maxAge;
    this->takenSeats = copy.takenSeats;
}

bool Wedding::Blessing(Person& fperson, Person& sperson)
{
    bool marriedOrNot;
    if (fperson.GetFamilyStatus() == Person::FamilyStatus::taken && sperson.GetFamilyStatus() == Person::FamilyStatus::taken && (fperson.GetPersonalStatus() == Person::PersonalStatus::bride && fperson.GetPersonalStatus() == Person::PersonalStatus::groom) || (fperson.GetPersonalStatus() == Person::PersonalStatus::groom && fperson.GetPersonalStatus() == Person::PersonalStatus::bride) )
    {
        std::cout<< "You are ready to get married";
        return marriedOrNot = true;

    }
    else std::cout<< "First you have to be taken in order to get married"; return marriedOrNot = false;
}

void Marry(Person &fperson, Person &sperson)
{
    if (Wedding::Blessing(fperson, sperson) == true)
    {
        fperson.SetFamilyStatus(Person::FamilyStatus::married);
        sperson.SetFamilyStatus(Person::FamilyStatus::married);
    }
    else std::cout<< "The priest cannot marry you";
}

const char *Table::GetName() const
{
    return name;
}

Person Table::GetListOfPeople() const
{
    return listOfPeople[CAPACITY];
}

int Table::GetMaxAge() const
{
    return maxAge;
}

int Table::GetTakenSeats() const
{
    return takenSeats;
}

Wedding::Wedding()
{
    Table firstTable;
    tables[0] = firstTable;
    place = new char[1];
    Date date;
}

Wedding::Wedding(const Wedding &other)
{
    copy(other);
}

Wedding &Wedding::operator=(const Wedding &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Wedding::~Wedding()
{
    clear();
}

void Wedding::SetTables(const Table Table)
{
    *this->tables = Table;
}

void Wedding::SetPlace(const char *Place)
{
    if (strlen(Place) < CAPACITY)
    {
        this->place = new char[CAPACITY];
        if (Place) strcpy(this->place, Place);
    }
}

void Wedding::SetDate(Date Date)
{
    this->date = Date;
}

Table Wedding::GetTable() const
{
    return tables[CAPACITY];
}

const char *Wedding::GetPlace() const
{
    return place;
}

Date Wedding::GetDate() const
{
    return date;
}

void Wedding::copy(const Wedding &copy)
{
    place = new char[strlen(copy.place) +1];
    if(place)  strcpy(this->place, copy.place);

    this->date = copy.date;
    
    for (size_t i = 0; i < CAPACITY; i++)
    {
        this->tables[i] = copy.tables[i];
    }
}

void Wedding::clear()
{
    delete [] place;
}




