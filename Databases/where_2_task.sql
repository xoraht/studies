Tomasz Wronkowski 313072 | Zadania WHERE
1. 
SELECT CONCAT(SUBSTRING(nazwisko, 1, 2), SUBSTRING(imie, 1, 1), id) AS kod FROM Pracownicy;
2.
SELECT TRANSLATE(nazwisko, 'kwsKWS', 'xxxxxx') AS zmienione_nazwisko FROM Pracownicy;
3.
SELECT nazwisko, ROUND(pensja * 1.15) AS pensja_powiekszona FROM Pracownicy ORDER BY imie DESC;
4.
SELECT nazwa, termin_oddania, AGE(termin_oddania, CURRENT_DATE) AS czas_do_terminu FROM Projekty WHERE termin_oddania < '2008-01-01';
5.
SELECT TO_CHAR(termin_oddania, 'FMDay') AS dzien_tygodnia FROM Projekty WHERE p_id = 'p1';
6.
SELECT szef_projektu FROM Projekty WHERE termin_oddania BETWEEN '2009-08-15' AND '2010-03-30';
