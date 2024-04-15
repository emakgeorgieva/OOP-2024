#pragma once
#include <iostream>
#include <cstring>

const size_t CAPACITY = 100;
class Date
{
    public:
    Date();
    Date(const unsigned day, const unsigned month, const unsigned year);
    void Print() const;

    void SetDay(unsigned Day);
    void SetMonth(unsigned Month);
    void SetYear(unsigned Year);

    unsigned GetDay() const;
    unsigned GetMonth() const;
    unsigned GetYear() const;
    
    private:
    bool isLeapYear(const unsigned year);
    void isValidDate(unsigned day, unsigned month, unsigned year);

    unsigned day;
    unsigned month;
    unsigned year;
};

class Person
{
    public:
    enum class Sex {male, female};
    enum class FamilyStatus {single, taken, married};
    enum class PersonalStatus {groom, bride, guest, priest};
    
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void SetName(const char * name);
    void SetAge(unsigned age);
    void SetId(unsigned createdPerson);
    void SetSex(const Sex s);
    void SetFamilyStatus(const FamilyStatus fs);
    void SetPersonalStatus(const PersonalStatus ps);

    const char * GetName() const;
    unsigned GetAge() const;
    int GetId() const;
    Sex GetSex() const;
    FamilyStatus GetFamilyStatus() const;
    PersonalStatus GetPersonalStatus() const;

    
    private:
    void copy(const Person& copy);
    void clear();

    Sex sex;
    FamilyStatus fstatus;
    PersonalStatus pstatus;

    char * name;
    unsigned age;
    static int id;
    static unsigned createdPerson;
};

class Table
{
    public:
    Table();
    Table(const Table& other);
    Table& operator=(const Table& other);
    ~Table();

    void SetName(const char * Name);
    void SetListOfPeople(const Person * ListOfPeople);
    void SetMaxAge(int MaxAge);
    void SetTakenSeats(int TakenSeats);

    const char * GetName() const;
    Person GetListOfPeople() const;
    int GetMaxAge() const;
    int GetTakenSeats() const;

    private:
    void clear();
    void copy(const Table& copy);

    char * name;
    Person listOfPeople [CAPACITY];
    int maxAge;
    int takenSeats;
};

class Wedding
{
    private:
    static bool Blessing(Person& fperson, Person& sperson);

    public:
    friend void Marry(Person& fperson, Person& sperson);

    Wedding();
    Wedding(const Wedding& other);
    Wedding& operator=(const Wedding& other);
    ~Wedding();

    void SetTables(const Table Table);
    void SetPlace(const char * Place);
    void SetDate(Date Date);

    Table GetTable() const;
    const char * GetPlace() const;
    Date GetDate() const;

    private:
    void copy(const Wedding& copy);
    void clear();

    
    Table tables [CAPACITY];
    char * place;
    Date date;
};