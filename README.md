# Facharbeit_Kryptologie_cpp

Facharbeit_Kryptologie_cpp ist ein Programm für eine Facharbeit. Es handelt sich hierbei um mehrere Funktionen die dieses Programm mitführt.
Zum einen wird iterativ ein Loginsystem dargestellt und gezeigt, wie sich die Sicherheitsstandards über die Jahre entwickelt haben.
Zum anderen gibt es "tools" die vereinfacht hacker-tools demonstrieren, hashes generieren und die Entropie eines Passwortes messen.

---

## Installation

Nutze ``git clone`` um das Projekt im beliebigen Projektverzeichnis zu klonen oder lade das Projekt direkt über Github herunter.

```bash
git clone https://github.com/dev-dawud/Facharbeit_Kryptologie_cpp.git
```

Nachdem das Projekt heruntergeladen ist es wichtig die ``rockyou.txt`` aus folgendem Repository aus Github herunter zu laden und entpacken.
WICHTIG: die datei muss in den Ordner ``data/list`` liegen bzw. verschoben werden:
1. ```bash
   cd projektverzeichnis/data/list
   ```

2. ```bash
   git clone https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt.git
   ```
Bevor man das Projekt ausführt wäre es am besten, den Compiler vom **Debug** -modus in den **Release (x64)** -modus zu wechseln, um die optimalste Performance zu erhalten.

### WICHTIG
- Compiler version muss mind. die version **C++ 17** haben
- es kann vorkommen, dass sich der Windows defender oder ein anderes Antiviren Programm meldet und das Projekt als "gefahr" kennzeichnet und somit den download verhindert. Darum das Projekt zu beginn Whitelisten.
-  Das Projekt funktioniert nur auf Windows, da es die ``<windows.h`` header datei nutzt (kann aber auch auf Linux und MacOS laufen wenn man die ersatz header nutzt)
- ersatz für ``<windows.h>`` wären librarys wie ``<chrono>`` oder ``<ctime>`` (Code müsste an den dementsprechenden teilen angepasst werden)

## Nutzung
Im folgenden wird ein Beispiel Programm ausgeführt: 

1. Im Menü klicken sie die 4. Option an. Damit können sie die Stärke ihres Passwortes das sie nutzen wollen messen.
2. Danach gehen sie zum Hash Generator. Dort können sie selbst entscheiden ob sie den MD5 oder den SHA-256 algorithmus verwenden wollen und mit Salt (zusätliche Schutzmaßnahme) oder ohne.
3. Nachdem der hash erstellt wurde kopieren sie diesen und gehen sie zur 2.Option zu den Hacker tools. Dort können sie ihr Passwort testen wie einfach er zu knacken ist. 
4. mit der 1. Option im Menü am Anfang kommen ganz viele verschiedene versionen die sie alle testen können wie Passwörter sicher gespeichert werden von Firmen. und wie ein registrierungsvorgang abläuft.

---

# Zusammenfassung einzelner Tools und Versionen:

## Version 1:
[main_v1_unsicher.h](src/versionen/main_v1_unsicher.h)

- Passwörter sind in Klartext gespeichert
- einfaches Konsolenmenü
- keinerlei kryptographischen Verfahren
- dient als Grundlage für die anderen Versionen

## Version 2:
[main_v2_hashing_MD5.h](src/versionen/main_v2_hashing_MD5.h)

- Passwörter werden durch MD5 gehasht
- Passwörter dadurch nicht mehr im Klartext gespeichert

## Version 3:
[main_v3_hashing_SHA256.h](src/versionen/main_v3_hashing_SHA256.h)

- umstellung auf moderneres kryptographisches Verfahren (SHA-256)
- erhöhte Sicherheit gegenüber MD5

## Version 4:
[main_v4_salted_hashing.h](src/versionen/main_v4_salted_hashing.h)

- Einführung von Salt
- Wiederstandsfähiger gegenüber Rainbow Tables
- gleiche Passwörter erhalten unterschiedliche Hashwerte
- Einführung vom entfernen sensible Daten aus dem ram

## Version 5:
[main_v5_pepper.h](src/versionen/main_v5_peppered_hashing.h) | [AuthManager.h](src/versionen/AuthManager-v5.h)

- einführung von einem nicht veränderbaren Peppers
- Erschwert Angriffe

## Version 6:
[main_v6_2fa.h](src/versionen/main_v6_2fa.h) | [AuthManager.h](src/versionen/AuthManager.h)

- Implementierung von 2fa (6 stelliger Sicherheitscode)


---
# Hacker Tools:

- im ordner tools befinden sich beispiele für einfache hacker tools, die zeigen, wie unsicher die versionen 1-4 sind.
- das gesamte toolset wird über tool.h gesteuert
- Im Hauptmenü kann man pber die 2. Optionen die tools aufrufen und testen. 
- es gibt 4 tools die unterschiedliche Angriffmethoden simulieren:

## 1. Rainbow Table:
[main_rainbow_table.h](tools/main_rainbow_table.h)

- läuft mithilfe einer API 
- Hashes werden mit dem des Programms verglichen und ausgewertet
- zeigt wie schnell Passwörter durch Rainbow Tables geknackt werden können

## 2. Brute Force:
[main_brute_force.h](tools/main_brute_force.h)

- generiert alle möglichen Kombinationen von Passwörtern
- ab 5 stelliges Passwort dauert es zu lange (zum Test lieber 3-4 stelliges verwenden)
- Zeit wird gemessen für die länge des Brute Force versuches
- das ganze funktioniert nur mit Passwörtern die 7 stellig sind

## Main tool:
[main_hack.h](tools/main_hack.h)

- nutzt die rockyou.txt Passwortliste und die API um als erstes Passwörter zu knacken die in einer Rainbow Table sind
- brute force als letzte option um alle möglichen Kombinationen durchzugehen, falls das Passwort nicht in der Rainbow Table ist
- Programm erkennt automatisch ob es ein md5 oder sha256 hash ist

---
## Hash Generator:
- Über die 3. Option im Hauptmenü kann man sich hashes erstellen lassen mit salt oder ohne salt um direkt danach mit dne tools zu testen wie sicher diese sind.