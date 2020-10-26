# ASSIGNMENT 4
## Richieste
Le richieste per tale assignment sono esplicitate nel README generale.


## Schematico
Vi sono presenti i seguenti componenti:
- Pagina 1:
	- CY8CKIT-059 KIT: impostato con "visibile" solo sui canali Rx e TX e Blue_Led;
	- Resistenza da 330 Ohm per LED esteno al PSoC;
	- Led_Red: Pin relativo al canale del rosso;
	- UART: componente interno al PSoC per comunicazione con terminale;
	- PWM_RG: PWM per gestire i colori rosso e verde del LED RGB.
- Pagina 2:
	- Timer: timer per avere una isr che permetta il campionamento dei 2 canali ogni 100ms.


## Port/Pin
Si hanno le seguenti porte con i corrispettivi pin:
- P2[5]: porta relativa al potenziometro e corrispondente al pin 68;
- P2[6]: porta relativa alla fotoresistenza e corrispondente al pin 1;
- P2[7]: porta relativa al LED esterno al PSoC e corrispondente al pin 2;
- P12[6]: port relativa al Rx del PSoC e corrispondente al pin 20;
- P12[7]: port relativa al Rx del PSoC e corrispondente al pin 21.


## Firmware
Nei file di "Header" e di "Source" vi sono esplicitati già i dettagli reativi alle righe di codice presenti.


## Nota sulla programmazione dell'elaborato
 

