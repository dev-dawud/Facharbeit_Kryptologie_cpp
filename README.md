# Facharbeit_Kryptologie_cpp

Hier ist mein Quellcode passend zu meiner Facharbeit.
Es ist ein login system (Konsolenanwendung) mit Fokus auf Passwortsicherheit.

Ich habe das ganze bewusst in mehrere Versionen unterteilt, um zu zeigen, wie sich die Sicherheitslücken schrittweise
verbessern.

---

## Version 1:
[main_v1_unsicher.cpp](src/versionen/main_v1_unsicher.cpp)


- Passwörter sind in Klartext gespeichert
- einfaches Konsolenmenü
- keinerlei kryptographischen Verfahren
- dient als Grundlage für die anderen Versionen

## Version 2:
[main_v2_hashing_MD5.cpp](src/versionen/main_v2_hashing_MD5.cpp)

- Passwörter werden durch MD5 gehasht
- Passwörter dadurch nicht mehr im Klartext gespeichert

# Version 3:
[main_v3_hashing_SHA256.cpp](src/versionen/main_v3_hashing_SHA256.cpp)

- umstellung auf moderneres kryptographisches Verfahren (SHA-256)
- erhöhte Sicherheit gegenüber MD5

# Version 4:
[main_v4_salted_hashing.cpp](src/versionen/main_v4_salted_hashing.cpp)

- Einführung von Salt
- Wiederstandsfähiger gegenüber Rainbow Tables
- gleiche Passwörter erhalten unterschiedliche Hashwerte

---

## Repo klonen:

```bash
git clone https://github.com/dev-dawud/Facharbeit_Kryptologie_cpp

````
