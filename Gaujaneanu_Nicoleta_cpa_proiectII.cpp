#include<iostream>

using namespace std;

class Produs{

    protected:

        int id;
        string nume;
        double pret;

        inline void set_id(int id){this->id = id;}
        inline void set_nume(string s){nume = s;}
        inline void set_pret(double pret){this->pret = pret;}

    public:

        inline int get_id()const{return id;}
        inline string get_nume()const{return nume;}
        inline double get_pret()const{return pret;}


        Produs(int id = 0, string nume = "", double pret = 0):
            id(id), nume(nume), pret(pret){}

        Produs(const Produs& ob):
            id(ob.get_id()), nume(ob.get_nume()), pret(ob.get_pret()){}

        virtual ~Produs(){id = 0; pret = 0; nume.clear();}

        Produs operator=(const Produs& ob){
            set_id(ob.get_id());
            set_nume(ob.get_nume());
            set_pret(ob.get_pret());
            return *this;
        }


        virtual void citire();

        virtual void afisare()const;


        friend istream& operator>>(istream& in, Produs& de_citit);

        friend ostream& operator<<(ostream& out, const Produs& de_afisat);


};

void Produs::citire(){
    cout<<"ID: ";
    int x;
    cin>>x;
    cin.get();
    this->set_id(x);

    cout<<"Nume: ";
    string s;
    getline(cin, s);

    this->set_nume(s);

    cout<<"Pret: ";
    double pret;
    cin>>pret;
    cin.get();
    this->set_pret(pret);
}

void Produs::afisare()const{
    cout<<"ID: "<<this->get_id()<<"\n";
    cout<<"Nume: "<<this->get_nume()<<"\n";
    cout<<"Pret: "<<this->get_pret()<<"\n";
}


istream& operator>>(istream& in, Produs& de_citit){
    de_citit.citire();
    return in;
}

ostream& operator<<(ostream& out, const Produs& de_afisat){
    de_afisat.afisare();
    return out;
}

class Frigider: public Produs{

    private:

        int volum;
        bool areCongelator;

        inline void set_volum(int v){volum = v;}
        inline void set_congelator(bool x){areCongelator = x;}

    public:

        inline int get_volum()const{return volum;}
        inline bool get_congelator()const{return areCongelator;}

        Frigider(int volum = 0, bool areCongelator = false, int id = 0, string nume = "", double pret = 0):
            Produs(id, nume, pret),volum(volum), areCongelator(areCongelator){}

        Frigider(const Frigider& ob):
            Produs(ob), volum(ob.get_volum()), areCongelator(ob.get_congelator()){
                // this->Produs::operator=(ob);
                }
        Frigider operator=(const Frigider& ob){
            Produs::operator=(ob);
            set_volum(ob.get_volum());
            set_congelator(ob.get_congelator());
            return *this;
        }

        ~Frigider(){
            volum = 0;
            areCongelator = false;
        }

        void citire();

        void afisare()const;


        friend istream& operator>>(istream& in, Frigider& de_citit);

        friend ostream& operator<<(ostream& out, const Frigider& de_afisat);

};

void Frigider::citire(){
    this->Produs::citire();
    cout<<"Volum: ";
    int volum;
    cin>>volum;
    cin.get();
    set_volum(volum);

    cout<<"Are Congelator?(0 = NU, 1 = DA) ";
    bool areCongelator;
    cin>>areCongelator;
    cin.get();
    set_congelator(areCongelator);

}

void Frigider::afisare()const{
    this->Produs::afisare();
    cout<<"Volum: "<<get_volum()<<"\n";
    cout<<"Congelator: "<<get_congelator()<<"\n";
}

istream& operator>>(istream& in, Frigider& de_citit){
    de_citit.citire();
    return in;
}

ostream& operator<<(ostream& out, const Frigider& de_afisat){
    de_afisat.afisare();
    return out;
}


class MasinaDeSpalat: public Produs{
    private:

        int rotatiiPeMinut;
        string clasaEnergetica;

        inline void set_rotatiiPeMinut(int x){rotatiiPeMinut = x;}
        inline void set_clasaEnergetica(string s){clasaEnergetica = s;}

    public:

        inline int get_rotatiiPeMinut()const{return rotatiiPeMinut;}
        inline string get_clasaEnergetica()const{return clasaEnergetica;}

