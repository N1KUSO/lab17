#include "string_.h"
#include <assert.h>

int isLetter(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void testStrlen() {
    const char *str = "Hello, World!";
    size_t length = strlen_(str);
    assert(length == 13);
}

void testFind() {
    char str[] = "Hello, World!";
    char *found = find(str, str + 13, 'W');
    assert(*found == 'W');
}

void testFindNonSpace() {
    char str[] = "   Hello, World!  ";
    char *nonSpace = findNonSpace(str);
    assert(*nonSpace == 'H');
}

void testFindSpace() {
    char str[] = "Hello, World!";
    char *space = findSpace(str);
    assert(*space == ' ');
}

void testFindSpaceReverse() {
    char str[] = "Hello, World!";
    char *rend = str - 1;
    char *rbegin = findSpaceReverse(str + 13, rend);
    assert(*rbegin == 'W');
}

void testFindNonSpaceReverse() {
    char str[] = "   Hello, World!  ";
    char *rend = str - 1;
    char *rbegin = findNonSpaceReverse(str + 15, rend);
    assert(*rbegin == '!');
}

void testStrcmp() {
    const char *str1 = "Hello";
    const char *str2 = "World";
    assert(strcmp(str1, str2) < 0);
}

void testCopy() {
    const char *str = "Hello, World!";
    char destination[20];
    char *nextFree = copy(str, str + 14, destination);
    assert(nextFree - destination == 14);
}

void testCopyIf() {
    char* str = "Hello123World456";
    char destination[20];
    copyIf(str, str + 14, destination, isLetter);
    assert(*destination == 'H' && *(destination + 1) == 'e' && *(destination + 2) == 'l' && *(destination + 3) == 'l' && *(destination + 4) == 'o');
}

void testCopyIfReverse() {
    char* str = "Hello123World456";
    char destination[20];
    copyIfReverse(str + 14, str, destination, isLetter);
    assert(*destination == 'd' && *(destination + 1) == 'l' && *(destination + 2) == 'r' && *(destination + 3) == 'o' && *(destination + 4) == 'W');
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