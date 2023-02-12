﻿#include "API/sshell_api.h"

double sum(double x, double y){
    return x + y;
}

int main() {
    SOSH_Manager Manager;
    Manager.CreateShell("Shell1");
    SOSH_Shell Shell1 = Manager.FindShell("Shell1");

    SOSH_Function func("sum", sum);
    Shell1.AddFunction(func);
    SOSH_Function func2 = Shell1.FindFunction("sum");

    double f = 3, k = 7;
    std::cout << func2.Run(f, k) << std::endl;


    SOSH_Parser pars;
    std::vector<SOSH_Token> out;
    out = pars.Tokenize("sum qwer 4.667 8");

    std::cout << out[0].Value() << std::endl;
    std::cout << out[1].Value() << std::endl;
    std::cout << out[2].Value() << std::endl;
    std::cout << out[3].Value() << std::endl;

    /*std::cout << out[0].TestToken() << " " << out[0].TestValue() << std::endl;
    std::cout << out[1].TestToken() << " " << out[1].TestValue() << std::endl;
    std::cout << out[2].TestToken() << " " << out[2].TestValue() << std::endl;
    std::cout << out[3].TestToken() << " " << out[3].TestValue() << std::endl;*/


    //for (auto &s: out) {
    //    std::cout << s << std::endl;
    //}

    /*
    Shell1.DeclareFunction("summ");
    std::cout << "Get: " << Shell1.FindFunction("summ").get() << std::endl;
    std::vector<SOSH_Function> list;
    list = Shell1.ListFunction();
    std::cout << "List: " << std::endl;
    for (int i = 0; i < list.size(); i++) {
        std::cout << list.at(i).get() << std::endl;
    }
    return 0;
    */
};
