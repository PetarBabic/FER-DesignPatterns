#include <iostream>
#include <set>

template <typename Iterator, typename Predicate>
Iterator mymax(
        Iterator first, Iterator last, Predicate pred){
    Iterator max = first;

    ++first;

    while(first != last) {
        if(pred(*first, *max) == 1)
            max = first;
        ++first;
    }

    return max;
}

int gt_int(int num1, int num2) {
    return num1 > num2 ? 1: 0;
}
int gt_char(char ch1, char ch2) {
    return ch1 > ch2 ? 1: 0;
}
int gt_str(const std::string& str1, const std::string& str2) {
    return str1 > str2 ? 1: 0;
}

int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
char arr_char[]="Suncana strana ulice";

std::vector<std::string> arr_str = {
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"
};

std::vector<int> vect_int = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
std::set<char> set_char = {'S', 'u', 'n', 'c', 'a', 'n', 'a', ' ', 's', 't', 'r', 'a', 'n', 'a', ' ', 'u', 'l', 'i', 'c', 'e'};

int main(){
    const int* maxint = mymax( &arr_int[0],
                               &arr_int[sizeof(arr_int)/sizeof(*arr_int)], gt_int);
    std::cout <<*maxint <<"\n";

    const char* maxchar = mymax( &arr_char[0],
                               &arr_char[sizeof(arr_char)/sizeof(*arr_char)], gt_char);
    std::cout <<*maxchar <<"\n";

    auto maxstr = mymax(arr_str.begin(), arr_str.end(), gt_str);
    std::cout << *maxstr << "\n";

    auto maxvect = mymax(vect_int.begin(), vect_int.end(), gt_int);
    std::cout << *maxvect << "\n";

    auto maxset = mymax(set_char.begin(), set_char.end(), gt_char);
    std::cout << *maxset << "\n";
}

/*
 Prednost ove implementacije čitljivost koda i type safety.
*/