        MasinaDeSpalat(int rotatii = 0, string clasa = "", int id = 0, string nume = "", double pret = 0):
            Produs(id, nume, pret), rotatiiPeMinut(rotatii), clasaEnergetica(clasa){}

        MasinaDeSpalat(const MasinaDeSpalat& ob):
            Produs(ob), rotatiiPeMinut(ob.get_rotatiiPeMinut()), clasaEnergetica(ob.get_clasaEnergetica()){}


        ~MasinaDeSpalat(){
            rotatiiPeMinut = 0;
            clasaEnergetica.clear();
        }

        MasinaDeSpalat operator=(const MasinaDeSpalat& ob){
            this->Produs::operator=(ob);
            set_rotatiiPeMinut(ob.get_rotatiiPeMinut());
            set_clasaEnergetica(ob.get_clasaEnergetica());
            return *this;
        }

        void citire();

        void afisare()const;


        friend istream& operator>>(istream& in, MasinaDeSpalat& de_citit);

        friend ostream& operator<<(ostream& out, const MasinaDeSpalat& de_afisat);

};



void MasinaDeSpalat::citire(){
    this->Produs::citire();

    int rotatii;
    cout<<"Rotatii Pe Minut: ";
    cin>>rotatii;
    cin.get();
    set_rotatiiPeMinut(rotatii);

    string clasa;
    cout<<"Clasa Energetica: ";
    getline(cin, clasa);
    set_clasaEnergetica(clasa);

}

void MasinaDeSpalat::afisare()const{
    this->Produs::afisare();
    cout<<"Rotatii Pe Minut: "<<get_rotatiiPeMinut()<<"\n";
    cout<<"Clasa Energetica: "<<get_clasaEnergetica()<<"\n";
}

istream& operator>>(istream& in, MasinaDeSpalat& de_citit){
    de_citit.citire();
    return in;
}

ostream& operator<<(ostream& out, const MasinaDeSpalat& de_afisat){
    de_afisat.afisare();
    return out;
}

class Magazin{

    private:

        int nrMaximProduse;

        Produs** produse;

        int nrCurentProduse;


        inline void set_produse(int nr, Produs** produse_de_adaugat);

        inline void set_produse_curente(int nr_curent, Produs** produse_curente_de_adaugat);

    public:

        inline int get_nrMaximProduse()const{return nrMaximProduse;}

        inline Produs** get_produse()const{return produse;}

        inline int get_nrCurentProduse()const{return nrCurentProduse;}


        void stergere();


        Magazin(int nrProduse = 0):
            nrMaximProduse(nrProduse), nrCurentProduse(0){
                if(nrMaximProduse == 0)
                    produse = NULL;
                else{
                    produse = new Produs*[nrMaximProduse];
                    for(int i = 0; i < nrMaximProduse; i++)
                        produse[i] = NULL;
                }
            }

        Magazin(const Magazin& ob):
            nrMaximProduse(0), nrCurentProduse(0), produse(NULL){
                set_produse(nrMaximProduse, produse);
            }

        ~Magazin(){
            if(produse != NULL){
                for(int i = 0 ; i < nrCurentProduse ; i++)
                    if(produse[i] != NULL)
                        delete produse[i];
                delete [] produse;
            }
            nrCurentProduse = 0;
            nrMaximProduse = 0;
            produse = NULL;
        }

        Magazin operator=(const Magazin& ob){
            set_produse(ob.get_nrMaximProduse(), ob.get_produse());
            return *this;
        }


        friend istream& operator>>(istream& in, Magazin& de_citit);

        friend ostream& operator<<(ostream& out, const Magazin& de_afisat);



        void adaugaProdus(Produs* produs);

        void eliminaProdus(int idProdus);

        Produs* cautaProdus(int idProdus);

        int numaraMasiniDeSpalat();

        void scrieProduse();


};

void Magazin::stergere(){
    if(produse != NULL){
        for(int i = 0; i < nrMaximProduse; i++)
            delete produse[i];
        delete [] produse;
        produse = NULL;
        nrMaximProduse = 0;
    }
}

