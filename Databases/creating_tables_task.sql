CREATE TABLE Zlecenia (
    id INTEGER,
    data_rozpoczecia DATE DEFAULT CURRENT_DATE,
    nazwa VARCHAR(255),
    zespol INTEGER,
    termin DATE NOT NULL,
    ukonczone VARCHAR(3) NOT NULL,
    koszt DECIMAL(12,2),
    CONSTRAINT pk_zlecenia PRIMARY KEY (id),
    CONSTRAINT chk_termin CHECK (termin >= data_rozpoczecia),
    CONSTRAINT chk_ukonczone CHECK (ukonczone IN ('tak', 'nie')),
    CONSTRAINT chk_koszt_zlecenia CHECK (koszt >= 0),
    CONSTRAINT fk_zespol FOREIGN KEY (zespol) REFERENCES Dzialy(id_dzialu)
);
CREATE TABLE Wlasciciele (
    id INTEGER,
    nazwa VARCHAR(255) NOT NULL,
    telefon VARCHAR(50),
    uwagi VARCHAR(255),
    CONSTRAINT pk_wlasciciele PRIMARY KEY (id)
);
CREATE TABLE Pojazdy (
    id INTEGER,
    nrVin VARCHAR(50) UNIQUE,
    marka VARCHAR(100) NOT NULL,
    kolor VARCHAR(50) NOT NULL,
    wlasciciel INTEGER,
    uwagi VARCHAR(255),
    CONSTRAINT pk_pojazdy PRIMARY KEY (id),
    CONSTRAINT fk_pojazdy_wlasciciel FOREIGN KEY (wlasciciel) REFERENCES Wlasciciele(id)
);
CREATE TABLE Naprawy (
    id INTEGER,
    pojazd INTEGER NOT NULL,
    data_rozp DATE DEFAULT CURRENT_DATE NOT NULL,
    data_naprawy DATE,
    koszt DECIMAL(12,2),
    opis_zgloszenia VARCHAR(255) NOT NULL,
    CONSTRAINT pk_naprawy PRIMARY KEY (id),
    CONSTRAINT fk_naprawy_pojazd FOREIGN KEY (pojazd) REFERENCES Pojazdy(id),
    CONSTRAINT chk_data_naprawy CHECK (data_naprawy IS NULL OR data_naprawy >= data_rozp),
    CONSTRAINT chk_koszt_naprawy CHECK (koszt >= 0)
);
CREATE TABLE Czesci (
    id INTEGER,
    nazwa VARCHAR(255) NOT NULL,
    cena DECIMAL(10,2),
    producent VARCHAR(100),
    dostawca VARCHAR(100),
    CONSTRAINT pk_czesci PRIMARY KEY (id),
    CONSTRAINT chk_nazwa_czesci CHECK (nazwa <> ''),
    CONSTRAINT chk_cena_czesci CHECK (cena >= 0)
);
CREATE TABLE UzyteCzesci (
    id_cz INTEGER,
    id_naprawy INTEGER,
    ilosc INTEGER NOT NULL,
    uwagi VARCHAR(255),
    CONSTRAINT pk_uzyteczesci PRIMARY KEY (id_cz, id_naprawy),
    CONSTRAINT fk_ucz_czesci FOREIGN KEY (id_cz) REFERENCES Czesci(id),
    CONSTRAINT fk_ucz_naprawy FOREIGN KEY (id_naprawy) REFERENCES Naprawy(id),
    CONSTRAINT chk_ilosc_ucz CHECK (ilosc >= 0)
);