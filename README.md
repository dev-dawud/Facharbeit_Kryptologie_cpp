# Facharbeit_Kryptologie_cpp

Hier ist mein Quellcode passend zu meiner Facharbeit. 
Es ist ein login system (Konsolenanwendung) mit Fokus auf Passwortsicherheit.

Ich habe das ganze bewusst in mehrere Versionen unterteilt, um zu zeigen, wie sich die Sicherheitslücken schrittweise verbessern.

---

## Version 1:
[main_v1_unsicher.cpp](src/versionen/main_v1_unsicher.h)

- Passwörter sind in Klartext gespeichert
- einfaches Konsolenmenü
- keinerlei kryptographischen Verfahren
- dient als Grundlage für die anderen Versionen

## Version 2:
[main_v2_hashing_MD5.cpp](src/versionen/main_v2_hashing_MD5.h)

- Passwörter werden durch MD5 gehasht
- Passwörter dadurch nicht mehr im Klartext gespeichert

## Version 3:
[main_v3_hashing_SHA256.cpp](src/versionen/main_v3_hashing_SHA256.h)

- umstellung auf moderneres kryptographisches Verfahren (SHA-256)
- erhöhte Sicherheit gegenüber MD5

## Version 4:
[main_v4_salted_hashing.cpp](src/versionen/main_v4_salted_hashing.h)

- Einführung von Salt
- Wiederstandsfähiger gegenüber Rainbow Tables
- gleiche Passwörter erhalten unterschiedliche Hashwerte
- Einführung vom entfernen sensible Daten aus dem ram

## Version 5:
[main_v5_pepper.cpp](src/versionen/main_v5_peppered_hashing.h) | [AuthManager.h](src/versionen/AuthManager-v5.h)

- einführung von einem nicht veränderbaren Peppers
- Erschwert Angriffe

## Version 6:
[main_v6_2fa.cpp](src/versionen/main_v6_2fa.h) | [AuthManager.h](src/versionen/AuthManager.h)

- Implementierung von 2fa (6 stelliger Sicherheitscode)


---
# Hacker Tools:

- im ordner tools befinden sich beispiele für einfache hacker tools die zeigen wie unsicher die versionen 1-4 sind

## Rainbow Table:
[main_rainbow_table.cpp](tools/main_rainbow_table.cpp)

- läuft mithilfe einer API 
- Hashes werden mit dem des Programms verglichen und ausgewertet
- zeigt wie schnell Passwörter mit Rainbow Tables geknackt werden können

## Brute Force:
[main_brute_force.cpp](tools/main_brute_force.cpp)

- generiert alle möglichen Kombinationen von Passwörtern
- ab 5 stelliges Passwort dauert es zu lange (zum Test lieber 3-4 stelliges verwenden)

## Main tool:
[main_hack.cpp](tools/main_hack.cpp)

- nutzt die rockyou.txt Passwortliste und die API um als erstes Passwörter zu knacken die in einer Rainbow Table sind
- brute force als letzte option um alle möglichen Kombinationen durchzugehen, falls das Passwort nicht in der Rainbow Table ist
- Programm erkennt automatisch ob es ein md5 oder sha256 hash ist

---
# Hinweis:

- Projekt funktioniert nur auf Windows da es die ``<windows.h`` header datei nutzt
- ersatz für ``<windows.h>`` wären librarys wie ``<chrono>`` oder ``<ctime>``
- Compiler muss mindestens auf C++ 17 sein um es nutzen zu können
- WICHTIG: alle only header files außer (versionen), müssen im include ordner liegen (generell nicht vom Projekt entfernt werden)!
- WICHTIG: über github ``https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt`` muss man eine .txt datei herunterladen, um die tools nutzen zu können. Diese datei beinhaltet millionen von Passwörtern die geleaked wurden. Deswegen bitte nicht öffnen da dies den Pc sehr verlangsamt einfach unentpackt in den ``/data/list`` ordner verschieben.
- Beim ausführen des Projekts kann es sein das sich bestimmte Virenscanner melden und das Programm blockieren. Um das Problem zuz lösen muss man den Projektordner im virenprogramm whitelisten. Windows defender ignoriert es aber bestimmte Virenprogramme könnten es als geafhr sehen (ist es aber nicht)!

---

## Repo klonen:

```bash
git clone https://github.com/dev-dawud/Facharbeit_Kryptologie_cpp.git
```
