#include <iostream>
#include <fstream>
#include "VociTable.h"


int main(int argc, char** argv)
{
    if (argc <= 1) {
        std::cerr << "no filename specified" << std::endl;
        return 1;
    }

    std::wifstream file(argv[1]);
    VociTable vt(file);
    file.close();

    vt.runTraining();
}


