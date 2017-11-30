# Capteur de présence

Les capteurs PIR, pour Passive Infrared Sensor (capteur infrarouge passif) permettent de détecter la présence d’humains mobiles dans le champ du capteur. Ils sont utilisés dans divers systèmes de sécurité et détecteurs de mouvements.

## Branchements du capteur de présence

*Pin1 +V -> Alim +5V de l'arduino

*Pin2 OUT -> Signal pin 2 digital Arduino

*Pin3 GND -> GND


Pour voir si cela fontionne, il suffit d'aller dans la fenêtre "moniteur série" dans outils, et lorsqu'un mouvement sera détecté; le message "motion detected !" apparaîtra. Dès que le capteur ne perçoit plus de mouvement, le message "motion ended" apparaîtra à son tour.


Article utilisé : http://mycoolpizza.blogspot.fr/2013/05/arduino-utiliser-un-capteur-de.html


# Oled

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


Lucile Renaud & Dylan Germanicus

