#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Produs
{
private:
  

public:
float cantitate;
  float pret
  string nume;
    Produs (float cantitate1,float pret1,string nume1)
  {
    cantitate=cantitate1;
    pret=pret1;
    nume=nume1;
  }
  Produs (Produs produs)
  {
    cantitate = produs.cantitate;
    pret = produs.cantitate;
    nume = produs.nume;
  }
  Produs (){
    
  }

  friend std::ostream & operator<< (std::ostream & os, const Produs & produs)
  {

	os << produs.cantitate << " "<<produs.pret<<" "<<produs.nume;
      
    return os;
  }
  friend std::istream & operator>> (std::istream & in, Produs & produs)
  {

    in >> produs.cantitate>>" ">>produs.pret>>" ">>produs.nume;
    return in;
  }
};

class Cerere
{
private:


public:
  float cantitate;
  string nume;
    Cerere (float cantitate1,string nume1)
  {
    cantitate = cantitate1;
    nume=nume1;
  }
  Cerere(){

  }

  friend std::ostream & operator<< (std::ostream & os, const Cerere &cerere)
  {

	os << cantitate<<" "<<nume;
      
    return os;
  }
  friend std::istream & operator>> (std::istream & in, Cerere &cerere)
  {

    in >> cantitate>>nume;
    return in;
  }
  void addProdus (const Produs produs){
    produse.push_back(produs);
  }
};

class Magazin
{
private:
  float bani=0;
  Vector<Produs> produse;

public:
    Magazin (Vector<Produs> produse1)
  {
    produse = produse1;
  }

  friend std::ostream & operator<< (std::ostream & os, const Produs & produs)
  {

	os << bani;
       for (auto i = produse.begin(); i != produse.end(); ++i) 
        os<<*i;
    return os;
  }
  friend std::istream & operator>> (std::istream & in, Produs & produs)
  {

    in >> bani;
    return in;
  }
  void addProdus (Produs produs){
    produse.push_back(produs);
  }
  void proceseaza(Cerere cerere){
    for (auto i = produse.begin(); i != produse.end(); ++i) 
        if((*i).nume.compare(cerere.nume)){
          bani+=(*i).pret*cerere.cantitate;
          (*i).cantitate-=cerere.cantitate;
          cout<<"Am vandut "<<cerere.cantitate<<cerere.nume;
        }
  }
};



main ()
{   Magazin magazin;
    Produs produs;
    int produse;
    cin>>produse;
    for(int i=0;i<produse;i++){
      float cantitate;
      cin>>cantitate;
      float pret;
      cin>>pret;
      string nume;
      cin>>nume;
      produs = new Produs(cantitate,pret,nume);
      magazin.addProdus(produs);
    }
    int nrCereri;
    cin>> nrCereri;
    for(int i=0;i<nrCereri;i++){
      Cerere cerere;
      cin>>cerere;
      magazin.proceseaza(cerere);

    }
   
  return 0;
}
