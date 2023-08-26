#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

#define color(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (x))

int main() {
    srand(time(nullptr));
    int test = 1, ac = 0, wa = 0, re = 0;
    int num;
    cout << "Test number: ";
    cin >> num;
    while (test <= num) {
        color(14);
        system(("echo " + to_string(rand()) + " > seed.txt").c_str());
        system("gen.exe < seed.txt > input.in");
        unsigned res = system("sol.exe < input.in > sol.out");
        system("bf.exe < input.in > bf.out");
        system("pause");
        if (res != 0) {
            system("cls");
            color(13);
            cout << "Runtime Error on test " << test << endl;
            color(14);
            cout << endl;
            cout << "Input:" << endl;
            system("type input.in");
            cout << endl;
            cout << "Correct Output:" << endl;
            system("type bf.out");
            cout << endl;
            cout << "Your Output:" << endl;
            cout << "---" << endl;
            cout << endl;
            cout << "Exit Code:" << endl;
            cout << res << endl;
            re++;
            cout << endl;
        } else if (system("fc > nul sol.out bf.out")) {
            system("cls");
            color(12);
            cout << "Wrong Answer on test " << test << endl;
            color(14);
            cout << endl;
            cout << "Input:" << endl;
            system("type input.in");
            cout << endl;
            cout << "Correct Output:" << endl;
            system("type bf.out");
            cout << endl;
            cout << "Your Output:" << endl;
            system("type sol.out");
            wa++;
            cout << endl;
        } else {
            system("cls");
            color(10);
            cout << "Accepted on test " << test << endl;
            color(14);
            cout << endl;
            cout << "Input:" << endl;
            system("type input.in");
            cout << endl;
            cout << "Correct Output:" << endl;
            system("type bf.out");
            cout << endl;
            cout << "Your Output:" << endl;
            system("type sol.out");
            ac++;
            cout << endl;
        }
        color(14);
        cout << "Score: " << floor(100.0 * (double)ac / (double)test) << endl;
        test++;
    }
    test--;
    system("cls");
    color(15);
    cout << "Result" << endl;
    color(14);
    cout << "Test number: " << test << endl;
    if (ac) {
        color(10);
        cout << "Accepted: " << ac << endl;
    }
    if (wa) {
        color(12);
        cout << "Wrong Answer: " << wa << endl;
    }
    if (re) {
        color(13);
        cout << "Runtime Error: " << re << endl;
    }
    color(15);
    cout << "Score: " << floor(100.0 * (double)ac / (double)test) << endl;
    color(15);
    return 0;
}

