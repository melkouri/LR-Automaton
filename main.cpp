#include <iostream>
#include "lexer.h"
#include "Automate.h"

int main(void) {
   string chaine("");
   
   cout <<"Information : Pour stopper l'automate de calcul, veuillez entrer le mot STOP"<<endl;
   do
   {
      cout << "Veuillez entrer une formule mathématique: " << endl;

      cin >> chaine;
      if (chaine =="STOP"){
         break;
      }
      Automate automate(chaine);
      automate.executer();
      if (!automate.error){
      
         cout << "Le résultat du calcul est : "<< automate.resultat<<endl;
      }else{
         cout << " Une erreur a été remarqué! Veuillez vérifier la syntaxe de la chaîne"<<endl;
      }

   } while (true);

  
   return 0;
}

