#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}


void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}



void Expression::Affiche() { Symbole::Affiche(); }

void ExpBinaire::Affiche() { Symbole::Affiche(); }

void ExpConstante::Affiche() { Symbole::Affiche(); }

void ExpPlus::Affiche() { Symbole::Affiche(); }

void ExpMult::Affiche() { Symbole::Affiche(); }

ExpPlus::ExpPlus(Expression * exp1 , Expression * exp2){
   this->valeur=exp1->getValeur()+exp2->getValeur();
}

ExpMult::ExpMult(Expression * exp1 , Expression * exp2){
   this->valeur=exp1->getValeur()*exp2->getValeur();
}

int Entier::getValeur()
{
   return valeur;
}

int ExpConstante::getValeur()
{
   return valeur;
}

int ExpBinaire::getValeur()
{
   return valeur;
}
int ExpPlus::getValeur()
{
   return valeur;
}
int ExpMult::getValeur()
{
   return valeur;
}

