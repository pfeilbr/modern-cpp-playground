#include "Headers.h"
#include <boost/filesystem.hpp>
#include <sqlite3.h>

namespace fs = boost::filesystem;

class Animal
{
  public:
    virtual void speak()
    {
        cout << "Animal::speak" << endl;
    }
};

class Cow : public Animal
{
  public:
    void speak() override
    {
        cout << "Cow::speak" << endl;
    }
};

struct Person
{
    string name;
    int age;

    Person(const string &name, const int &age) : name{name}, age{age} {}

    const string toString() const
    {
        stringstream ss;
        ss << "name: " << name << ", age: " << age;
        return ss.str();
    }
};

static void virtual_method_example()
{
    unique_ptr<Animal> a = make_unique<Animal>();
    a->speak();

    unique_ptr<Cow> c = make_unique<Cow>();
    c->speak();
}

static void unique_pointer_example()
{
    unique_ptr<Person> p = make_unique<Person>("Brian Pfeil", 40);
    cout << p->toString() << endl;
}

static void lambda_example()
{
    auto printer = []() { cout << "hello " << endl; };
    printer();
}

static void vector_for_example()
{
    vector<string> names{"brian", "tricia", "wyatt", "max"};
    for (const string &name : names)
    {
        cout << name << endl;
    }
}

static void filesystem_example()
{
    fs::path path{"/Users/brianpfeil/Documents"};
    for_each(fs::recursive_directory_iterator(path), fs::recursive_directory_iterator(), [](fs::directory_entry entry) { cout << entry.path() << endl; });
}

static void sqlite_example()
{
    sqlite3 *db;
    sqlite3_open("db.sqlite", &db);
    sqlite3_exec(
        db,
        "SELECT 'Hello world'",
        [](auto data, auto argc, auto argv, auto columns) -> int {
            printf("%s", argv[0]); // output: 'Hello world'

            int idx;
            printf("There are %d column(s)\n", argc);
            for (idx = 0; idx < argc; idx++)
            {
                printf("The data in column \"%s\" is: %s\n", columns[idx], argv[idx]);
            }
            return 0;
        },
        nullptr,
        nullptr);
    sqlite3_close(db);
}

static void random_example()
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 6);
    const int number_of_rolls = 10;
    int dice_rolls[number_of_rolls];
    generate_n(dice_rolls, number_of_rolls, [&]() {
        int dice_roll = distribution(generator);
        return dice_roll;
    });
    cout << "dice rolls: ";
    for (const int &dice_roll : dice_rolls)
    {
        cout << dice_roll << ",";
    }
}

static void sort_example()
{
    int arr[]{2, 1, 3, 9, 4};
    sort(begin(arr), end(arr));
    cout << "sorted arr: ";
    for (const int &i : arr)
    {
        cout << i << ",";
    }
}

static void pair_example() {
    pair<string,int> name_age{"brian", 40};
    cout << "name: " << name_age.first << ", age: " << name_age.second << endl;
}

int main()
{
    cout << "\n--- playground ---\n\n";
    // unique_pointer_example();
    // lambda_example();
    // vector_for_example();
    // filesystem_example();
    // sqlite_example();
    // random_example();
    // sort_example();
    // virtual_method_example();
    // pair_example();

    return 0;
}