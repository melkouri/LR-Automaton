#pragma once
#include "Automate.h"
#include <string>
using namespace std;

class Etat {
   public:
      Etat (string nom) : nom(nom) {}
      virtual ~Etat() {};
      virtual bool transition(Automate & automate, Symbole * s) =0;

   protected:
      string nom;
};

class Etat0 : public Etat {
   public:
      Etat0(string nom) : Etat(nom){ }
      virtual ~Etat0() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat1 : public Etat {
   public:
      Etat1(string nom) : Etat(nom){ }
      virtual ~Etat1() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat2 : public Etat {
   public:
      Etat2(string nom) : Etat(nom){ }
      virtual ~Etat2() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat3 : public Etat {
   public:
      Etat3(string nom) : Etat(nom){ }
      virtual ~Etat3() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat4 : public Etat {
   public:
      Etat4(string nom) : Etat(nom){ }
      virtual ~Etat4() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat5 : public Etat {
   public:
      Etat5(string nom) : Etat(nom){ }
      virtual ~Etat5() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat6 : public Etat {
   public:
      Etat6(string nom) : Etat(nom){ }
      virtual ~Etat6() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat7 : public Etat {
   public:
      Etat7(string nom) : Etat(nom){ }
      virtual ~Etat7() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat8 : public Etat {
   public:
      Etat8(string nom) : Etat(nom){ }
      virtual ~Etat8() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};

class Etat9 : public Etat {
   public:
      Etat9(string nom) : Etat(nom){ }
      virtual ~Etat9() { }
      bool transition(Automate & automate, Symbole * s);
   protected:
};
