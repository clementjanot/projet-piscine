#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include<string>
#include<iostream>
#include"sommet.h"


class Arete
{

    public:

        Arete();
        Arete(std::string id_arete, Sommet* sommet_initial, Sommet* sommet_final);

        void afficherArete()const;
        void afficherSommetsInitiaux()const;
        void afficherSommetsFinaux()const;
        ~Arete();

        int getCoutEnv()const{

        return m_cout_env;}


        int getCoutFinancier()const{

        return m_cout_fin;}

        std::string getId() const;

        double getSommetInitialX()const
        {
            return m_x1;
        }

        double getSommetInitialY()const
        {
            return m_y1;
        }

        double getSommetFinalX()const
        {
            return m_x2;
        }

        double getSommetFinalY()const
        {
            return m_y2;
        }

    private:

        double m_x1,m_y1;
        double m_x2,m_y2;

        Sommet* sommet_init;
        Sommet* sommet_final;

        float m_cout_env;
        float m_cout_fin;

        std::string m_id;


};

#endif // ARETE_H_INCLUDED
