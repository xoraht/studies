SELECT 
    MIN(pensja) AS najnizsza,
    MAX(pensja) AS najwyzsza,
    MAX(pensja) - MIN(pensja) AS roznica
FROM Pracownicy;

SELECT 
    id_dzialu,
    AVG(pensja) AS srednia_pensja
FROM Pracownicy
GROUP BY id_dzialu
ORDER BY srednia_pensja DESC;

SELECT 
    COUNT(*) AS liczba_osob
FROM Pracownicy
WHERE projekt = 'p2';

SELECT 
    id_dzialu,
    SUM(pensja) AS suma_pensji
FROM Pracownicy
GROUP BY id_dzialu;

SELECT 
    id_dzialu,
    COUNT(*) AS liczba_pracownikow
FROM Pracownicy
GROUP BY id_dzialu
HAVING COUNT(*) > 2
ORDER BY liczba_pracownikow DESC;

SELECT 
    projekt,
    AVG(pensja) AS srednia_pensja,
    COUNT(*) AS liczba_pracownikow
FROM Pracownicy
WHERE projekt IS NOT NULL
GROUP BY projekt;

SELECT 
    d.nazwa,
    MIN(p.pensja) AS najnizsza_pensja
FROM Dzialy d
JOIN Pracownicy p ON d.id_dzialu = p.id_dzialu
GROUP BY d.nazwa;

SELECT 
    d.nazwa,
    COUNT(p.id) AS liczba_pracownikow
FROM Dzialy d
LEFT JOIN Pracownicy p ON d.id_dzialu = p.id_dzialu
GROUP BY d.nazwa;

SELECT 
    pr.nazwa AS nazwa_projektu,
    szef.nazwisko AS nazwisko_szefa,
    (
        SELECT COUNT(DISTINCT p2.id_dzialu)
        FROM Pracownicy p2
        WHERE p2.projekt = pr.p_id
    ) AS liczba_dzialow
FROM Projekty pr
JOIN Pracownicy szef ON pr.szef_projektu = szef.id;

SELECT 
    d.nazwa,
    COUNT(p.id) AS liczba_pracownikow,
    AVG(p.pensja) AS srednia_pensja
FROM Dzialy d
LEFT JOIN Pracownicy p ON d.id_dzialu = p.id_dzialu
GROUP BY d.nazwa;