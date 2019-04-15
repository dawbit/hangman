/*-----------------------------
PROJEKT GRY W WISIELCA [C]
DAWID BITNER IA MS INF
-----------------------------*/

/*-----------------------------
AUTOR ASCII-ART MANUS O'DONNELL
èR”D£O ascii.co.uk/art/hangman
-----------------------------*/
 
/*-----------------------------
POLSKIE ZNAKI - åCI•GA:
\206 - Ê
\210 - ≥
\230 - ú
\242 - Û
\245 - π
\251 - Í
\253 - ü
\276 - ø
\344 - Ò
-----------------------------*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char slowo[1024] = {0}, wskazowka[1024] = {0};					//zmienne globalne
int szanse = 0;

powitanie(){                                                    //funkcja rysuje powitanie na ekranie;
    system("cls");												//funkcja czyúci ekran konsoli;
   
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

tryb_gry(){														//funkcja odpowiada za wybÛr trybu gry;
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
	 
    switch(tryb_bool){											//zaleønie od tego czy tryb_bool ma wartoúÊ 0 lub 1 wywo≥uje siÍ odpowiedni case;
        case 0: {                                               //jeúli wybrano singlelayer...
            srand(time(NULL));                                  //zeruje zegar, tak aby za kaødym razem zosta≥a wylosowana nowa liczba pseudolosowa;
            powrot1: printf("Wybierz poziom:\n LATWY  [E]\n SREDNI [M]\n TRUDNY [H]");
            poziom=getch();
           
            if(poziom == 'e' || poziom == 'E') poziom_e();
            else if(poziom == 'm' || poziom == 'M') poziom_m();
            else if(poziom == 'h' || poziom == 'H') poziom_h();
            else {
            	printf("\n");
				goto powrot1;									//jeøeli nie wybrano e, m, lub h to idziemy do etykiety powrot1;
			}

            break;
        }
       
        case 1: {                                               //jeúli wybrano multiplayer...
            powrot2: fflush(stdin);                             //czyúci bufor, podczas ponownej gry gets(slowo) byl pomijany;                                
            printf("Podaj slowo:\n");
            gets(slowo);
            if(strlen(slowo)<1) goto powrot2;					//jeøeli nie podano s≥owa, program prosi by podaÊ je ponownie;
            printf("Podaj wskazowke:\n");
            gets(wskazowka);
			printf("Wybierz liczbe szans: [5/10/15]\n");
            scanf("%d", &szanse);
            
            if(isdigit(szanse == 5 || szanse == 10 || szanse == 15 )) return gra();
            else{												//jeøeli wpisano innπ liczbÍ niø 5, 10, lub 15 program sam losuje ile gracz bÍdzie mia≥ szans;
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
 
poziom_e(){														//funkcja odpowiada za poziom ≥atwy;
    szanse = 15;
    int losowane_slowo;
    losowane_slowo = rand()%15;									//losujemy pseudolosowπ liczbÍ ca≥kowitπ z przedzia≥u 0-14;
    switch(losowane_slowo){										//dla odpowiedniej wartoúci zmiennej losowane_slowo przypisujemy has≥o i wskazÛwkÍ, analogiczna sytuacja zachodzi w funkcjach poziom_m() i poziom_h();
        case 0: strcpy(slowo, "NIEMCY"); strcpy(wskazowka, "s\245siad Polski"); break;
        case 1: strcpy(slowo, "POLSKA"); strcpy(wskazowka, "nasz kraj"); break;
        case 2: strcpy(slowo, "\210OSOå"); strcpy(wskazowka, "ryba"); break;
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

poziom_m(){														//funkcja odpowiada za poziom úredni;
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

gra(){															//funkcja zawiera rdzeÒ gry;
	char podlogi[1024] = {0}, litera;
    int i, p, trafione_litery = 0, wynik = 0, szubienica=szanse/5, krok = 0, rysunek = 0;
    
	powitanie();												//wyúwietla powitanie, wraz z czyszczeniem okna, tak by "hangman" napis w ascii-arcie by≥ widoczny przez ca≥π rozgrywkÍ;
    printf("WSKAZOWKA: %s \n\n", wskazowka);                    //wyúwietla wskazÛwkÍ;
   
    for(p=0; p<strlen(slowo); p++){                             //po wczytaniu s≥owa pÍtla tworzy bliüniaczy char wype≥niony '_' o takiej samej d≥ugoúci jak s≥owo;
        slowo[p] = toupper(slowo[p]);                           //litery we wpisanym s≥owie zostajπ zamienione na wielkie, po to by nie rozrÛøniaÊ wielkich i ma≥ych liter;
        if(slowo[p]==' '){                                      //jeúli w s≥owie wystÍpuje spacja to na poczπtku zamiast pod≥ogi rÛwnieø pokazana jest spacja, tak by nie wprowadzaÊ gracza w b≥πd co do iloúci liter;
            podlogi[p]=' ';
            wynik++;                                            //zwiÍkszamy wynik o 1, jeøeli w s≥owie wystÍpuje spacja
        }
        else if(slowo[p]=='-'){                                 //jeúli w s≥owie wystÍpuje myúlnik, to postÍpuj analogicznie do sytuacji w ktÛrej wystÍpuje spacja;
            podlogi[p]='-';
            wynik++;
        }
        else{													//w innym przypadku ukrywamy litery pod postaciπ pod≥Ûg;
        podlogi[p]='_';
        }
    }
    
    printf("%s",podlogi);                                       //wypisanie na wstÍpie pod≥Ûg, dziÍki temu gracz zna mniej-wiÍcej d≥ugoúÊ s≥owa;
    printf("\n Pozostala liczba szans: %d", szanse);    		//wyúwietla liczbÍ pozosta≥ych szans;
 
    while(szanse){                                              //pÍtla while wykonuje siÍ dopÛki istniejπ szanse;
        litera=getch();
        litera = toupper(litera);                               //wpisana litera zawsze bÍdzie wielka, poniewaø s≥owo rÛwnieø zostaje ustawione na same wielkie litery;
        powitanie();											//czyúci ekran i wyúwietla hangmana;
        printf("WSKAZOWKA: %s \n\n", wskazowka);                //wyúwietla wskazÛwkÍ;
   
        int temp = 0;                                           //zmienna tymczasowa, przy kaødym wywo≥aniu pÍtli jej wartoúÊ zostaje ustawiona na 0;
   
        for(i=0; i<strlen(slowo); i++){                         //pÍtla wczytuje literkÍ po literce;
            if(litera==slowo[i]){                               //jeúli litera odpowiada literze w s≥owie to...(1);
                if(litera==podlogi[i]){                         //jeúli pod≥oga zamieniona na literkÍ (2) zosta≥a podana ponownie przez uøytkownika to wyúwietla odpowiedni komunikat...(3);
                    printf("Podales litere podana wczesniej: %c \n", litera);
                    temp++;                                     //zmienna tymczasowa +1;
                    break;                                      //(3) i przerywa dalszπ czÍúÊ pÍtli for m.in.: po to øeby do wyniku nie zosta≥o dodane 1 i nie zosta≥a utracona szansa.
                }  
                podlogi[i]=slowo[i];                            //(1)(2)podlogi zamieniane sπ na literki;
                wynik++;                                        //wynik+1;
                temp++;                                         //zmienna tymczasowa +1;
            }        
        }
         

        if(!temp){                                              //jeúli zmienna tymczasowa nie zosta≥a zwiÍkszona to tracimy szanse;
            szanse--;
        	krok++;												//jeúli odpowiadamy b≥Ídnie to zwiÍkszamy krok rysowania szubienicy;
        	if(krok%szubienica == 0)rysunek++;					//jeúli liczba krokÛw jest podzielna przez szanse/5 to zwiÍkszamy poziom rysunku;
        }
   
         
        for(i=0; i<=strlen(slowo); i++){                        //pÍtla wypisuje zamienione pod≥ogi na litery jeøeli zosta≥y zamienione, jeøeli nie to pod≥ogi;
            printf("%c", podlogi[i]);
        }
        
 
        if(szanse>0){
            printf("\n Pozostala liczba szans: %d", szanse);    //wyúwietla liczbÍ pozosta≥ych szans;
        }
  
  		rysunek_szubienicy(rysunek);							//funckja odpowiada za rysunek wisielca na szubienicy;
        
        if(wynik==strlen(slowo)){                               //jeúli iloúÊ trafionych liter odpowiada d≥ugoúci s≥owa to mamy wygranπ i koÒczymy grÍ;
            printf("\n%s\n WYGRALES!\n\n", slowo);
            return koniec_gry();								//i przechodzimy od funkcji koniec_gry();
        }
        
        if(szanse==0){
        	printf("\n haslo to: %s\n PORAZKA!\n\n", slowo);	//jeúli zostaje 0 szans to wyúwietlany jest komunikat o poraøce, oraz szgadywane s≥owo;
            return koniec_gry();    
		}
 
    }
 
    printf("\n\n");												//dwa entery dla przyjrzystoúci w grze;
   	
}
 
rysunek_szubienicy(rysunek){									//funkcja odpowiada za rysowanie szubienicy;
	printf("\n");
	if(rysunek == 1){											//jeøeli poziom zmiennej rysunek wynosi 1 to wyúwietlany jest pierwszy etap grafiki, dla kaødego nastÍpnego poziomu wystÍpuje inny "obrazek", dziÍki system("cls") poprzedni obrazek zostajÍ zastπpiony nowym;
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
 
koniec_gry(){                                                   //funkcja w ktÛrej pytamy uøytkownika czy chce zagraÊ jeszcze raz, czy zakoÒczyÊ grÍ;
    char koniec;
    
    system("PAUSE");
    powitanie();
    printf("Gra skonczona\nZAMKNIJ PROGRAM [Q]\nZAGRAJ PONOWNIE [R]\n");
    koniec=getch();
    
    if(koniec == 'q' || koniec == 'Q') system("PAUSE");			//jeúli gracz wybierze Q to koÒczy dzia≥anie programu;
    else if(koniec == 'r' || koniec == 'R') return main();		//gracz chce graÊ nadal - wracamy na poczatek programu;
    else return koniec_gry();                                   //uøytkownik nie wybra≥ ani Q ani R, wypytujemy go dalej wywo≥ujπc tπ samπ funkcjÍ;
}
 
main(){
    system("COLOR 1F");											//ustawia kolor t≥a konsoli na niebieski i kolor czcionki na bia≥y;
   
	powitanie();												//nastÍpuje wywo≥ywanie kolejnych funkcji po sobie;
	tryb_gry();
	gra();
}
