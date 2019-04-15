/*-----------------------------
PROJEKT GRY W WISIELCA [C]
DAWID BITNER IA MS INF
-----------------------------*/

/*-----------------------------
AUTOR ASCII-ART MANUS O'DONNELL
�R�D�O ascii.co.uk/art/hangman
-----------------------------*/
 
/*-----------------------------
POLSKIE ZNAKI - �CI�GA:
\206 - �
\210 - �
\230 - �
\242 - �
\245 - �
\251 - �
\253 - �
\276 - �
\344 - �
-----------------------------*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char slowo[1024] = {0}, wskazowka[1024] = {0};					//zmienne globalne
int szanse = 0;

powitanie(){                                                    //funkcja rysuje powitanie na ekranie;
    system("cls");												//funkcja czy�ci ekran konsoli;
   
    printf("888\n");                                                        
    printf("888\n");                                                          
    printf("888\n");                                                          
    printf("88888b.  8888b. 88888b.  .d88b. 88888b.d88b.  8888b. 88888b.\n");  
    printf("888  88b     88b888  88bd88P 88b888  888  88b     88b888  88b\n");
    printf("888  888.d888888888  888888  888888  888  888.d888888888  888\n");
    printf("888  888888  888888  888Y88b 888888  888  888888  888888  888\n");
    printf("888  888 Y888888888  888  Y88888888  888  888 Y888888888  888\n");
    printf("                            888                              \n");
    printf("                        Y8b d88                             \n");
    printf("                         Y88P                               \n\n");
}

tryb_gry(){														//funkcja odpowiada za wyb�r trybu gry;
    char tryb = {0},  poziom;
    int tryb_bool = 0;

    printf("Chcesz zeby slowo podal przeciwnik, czy zeby wygenerowal je program?\n SINGLEPLAYER [S]\n MULTIPLAYER  [M]\n\n");
    tryb=getch();
   
    if(tryb == 's' || tryb == 'S'){
        tryb_bool = 0;
        printf("SINGLEPLAYER\n\n");
    }  
    else if(tryb == 'm' || tryb == 'M'){
        tryb_bool = 1;
        printf("MULTIPLAYER\n\n");
    }
    else{
    	return tryb_gry();
	}
	 
    switch(tryb_bool){											//zale�nie od tego czy tryb_bool ma warto�� 0 lub 1 wywo�uje si� odpowiedni case;
        case 0: {                                               //je�li wybrano singlelayer...
            srand(time(NULL));                                  //zeruje zegar, tak aby za ka�dym razem zosta�a wylosowana nowa liczba pseudolosowa;
            powrot1: printf("Wybierz poziom:\n LATWY  [E]\n SREDNI [M]\n TRUDNY [H]");
            poziom=getch();
           
            if(poziom == 'e' || poziom == 'E') poziom_e();
            else if(poziom == 'm' || poziom == 'M') poziom_m();
            else if(poziom == 'h' || poziom == 'H') poziom_h();
            else {
            	printf("\n");
				goto powrot1;									//je�eli nie wybrano e, m, lub h to idziemy do etykiety powrot1;
			}

            break;
        }
       
        case 1: {                                               //je�li wybrano multiplayer...
            powrot2: fflush(stdin);                             //czy�ci bufor, podczas ponownej gry gets(slowo) byl pomijany;                                
            printf("Podaj slowo:\n");
            gets(slowo);
            if(strlen(slowo)<1) goto powrot2;					//je�eli nie podano s�owa, program prosi by poda� je ponownie;
            printf("Podaj wskazowke:\n");
            gets(wskazowka);
			printf("Wybierz liczbe szans: [5/10/15]\n");
            scanf("%d", &szanse);
            
            if(isdigit(szanse == 5 || szanse == 10 || szanse == 15 )) return gra();
            else{												//je�eli wpisano inn� liczb� ni� 5, 10, lub 15 program sam losuje ile gracz b�dzie mia� szans;
            	srand(time(NULL));
            	int szanse_losowe = 1 + rand()%3;
            	if(szanse_losowe==1) szanse=5;
            	else if(szanse_losowe==2) szanse = 10;
            	else if(szanse_losowe==3) szanse = 15;
            	return gra();
			}
            break;
        }
    }
	
}
 
poziom_e(){														//funkcja odpowiada za poziom �atwy;
    szanse = 15;
    int losowane_slowo;
    losowane_slowo = rand()%15;									//losujemy pseudolosow� liczb� ca�kowit� z przedzia�u 0-14;
    switch(losowane_slowo){										//dla odpowiedniej warto�ci zmiennej losowane_slowo przypisujemy has�o i wskaz�wk�, analogiczna sytuacja zachodzi w funkcjach poziom_m() i poziom_h();
        case 0: strcpy(slowo, "NIEMCY"); strcpy(wskazowka, "s\245siad Polski"); break;
        case 1: strcpy(slowo, "POLSKA"); strcpy(wskazowka, "nasz kraj"); break;
        case 2: strcpy(slowo, "\210OSO�"); strcpy(wskazowka, "ryba"); break;
        case 3: strcpy(slowo, "LEKKOATLETYKA"); strcpy(wskazowka, "jedna z najstarszych dyscyplin sportu"); break;
        case 4: strcpy(slowo, "MORZE BA\210TYCKIE"); strcpy(wskazowka, "nad nim le\276y Polska"); break;
        case 5: strcpy(slowo, "POMIDOR"); strcpy(wskazowka, "czerwona ro\230lina"); break;
        case 6: strcpy(slowo, "GLIWICE"); strcpy(wskazowka, "\230l\245skie miasto"); break;
        case 7: strcpy(slowo, "WARSZAWA"); strcpy(wskazowka, "stolica Polski"); break;
        case 8: strcpy(slowo, "KOPENHAGA"); strcpy(wskazowka, "stolica Danii"); break;
        case 9: strcpy(slowo, "ANTARKTYDA"); strcpy(wskazowka, "zimny kontynent"); break;
        case 10: strcpy(slowo, "\210ADA"); strcpy(wskazowka, "rosyjski samoch\242d"); break;
        case 11: strcpy(slowo, "JEDNORO\276EC"); strcpy(wskazowka, "fantastyczne zwierze, wyst\251pujace w mitach i legendach, podobne do konia"); break;
        case 12: strcpy(slowo, "KIWI"); strcpy(wskazowka, "ptak i owoc"); break;
        case 13: strcpy(slowo, "SYCYLIA"); strcpy(wskazowka, "W\210oska wyspa"); break;
        case 14: strcpy(slowo, "P\242\210WYSEP IBERYJSKI"); strcpy(wskazowka, "jeden z europejskich p\242lwyspow"); break;
    }	
}

poziom_m(){														//funkcja odpowiada za poziom �redni;
    szanse = 10;
    int losowane_slowo;
    losowane_slowo = rand()%15;
    switch(losowane_slowo){
        case 0: strcpy(slowo, "KWAS DEOKSYRYBONUKLEINOWY"); strcpy(wskazowka, "DNA"); break;
        case 1: strcpy(slowo, "KONSTANTYNOPOL"); strcpy(wskazowka, "dawniej Stambu\210"); break;
        case 2: strcpy(slowo, "PEUGEOT"); strcpy(wskazowka, "francuska marka samochod\242w"); break;
        case 3: strcpy(slowo, "SKOK O TYCZCE"); strcpy(wskazowka, "dyscyplina lekkoatletyczna"); break;
        case 4: strcpy(slowo, "TR\242JSKOK"); strcpy(wskazowka, "dyscyplina lekkoatletyczna"); break;
    	case 5: strcpy(slowo, "RABARBAR"); strcpy(wskazowka, "czerwona ro\230lina"); break;
        case 6: strcpy(slowo, "BYTOM"); strcpy(wskazowka, "\230l\245skie miasto"); break;
    	case 7: strcpy(slowo, "PANAMERA"); strcpy(wskazowka, "model Porsche"); break;
        case 8: strcpy(slowo, "RADZIONK\242W"); strcpy(wskazowka, "ma\210e \210l\245skie miasto"); break;
        case 9: strcpy(slowo, "BUDAPESZT"); strcpy(wskazowka, "stolica W\251gier"); break;
        case 10: strcpy(slowo, "BUKARESZT"); strcpy(wskazowka, "stolica Rumunii"); break;
        case 11: strcpy(slowo, "BRASILIA"); strcpy(wskazowka, "stolica Brazylii"); break;
        case 12: strcpy(slowo, "ABORYGEN"); strcpy(wskazowka, "rdzenny mieszkaniec antypod\242w"); break;
        case 13: strcpy(slowo, "BRONHOLM"); strcpy(wskazowka, "Du\344ska wyspa na Ba\210tyku"); break;
        case 14: strcpy(slowo, "KATAR"); strcpy(wskazowka, "gospodarz Mistrzostw \232wiata w pi\210ce no\276nej w 2022 roku"); break;                  
	}
}

poziom_h(){														//funkcja odpowiada za poziom trudny;
	szanse = 5;
	int losowane_slowo;
    losowane_slowo = rand()%15;
    switch(losowane_slowo){
        case 0: strcpy(slowo, "KWAS RYBONUKLEINOWY"); strcpy(wskazowka, "RNA"); break;
        case 1: strcpy(slowo, "INTERPUNKCJA"); strcpy(wskazowka, "graficzny odpowiednik intonacji"); break;
        case 2: strcpy(slowo, "G\276EG\276\242\210ka"); strcpy(wskazowka, "ptak"); break;
        case 3: strcpy(slowo, "\276\242\210\206"); strcpy(wskazowka, "wydzielina w\245troby"); break;
        case 4: strcpy(slowo, "MONTEVIDEO"); strcpy(wskazowka, "stolica Urugwaju"); break;
        case 5: strcpy(slowo, "ANATOMOPATOLOGIA"); strcpy(wskazowka, "dzia\210 anatomii zajmuj\245cy si\251 badaniem zmian w budowie tkanek"); break;
        case 6: strcpy(slowo, "Kiszyni\242w"); strcpy(wskazowka, "stolica Mo\210dawii"); break;
        case 7: strcpy(slowo, "GIBRALTAR"); strcpy(wskazowka, "brytyjskie terytorium zamorskie"); break;
        case 8: strcpy(slowo, "RADZIONK\242W"); strcpy(wskazowka, "ma\210e \210l\245skie miasto"); break;
        case 9: strcpy(slowo, "\230wiatowid"); strcpy(wskazowka, "s\210owia\344ski bo\276ek"); break;
        case 10: strcpy(slowo, "CARACAS"); strcpy(wskazowka, "stolica Wenezuelii"); break;
        case 11: strcpy(slowo, "W\10ADYWOSTOK"); strcpy(wskazowka, "du\276e miasto w azjatyckiej cz\251\230ci Rosji"); break;
        case 12: strcpy(slowo, "SALMONELLA"); strcpy(wskazowka, "rodzaj bakterii"); break;
        case 13: strcpy(slowo, "DURALUMINIUM"); strcpy(wskazowka, "rodzaj stopu metali"); break;
        case 14: strcpy(slowo, "SAPROBIONTY"); strcpy(wskazowka, "organizmy cudzo\276ywne \276yj\245ce w rozk\210adaj\245cej si\251 materii organicznej"); break;
	}
}

gra(){															//funkcja zawiera rdze� gry;
	char podlogi[1024] = {0}, litera;
    int i, p, trafione_litery = 0, wynik = 0, szubienica=szanse/5, krok = 0, rysunek = 0;
    
	powitanie();												//wy�wietla powitanie, wraz z czyszczeniem okna, tak by "hangman" napis w ascii-arcie by� widoczny przez ca�� rozgrywk�;
    printf("WSKAZOWKA: %s \n\n", wskazowka);                    //wy�wietla wskaz�wk�;
   
    for(p=0; p<strlen(slowo); p++){                             //po wczytaniu s�owa p�tla tworzy bli�niaczy char wype�niony '_' o takiej samej d�ugo�ci jak s�owo;
        slowo[p] = toupper(slowo[p]);                           //litery we wpisanym s�owie zostaj� zamienione na wielkie, po to by nie rozr�nia� wielkich i ma�ych liter;
        if(slowo[p]==' '){                                      //je�li w s�owie wyst�puje spacja to na pocz�tku zamiast pod�ogi r�wnie� pokazana jest spacja, tak by nie wprowadza� gracza w b��d co do ilo�ci liter;
            podlogi[p]=' ';
            wynik++;                                            //zwi�kszamy wynik o 1, je�eli w s�owie wyst�puje spacja
        }
        else if(slowo[p]=='-'){                                 //je�li w s�owie wyst�puje my�lnik, to post�puj analogicznie do sytuacji w kt�rej wyst�puje spacja;
            podlogi[p]='-';
            wynik++;
        }
        else{													//w innym przypadku ukrywamy litery pod postaci� pod��g;
        podlogi[p]='_';
        }
    }
    
    printf("%s",podlogi);                                       //wypisanie na wst�pie pod��g, dzi�ki temu gracz zna mniej-wi�cej d�ugo�� s�owa;
    printf("\n Pozostala liczba szans: %d", szanse);    		//wy�wietla liczb� pozosta�ych szans;
 
    while(szanse){                                              //p�tla while wykonuje si� dop�ki istniej� szanse;
        litera=getch();
        litera = toupper(litera);                               //wpisana litera zawsze b�dzie wielka, poniewa� s�owo r�wnie� zostaje ustawione na same wielkie litery;
        powitanie();											//czy�ci ekran i wy�wietla hangmana;
        printf("WSKAZOWKA: %s \n\n", wskazowka);                //wy�wietla wskaz�wk�;
   
        int temp = 0;                                           //zmienna tymczasowa, przy ka�dym wywo�aniu p�tli jej warto�� zostaje ustawiona na 0;
   
        for(i=0; i<strlen(slowo); i++){                         //p�tla wczytuje literk� po literce;
            if(litera==slowo[i]){                               //je�li litera odpowiada literze w s�owie to...(1);
                if(litera==podlogi[i]){                         //je�li pod�oga zamieniona na literk� (2) zosta�a podana ponownie przez u�ytkownika to wy�wietla odpowiedni komunikat...(3);
                    printf("Podales litere podana wczesniej: %c \n", litera);
                    temp++;                                     //zmienna tymczasowa +1;
                    break;                                      //(3) i przerywa dalsz� cz�� p�tli for m.in.: po to �eby do wyniku nie zosta�o dodane 1 i nie zosta�a utracona szansa.
                }  
                podlogi[i]=slowo[i];                            //(1)(2)podlogi zamieniane s� na literki;
                wynik++;                                        //wynik+1;
                temp++;                                         //zmienna tymczasowa +1;
            }        
        }
         

        if(!temp){                                              //je�li zmienna tymczasowa nie zosta�a zwi�kszona to tracimy szanse;
            szanse--;
        	krok++;												//je�li odpowiadamy b��dnie to zwi�kszamy krok rysowania szubienicy;
        	if(krok%szubienica == 0)rysunek++;					//je�li liczba krok�w jest podzielna przez szanse/5 to zwi�kszamy poziom rysunku;
        }
   
         
        for(i=0; i<=strlen(slowo); i++){                        //p�tla wypisuje zamienione pod�ogi na litery je�eli zosta�y zamienione, je�eli nie to pod�ogi;
            printf("%c", podlogi[i]);
        }
        
 
        if(szanse>0){
            printf("\n Pozostala liczba szans: %d", szanse);    //wy�wietla liczb� pozosta�ych szans;
        }
  
  		rysunek_szubienicy(rysunek);							//funckja odpowiada za rysunek wisielca na szubienicy;
        
        if(wynik==strlen(slowo)){                               //je�li ilo�� trafionych liter odpowiada d�ugo�ci s�owa to mamy wygran� i ko�czymy gr�;
            printf("\n%s\n WYGRALES!\n\n", slowo);
            return koniec_gry();								//i przechodzimy od funkcji koniec_gry();
        }
        
        if(szanse==0){
        	printf("\n haslo to: %s\n PORAZKA!\n\n", slowo);	//je�li zostaje 0 szans to wy�wietlany jest komunikat o pora�ce, oraz szgadywane s�owo;
            return koniec_gry();    
		}
 
    }
 
    printf("\n\n");												//dwa entery dla przyjrzysto�ci w grze;
   	
}
 
rysunek_szubienicy(rysunek){									//funkcja odpowiada za rysowanie szubienicy;
	printf("\n");
	if(rysunek == 1){											//je�eli poziom zmiennej rysunek wynosi 1 to wy�wietlany jest pierwszy etap grafiki, dla ka�dego nast�pnego poziomu wyst�puje inny "obrazek", dzi�ki system("cls") poprzedni obrazek zostaj� zast�piony nowym;
		printf("\n ___________.._______\n");
		printf("| .__________))______|\n");
		printf("| | / / \n");
		printf("| |/ / \n");
		printf("| | / \n");
		printf("| |/ \n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n");
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n");  
		printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n");
		printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n");
		printf("| |        \\ \\        | |\n");
		printf(": :         \\ \\       : :\n");  
		printf(". .          `'       . .\n");
	}
		
    else if(rysunek == 2){
		printf("\n ___________.._______\n");
		printf("| .__________))______|\n");
		printf("| | / /      ||\n");
		printf("| |/ /       ||\n");
		printf("| | /        ||.-''.\n");
		printf("| |/         |/  _  \\ \n");
		printf("| |          ||  `/,|\n");
		printf("| |          (\\`_.'\n");
		printf("| |         .-`--'.\n");
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n");
		printf("| |\n");
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n"); 
		printf("| |\n"); 
		printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n");
		printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n");
		printf("| |        \\ \\        | |\n");
		printf(": :         \\ \\       : :\n");  
		printf(". .          `'       . .\n");	
	}
	
    else if(rysunek == 3){
		printf("\n ___________.._______\n");
		printf("| .__________))______|\n");
		printf("| | / /      ||\n");
		printf("| |/ /       ||\n");
		printf("| | /        ||.-''.\n");
		printf("| |/         |/  _  \\ \n");
		printf("| |          ||  `/,|\n");
		printf("| |          (\\`_.'\n");
		printf("| |         .-`--'.\n");
		printf("| |           . . \n");
		printf("| |          |   |\n");
		printf("| |          | . |\n");
		printf("| |          |   |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n");
		printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n");
		printf("| |        \\ \\        | |\n");
		printf(": :         \\ \\       : :\n");  
		printf(". .          `'       . .\n");
		}
    else if(rysunek == 4){
		printf("\n ___________.._______\n");
		printf("| .__________))______|\n");
		printf("| | / /      ||\n");
		printf("| |/ /       ||\n");
		printf("| | /        ||.-''.\n");
		printf("| |/         |/  _  \\ \n");
		printf("| |          ||  `/,|\n");
		printf("| |          (\\`_.'\n");
		printf("| |         .-`--'.\n");
		printf("| |        /Y . . Y\\ \n");
		printf("| |       // |   | \\\\ \n");
		printf("| |      //  | . |  \\\\ \n");
		printf("| |     ')   |   |   (` \n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("| |\n");
		printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n");
		printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n");
		printf("| |        \\ \\        | |\n");
		printf(": :         \\ \\       : :\n");  
		printf(". .          `'       . .\n");    	
	}
	
    else if(rysunek == 5){
		printf("\n ___________.._______\n");
		printf("| .__________))______|\n");
		printf("| | / /      ||\n");
		printf("| |/ /       ||\n");
		printf("| | /        ||.-''.\n");
		printf("| |/         |/  _  \\ \n");
		printf("| |          ||  `/,|\n");
		printf("| |          (\\`_.'\n");
		printf("| |         .-`--'.\n");
		printf("| |        /Y . . Y\\ \n");
		printf("| |       // |   | \\\\ \n");
		printf("| |      //  | . |  \\\\ \n");
		printf("| |     ')   |   |   (`\n");
		printf("| |          ||'||\n");
		printf("| |          || ||\n");
		printf("| |          || ||\n");
		printf("| |          || ||\n");
		printf("| |         / | | \\ \n");
		printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n");
		printf("|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n");
		printf("| |        \\ \\        | |\n");
		printf(": :         \\ \\       : :\n");  
		printf(". .          `'       . .\n"); 	
	}
} 
 
koniec_gry(){                                                   //funkcja w kt�rej pytamy u�ytkownika czy chce zagra� jeszcze raz, czy zako�czy� gr�;
    char koniec;
    
    system("PAUSE");
    powitanie();
    printf("Gra skonczona\nZAMKNIJ PROGRAM [Q]\nZAGRAJ PONOWNIE [R]\n");
    koniec=getch();
    
    if(koniec == 'q' || koniec == 'Q') system("PAUSE");			//je�li gracz wybierze Q to ko�czy dzia�anie programu;
    else if(koniec == 'r' || koniec == 'R') return main();		//gracz chce gra� nadal - wracamy na poczatek programu;
    else return koniec_gry();                                   //u�ytkownik nie wybra� ani Q ani R, wypytujemy go dalej wywo�uj�c t� sam� funkcj�;
}
 
main(){
    system("COLOR 1F");											//ustawia kolor t�a konsoli na niebieski i kolor czcionki na bia�y;
   
	powitanie();												//nast�puje wywo�ywanie kolejnych funkcji po sobie;
	tryb_gry();
	gra();
}
