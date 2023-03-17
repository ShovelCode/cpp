#include <mysqlx/xdevapi.h>
#include <iostream>

int main() {
    // Create a MySQL Connector/C++ session object
    mysqlx::Session session("localhost", 3306, "username", "password");

    // Connect to the MySQL database server
    session.connect();

    // Execute a SQL query
    mysqlx::Schema schema = session.getSchema("mydatabase");
    mysqlx::Table mytable = schema.getTable("mytable");
    mysqlx::Result result = mytable.select("*").execute();

    // Print the results
    std::cout << "Results:" << std::endl;
    while (result.hasData()) {
        mysqlx::Row row = result.fetchOne();
        std::cout << row[0].getString() << " " << row[1].getString() << std::endl;
    }

    // Close the connection
    session.close();

    return 0;
}
