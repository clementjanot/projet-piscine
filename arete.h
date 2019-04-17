#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED


class Arete
{

    public:

        Arete(std::string id_arete);
        Arete(std::string id1, std::string id2,double x1, double y1, double x2, double y2);
        void afficherArete()const;
        ~Arete();

        int getCoutEnv()const{

        return m_cout_env;}


        int getCoutFinancier()const{

        return m_cout_fin;}

    private:

        double m_x1,m_y1;
        double m_x2,m_y2;



        float m_cout_env;
        float m_cout_fin;

        std::string m_id;


};
#endif // ARETE_H_INCLUDED
