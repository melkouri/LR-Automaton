#include "Automate.h"
#include "symbole.h"
#include <iostream>
#include "Etat.h"
#include <stack>

Automate::Automate (string flux){
   this->pileEtat.push(new Etat0("Etat0"));
   this->l=new Lexer(flux);
   this->error=false;
}

void Automate::decalageTerminal(Symbole * s, Etat * e) {
   pileSymbole.push(s);
   pileEtat.push(e);
   l->Avancer();
}

void Automate::decalageNonTerminal(Symbole * s, Etat * e) {
   pileSymbole.push(s);
   pileEtat.push(e);
}

void Automate::reduction(int n, Symbole * s) {
   for (int i=0;i<n;i++)
   {
      delete(pileEtat.top());
      pileEtat.pop();
   }
   pileEtat.top()->transition(*this,s);
}

void Automate::executer(){
   bool fin = false;
   Symbole * s = this->l->Consulter();
   while(s && !fin && !this->error) {
      Etat * e=this->pileEtat.top();
      fin = e->transition(*this,s);
      s = this->l->Consulter();
   }
   if (!this->error && fin){
      Expression * expResultat = dynamic_cast<Expression *>(this->pileSymbole.top());
      this->resultat = expResultat->getValeur();
   }

}

Automate:: ~Automate(){
   while(!pileEtat.empty()){
      pileEtat.pop();
   }
   while(!pileSymbole.empty()){
      pileSymbole.pop();
   }
}

// fct executer qui appelle l'etat top de la stack et sa fct de transition