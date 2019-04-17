#include <iostream>
#include "graphe.h"

///MARZE OSCAR WANG DAVID TD8///
///TP2///

int main()
{
        Svgfile svgout;

    graphe g{"broadway.txt"};
    g.afficher();

    g.dessinerGraphe(svgout);


    return 0;
}
