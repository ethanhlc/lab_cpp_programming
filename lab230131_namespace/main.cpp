#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Function defined in BestCom" << std::endl;
    }
}

namespace ProgComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Function defined in ProgCom" << std::endl;
    }
}

int main(void)
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}
