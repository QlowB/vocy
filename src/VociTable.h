#ifndef VOCITABLE_H
#define VOCITABLE_H 

#include <vector>
#include <fstream>

class VociTable
{
    std::vector<std::wstring> lang1;
    std::vector<std::wstring> lang2;

public:

    VociTable(std::wifstream& in);

    void runTraining(void);
private:

    void runMultipleChoice(void);
};

#endif /* VOCITABLE_H */
