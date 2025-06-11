Tomasz Wronkowski 313072 | Zadania WHERE
a) SELECT * FROM Pracownicy;
b) SELECT imie, nazwisko, pensja * 0.19 AS podatek FROM Pracownicy;
c) SELECT * FROM Pracownicy WHERE id_dzialu = 5;
d) SELECT * FROM Klienci WHERE prac_kontaktowy IS NULL;
e) SELECT * FROM Pracownicy WHERE imie LIKE 'J%';
f) SELECT nazwa, prac_kontaktowy FROM Klienci ORDER BY nazwa DESC;