void Magazin::set_produse(int nr, Produs** produse_de_adaugat){
    if(nrMaximProduse == 0 && nr == 0)
        return;
    else if(nrMaximProduse > 0 && nr == 0){
        stergere();
        nrCurentProduse = 0;

    }
    else if(nrMaximProduse == 0 && nr > 0){
        produse = new Produs*[nr];
        nrCurentProduse = 0;
        if(produse_de_adaugat != NULL){
            for(int i = 0; i < nr; i++){
                if(produse_de_adaugat[i] != NULL){
                    nrCurentProduse++;
                    produse[i] = new Produs(*produse_de_adaugat[i]);
                }
                else produse[i] = NULL;
            }
        }
        else produse = NULL;

        nrMaximProduse = nr;

    }
    else if(nrMaximProduse > 0 && nr > 0){
        stergere();
        nrCurentProduse = 0;
        for(int i = 0; i < nr; i++){
            if(produse_de_adaugat[i] != NULL){
                produse[i] = new Produs(*produse_de_adaugat[i]);
                nrCurentProduse++;
            }
            else produse[i] = NULL;

        }
        nrMaximProduse = nr;
    }
}

void Magazin::set_produse_curente(int nr_curent, Produs** produse_curente_de_adaugat){
    if(nrCurentProduse == 0 && nr_curent == 0)
        return;
    else if(nrCurentProduse > 0 && nr_curent == 0){
        for(int i = 0; i < nrCurentProduse; i++){
            delete produse[i];
            produse[i] = NULL;
        }
        nrCurentProduse = 0;
    }
    else if(nrCurentProduse >= 0 && nr_curent > 0){
        set_produse(nr_curent, produse_curente_de_adaugat);
        nrCurentProduse = nr_curent;
    }
}


istream& operator>>(istream& in, Magazin& de_citit){
    cout<<"Numar Maxim De Produse: ";
    int maxim;
    in>>maxim;
    in.get();

    int curent;

    Produs** vector_auxiliar;

    if(maxim > 0){
        vector_auxiliar = new Produs*[maxim];
        for(int i = 0 ; i < maxim; i++)
            vector_auxiliar[i] = NULL;

        cout<<"Numarul Curent De Produse: ";
        in>>curent;
        in.get();
        for(int i = 0; i < curent; i++){
            vector_auxiliar[i] = new Produs;
            vector_auxiliar[i]->citire();
        }
    }

    else {
        vector_auxiliar = NULL;
        curent = 0;
    }

    de_citit.set_produse(maxim, vector_auxiliar);

    return in;
}

ostream& operator<<(ostream& out, Magazin& de_afisat){
    de_afisat.scrieProduse();
    return out;
}


void Magazin::adaugaProdus(Produs* produs){

    try{
        if(nrCurentProduse + 1 > nrMaximProduse)
            throw "\n MagazinPlinException";

        if(dynamic_cast<Frigider*>(produs) != NULL)
            produse[nrCurentProduse] = new Frigider(*dynamic_cast<Frigider*>(produs));
        else if(dynamic_cast<MasinaDeSpalat*>(produs) != NULL)
            produse[nrCurentProduse] = new MasinaDeSpalat(*dynamic_cast<MasinaDeSpalat*>(produs));
        nrCurentProduse++;

    }
    catch(const char* x){
        cout<<x<<"\n";
    }
    catch(...){
        cout<<"Orice alta exceptie pentru adaugaProdus\n";
    }

}

void Magazin::eliminaProdus(int idProdus){
    try{
        Produs* produsul_nostru = cautaProdus(idProdus);
        if(nrMaximProduse == 0 || nrCurentProduse == 0 || produse == NULL || produsul_nostru == NULL)
            throw "ProdusInexistentException";

        int poz = 0;

        for(int i = 0; i < nrCurentProduse; i++, poz++)
            if(produse[i]->get_id() == idProdus)
                break;
        delete produsul_nostru;
        int j;
        for(j = poz+1; j<nrCurentProduse; j++)
            produse[j-1] = produse[j];
        produse[j] = NULL;
        nrCurentProduse--;

    }
    catch(const char* x){
        cout<<x<<"\n";
    }
    catch(...){
        cout<<"Orice alta exceptie pentru cautaProdus\n";
    }
}

