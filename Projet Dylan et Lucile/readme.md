Nous avions pour projet de faire fonctionner ensemble le capteur de présence et l'écran oled: si le capteur de présence détectait un mouvement, l'écran oled afficherait "Dylan/Lucile".
Cependant au dernier cours nous n'avons pas reussi à refaire marcher l'écran Oled, malgès le fait que nous ayons fait les mêmes manipulations que la séance précédente, nous n'avons donc pas pu combiner les deux codes pour permettre cette programation, et nous n'avons pas eu non plus le temps de changer de projet et de prendre en main de nouveaux composants.


# -> Capteur de présence

Les capteurs PIR, pour Passive Infrared Sensor (capteur infrarouge passif) permettent de détecter la présence d’humains mobiles dans le champ du capteur. Ils sont utilisés dans divers systèmes de sécurité et détecteurs de mouvements.

## Branchements du capteur de présence

* Pin1 +V -> Alim +5V de l'arduino

* Pin2 OUT -> Signal pin 2 digital Arduino

* Pin3 GND -> GND


Pour voir si cela fontionne, il suffit d'aller dans la fenêtre "moniteur série" dans outils, et lorsqu'un mouvement sera détecté; le message "motion detected !" apparaîtra. Dès que le capteur ne perçoit plus de mouvement, le message "motion ended" apparaîtra à son tour.


Article utilisé : http://mycoolpizza.blogspot.fr/2013/05/arduino-utiliser-un-capteur-de.html



# -> écran Oled

L'écran Oled I2C de 0.91" est un petit écran (128 x 32) qui va nous permettre d'afficher un court texte.

Il nous faudra pour cela télécharger et inclure la bibliothèque "U8glib.h". 
Elle se télécharge ici: http://www.arduinolibraries.info/libraries/u8glib
Pour l'inclure il faut aller dans "croquis" -> "inclure une bibliothèque" -> "ajouter une bibliothèque.ZIP" puis selectionner le dossier de la librairie nouvellement téléchargée.

## Branchements de l'écran Oled:

* gnd -> gnd 
* sda -> sda
* sck -> scl
* vcc -> 5v


Article utilisé: http://rdiot.tistory.com/302


Nous avons pu brancher les deux composants ensemble lors de la première séance et pour cela nous avons utilisé une breadbord. L'écran Oled et le capteur fonctionnais simultanément. Nous n'avons cependant pas eu l'occasion de les faire interargir ensemble.

Lucile Renaud & Dylan Germanicus

