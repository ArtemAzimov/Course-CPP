#include <iostream>
#include <string>


class IDataBase
{
public:
    virtual void setDB(const std::string& dbname) = 0; // & передача по ссылке, чтобы не копировать все символы в строке
    virtual void createTable(const std::string& tablename) = 0; // нужна константа чтобы не менять
};

class MySQL : public IDataBase
{
public:
    void setDB(const std::string& dbname) override {std::cout << "DB setted " << dbname << std::endl;}
    void createTable(const std::string& tablename) override {std::cout << "Table " << tablename << std::endl;}
};

class MainClass // golden class , главный "золотой" класс
{
    IDataBase* db;

public:
    MainClass()
    {
        db = new MySQL();
    }

    void method()
    {
        db->setDB("Employers");
        db->createTable("Engineers");
    }
};