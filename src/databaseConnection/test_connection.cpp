#include "../../include/databaseConnection/test_connection.hpp" 

using namespace std;
using namespace pqxx;

int TestConnection::databaseConnection(){
    C = new connection("dbname=virus user=thomas password= \
            hostaddr=127.0.0.1 port=5432");
    if (C->is_open()){
        cout << "data base opened " << C->dbname() << endl;
    } else{
        cout << "cant open database" << endl;
        return 1;
    }
    return 0;
}

int TestConnection::sendSqlRequest(const char *sqlRequest){
    int res;
    connection &Cr = *C;
    nontransaction N(Cr);
    result R(N.exec(sqlRequest));

    for (auto s : R){
        for (auto field : s){
            res = field.as<int>(); 
            cout << "field " << res << endl;
        }
    }
    return res; 
}

