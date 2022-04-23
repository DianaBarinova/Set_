#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class  Set {
public:
    virtual void mult(const  Set*, const Set*) = 0;
    virtual void add(const  Set*, const  Set*) = 0;
    virtual void sim_sub(const Set*, const Set*) = 0;
    virtual void print() = 0;
};
class Set_int : public Set {
public:
    vector<int> set;
    vector <int> res;
    Set_int(vector<int> v = {}) :set(v) {};
    void print() override {
        for (auto i : res)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    void add(const Set* x1, const Set* x2) override { //объединение
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) res.push_back(a->set[i++]);
            else if (b->set[j] < a->set[i]) res.push_back(b->set[j++]);
            else {
                res.push_back(b->set[j++]);
                i++;
            }
        }
        while (i < a->set.size())
            res.push_back(a->set[i++]);
        while (j < b->set.size())
            res.push_back(b->set[j++]);
    }
    void mult(const Set* x1, const Set* x2) override {
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j])
                i++;
            else if (b->set[j] < a->set[i])
                j++;
            else {
                res.push_back(b->set[j]);
                i++;
                j++;
            }
        }
    }
    void sim_sub(const Set* x1, const Set* x2) override {
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) {
                res.push_back(a->set[i++]);
            }
            else if (b->set[j] < a->set[i]) {
                res.push_back(b->set[j++]);
            }
            else {
                i++;
                j++;
            }
        }
        while (i < a->set.size()) {
            res.push_back(a->set[i++]);
        }
        while (j < b->set.size()) {
            res.push_back(b->set[j++]);
        }
    }
};
class Set_string : public Set {
public:
    vector<string> set;
    vector <string> res;
    Set_string(vector<string> v = {}) :set(v) {};
    void print() override {
        for (auto i : res)
            std::cout << i << ' ';
        cout << '\n';
    }
    void add(const Set* x1, const Set* x2) override { //объединение
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) res.push_back(a->set[i++]);
            else if (b->set[j] < a->set[i]) res.push_back(b->set[j++]);
            else {
                res.push_back(b->set[j++]);
                i++;
            }
        }
        while (i < a->set.size())
            res.push_back(a->set[i++]);
        while (j < b->set.size())
            res.push_back(b->set[j++]);
    }
    void mult(const Set* x1, const Set* x2) override {
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j])
                i++;
            else if (b->set[j] < a->set[i])
                j++;
            else {
                res.push_back(b->set[j]);
                i++;
                j++;
            }
        }
    }
    void sim_sub(const Set* x1, const Set* x2) override {
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
if (a->set[i] < b->set[j]) {
    res.push_back(a->set[i++]);
}
else if (b->set[j] < a->set[i]) {
    res.push_back(b->set[j++]);
}
else {
    i++;
    j++;
}
    }
    while (i < a->set.size()) {
        res.push_back(a->set[i++]);
    }
    while (j < b->set.size()) {
        res.push_back(b->set[j++]);
    }
  }
};

int main() {
    vector <int> a1 = { 1,2, 3 };
    vector <int> b1 = { 2,3, 4 };

    Set_int A1(a1);
    Set_int B1(b1);
    Set_int C1;
    C1.mult(&A1, &B1);
    C1.print();

    vector <string> a2 = { "a" , "b", "c" };
    vector <string> b2 = { "b" , "c", "d" };

    Set_string A2(a2);
    Set_string B2(b2);
    Set_string C2;
    C2.add(&A2, &B2);
    C2.print();
}