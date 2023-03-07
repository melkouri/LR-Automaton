#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" , "EXPRESSION"};

class Symbole {
   public:
      Symbole(int i) : ident(i){  }
      Symbole()  { }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   public:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
   public:
      int valeur;
};



class Expression : public Symbole {
   public:
      Expression() : Symbole(EXPR)  { }
      ~Expression() { }
      virtual void Affiche() =0;
      virtual int getValeur() =0;
   protected:
};

class ExpConstante: public Expression {
   public:
      ExpConstante(int val) :  valeur(val){ }
      ExpConstante()  { }
      ~ExpConstante() { }
      virtual void Affiche();
      virtual int getValeur();
   protected:
      int valeur;
};

class ExpBinaire: public Expression {
   public:
      ExpBinaire(Expression * exp1 , Expression * exp2) { }
      ExpBinaire()  { }
      ~ExpBinaire() { }
      virtual void Affiche();
      virtual int getValeur();
   protected:
      int valeur;
};

class ExpPlus: public ExpBinaire {
   public:
      ExpPlus(Expression * exp1 , Expression * exp2);
      ~ExpPlus() { }
      virtual void Affiche();
      virtual int getValeur();
   protected:
      int valeur;
};

class ExpMult: public ExpBinaire {
   public:
      ExpMult(Expression * exp1 , Expression * exp2);
      ~ExpMult() { }
      virtual void Affiche();
      virtual int getValeur();
   protected:
      int valeur;
};