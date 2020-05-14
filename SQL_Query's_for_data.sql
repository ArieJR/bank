#[gebruiker voert pas in]
#[gebruiker voert pincode in]
#rekeningnummer kijken of het onze bank is   					QT
#{JA}
#in rekening kijken welke gebruiker_ID bij rekeningnummer hoort	#	&
#Pas_ID en rekeningnummer staan er al in
#Slaat Pas_ID, rekeningnummer en Automaat_ID op in Sessie    	#	&
#check pincode 													#	&
#check geblokkeerd												#	&
#-pincode true: 												QT
#poging 0														#	&
#-pincode false:												QT
#poging+1														#	&
#check pogingen (bij 3:)										#QT	&
#blokkeer pas													#	&
#
#uitlog_tijd													#	&



#in rekening kijken welke gebruiker_ID bij rekeningnummer hoort
SELECT Gebruikers_ID FROM Rekening WHERE Rekeningnummer='DU99ANVI4445556667';

#Slaat Pas_ID, rekeningnummer en Automaat_ID op in sessie
INSERT INTO `ANVI`.`Sessie` (`         Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`)
VALUES ('Pin_School', 'CHUAN', '3', 'DU99ANVI4445556667');

#laatste session_ID te krijgen
SELECT MAX(Session_ID) FROM Sessie;

#password (true or false)
SELECT case when 1234=(SELECT Pincode FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667') then 1 else 0 end as bool FROM Pas;

#check geblokkeerd
SELECT Pas_geblokkeerd FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667';	#(true of false terug)

#poging=0
UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer='DU99ANVI4445556667');

#poging+1
UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer='DU99ANVI4445556667');

#check pogingen
SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer='DU99ANVI4445556667');

#bij 3 pogingen: blokkeer
UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');

#uitlog_tijd	
UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = '8');

#UPDATE  `ANVI`.`Pas` SET case when 3=(SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer='DU99ANVI4445556667')) then `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');


#biljetten aantal
SELECT Biljet10 FROM Automaat WHERE Automaat_ID = "Pin_School";
SELECT Biljet20 FROM Automaat WHERE Automaat_ID = "Pin_School";
SELECT Biljet50 FROM Automaat WHERE Automaat_ID = "Pin_School";

#saldo aanpassen
UPDATE `ANVI`.`Rekening` SET `Saldo` = -00 WHERE (`Rekeningnummer` = 'DU-ANVI-12345600');

