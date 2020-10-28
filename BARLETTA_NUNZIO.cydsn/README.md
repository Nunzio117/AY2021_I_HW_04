# ASSIGNMENT 4
## Richieste
Le richieste per tale assignment sono esplicitate nel README generale.


## Schematico
Vi sono presenti i seguenti componenti:
- Pagina 1:
	- CY8CKIT-059 KIT: impostato con "visibile" solo sui canali Rx e TX e Blue_Led;
	- Resistenza da 330 Ohm per LED esteno al PSoC;
	- Led_Pin: pin relativo al canale del LED esterno al PSoC;
	- Red_Led: rappresentazione del LED esterno;
	- Pin_Blue: pin relativo al LED interno al PSoC;
	- UART: componente interno al PSoC per comunicazione con terminale;
	- PWM_LED: PWM per gestire l'intensità del LED, settato con risoluzione ad 8 bit e periodo di 1ms circa.
- Pagina 2:
	- Timer: timer per avere una isr che permetta lettura del dato campionanto dei 2 canali ogni 100ms;
	- R_Pin: pin relativo al potenziometro;
	- Pot: rappresentazione del potenziometro;
	- PR_Pin: pin relativo alla fotoresistenza;
	- PR: rappresentazione della fotoresistenza;
	- Resistenza da 10 k_Ohm per la fotoresistenza;
	- AMux a 2 canali (potenziometro --> channel 0 ; fotoresistenza --> channel 1);
	- ADC_DelSig: componente interno al PSoC per campionamento con diverse modalità, impostato su "Multi Sample" ed su
			   campionamento ad 8 bit.


## Port/Pin
Si hanno le seguenti porte con i corrispettivi pin:
- P2[1]: porta relativa al LED interno al PSoC e corrispondente al pin 63;
- P2[5]: porta relativa al potenziometro e corrispondente al pin 68;
- P2[6]: porta relativa alla fotoresistenza e corrispondente al pin 1;
- P2[7]: porta relativa al LED esterno al PSoC e corrispondente al pin 2;
- P12[6]: port relativa al Rx del PSoC e corrispondente al pin 20;
- P12[7]: port relativa al Rx del PSoC e corrispondente al pin 21.


## Firmware
Nei file di "Header" e di "Source" vi sono esplicitati già i dettagli reativi alle righe di codice presenti.


## Nota sulla programmazione dell'elaborato
L'elaborato è stato programmato centrandosi su campionamenti di segnali ad 8 bit. Inoltre vi è la possibilità di aumentare,
nel caso lo si voglia, il numero di fotoreistenze da campionare. Il codice infatti è già predisposto per tale upgrade, basta
lasciare il potenziometro sul channel 0 del multiplexer. Qual'ora si volesse cambiare la risoluzione di campionamento (ad
esempio da 8 a 10 bit), bisognerà fare degli accorgimenti sull'array "DataBuffer".
Infine, all'invio dei caratteri "b" o "B" il dispositivo funzionerà correttamente, mentre all'invio "s" o "S" il sistema
si stopperà, spegnedo il led nel caso fosse acceso.


## Bridge control panel confing
Nei file di "Config.iic" e "Confing.ini" vi sono esplicitati già i dettagli reativi ai comandi presenti.

