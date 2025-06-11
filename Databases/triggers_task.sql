CREATE OR REPLACE FUNCTION dzialy_on_update_cascade()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.id_dzialu <> OLD.id_dzialu THEN
        UPDATE Pracownicy
        SET id_dzialu = NEW.id_dzialu
        WHERE id_dzialu = OLD.id_dzialu;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS dzialy_update_cascade_trigger ON Dzialy;
CREATE TRIGGER dzialy_update_cascade_trigger
AFTER UPDATE ON Dzialy
FOR EACH ROW
EXECUTE FUNCTION dzialy_on_update_cascade();

CREATE OR REPLACE VIEW Kierownicy AS
SELECT
    p.p_id AS id_p,
    p.nazwa,
    p.szef_projektu AS idk,
    pr.imie,
    pr.nazwisko,
    pr.pensja
FROM Projekty p
JOIN Pracownicy pr ON p.szef_projektu = pr.id;

CREATE OR REPLACE FUNCTION kierownicy_instead_of_update()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE Pracownicy
    SET imie = NEW.imie,
        nazwisko = NEW.nazwisko,
        pensja = NEW.pensja
    WHERE id = OLD.idk;

    UPDATE Projekty
    SET nazwa = NEW.nazwa
    WHERE p_id = OLD.id_p;

    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS kierownicy_update_trigger ON Kierownicy;
CREATE TRIGGER kierownicy_update_trigger
INSTEAD OF UPDATE ON Kierownicy
FOR EACH ROW
EXECUTE FUNCTION kierownicy_instead_of_update();

CREATE SEQUENCE IF NOT EXISTS seq_log_id
    START 1
    INCREMENT 1
    CACHE 10;

CREATE TABLE IF NOT EXISTS Log (
    id INTEGER PRIMARY KEY DEFAULT nextval('seq_log_id'),
    "user" VARCHAR(50),
    date TIMESTAMP,
    row_id INTEGER
);

CREATE OR REPLACE FUNCTION klienci_audit_update()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO Log("user", date, row_id)
    VALUES (current_user, CURRENT_TIMESTAMP, NEW.k_id);
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS klienci_audit_trigger ON Klienci;
CREATE TRIGGER klienci_audit_trigger
AFTER UPDATE ON Klienci
FOR EACH ROW
EXECUTE FUNCTION klienci_audit_update();