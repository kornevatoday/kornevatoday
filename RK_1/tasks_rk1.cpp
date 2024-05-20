#include "tasks_rk1.h"

using namespace std;

union type
{
    float f;
    int i;
};



char reverse(char a)
{
    char b = 0;
    for(int i = 0; i < (sizeof(char)*8); i++)
    {
        b = (b<<1)|(a&1);
        a = a>>1;
    }
    return b;
}
void ChangeLSB(char* a)
{
    int l = 0;
    while(a[l] != '\0')
    {
        l ++;

    }

    for(int i = 0; i < l/2; i ++)
    {
        char bf =a[i];
        a[i] = reverse(a[l-i-1]);
        a[l-i-1] = reverse(bf);

    }
    a[l] = '\0';

}


char* convertBinToHex(const char* binNum) 
{
	int n = strlen(binNum);
    char* g = new char [(n / 4) + 1];
    for (int i = n - 1; i >= 0; i -= 4)
    {
        int a = 0;
        char t;
        for(int j = 0; j < 4; j++)
        {
            if(i - j < 0)
                t = '0';
            else
                t = binNum[i - j];
            a += (atoi(&t)) * (std::pow(2, j));
        }
        if(a > 9)
            t = 'A' + (a - 10);
        else
            t = '0' + (a);
        g[(n - i - 1) / 4] = t;
        g[1 + (n - i - 1) / 4] = '\0';
    }
    for(int i = 0; i < (strlen(g)) / 2; i++)
        std::swap(g[i], g[strlen(g) - 1 - i]);
    return g;
}

void ConvertDecToHex(int d, char* h)
{
    bool sminus = false;
    int bf;
    if(d < 0)
    {
        d = abs(d);
        sminus = true;
    }
    char st[17] = "0123456789ABCDEF";
    int i = 7;
    do
    {
        h[i] = st[d % 16];
        d /= 16;
        i--;
    }while(i > -1);
    if(h[0] == '0')
    {
        for(int j = 0; j < 8; j++)
        {
            if(h[j] != '0' && sminus == false)
            {
                for(int t = j; t < strlen(h) + 1; t++)
                {
                    h[t - j] = h[t];
                }
                break;
            }
            if(h[j] != '0' && sminus == true)
            {
                h[0] = '-';
                for(int t = j; t < strlen(h) + 1; t++)
                {
                    h[t - j + 1] = h[t];
                }
                break;

             }
        }
    } else if(sminus)
    {
        for(int t = strlen(h) + 1; t > -1; t--)
        {
            h[t + 1] = h[t];
        }
        h[0] = '-';
    }
    
    
}

long long int GetMantissa(float n)
{
    long long int a = 0;
    char* bf = new char[32];
    sprintf(bf, "%f", n);
    char bf1;
    int k = 0;
    for(int i = 0; i < strlen(bf); i++)
    {
        if(bf[i] == '.')
        {
            k = strlen(bf) - i;
            for(int j = i + 1; j < strlen(bf) + i; j++)
            {
                bf[j - i - 1] = bf[j];
            }
            i = 1000;
        }
    }
    a = atoi(bf);
    while(a % 10 == 0)
    {
        a /= 10;
    }
    return a;
}


char* reverse(char* buffer, int i, int j) {
  while (i < j) {
    char t = buffer[i];
    buffer[i++] = buffer[j];
    buffer[j--] = t;
  }

  return buffer;
}

char* itoa(int value, char* buffer, int base) {
  if (base < 2 || base > 32) return NULL;

  int n = abs(value);
  int i = 0;

  do {
    int r = n % base;
    buffer[i++] = (r < 10) ? (r + '0') : (r - 10 + 'A');
    n /= base;
  } while (n);

  if (value < 0 && base == 10) buffer[i++] = '-';
  buffer[i] = '\0';

  return reverse(buffer, 0, i - 1);
}

void SeparateFloat(float a, const char* fname) 
{
    type b;
    b.f = a;
    char stepen = (b.i << 1 >> 24);
    int mantisa = (b.i << 9 >> 9);
    char c[30];
    char c1[30];
    itoa(1, c, 16);
    itoa(1, c1, 2);
    FILE* f = fopen(fname, "w");
    if(!f)
        cout << "ыыы" << endl;
    fprintf(f, "1: %f \n", a);
    fprintf(f, "2: %s \t %s \n", c, c1);
    itoa(stepen, c, 16);
    itoa(stepen, c1, 2);
    fprintf(f, "3: %s \t %s \n", c, c1);
    itoa(mantisa, c, 16);
    itoa(mantisa, c1, 2);
    fprintf(f, "4: %s \t %s \n", c, c1);
    fclose(f);
}

	




