#include "symbole.h"
#include "Etat.h"
#include <iostream>

bool Etat0::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:
         automate.decalageTerminal(s, new Etat3("Etat3"));
         break;
      case OPENPAR:
         automate.decalageTerminal(s, new Etat2("Etat2"));
         break;
      case EXPR:
         automate.decalageNonTerminal(s, new Etat1("Etat1"));
         break;
      default:
         automate.error=true;
         break;
   }
   return false;
}

bool Etat1::transition(Automate & automate, Symbole * s){
   switch(*s){
      case PLUS:
         automate.decalageTerminal(s, new Etat4("Etat4"));
         break;
      case MULT:
         automate.decalageTerminal(s, new Etat5("Etat5"));
         break;
      case FIN:
         return true;
      default:
         automate.error=true;
         break;
   }
   return false;
}

bool Etat2::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:
         automate.decalageTerminal(s, new Etat3("Etat3"));
         break;
      case OPENPAR:
         automate.decalageTerminal(s, new Etat2("Etat2"));
         break;
      case EXPR:
         automate.decalageNonTerminal(s, new Etat6("Etat6"));
         break;
      default:
         automate.error=true;
         break;
   }
   return false;
}

bool Etat3::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:  
         break;   
      case OPENPAR:  
         automate.error=true;   
         break;
      case EXPR:
         automate.error=true;   
         break;
      default:
         Entier * s1 = dynamic_cast<Entier *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         ExpConstante *exp = new ExpConstante(s1->getValeur());
         automate.reduction(1, exp);
         break;
   }
   return false;
}

bool Etat4::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:
         automate.decalageTerminal(s, new Etat3("Etat3"));
         break;
      case OPENPAR:
         automate.decalageTerminal(s, new Etat2("Etat2"));
         break;
      case EXPR:
         automate.decalageNonTerminal(s, new Etat7("Etat7"));
         break;
      default:
         automate.error=true;   
         break;
   }
   return false;
}

bool Etat5::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:
         automate.decalageTerminal(s, new Etat3("Etat3"));
         break;
      case OPENPAR:
         automate.decalageTerminal(s, new Etat2("Etat2"));
         break;
      case EXPR:
         automate.decalageNonTerminal(s, new Etat8("Etat8"));
         break;
      default:
         automate.error=true;   
         break;
   }
   return false;
}

bool Etat6::transition(Automate & automate, Symbole * s){
   switch(*s){
      case PLUS:
         automate.decalageTerminal(s, new Etat4("Etat4"));
         break;
      case MULT:
         automate.decalageTerminal(s, new Etat5("Etat5"));
         break;
      case CLOSEPAR:
         automate.decalageTerminal(s, new Etat9("Etat9"));
         break;
      default:
         automate.error=true;   
         break;
   }
   return false;
}

bool Etat7::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT: 
         automate.error=true;   
         break;
      case OPENPAR: 
         automate.error=true;   
         break;
      case EXPR: 
         automate.error=true;   
         break;
      case MULT:
         automate.decalageTerminal(s, new Etat5("Etat5"));
         break;
      default:
         Expression * s1 = dynamic_cast<Expression *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         automate.pileSymbole.pop();
         Expression * s2 = dynamic_cast<Expression *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         ExpPlus * s3 = new ExpPlus(s2,s1);
         automate.reduction(3,s3);
         break;
   }
   return false;
}

bool Etat8::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:   
         automate.error=true;   
         break;
      case OPENPAR:  
         automate.error=true;   
         break;
      case EXPR:  
         automate.error=true;   
         break;
      default:
         Expression * s1 = dynamic_cast<Expression *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         automate.pileSymbole.pop();
         Expression * s2 = dynamic_cast<Expression *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         automate.reduction(3,new ExpMult(s2,s1));
         break;
   }
   return false;
}

bool Etat9::transition(Automate & automate, Symbole * s){
   switch(*s){
      case INT:   
         automate.error=true;   
         break;
      case OPENPAR:  
         automate.error=true;   
         break;
      case EXPR:  
         automate.error=true;   
         break;
      default:
         automate.pileSymbole.pop();
         Expression * s1 = dynamic_cast<Expression *>(automate.pileSymbole.top());
         automate.pileSymbole.pop();
         automate.pileSymbole.pop();
         automate.reduction(3,s1);
         break;
   }
   return false;
}