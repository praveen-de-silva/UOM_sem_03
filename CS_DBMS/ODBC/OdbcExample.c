#include <stdio.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>

int main() {
    SQLHENV env;       // Environment handle
    SQLHDBC dbc;       // Connection handle
    SQLHSTMT stmt;     // Statement handle
    SQLRETURN ret;     // Return status

    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    // 1. Allocate environment handle
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

    // 2. Allocate connection handle
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    // 3. Connect to DSN (replace DSN, USER, PASS with your details)
    ret = SQLConnect(dbc, (SQLCHAR*)"MyDSN", SQL_NTS,
                     (SQLCHAR*)"root", SQL_NTS,
                     (SQLCHAR*)"password", SQL_NTS);

    if (SQL_SUCCEEDED(ret)) {
        printf("Connected to the database successfully!\n");

        // 4. Allocate statement handle
        SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

        // 5. Execute query
        SQLExecDirect(stmt, (SQLCHAR*)"SELECT emp_id, name, salary FROM Employees", SQL_NTS);

        // 6. Bind columns
        SQLINTEGER emp_id;
        SQLCHAR name[50];
        SQLDOUBLE salary;

        SQLBindCol(stmt, 1, SQL_C_SLONG, &emp_id, 0, NULL);
        SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
        SQLBindCol(stmt, 3, SQL_C_DOUBLE, &salary, 0, NULL);

        // 7. Fetch and print results
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            printf("%d | %s | %.2f\n", emp_id, name, salary);
        }

        // 8. Clean up
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(dbc);
        SQLFreeHandle(SQL_HANDLE_DBC, dbc);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
    } else {
        printf("Connection failed!\n");
    }

    return 0;
}
