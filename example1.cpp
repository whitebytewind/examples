#include <iostream>
#include <string>

using std::string, std::cout;
enum {max_persons = 255};
/*------------------------------------------
              Class Employee
------------------------------------------*/
class Employee
{
public: 
    virtual const string& get_fname() const = 0; 
    virtual const string& get_lname() const = 0; 
    virtual short get_old() const = 0; 
};

/*------------------------------------------
              Class Lector
------------------------------------------*/
class Lector : public Employee
{

private:
    string first_name;
    string last_name; 
    short old {0}; 
    int salary {0};

public:
    // getters
    int get_salary() const { return salary; }
    const string& get_fname() const { return first_name; }
    const string& get_lname() const { return last_name; }
    short get_old() const { return old; } 

    // setters
    void set_salary(int salary) {if (salary > 0) this->salary = salary; } 
    
    // constructors
    Lector(string first_name, string last_name, short old) :
        first_name(first_name), 
        last_name(last_name),
        old(old)
        { }
        
    Lector(string first_name, string last_name, short old, int salary) :
        Lector(first_name, last_name, old)
        {
            set_salary(salary);
        }
};

/*------------------------------------------
              Class Laborant
------------------------------------------*/
class Laborant : public Employee
{
private:
    string first_name; 
    string last_name; 
    short old {0}; 
    string job_title;

public:
// геттеры    
    const string& get_job_title() const { return job_title; }
    const string& get_fname() const { return first_name; }
    const string& get_lname() const { return last_name; }
    short get_old() const { return old; } 
    
// сеттер        
    void set_job_title(const std::string& job_title) { this->job_title = job_title; }  
    
// конструкторы    
    Laborant(string first_name,string last_name, short old) :
        first_name(first_name), 
        last_name(last_name),
        old(old)
        { }
        
    Laborant(string first_name, string last_name, short old, string job_title) :
        first_name(first_name), 
        last_name(last_name),
        old(old),
        job_title(job_title)
        { }
};

/*------------------------------------------
              Main function
------------------------------------------*/
int main(void)
{
    Employee* staff[max_persons] {nullptr};

    staff[0] = new Lector("Sergey", "Balakirev", 33, 85000);
    staff[1] = new Laborant("Elena", "Pozdnjakova", 27, "Programmer");
    staff[2] = new Lector("Olga", "Levkina", 38, 120000);

    for(const auto &st : staff)
    {
        if (!st) break;
        cout << st->get_fname() << " ";
    }

    for(const auto &st : staff)
    {
        if (!st) break;
        delete st;
    }
    
    return 0;
}
