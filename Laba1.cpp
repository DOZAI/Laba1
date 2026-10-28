#include <iostream>
#include <cstring>
#include <cstdint>
#include <windows.h> // для кириллицы
using namespace std;



void printIntBit(int value){
    int width = sizeof(value)*8;
    unsigned uns_value = static_cast<unsigned>(value);

    cout << "int value = " << value << " | unsigned value = " << uns_value << endl;
    cout << "S | Значащие разряды" << endl;
    for (int i = width - 1; i>=0; --i){
        if (i == width - 2) cout << " | ";
        if (i%8 == 7 && i!= width - 1) cout << " ";
        cout << ((uns_value >> i) & 1);
    }
    cout << endl;
}




void printFloatBit(float value){
    int width = sizeof(value)*8;
    uint32_t u_value;
    std::memcpy(&u_value, &value, sizeof(u_value));

    cout << "float value = " << value << "; uint32 value = " << u_value << endl;
    cout << "S | Порядок  | Мантисса" << endl;
    for (int i = width - 1; i>=0; --i){
        if (i == width - 1 - 1) cout << " | ";
        if (i == width - 2 - 8) cout << " | ";
        cout << ((u_value >> i) & 1);

    }
    cout << endl;
}

void printDoubleBit(double value){
    int width = sizeof(value)*8;
    uint64_t u_value;
    std::memcpy(&u_value, &value, sizeof(u_value));

    cout << "double value = " << value << "; uint64 value = " << u_value << endl;
    cout << "S | Порядок     | Мантисса" << endl;
    for (int i = width -1; i>=0; i--){
        if (i == width - 1 - 1) cout << " | ";
        if (i == width - 2 - 11) cout << " | ";
        cout << ((u_value >> i) & 1);
    }
    cout << endl;
}




int main() {
    
    SetConsoleOutputCP(CP_UTF8); // для кириллицы
    cout << "Task 1" << endl;

    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short int: " << sizeof(short int) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long int: " << sizeof(long int) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;

    cout << endl << "Task 2" << endl;

    int int_value = 5;
    printIntBit(int_value);

    cout << endl;

    int_value = -5;
    printIntBit(int_value);

    cout << endl << "Task 3" << endl;
    
    float float_value = 0.0;
    printFloatBit(float_value);

    float_value = 1.4e-45;
    printFloatBit(float_value);

    float_value = 1e100;
    printFloatBit(float_value);

    cout << endl << "Task 4" << endl;

    double double_value = -5.5;
    printDoubleBit(double_value);



    cout << endl << "Task 5" << endl;

    //Целые числа
    cout << "Целые числа" << endl;

    cout << "было число 15"  << endl;
    int i_value = 15;
    cout << "ему инвертировали 3 бит" << endl;
    unsigned u_value = static_cast<unsigned>(i_value);
    unsigned mask = 1u << 3;
    cout << "теперь оно стало " << (u_value^mask) << endl;

    cout << "было число 0"  << endl;
    i_value = 0;
    cout << "ему поставили единичку в 2 бит" << endl;
    u_value = static_cast<unsigned>(i_value);
    mask = 1u << 2;
    cout << "теперь оно стало " << (u_value|mask) << endl;

    cout << "было число -7"  << endl;
    i_value = -7;
    cout << "ему поставили ноль в 31 бит" << endl;
    u_value = static_cast<unsigned>(i_value);
    mask = 1u << 31;
    cout << "теперь оно стало " << (u_value&~mask) << endl;


    //float числа
    cout << endl << "float числа" << endl;
    cout << "было число 5.5"  << endl;
    float f_value = 5.5f;
    cout << "ему инвертировали 10 бит" << endl;
    uint32_t u32_value;
    std::memcpy(&u32_value, &f_value,sizeof(u32_value));
    mask = 1u << 10;
    u32_value = u32_value^mask;
    std::memcpy(&f_value, &u32_value, sizeof(f_value));
    cout << "теперь оно стало " << (f_value) << endl;

    cout << "было число 0.0"  << endl;
    f_value = 0.0f;
    cout << "ему поставили единичку в 1 бит" << endl;
    std::memcpy(&u32_value, &f_value,sizeof(u32_value));
    mask = 1u << 1;
    u32_value = u32_value|mask;
    std::memcpy(&f_value, &u32_value, sizeof(f_value));
    cout << "теперь оно стало " << (f_value) << endl;

    cout << "было число -999999.9"  << endl;
    f_value = 999999.9f;
    cout << "ему поставили ноль в 31 бит" << endl;
    std::memcpy(&u32_value, &f_value,sizeof(u32_value));
    mask = 1u << 31;
    u32_value = u32_value^mask;
    std::memcpy(&f_value, &u32_value, sizeof(f_value));
    cout << "теперь оно стало " << (f_value) << endl;

    //double числа
    uint64_t mask64;

    cout << endl << "double числа" << endl;
    cout << "было число 4.94e-324 (денормализованное)"  << endl;
    double d_value = 4.94e-324;
    uint64_t u64_value;
    cout << "ему инвертировали 0 бит" << endl;
    std::memcpy(&u64_value, &d_value,sizeof(u64_value));
    mask64 = 1ULL << 0;
    u64_value = u64_value^mask64;
    std::memcpy(&d_value, &u64_value,sizeof(d_value));
    cout << "теперь оно стало " << (d_value) << endl;
    
    cout << "было число 0.0"  << endl;
    d_value = 0.0;
    cout << "ему поставили единичку в 0 бит" << endl;
    std::memcpy(&u64_value, &d_value,sizeof(u64_value));
    mask64 = 1ULL << 0;
    u64_value = u64_value|mask64;
    std::memcpy(&d_value, &u64_value,sizeof(d_value));
    cout << "теперь оно стало " << (d_value) << endl;

    cout << "было число -999999.9"  << endl;
    d_value = -999999.9;
    cout << "ему поставили ноль в 63 бит" << endl;
    std::memcpy(&u64_value, &d_value,sizeof(u64_value));
    mask64 = 1ULL << 63;
    u64_value = u64_value&~mask64;
    std::memcpy(&d_value, &u64_value,sizeof(d_value));
    cout << "теперь оно стало " << (d_value) << endl;

    cout << "Умножение на 2 через битовый сдвиг" << endl;

    i_value = 15;
    cout << "было " << i_value;
    i_value <<= 1;
    cout << ", стало " << i_value << endl;

    i_value = 0;
    cout << "было " << i_value;
    i_value <<= 1;
    cout << ", стало " << i_value << endl;

    i_value = -9;
    cout << "было " << i_value;
    i_value <<= 1;
    cout << ", стало " << i_value << endl;
}