void buildTree(int height, int shift, int rotate)
{
	bool fl3 = false;
	bool fl2 = false;
	int n = 1;
	int bf2 = 1;
	bool fl = true;
	int s = shift;
	int k = 1;
	int bf = 0;
	if(shift < height)
	{
		bf = s;
	}
	if(rotate == 0)
	{
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < s; j++)
			{
				cout << " ";
			}
			if(shift < height)
			{
				for(int j = 0; j < (bf - s); j++)
				{
					cout << "*";
				}
				for(int j = 0; j < k; j++)
				{
					cout << "*";
				}
				if(k < shift + 1)
				{
					k++;
				}
				s--;
			}
			else
			{
			for(int j = 0; j <(2*k -1); j++)
				cout << "*";
			k++;
			s--;
			}
			cout << "\n";
		}
		fl = false;
	}
	while(fl)
	{
		if(rotate == 90*n)
		{
			for(int i = 0; i < (height * 2 - 1); i++)
			{
				for(int j = 0; j < s-1; j++)
					cout << " ";

				for(int j = 0; j < k; j++)
					cout << "*";


				if(k == height)
					fl2 = true;

				if(!fl2)
				{
					k++;
				}else
					k--;


				cout << "\n";
			}
			fl = false;
		}
		if(rotate == 180*n)
		{
			k = height;
			s = 0;
			for(int i = 0; i < height; i++)
                {
                        if(shift < height)
                        {
				if(k <= shift)
                                {
                                        for(int j = 0; j < bf2; j++)
                                        {
                                                cout << " ";
                                        }
					bf2++;
					
                                }
				if(k > shift)
				{
				for(int j = 0; j < shift; j++)
					cout << "*";
				}

				if(k <= shift)
				{
					
					for(int j = 0; j <(2*k - 1); j++)
						cout << "*";
				}else
				{
					for(int j = 0; j < k; j++)
                	                        cout << "*";

				}
				k--;
				s++;
				
                        }
                        else
                        {
				for(int j = 0; j < s; j++)
                                	cout << " ";

                        	for(int j = 0; j <(2*k -1); j++)
                                	cout << "*";
                        k--;
                        s++;
                        }
                        cout << "\n";
                }
                fl = false;

		}
		if(rotate == 270*n)
		{
			bf2 = 1000;
			k = 1;
			
			for(int f = 0; f < (height*2 - 1) && bf2 > 0  ; f++)
			{
				if(shift < height)
				{
					if(k < shift + 1)
					{
						for(int i = 0; i < shift - k + 1; i++)
							cout << " ";
						for(int i = 0; i < k; i++)
							cout << "*";
						k++;
						bf = k;
					}
					if(k == shift +1)
					{
						cout << "\n";
					}
					if(k >= shift+1 && k <=((shift + 1) + (height - shift)))
					{
						
						for(int i = 0; i < bf; i++)
							cout << "*";
						k++;
					}
					if ( k > ((shift + 1) + (height - shift)) && !fl3)
					{
						fl3 = true;
						cout << "\n";
						bf2 = k - (height - shift+1);
					}	
					if(k > ((shift + 1) + (height - shift)))
					{
						for(int i = 0; i < shift+1 - bf2; i++)
							cout << " ";
						for(int i = 0; i < bf2; i++)
							cout << "*";
						bf2--;
					}
				}else
				{
					for(int i = 0; i < shift - k; i++)
						cout << " ";
					for(int i = 0; i < k; i++)
						cout << "*";
					if(k == height)
						fl2 = true;
					if(!fl2)
					{
						k++;
					}else
					{
						k--;
					}
				}
				cout << "\n";
			}
			fl = false;
		}
		if(rotate == 360*n)
		{
			   for(int i = 0; i < height; i++)
                {
                        for(int j = 0; j < s; j++)
                        {
                                cout << " ";
                        }
                        if(shift < height)
                        {
                                for(int j = 0; j < (bf - s); j++)
                                {
                                        cout << "*";
                                }
                                for(int j = 0; j < k; j++)
                                {
                                        cout << "*";
                                }
                                if(k < shift + 1)
                                {
                                        k++;
                                }
                                s--;
                        }
                        else
                        {
                        for(int j = 0; j <(2*k -1); j++)
                                cout << "*";
                        k++;
                        s--;
                        }
                        cout << "\n";
                }
                fl = false;

		}
		if(n == 250)
		{
			cout << "plohoi rotate";
			fl = false;
		}
		n++;
	}
	
}
