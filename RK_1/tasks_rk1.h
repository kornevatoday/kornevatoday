#include <iostream>
#include <ostream>
#include <cmath>
#include <cstdint>
#include <bitset>
#include <sstream>
#include <string.h>
#include <string>
#include <cstring>

void buildTree(int height, int shift, int rotate);
void SeparateFloat(float a, const char* fname);
int kolvo_raz(int a);
long long int GetMantissa(float a);
void ConvertDecToHex(int a, char* h);
char* convertBinToHex(const char* binNum);
void ChangeLSB(char* a);
char* reverse(char* buffer, int i, int j);
char* itoa(int value, char* buffer, int base);
char reverse(char a);


