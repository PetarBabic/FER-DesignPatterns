#include<string.h>
#include <stdio.h>

int gt_int(const void* num1, const void* num2) {
    return *(const int*)num1 > *(const int*)num2 ? 1: 0;
}
int gt_char(const void* ch1, const void* ch2) {
    return *(const char*)ch1 > *(const char*)ch2 ? 1: 0;
}
int gt_str(const void* str1, const void* str2) {
    return strcmp(*(const char**)str1, *(const char**)str2);
}

const void* mymax(
        const void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *)) {

    const char* ptr = (const char*) base;
    const void* max = ptr;

    for(size_t i = 1; i < nmemb - 1; i++) {
        const void *current = ptr + i * size;
        if (compar((const void*)(ptr + i * size), max) > 0) {
            max = current;
        }
    }

    return max;
}

void hello(void) {
    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
            "Gle", "malu", "vocku", "poslije", "kise",
            "Puna", "je", "kapi", "pa", "ih", "njise"
    };


    printf("arr_int[]: %d\n", *(const int*)mymax(arr_int, sizeof(arr_int)/sizeof(int), sizeof(int), gt_int));
    printf("arr_char[]: %c\n", *(const char*)mymax(arr_char, sizeof(arr_char)/sizeof(char), sizeof(char), gt_char));
    printf("arr_str[]: %s\n", *(const char**)mymax(arr_str, sizeof(arr_str) / sizeof(arr_str[0]), sizeof(char*), gt_str));
}

int main() {
    hello();
}