/*
 * Projekt z Zastosowania Procesorów Sygnałowych 2020
 * Projekt dla DSP TMS320C5535
 */


// Dołączenie wszelkich potrzebnych plików nagłówkowych
#include "usbstk5515.h"
#include "usbstk5515_led.h"
#include "aic3204.h"
#include "PLL.h"
#include "bargraph.h"
#include "oled.h"
#include "pushbuttons.h"
#include "Dsplib.h"


// Wzmocnienie wejścia w dB: 0 dla wejścia liniowego, 30 dla mikrofonowego
#define WZMOCNIENIE_WEJSCIA_dB 30

// Wybór sygnału do przetwarzania
// 0: próbki z wejścia mikrofonowego
// 1: biały szum
// 2: sygnał piłokształtny
// 3: sinus (stała częstotliwość)
// 4: sygnał z testsignal.h
#define SIGNAL 0

/*MÓJ SHIT*/
int k, i, j;
#define NUM_SAMPLES 5000                                               				    //ilosc probek
#define N 57
#define M 512
short wynik[NUM_SAMPLES];

short bufor[N + 2];
Int16 probka = 0;
short obliczona = 0;
long y = 0;

const short filtr_fir[] = {-30, -32, -36, -41, -46, -51, -53, -50, -41, 				//wspolczynniki filtru obliczone w programie Matlab
-23, 6, 49, 106, 178, 267,372, 492, 624, 766, 914, 1064, 1212, 1353,
1482, 1594, 1687, 1755, 1797, 1811, 1797, 1755, 1687, 1594, 1482, 1353,
1212, 1064, 914, 766, 624, 492, 372, 267, 178, 106,49, 6, -23, -41
, -50, -53, -51, -46, -41, -36, -32, -30};                              				//suma współczynników = 32441; 32441/2^15 = 0,990021 (przemnożenie przez 0.99 przed zaokrągleniem)
/*MÓJ SHIT*/



// Głowna procedura programu

void main(void) {

	// Inicjalizacja układu DSP
	USBSTK5515_init();			// BSL - układ uruchomieniowy
	pll_frequency_setup(100);	// ustawienie częstotliwości zegara DSP (PLL) na 100 MHz
	aic3204_hardware_init();	// kodek dźwięku AIC3204
	aic3204_init();				// jw.
	USBSTK5515_ULED_init();		// diody LED
	SAR_init_pushbuttons();		// przyciski
	oled_init();				// wyświelacz OLED 2x19 znaków

	// ustawienie częstotliwości próbkowania i wzmocnienia wejścia
	set_sampling_frequency_and_gain(48000L, WZMOCNIENIE_WEJSCIA_dB);

	// wypisanie komunikatu na wyświetlaczu
	// 2 linijki po 19 znaków, tylko wielkie angielskie litery
	oled_display_message("PROJEKT ZPS        ", "                   ");

	// 'krok' oznacza tryb pracy wybrany przyciskami
	unsigned int krok = 0;
	unsigned int poprzedni_krok = 9999;

	// zmienne do przechowywania wartości próbek
	Int16 lewy_wejscie;
	Int16 prawy_wejscie;
	Int16 lewy_wyjscie;
	Int16 prawy_wyjscie;
	Int16 mono_wejscie;

	// Przetwarzanie próbek sygnału w pętli
	while (1) {

		// odczyt próbek audio, zamiana na mono
		aic3204_codec_read(&lewy_wejscie, &prawy_wejscie);
		mono_wejscie = (lewy_wejscie >> 1) + (prawy_wejscie >> 1);

		// sprawdzamy czy wciśnięto przycisk
		// argument: maksymalna liczba obsługiwanych trybów
		krok = pushbuttons_read(4);
		if (krok == 0) // oba wciśnięte - wyjście
			break;
		else if (krok != poprzedni_krok) {
			// nastąpiła zmiana trybu - wciśnięto przycisk
			USBSTK5515_ULED_setall(0x0F); // zgaszenie wszystkich diód
			if (krok == 1) {
				// wypisanie informacji na wyświetlaczu
				oled_display_message("PROJEKT ZPS        ", "ORYGINALNY         ");
				// zapalenie diody nr 1
				USBSTK5515_ULED_on(0);
			} else if (krok == 2) {
				oled_display_message("PROJEKT ZPS        ", "FILTR              ");
				USBSTK5515_ULED_on(1);
			} else if (krok == 3) {
				oled_display_message("PROJEKT ZPS        ", "FILTR BLOK         ");
				USBSTK5515_ULED_on(2);
			} else if (krok == 4) {
				oled_display_message("PROJEKT ZPS        ", "KROK 4             ");
				USBSTK5515_ULED_on(3);
			}
			// zapisujemy nowo ustawiony tryb
			poprzedni_krok = krok;
		}


		// zadadnicze przetwarzanie w zależności od wybranego kroku

		if (krok == 1) {
			// tryb podstawowy - kopiowanie sygnału
			lewy_wyjscie = mono_wejscie;
			prawy_wyjscie = mono_wejscie;

		} else if (krok == 2) {

			for(k = 0; k < NUM_SAMPLES; k++){                                         		    //pętla filtrująca sygnał z tablicy wejściowej metodą próbka po próbce
					//probka = mono_wejscie;
					fir((DATA*)&mono_wejscie, (DATA*)filtr_fir, (DATA*)&obliczona, bufor, 1, N); 			//wywołanie funkcji fir z biblioteki DSPLIB (liczenie pojedynczych próbek)
					lewy_wyjscie =  obliczona;
					prawy_wyjscie = obliczona;
				}


		} else if (krok == 3) {

			/*for(j = 0; j < M; j++){                                    				//pętla iterująca próbki z sygnalu wejsciowego
				for(i = 0; i < N; i++){                                        				    //pętla realizująca obliczenia dla jednej próbki
						if(i > j || i == j){break;}                                 				//zatrzymanie pętli jesli i => j
						y = _smaci(y, mono_wejscie, filtr_fir[i]);					    		//mnożenie dwóch liczb Q15 sprawia, że y jest w formacie Q30
					}
					wynik[j] = (short)(_sround(y) >> 15);                          				//zaokrąglenie i przejcie z formatu Q30 na Q15
				}*/

			for(i = 0; i < N; i++){																	//pętla iterująca próbki z sygnalu wejsciowego
				y = _smaci(y, mono_wejscie, filtr_fir[i]);                                          //mnożenie dwóch liczb Q15 sprawia, że y jest w formacie Q30
				lewy_wyjscie =  (short)(_sround(y) >> 15);                          				//zaokrąglenie i przejcie z formatu Q30 na Q15
				prawy_wyjscie = (short)(_sround(y) >> 15);                          				//zaokrąglenie i przejcie z formatu Q30 na Q15
			}


			//lewy_wyjscie =  wynik;
			///prawy_wyjscie = wynik;

		} else if (krok == 4) {
			lewy_wyjscie = mono_wejscie;
			prawy_wyjscie = mono_wejscie;


		}

		// zapisanie wartości na wyjście audio
		aic3204_codec_write(lewy_wyjscie, prawy_wyjscie);

	}

	// wciśnięcie obu przycisków jednocześnie kończy działanie pętli
	aic3204_disable();
	oled_display_message("KONIEC PRACY       ", "                   ");
	while(1); // nie wychodź z programu
}
