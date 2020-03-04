#include "String.h"

int main(){

    String s;
    String t("Hello");
    String r = "World";
    std::cout << t << " " << r << std::endl;

    s = t + " " + r;
    std::cout << s << std::endl;

    s = s - r;
    s = s + "Again";
    std::cout << s << std::endl;
}
