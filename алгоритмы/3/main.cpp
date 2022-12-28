#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <regex>
#include <functional>

using namespace std;

int main() {
    try {
        std::vector<int> arr;
        arr.at(6);
    } catch (std::out_of_range err) {
        cout << err.what() << "  out of range"<< endl; //std::logic_error
    }

    try {
        vector<int> v;
        v.reserve(v.max_size()+1);
    } catch (std::length_error err) {
        cout << err.what() << "  length" << endl; //std::logic_error
    }

    try {
        stoi("a");
    } catch (std::invalid_argument err) {
        cout << err.what() << "  argument" << endl; //std::logic_error
    }

    try {
        bitset<33> b(10);
        bitset<33> inv = ~b;
        inv.to_ulong();
    } catch (std::overflow_error err) {
        cout << err.what() << "  overflow" << endl; //std::runtime_error
    }

    struct Basic {} b;
    struct Virtual {public: virtual void m(){};} v;

    try {
        dynamic_cast<Basic&>(v);
    } catch (std::bad_cast err) {
        cout << err.what() << "  bad cast" << endl;
    }

    try {
        Virtual* vptr = nullptr;
        typeid(*vptr);
    } catch (std::bad_typeid err) {
        cout << err.what() << "  bad type id" << endl;
    }

    try {
        long long n = 10e17;
        double* arr = new double[n*n];
    } catch (std::bad_alloc err) {
        cout << err.what() << "  bad alloc" << endl;
    }

    try {
        std::regex re("[");
    }
    catch (std::regex_error err) {
        cout << err.what() << "  regex" << endl;
    }

    std::function<int()> f = nullptr;
    try {
        f();
    } catch(std::bad_function_call err) {
        std::cout << err.what() << "  bad function call" << endl;
    }
}