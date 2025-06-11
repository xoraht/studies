CREATE OR REPLACE FUNCTION vat22(kwota_brutto NUMERIC)
RETURNS NUMERIC AS $$
BEGIN
    RETURN ROUND(kwota_brutto * 0.22, 2);
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION liczba_pracownikow_o_imieniu(imie_in VARCHAR)
RETURNS INTEGER AS $$
DECLARE
    liczba INTEGER;
BEGIN
    SELECT COUNT(*) INTO liczba FROM Pracownicy WHERE imie = imie_in;
    RETURN liczba;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION potega2(n INTEGER)
RETURNS INTEGER AS $$
DECLARE
    wynik INTEGER := 1;
    i INTEGER;
BEGIN
    FOR i IN 1..n LOOP
        wynik := wynik * 2;
    END LOOP;
    RETURN wynik;
END;
$$ LANGUAGE plpgsql;