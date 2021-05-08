
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<stdio.h>
#include<string.h>



using namespace ::std;
class DbConnect
{
private:
    MYSQL * conn;
public:
    void getConnection()
    {
        this->conn = mysql_init(0);
        this->conn = mysql_real_connect(conn,"192.167.0.106","root","","doan",3306,NULL,0);
        if(this->conn)
        {
            cout<<"success"<<endl;
        }
        else
        {
            cout<<"fail"<<endl;
        }
    }
};
int main()
{
    DbConnect dbConn;
    dbConn.getConnection();

}