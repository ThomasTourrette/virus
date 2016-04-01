#include <iostream>
#include <pqxx/pqxx>


using namespace std;
using namespace pqxx;


int main(int argc, char* argv[]){

    try{
        connection C("dbname=myFirstDatabase user=thomas password= \
                hostaddr=127.0.0.1 port=5432");
        if (C.is_open()){
            cout << "data base open " << C.dbname() << endl;
        } else{
            cout << "cant oppen database" << endl;
            return 1;
        }
//        const char *sql = "SELECT * from person where nom = 'tourrette'";
        const char *sql = "SELECT * from person";
        nontransaction N(C);
        result R(N.exec(sql));

        for (auto s : R){
            cout << "nom " << s[0].as<string>() << endl;
            cout << "prenom " << s[1].as<string>() << endl;
            cout << "age " << s[2].as<int>() << endl;
        }
        C.disconnect();
    }
    catch (const exception &e){
        cerr << e.what() << endl;
        return 1;
    }

}
