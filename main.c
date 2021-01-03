/**
 * x86_64 64 bit bitwise rotate right
 */
static inline unsigned long long rorq(unsigned long long var, unsigned short amount) {
    __asm__("rorq %%cl,%0" : "=r" (var) : "0" (var), "c" (amount));
    return var;
}

/**
 * x86_64 64 bit bitwise rotate left
 */
static inline unsigned long long rolq(unsigned long long var, unsigned short amount) {
    __asm__("rolq %%cl,%0" : "=r" (var) : "0" (var), "c" (amount));
    return var;
}

// matrix positions
#define pos0_0 0
#define pos1_0 1
#define pos2_0 2
#define pos3_0 3
#define pos4_0 4
#define pos5_0 5
#define pos6_0 6
#define pos1_1 7
#define pos2_1 8
#define pos3_1 9
#define pos4_1 10
#define pos5_1 11
#define pos2_2 12
#define pos3_2 13
#define pos4_2 14
#define pos3_3 15
#define pos7_0 16
#define pos7_1 17
#define pos7_2 18
#define pos7_3 19
#define pos7_4 20
#define pos7_5 21
#define pos7_6 22
#define pos6_1 23
#define pos6_2 24
#define pos6_3 25
#define pos6_4 26
#define pos6_5 27
#define pos5_2 28
#define pos5_3 29
#define pos5_4 30
#define pos4_3 31
#define pos7_7 32
#define pos6_7 33
#define pos5_7 34
#define pos4_7 35
#define pos3_7 36
#define pos2_7 37
#define pos1_7 38
#define pos6_6 39
#define pos5_6 40
#define pos4_6 41
#define pos3_6 42
#define pos2_6 43
#define pos5_5 44
#define pos4_5 45
#define pos3_5 46
#define pos4_4 47
#define pos0_7 48
#define pos0_6 49
#define pos0_5 50
#define pos0_4 51
#define pos0_3 52
#define pos0_2 53
#define pos0_1 54
#define pos1_6 55
#define pos1_5 56
#define pos1_4 57
#define pos1_3 58
#define pos1_2 59
#define pos2_5 60
#define pos2_4 61
#define pos2_3 62
#define pos3_4 63

int main() {
    unsigned long long a = rorq(10, 16);
    unsigned long long b = rolq(10, 48);
    int result = a == b;
    a++;
}
