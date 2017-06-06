//Program made by Oussama Ben Ghorbel & Yassine Chaouch, students at MedTech, for educational purposes.
//This program is a design of a popular game known as Hangman.
// For more informations contact us via email : D.oussamabenghorbel@gmail.com || Chaouchyassine@gmail.com.
#include <iostream>
#include <ctime>
#include "Word.h"
#include<fstream>
#include<vector>
#include<string>
using namespace std ;


void game();
//Pre-Condition: Called by the main to run the whole game.
//Post-condition: The whole game is played in this function.

int main()
{
    srand(time(NULL)) ;
   char choice ;
    string s;

   //Open the file dic to read from it.
   ifstream dic("dic.txt");
   //Open both files dic_e and dic_c to write on them.
   ofstream dic_e("easy.txt");
   ofstream dic_c("challenge.txt");
   while (getline(dic,s))
   {
       if (s.size()<7) //If the word read is less than 7 characters length, put it in the easy file.
           dic_e << s << endl;
       else //Else put it in the challenge file.
           dic_c << s << endl;
   }
    //Close all the files to avoid any errors.
   dic.close();
   dic_e.close();
   dic_c.close();

   cout <<"\aWelcome to Hangman-Medtech!"<<endl ;
   _sleep(1500) ;
   cout<<"\a" ;
//The repeating choice.
   do
   {
    system("cls") ;
    game() ;
      do
      {
          cout << endl <<"\n\t\t\tPlay again (P) or Quit (Q)? "<< endl << "\t\t\t"  ;
          fflush(stdin) ;
          cin >>choice ;
          choice=tolower(choice);
      }
      while(choice!='p' && choice!='q') ;
    if (choice=='q')
        cout << "Thanks for playing hangman, see you soon! :D" ;
   }
   while(choice=='p' ) ;

   return 0 ;
}

void game()
{
    int k(0) ;
    Word word_on_play ;
    bool test = true ;
    char done[10]="" ;
    char guess ;
    int mistake(0),mode;
    string file, mode_s;
    int max ;

    //Choosing the mode.
   do
   {
       cout <<"To start the game, you need to choose one of the following modes:"<<endl ;
       cout << "1.Easy Mode" << endl << "2.Challenge mode" << endl ;
       cin >> mode_s ;
   }
   while(mode_s!="1" && mode_s!="2") ;
   if (mode_s=="1")
   mode=1;
   else
   mode=2;

    //Choosing the dictionary file depending on the mode chosen by the user.
   if(mode==1)
   {
       file="easy.txt" ;
       max=8 ;
   }
   else
   {
       file="challenge.txt" ;
       max=7 ;
   }
   word_on_play.loadFile(file.c_str()) ;



   do
   {
       system("cls") ;
       word_on_play.display(mistake,mode) ;
       fflush(stdin) ;
    do
    {
    fflush(stdin) ;
	cin >>guess ;
    guess=tolower(guess);
	//Checking if the mistake is already done.
	for (int i(0); i<=10;i++)
        {

            if (guess==done[i])
            {

                cout << "\n\n\t\t\tYou already did this mistake, this won't be counted." << endl << "\n\t\tMistakes already done: " ;
                for (int i(0); i<10; i++)
                {
                    cout <<done[i] << " , " ;
                }
                cout << endl << "\n\t\t\tEnter a letter: " ;
                test=false;
                break;
            }
            else
            {
                if (!(guess>=97 && guess<=122))
                {
                    cout << "\n\n\t\tOnly an alphabetic letter is considered as a valid guess." << endl;
                    cout << endl << "\n\t\t\tWait 3 seconds and Try again!";
                    _sleep(3000);
                    test=false;
                    system("cls") ;
                    word_on_play.display(mistake,mode) ;
                    break;
                }
            test=true;
            }
        }


    }
    while(test==false) ;

    if(!(word_on_play.decrypt(guess,done,k)))
        {
            mistake++ ;
            cout<<"\a\a" ;
        }
        //End of the game if the mistakes number hit the maximum (case of loss).
        if(mistake==max)
         break ;


   }
   //End of the game if the word is decrypted (case of win).
   while(!word_on_play.win()) ;

//Display.
   system("cls") ;

   //In case of winning.
   if(mistake<max)
   {
     cout <<"\t\t\t _____"<<endl ;


     {
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|      "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|      "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /"<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
         cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /X"<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /X\\"<<endl ;
     cout <<"\t\t\t|     "<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /X\\"<<endl ;
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|    "<<endl ;
     }

     {
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /X\\"<<endl ;
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|    /"<<endl ;
     }

     cout <<"\t\t\t|"<<endl ;
     cout <<"\t\t\t|"<<endl ;

     cout <<"\t\t\t|_________\n\n"<<endl;

     cout << "\n\t\t\tWord:" << word_on_play.getCrypted() << endl;
     cout <<"\n\t\t\tYou Won!"<<endl ;
     cout <<"\n\t\t\tWord is " << word_on_play.getWord() <<endl; ;
   }
   //In case of loss.
   else
   {
     cout <<"\t\t\t _____"<<endl ;

     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|     O"<<endl ;
     cout <<"\t\t\t|    /X\\"<<endl ;
     cout <<"\t\t\t|     |"<<endl ;
     cout <<"\t\t\t|    / \\"<<endl ;

     cout <<"\t\t\t|"<<endl ;
     cout <<"\t\t\t|"<<endl ;
     cout <<"\t\t\t|_________\n\n"<<endl;

     cout << "\n\t\t\tWord: " << word_on_play.getCrypted() << endl;

     cout <<"\n\t\t\tYou Lost! "<<endl ;

     cout <<"\n\t\t\tWord is " << word_on_play.getWord() << endl ;

   }

}





