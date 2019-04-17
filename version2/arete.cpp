#include"arete.h"




Arete::Arete(std::string id_arete, Sommet* sommet_initial, Sommet* sommet_final) :
    m_id{id_arete}, sommet_init{sommet_initial}, sommet_final{sommet_final}
    {}



void Arete::afficherArete()const
{
    std::cout<<"    "<<m_id;
}

void Arete::afficherSommetsInitiaux() const
{
    std::cout<<"    "<<this->sommet_init->getId();
}

void Arete::afficherSommetsFinaux() const
{
    std::cout<<"    "<<this->sommet_final->getId();
}

std::string Arete::getId( )const
{
    return m_id;
}
