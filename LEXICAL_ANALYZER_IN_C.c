/*
============================================================
=    DAFFODIL INTERNATIONAL UNIVERSITY                     =
=                                                          =
=    COURSE CODE : CSE332                                  =
=    COURSE TITLE: COMPILER DESIGN LAB                     =
=                                                          =
=    PROJECT TITLE : Implementing Lexical Analyzer in C    =
=    GROUP NAME : TEAM LIQUID                              =
=                                                          =
=    SUBMITTED BY :                                        =
=    1. Md. Shahriar Karim Shawon : 171-15-1269            =
=    2. Hosnain Ahammad : 171-15-1233                      =
=    3. Fariha Zannat Luna : 171-15-1261                   =
=                                                          =
=    SUBMITTED TO :                                        =
=    Zarin Tasnim Shejuti                                  =
=    Lecturer,                                             =
=    Department of Computer Science and Engineering        =
=    DATE OF SUBMISSION : 02 DECEMBER 2019                 =
============================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char expr[100], op[20];
    char var[20][20];
    int cons[20], ascii[100] = {0};
    int len, i, num = 0;
    int j = -1, k = -1, l = -1, n = 0;
    int pr[10] = {0}, m = 0;
    int c = 0, v = 0, o = 0, ct = 1;

    printf("\n     \xB2\xB4\xB2\xB4\xB2\xB4\xB2\xB4\xB2\xB4\xB2\xB4 Welcome to Lexical Analysis System \xC3\xB2\xB4\xB2\xB4\xB2\xB4\xB2\xB4\xB2\xB4\xB2");
    printf("\n\n\n\t\t       LEXICAL ANALYZER\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

    printf("\n\xC3 Enter the Expression   : ");
    scanf("%[^\n]%*c", expr);
    len = strlen(expr);
    printf("\n\xC3 String length is: %d\n", len);

    for (i = 0; i < len; ++i) //STORE IN INT
    {
        ascii[i] = (int)expr[i];
    }

    /*
    ======================
    =   STREAM OF TOKENS =
    ======================
    */
    printf("\n\xC3 STREAM OF TOKENS :\n");
    LineStart();
    for (i = 0; i < len; ++i)

    {

        if (isdigit(expr[i]))
        {
            while (isdigit(expr[i]))                                                                //Constraints
            {
                num = 10 * num + ascii[i] - '0';                                                    //'2''4' to '24'
                i++;
            }
            j++;
            cons[j] = num;
            num = 0;
            printf(" <%d> ", cons[j]);
        }

        if (isalpha(expr[i]))
        {
            while (isalpha(expr[i]) || isdigit(expr[i]) || expr[i] == '_')                          //Single_Variable
            {
                k++;
                var[m][k] = expr[i];
                i++;
            }
            printf(" <id,%d> ", ct);
            m++;
            pr[n] = k;
            n++;
            k = -1;
            ct++;
        }

        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*' || expr[i] == '=' || expr[i] == '^')   //Operators
        {
            l++;
            op[l] = expr[i];
            printf(" <%c> ", expr[i]); //change
        }
    }
    printf("\n");
    LineEnd();
    /*
    ======================
    =   CONSTRAINTS      =
    ======================
    */
    printf("\n\xC3 Total Constraints : %d\n", j + 1);
    LineStart();
    printf("  The Constraints are: \n");
    for (i = 0; i <= j; i++)
    {
        printf("\t<%d>\n", cons[i]);
        c++;
    }
    LineEnd();
    /*
    ======================
    =   OPERATORS        =
    ======================
    */
    printf("\n\xC3 Total Operators : %d\n", l + 1);
    LineStart();
    printf("  The Operators are: \n");
    for (i = 0; i <= l; i++)
    {
        printf("\t<%c>\n", op[i]);
        o++;
    }
    LineEnd();
    /*
    ======================
    =   VARIABLES        =
    ======================
    */
    printf("\n\xC3 Total Variables : %d\n", m);
    LineStart();
    printf("  The Variables are: \n");
    printf("\n    ID   \xB3  VALUE\t");
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

    for (i = 0; i < m; i++)
    {
        printf("\n\xB3 <id,%d> \xB3", i + 1);
        printf("  ");
        for (j = 0; j <= pr[i]; j++)
        {
            printf("%c", var[i][j]);

        }

        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

        v++;
    }
    printf("\n");
    LineEnd();
    return 0;
}

    /*
    ============================
    =   DESIGN OF UI METHOD    =
    ============================
    */

int LineStart()
{
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");

}
int LineEnd()
{
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");

}
