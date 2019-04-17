#include <fstream>
#include <iostream>

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
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extrémités
        ifs>>id_arete;
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
        mes_aretes.push_back(new Arete(id_arete));
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
        it->second->afficherVoisins();

    }
    std::cout<< "aretes :"<<std::endl;
    for(int i=0;i<mes_aretes.size();++i)
    {
        mes_aretes[i]->afficherArete();
    }


}



graphe::~graphe()
{
    //dtor
}
