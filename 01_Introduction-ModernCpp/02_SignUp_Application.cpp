/**
 * @brief Sign-Up Application
 *
 * Project Requirements:-
 * we’re going to be writing a user registration application. This will allow users to register with the system,
 * providing both their name and age, and we’ll store this information in our own custom type.
 * We’ll also provide the ability for a user to be looked up by an ID, retrieving their information.
 *
 */

#include <iostream>
#include <vector>

#define ENDL "\n"

enum class appOption
{
    ADD_RECORD=1,
    FETCH_RECORD,
    DELETE_RECORD,
    SHOW_DB_RECORDS,
    QUIT_APP,
    INVALID,
};

/* FUNCTION PROTOTYPE */
std::istream& operator>>(std::istream& ip_stream, appOption& appOptionInstance);


class userEntry
{
    unsigned int id;
    std::string name;
    unsigned int age;

public:
    userEntry(unsigned int userId, std::string userName, unsigned int userAge) : id(userId), name(userName), age(userAge) {}
    void displayUser() const
    {
        std::cout << "Id: " << id << "\tName: " << name << "\tAge: " << age << ENDL;
    }
    unsigned int getId()
    {
        return id;
    }
};

class userDatabase
{
    std::vector<userEntry> users;
    
    const unsigned int databaseIdBase=1000;
    static unsigned int databaseIdOffset;

    const unsigned int databaseMaxSize=100;
    static unsigned int databaseCount;

public:
    appOption showOptionMenu() 
    {
        appOption selected;
        std::cout<< "User SignUp Application" << ENDL << ENDL;
        std::cout<< "Please select an Option: " << ENDL;
        std::cout<< "1: Add Record" << ENDL << "2: Fetch Record" << ENDL << "3: Delete Record" << ENDL << "4: Show All Records" << ENDL << "5: Quit App" << ENDL << ENDL;
        std::cout<< "Enter Option: ";
        try 
        {
            std::cin >> selected;
            std::cout << ENDL;
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
        }

        return selected;
    }
    void addRecord()
    {
        if(databaseCount >= databaseMaxSize) 
        {
            std::cout<< "Error, Failed to perform Add Operation ... Database is FULL!" << ENDL << ENDL;
            return;
        }

        unsigned int userId;
        ++databaseCount;
        ++databaseIdOffset;
        userId = databaseIdBase + databaseIdOffset;

        std::string userName;
        std::cout << "Enter Username: ";
        std::cin >> userName;

        unsigned int userAge;
        std::cout << "Enter Age: ";
        std::cin >> userAge;

        users.push_back(userEntry(userId, userName, userAge));
        std::cout << "User add operation done successfully!" << ENDL;
    }
    void fetchRecord(unsigned int userId)
    {
        for (auto entry : users)
        {
            if (entry.getId() == userId)
            {
                entry.displayUser();
                return;
            }
        }
        std::cout << "Error! Record not found." << ENDL;
    }
    void deleteRecord(unsigned int userId)
    {
        for (int idx=0; idx<users.size(); idx++)
        {
            if (users[idx].getId() == userId)
            {
                --databaseCount;
                users.erase(users.begin() + idx);
                return;
            }
        }
        std::cout << "Error! Record not found." << ENDL;
    }
    void showAllDbRecords()
    {
        std::cout<< "---------------- DB Records ----------------" << ENDL;
        for (auto entry : users)
        {
            entry.displayUser();
        }
        std::cout<< "--------------------------------------------" << ENDL;
        std::cout<< "DB Size: " << userDatabase::databaseCount << ENDL;

    }
};
/**
 * Initialize Class Static Members
 */
unsigned int userDatabase::databaseCount=0;
unsigned int userDatabase::databaseIdOffset=0;


/* MAIN FUNCTION */
int main()
{
    userDatabase MyUserDatabase;

    unsigned int uid;
    char appIsRunning = 'Y';
    appOption selectedOption;
    do{
        std::cout<< ENDL;
        selectedOption = MyUserDatabase.showOptionMenu();

        switch (selectedOption)
        {
        case appOption::ADD_RECORD:
            MyUserDatabase.addRecord();
            break;

        case appOption::FETCH_RECORD:       
            std::cout<< "Please Enter UserId: ";
            std::cin >> uid;
            MyUserDatabase.fetchRecord(uid);
            std::cout<< ENDL;
            break;

        case appOption::DELETE_RECORD:
            std::cout<< "Please Enter UserId: ";
            std::cin >> uid;
            MyUserDatabase.deleteRecord(uid);
            std::cout<< ENDL;
            break;

        case appOption::SHOW_DB_RECORDS:
            MyUserDatabase.showAllDbRecords();
            break;

        case appOption::QUIT_APP:
            appIsRunning = 'N';
            break;

        default:
            break;
        }
        std::cout<< "__________________________________________________" << ENDL << ENDL;
    }while(appIsRunning == 'Y');
    std::cout<< "Goodbye!" << ENDL << ENDL;
    
    return 0;
}


/* FUNCTION DEFINITION */
/** 
 * Operator overloading for istream "cin" to be able to read Enum Class variable
*/
std::istream& operator>>(std::istream& ip_stream, appOption& appOptionInstance)
{
    int intOption;
    ip_stream >> intOption;
    if(intOption==1 || intOption==2 || intOption==3 || intOption==4 || intOption==5) 
    {
        appOptionInstance = static_cast<appOption>(intOption);
    }
    else 
    {
        throw std::invalid_argument("Error, Invalid input!");
    }
    return ip_stream;
}
