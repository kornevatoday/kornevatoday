#include "test_tasks_rk1.h"


void task_3()
{
    float a = 0;

    a = 178.125;
    long long int b = GetMantissa(a);
    Assert(b == 125);

    a = 123.45678;
    b = GetMantissa(a);
    Assert(b == 456779); //погрешность

    a = 111.99999;
    b = GetMantissa(a);
    Assert(b == 999992);
}

void task_4()
{
    int a = 178;
    char* bf = new char[32];

    ConvertDecToHex(a, bf);
    AssertArray(bf, "B2", 3);


    a = 37111;
    ConvertDecToHex(a, bf);
    AssertArray(bf, "90F7", 5);

    a = 55555;
    ConvertDecToHex(a, bf);
    AssertArray(bf, "D903", 5);
}

void task_2()
{
    float a = 125.178;
    char b[13] = "../test4.txt";

    SeparateFloat(a, b);

    FILE* f = fopen(b, "r");
    Assert(f != NULL);
}


void task_5()
{
    char a[17] = "1001000110101111";
    char* b = new char[17];
    
    b = convertBinToHex(a);
    AssertArray(b, "91AF", 5);

    char c[9] = "10110010";
    b = convertBinToHex(c);
    AssertArray(b, "B2", 3);
    
    char d[10]  = "101000001";
    b = convertBinToHex(d);
    AssertArray(b, "141", 4);
}

void task_6()
{
    char g[3] = "AB";
   // char* g = new char[3];
    ChangeLSB(g);
    AssertArray(g, "B\202", 3);
}


/*
bool task_4(int d, char* h)
{
    bool fl1 = false;
    char hex1[17] = "0123456789ABCDEF";
    ConvertDecToHex(d, h);
    char bf = '0';
    int a = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 48; j < 71; j++)
        {
            if(h[i] == j)
            {
//                cout << "\n";
                a = a + ((fl1) ? ((j - 48 - 7) * pow(16, (7 - i))) : ((j - 48) * pow(16, (7- i))));
//                cout << a << "  " << j << " | " << (j - 48) << " || "<< (j - 48 - 7) << "  " << fl1  << "  " << 7-i<< endl;
            }
            if(j == 57)
            {
                fl1 = true;
                j = 64;
            }
        }
        fl1 = false;
    }
    if(d == a)
        return true;
    else
        return false;
    
}
*/

/*
char* task_5(const char* a)
{
    int r = 0;
    char hex1[17] = "0123456789ABCDEF";
    char* b = new char[16];
    int bf = 0;
    int k = 63;

    b = convertBinToHex(a);
    int n = strlen(b);
    char* f = new char[64];
    for(int i = 0; i < 63; i++)
        f[i] = '0';
//    f[0] = '3';
    for(int i = n-1; i > -1 ; i--)
    {
        for(int j = 0; j < 16; j++)
        {
            if(b[i] == hex1[j])
            {
                bf = j;
                k -= 3;
                do
                {
  //                  cout << j << "  " << bf % 2 << " || " << f << endl;
                    f[k] = (bf % 2) + 48;
                    k++;
                    bf /= 2;
                    r++;

                }while(r < 4);
                k -= 5;
                r = 0;

//                cout << j << " || " << f << endl;



            }
        }
    }
    return f;
}
*/

