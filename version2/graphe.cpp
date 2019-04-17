#include <fstream>
#include <iostream>
#include "svgfile.h"
#include "graphe.h"


graphe::graphe(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    std::string id_arete;

    Sommet* sommet1;
    Sommet* sommet2;

    std::string som1;
    std::string som2;
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extrémités

        ifs>>id_arete;
        ifs>>som1;
        ifs>>som2;

        mes_aretes.push_back(new Arete(id_arete,new Sommet{som1,2,3},new Sommet{som2,2,3}));
    }
}
void graphe::afficher() const
{
    std::cout<<"graphe : "<<std::endl;
    std::cout<<"ordre : "<<m_sommets.size()<<std::endl;
    for(auto it=m_sommets.cbegin(); it!=m_sommets.cend(); ++it)
    {
        std::cout<<"sommet :";
        it->second->afficherData();


    }
    std::cout<<"nombre d'aretes : "<<mes_aretes.size()<<std::endl;
    for(int i=0;i<mes_aretes.size();++i)
    {
        mes_aretes[i]->afficherArete();
        mes_aretes[i]->afficherSommetsInitiaux();
        mes_aretes[i]->afficherSommetsFinaux();
        std::cout<<std::endl;


    }


}


void graphe :: dessinerGraphe(Svgfile& svgout) const
{
    for(int i=0;i<mes_aretes.size();++i)
    {
        svgout.addLine(mes_aretes[i]->getSommetInitialX(), mes_aretes[i]->getSommetInitialY(),mes_aretes[i]->getSommetFinalX(), mes_aretes[i]->getSommetFinalY(), "black");
    }

}
graphe::~graphe()
{
    //dtor
}
