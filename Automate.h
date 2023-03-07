#pragma once
#include "lexer.h"
#include <string>
#include <stack>
using namespace std;

class Etat;
class Automate {
   public:
   Automate (string flux);  
   virtual ~Automate();
   void decalageTerminal(Symbole * s, Etat * e);
   void decalageNonTerminal(Symbole * s, Etat * e);
   void reduction(int n, Symbole * s);
   void executer();
   public:
      stack <Etat *> pileEtat;
      stack <Symbole *> pileSymbole;
      Lexer *l;
      int resultat;
      bool error;
};


