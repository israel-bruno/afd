#include <iostream>
#include "AFD.h"


using namespace std;

int main()
{
    ifstream ifs;
    
    AFD aut(ifs);

    aut.mostra();
    aut.testarPalavras();

    return 0;
}