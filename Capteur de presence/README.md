# Capteur de présence

Les capteurs PIR, pour Passive Infrared Sensor (capteur infrarouge passif) permettent de détecter la présence d’humains mobiles dans le champ du capteur. Ils sont utilisés dans divers systèmes de sécurité et détecteurs de mouvements.

## Branchement

*Pin1 +V -> Alim +5V de l'arduino

*Pin2 OUT -> Signal pin 2 digital Arduino

*Pin3 GND -> GND


Pour voir si cela fontionne, il suffit d'aller dans la fenêtre "moniteur série" dans outils, et lorsqu'un mouvement sera détecté; le message "motion detected !" apparaîtra. Dès que le capteur ne perçoit plus de mouvement, le message "motion ended" apparaîtra à son tour.


Article utilisé : http://mycoolpizza.blogspot.fr/2013/05/arduino-utiliser-un-capteur-de.html


Lucile Renaud et Dylan Germanicus