Produs* Magazin::cautaProdus(int idProdus){
    try{
        if(nrMaximProduse == 0 || nrCurentProduse == 0 || produse == NULL)
            throw "ProdusInexistentException";
        for(int i = 0; i < nrCurentProduse; i++)
            if(produse[i]->get_id() == idProdus)
                return produse[i];
        throw "ProdusInexistentException";

    }
    catch(const char* x){
        cout<<x<<"\n";
    }
    catch(...){
        cout<<"Orice alta exceptie pentru cautaProdus\n";
    }
    return NULL;

}

int Magazin::numaraMasiniDeSpalat(){

    if(nrMaximProduse == 0 || nrCurentProduse == 0 || produse == NULL)
        return 0;
    else{
        int nr = 0;
        for(int i = 0 ; i < nrCurentProduse; i++)
            if(dynamic_cast<MasinaDeSpalat*>(produse[i]) != NULL)
                nr++;
        return nr;
    }
}


void Magazin::scrieProduse(){

    if(nrMaximProduse == 0 || nrCurentProduse == 0 || produse == NULL)
        cout<<"Magazinul este gol :( \n";
    else{
        for(int i = 0 ; i < nrCurentProduse; i++){
            for(int j = 1 ; j <= 50; j++)
                cout<<'-';
            cout<<"\n\n";

            produse[i]->afisare();

            cout<<"\n\n";
            for(int j = 1 ; j <= 50; j++)
                cout<<'-';
            cout<<"\n";

        }

    }

}

void comenzi(bool de_afisat = false){
    cout<<"\t\t\t A - Adauga produs (se citesc detaliile de la tastatura)\n";
    cout<<"\t\t\t E - elimina produs (se citeste id produs de la tastatura)\n";
    cout<<"\t\t\t C - cauta produs (se citeste id produs de la tastatura)\n";
    cout<<"\t\t\t N - numara masina de spalat\n";
    cout<<"\t\t\t L - scrie produse\n";
    cout<<"\t\t\t COMENZI - afiseaza comenzile programului\n";
    cout<<"\t\t\t STOP - opreste programul\n\n";

}


int selectare_indice(int n){
    double indice;

    cin>>indice;
    cin.get();

    while(indice > n || indice < 0 || indice - int(indice) != 0){
        cout<<"Indicele tastat este incorect. Mai tastati odata un indice din intervalul [1, "<<n<<"]: ";
        cin>>indice;
        cin.get();
    }
    cout<<"\n";
    return indice;
}

string comanda;

Magazin magazin_electrocasnice;

void rulare_program(){

    cout<<"\nTastati Comanda: ";
    getline(cin, comanda);


    if(comanda == "A"){
        cout<<"\t\t1. Frigider\n";
        cout<<"\t\t2. Masina De Spalat\n";
        cout<<"\nTastati indicele corespunzator optiunii dorite: ";
        int x = selectare_indice(2);

        Produs* ob;

        if(x == 1)
            ob = new Frigider;
        else if(x == 2)
            ob = new MasinaDeSpalat;

        ob->citire();
        magazin_electrocasnice.adaugaProdus(ob);

    }
    else if(comanda == "E"){
        int id;
        cout<<"Tastati ID-ul Produsului pe care doriti sa il eliminati: ";
        cin>>id;
        cin.get();
        cout<<"\n\n";
        magazin_electrocasnice.eliminaProdus(id);
    }
    else if(comanda == "C"){
        int id;
        cout<<"Tastati ID-ul Produsului pe care doriti sa il cautati: ";
        cin>>id;
        cin.get();
        cout<<"\n\n";
        Produs* ob = magazin_electrocasnice.cautaProdus(id);
        if(ob != NULL)
            ob->afisare();
    }
    else if(comanda == "N"){
        cout<<"Numarul de Masini de Spalat este Egal cu "<<magazin_electrocasnice.numaraMasiniDeSpalat()<<"\n";
    }
    else if(comanda == "L"){
        cout<<magazin_electrocasnice;
    }
    else if(comanda == "COMENZI"){
        comenzi();
    }
    else if(comanda == "STOP"){
        return;
    }
    else{
        cout<<"Comanda invalida.\n";

    }
    rulare_program();
}


int main(){

    cout<<"Tastati Numarul Maxim De Produse Ale Magazinului: ";
    int x;
    cin>>x;
    cin.get();

    Magazin aux(x);

    magazin_electrocasnice = aux;


    comenzi(true);
    rulare_program();

    return 0;
}
