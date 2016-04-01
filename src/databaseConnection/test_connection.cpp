#include "../../include/databaseConnection/test_connection.hpp" 

using namespace std;
using namespace pqxx;

int TestConnection::databaseConnection(){
    C = new connection("dbname=myFirstDatabase user=thomas password= \
            hostaddr=127.0.0.1 port=5432");
    if (C->is_open()){
        cout << "data base open " << C->dbname() << endl;
    } else{
        cout << "cant oppen database" << endl;
        return 1;
    }
    return 0;
}

int TestConnection::sendSqlRequest(const char *sqlRequest){
    connection &Cr = *C;
    nontransaction N(Cr);
    result R(N.exec(sqlRequest));

    for (auto s : R){
        cout << "nom " << s[0].as<string>() << endl;
        cout << "prenom " << s[1].as<string>() << endl;
        cout << "age " << s[2].as<int>() << endl;
    }
    return 0;
}

