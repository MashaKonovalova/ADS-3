// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int  Prioritet ( char ch) {
    switch (ch) {
    case  ' ( ' :
        возврат  0 ;
    case  ' ) ' :
        возврат  1 ;
    case  ' + ' :
        возврат  2 ;
    case  ' - ' :
        возврат  2 ;
    case  ' * ' :
        возврат  3 ;
    case  ' / ' :
        возврат  3 ;
    по умолчанию :
        возврат - 1 ;
    }
}

std :: string infx2pstfx (std :: string inf) {
  std :: string pstfx;
    int я = 0 ;
    char ch = inf [я];
    char top = 0 ;
    TStack < char > stackChar;
    while (ch) {
        int pr;
        пр = приоритет (ч);
        if (pr> - 1 ) {
            if ((pr == 0 || pr> priority (top) ||
                stackChar. isEmpty ()) && ch! = ' ) ' ) {
                если (stackChar. isEmpty ())
                    верх = ч;
                stackChar. толкать (ч);
            } else  if (ch == ' ) ' ) {
                while (stackChar. get ()! = ' ( ' ) {
                    pstfx. push_back (stackChar. получить ());
                    pstfx. push_back ( '  ' );
                    stackChar. pop ();
                }
                stackChar. pop ();
                если (stackChar. isEmpty ())
                    верх = 0 ;
            } else {
                в то время как (! stackChar. isEmpty () &&
                       Prioritet (stackChar. get ())> = pr) {
                    pstfx. push_back (stackChar. получить ());
                    pstfx. push_back ( '  ' );
                    stackChar. pop ();
                  }
                если (stackChar. isEmpty ())
                    верх = ч;
                stackChar. толкать (ч);
            }
        } else {
            pstfx. push_back (ch);
            pstfx. push_back ( '  ' );
        }
        ch = inf [++ i];
    }
    while (! stackChar. isEmpty ()) {
        pstfx. push_back (stackChar. получить ());
        pstfx. push_back ( '  ' );
        stackChar. pop ();
    }
    pstfx. стереть (pstfx. end () - 1 , pstfx. end ());
    return pstfx;
}
int  вычисление ( операция char , int n1, int n2) {
    переключатель (операция) {
    case  ' + ' :
        вернуть n1 + n2;
        перерыв ;
    case  ' - ' :
        вернуть n1 - n2;
        перерыв ;
    case  ' * ' :
        вернуть n1 * n2;
        перерыв ;
    case  ' / ' :
        вернуть n1 / n2;
        перерыв ;
    }
}


int  eval (std :: string pst) {
 TStack < int > stackInt;
    int i = 0 , результат = 0 ;
    char ch = pst [я];
    while (ch) {
        if (ch> = ' 0 ' && ch <= ' 9 ' ) {
            int insertInt = 0 ;
            int dec = 1 ;
            while (ch! = '  ' ) {
                insertInt + = (ch - 48 ) * dec;
                уб * = 10 ;
                ch = pst [++ i];
            }
            stackInt. push (insertInt);
        } else {
            char operation = ch;
            i ++;
            int n2 = stackInt. получить ();
            stackInt. pop ();
            int n1 = stackInt. получить ();
            stackInt. pop ();
            int результат = вычисление (операция, n1, n2);
            stackInt. push (результат);
        }
        если (i <pst. size ())
            ch = pst [++ i];
        еще
            ch = 0 ;
    }
    результат = stackInt. получить ();
    stackInt. pop ();
    вернуть результат;
}
