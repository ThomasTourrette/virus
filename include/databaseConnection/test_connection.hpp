#ifndef TESTCONNECTION_HPP
#define TESTCONNECTION_HPP
#include <iostream>
#include <pqxx/pqxx>

class TestConnection{
    public:
        int databaseConnection();
        int sendSqlRequest(const char *sqlRequest);
    private:
        pqxx::connection* C;
};


#endif
