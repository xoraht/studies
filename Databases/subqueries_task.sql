SELECT *
FROM Pracownicy
WHERE projekt = (
    SELECT p_id FROM Projekty WHERE nazwa = 'Statistica'
);
SELECT nazwisko, pensja
FROM Pracownicy
WHERE id_dzialu = (
    SELECT id_dzialu FROM Pracownicy WHERE imie = 'Ian' AND nazwisko = 'Cook'
);
SELECT nazwa
FROM Projekty
WHERE p_id IN (
    SELECT DISTINCT projekt
    FROM Pracownicy
    WHERE id_dzialu = (
        SELECT id_dzialu FROM Dzialy WHERE nazwa = 'Programisci'
    )
);
SELECT nazwa
FROM Dzialy
WHERE id_dzialu IN (
    SELECT DISTINCT id_dzialu
    FROM Pracownicy
    WHERE projekt = (
        SELECT p_id FROM Projekty WHERE nazwa = 'Inwentaryzacja'
    )
);
SELECT *
FROM Pracownicy
WHERE id NOT IN (
    SELECT prac_kontaktowy FROM Klienci WHERE prac_kontaktowy IS NOT NULL
);
SELECT nazwisko, imie
FROM Pracownicy p1
WHERE pensja > 0.5 * (
    SELECT MAX(pensja)
    FROM Pracownicy p2
    WHERE p2.id_dzialu = p1.id_dzialu
);
SELECT *
FROM Dzialy d
WHERE NOT EXISTS (
    SELECT 1
    FROM Pracownicy p
    WHERE p.id_dzialu = d.id_dzialu AND p.projekt = 'p1'
);
SELECT nazwisko, pensja
FROM Pracownicy p1
WHERE (
    SELECT COUNT(*)
    FROM Pracownicy p2
    WHERE p2.pensja > p1.pensja
) < 3;
SELECT *
FROM Pracownicy p
WHERE projekt IS NOT NULL
  AND (
    SELECT termin_oddania
    FROM Projekty pr
    WHERE pr.p_id = p.projekt
  ) < CURRENT_DATE;