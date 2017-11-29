PRINCIPE:
- Affficher le mot "Bonjour" sur la LED 8x8 avec le bouton. Après la fin du message, il faut réappuyer sur le bouton pour que le message s'affiche encore.

BRANCHEMENT:
Bouton:
- "Pin -" = GND              --> GND
- "Pin (Pin Millieur)" = +5V   --> 5V
- "Pin S" = signal           --> Pin 4

LED 8x8:
- Gnd --> GND il faut impérativement relier les masses du module et du contrôleur
- +V  --> 5V
- DIN --> Pin8
- CS  --> Pin 9
- CLK --> Pin 10
