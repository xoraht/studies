INSERT INTO Projekty (p_id, szef_projektu, nazwa, termin_oddania)
VALUES ('odi', 17, 'Inwentaryzacja oddzialu Turzno', '2010-12-30');

SELECT nazwisko, pensja, 'mniejsza' AS relacja FROM Pracownicy WHERE pensja < 1800
UNION
SELECT nazwisko, pensja, 'równa' FROM Pracownicy WHERE pensja = 1800
UNION
SELECT nazwisko, pensja, 'większa' FROM Pracownicy WHERE pensja > 1800;

SELECT nazwa, 'ukończony' AS status FROM Projekty WHERE termin_oddania < CURRENT_DATE
UNION
SELECT nazwa, 'trwający' FROM Projekty WHERE termin_oddania >= CURRENT_DATE;

SELECT id FROM Pracownicy WHERE pensja > 3000
EXCEPT
SELECT szef_projektu FROM Projekty;

SELECT id FROM Pracownicy WHERE pensja < 2000
INTERSECT
SELECT prac_kontaktowy FROM Klienci WHERE prac_kontaktowy IS NOT NULL;

SELECT p.imie, p.nazwisko, d.nazwa
FROM Pracownicy p
JOIN Dzialy d ON p.id_dzialu = d.id_dzialu;

SELECT pr.nazwa, p.nazwisko, p.pensja
FROM Projekty pr
JOIN Pracownicy p ON pr.szef_projektu = p.id;

SELECT DISTINCT p1.imie, p2.nazwisko
FROM Pracownicy p1
CROSS JOIN Pracownicy p2;

SELECT k.nazwa, k.telefon, p.imie, p.nazwisko
FROM Klienci k
LEFT JOIN Pracownicy p ON k.prac_kontaktowy = p.id;

SELECT p.imie, p.nazwisko, pr.nazwa
FROM Pracownicy p
LEFT JOIN Projekty pr ON p.projekt = pr.p_id;

SELECT k1.nazwa, k2.telefon, k3.prac_kontaktowy
FROM Klienci k1
CROSS JOIN Klienci k2
CROSS JOIN Klienci k3;

SELECT p.nazwisko, p.pensja, pr.nazwa
FROM Pracownicy p
LEFT JOIN Projekty pr ON p.projekt = pr.p_id;

SELECT p.imie, p.nazwisko, pr.nazwa
FROM Dzialy d
JOIN Pracownicy p ON d.id_dzialu = p.id_dzialu
LEFT JOIN Projekty pr ON p.projekt = pr.p_id
WHERE d.nazwa = 'Programisci';

SELECT k.nazwa, p.imie, p.nazwisko, d.nazwa AS dzial
FROM Klienci k
JOIN Pracownicy p ON k.prac_kontaktowy = p.id
JOIN Dzialy d ON p.id_dzialu = d.id_dzialu
WHERE k.k_id = 1;

SELECT k.nazwa, p.imie, p.nazwisko, d.nazwa AS dzial
FROM Klienci k, Pracownicy p, Dzialy d
WHERE k.prac_kontaktowy = p.id
  AND p.id_dzialu = d.id_dzialu
  AND k.k_id = 1;