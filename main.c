#include "string_.h"
#include <assert.h>

int isLetter(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void testStrlen() {
    const char *str = "Hello, World!";
    const char *str2 = "";
    size_t length1 = strlen_(str);
    size_t length2 = strlen_(str2);
    assert(length1 == 13 && length2 == 0);
}

void testFind() {
    char str[] = "Hello, World!";
    char *found = find(str, str + 13, 'W');
    char *found2 = find(str, str + 13, ',');
    assert(*found == 'W' && *found2 == ',');
}

void testFindNonSpace() {
    char str[] = "   Hello, World!  ";
    char str2[] = "A        W";
    char *nonSpace = findNonSpace(str);
    char *nonSpace2 = findNonSpace(str2);
    assert(*nonSpace == 'H' && *nonSpace2 == 'A');
}

void testFindSpace() {
    char str[] = "Hello, World!";
    char str2[] = "H e l l o, W o r l d !";
    char *space = findSpace(str);
    char *space2 = findSpace(str2);
    assert(*space == ' ' && *space2 == ' ');
}

void testFindSpaceReverse() {
    char str[] = "Hello, World!";
    char str2[] = "Hello, W orld!";
    char *rend = str - 1;
    char *rbegin = findSpaceReverse(str + 13, rend);
    char *rbegin2 = findSpaceReverse(str2 + 13, rend);
    assert(*rbegin == 'W' && *rbegin2 == 'o');
}

void testFindNonSpaceReverse() {
    char str[] = "   Hello, World!  ";
    char str2[] = "Hello, World!   ";
    char *rend = str - 1;
    char *rend2 = str2 - 1;
    char *rbegin = findNonSpaceReverse(str + 15, rend);
    char *rbegin2 = findNonSpaceReverse(str2 + 10, rend2);
    assert(*rbegin == '!' && *rbegin2 == 'l');
}

void testStrcmp() {
    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Hello";

    assert(strcmp(str1, str2) < 0 && strcmp(str1, str3) >= 0);
}

void testCopy() {
    const char *str = "Hello, World!";
    const char *str2 = ",World!";
    char destination[20];
    char *nextFree = copy(str, str + 14, destination);
    char *nextFree2 = copy(str2, str2 + 7, destination);
    assert(nextFree - destination == 14 && nextFree2 - destination == 7);
}

void testCopyIf() {
    char* str = "Hello123World456";
    char destination[20];
    char destination2[20];
    copyIf(str, str + 14, destination, isLetter);
    copyIf(str, str + 14, destination2, isdigit);
    assert(*destination == 'H' && *(destination + 1) == 'e' && *(destination + 2) == 'l' && *(destination + 3) == 'l' && *(destination + 4) == 'o');
    assert(*destination2 == '1' && *(destination2 + 1) == '2' && *(destination2 + 2) == '3' && *(destination2 + 3) == '4');
}

void testCopyIfReverse() {
    char* str = "Hello123World456";
    char destination[20];
    char destination2[20];
    copyIfReverse(str + 14, str, destination, isLetter);
    copyIfReverse(str + 14, str, destination2, isdigit);
    assert(*destination == 'd' && *(destination + 1) == 'l' && *(destination + 2) == 'r' && *(destination + 3) == 'o' && *(destination + 4) == 'W');
    assert(*destination2 == '4' && *(destination2 + 1) == '3' && *(destination2 + 2) == '2' && *(destination2 + 3) == '1');
}

void test() {
    testStrlen();
    testFind();
    testFindNonSpace();
    testFindSpace();
    testFindSpaceReverse();
    testFindNonSpaceReverse();
    testStrcmp();
    testCopy();
    testCopyIf();
    testCopyIfReverse();
}

int main() {
    test();

    return 0;
}