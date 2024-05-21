#include <iostream>
#include <vector>

using namespace std;

unsigned short swap_bytes(unsigned short value) {
    return (value >> 8) | (value << 8);
}

void print_swapped_bytes(unsigned short value) {
    cout << hex << swap_bytes(value) << endl;
}

int max_equal_bytes(long int value) {
    vector<int> count(256);
    for (int i = 0; i < sizeof(long int); i++) {
        count[(int)((value >> (8 * i)) & 0xFF)]++;
    }

    count[0xFF] = 0;
    count[0x00] = 0;

    int max_count = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    return max_count;
}

int main() {
    unsigned short value;
    long int temp;
    cin >> value;
    print_swapped_bytes(value);
    cin >> temp;
    cout << max_equal_bytes(temp) << endl;

    return 0;
}