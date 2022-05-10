# arduino-tinkercad-watch

## Descriptif du projet

Le but du projet est de réaliser une montre connectée permettant de surveiller son enfant. Après avoir connectée la montre de l'enfant avec une application disponible sur le téléphone du parent, çelui aura accès a plusieurs informations:
- La position GPS de l'enfant
- La température de l'enfant
- Le rythme cardiaque de l'enfant

Ces informations seront stockées automatiquement sur le cloud et des rapports seront automatiquement crées.

## <span style='color:white'> État de l'art </span>

### <span style='color:white'> Okki </span>  

Renvoie la géolocalisation, la température, le rythme cardiaque ainsi que l’humeur de l’enfant. 
Permet aussi de prendre des photos et vidéos qui seront stockées sur l’appareil (32 GO de stockage) 

### <span style='color:white'> Bhdlovely </span>  

Montre GPS permettant d’effectuer des appels vidéo 
Bouton SOS qui si maintenu pendant plusieurs secondes compose automatiquement et l’un après l’autre 3 numéros jusqu’à ce qu’un réponde. 

### <span style='color:white'> Starlian tracker </span>  

En plus du GPS il est possible d’accéder à l’historique des appels ainsi que la caméra à distance. Possibilité de définir des zones de sécurité, si l’enfant sort de cette zone une alerte est levée. 
Il existe un mode cours permettant de suspendre les appels ainsi qu’un mode SOS qui permet à l’enfant d’appeler ses parents en cas d’urgence. 
La montre est également dotée d’un podomètre, d’une lampe de torche ainsi qu’une alarme 

## <span style='color:white'> Scénarios </span>

|Scénario d'un point de vue narratif|Actions|Hardware|Software|
|:----:|:----:|:----:|:----:|
|L'enfant met la montre autour de son bras et l'allume|Allumer la montre - Appuie 5s sur le bouton ON/OFF pour la première mise en marche - Ecran de la montre s'allume - Affichage de l'identifiant de la montre - Demande/Attente d'appairage|Bouton, cable alimentation, ecran, pavé numérique ou clavier micro-contrôleur |démarrage => écran d'acceuil => affichge message de non appairage - mode appairage => écran d'attente d'appairage - Si Appairage sous 30s OK => envoi message d'appairage + retour page accueil + suppression message de non appaiarge - Si non Appairage sous 30s => quitter le mode appairage + retour acceuil |
|Le parent crée un compte et se connecte à la montre de son enfant|Télécharger l'application - Création d'un compte - Ajout de la montre de l'enfant - Définition des préférences||démarrage => chargement de la page d'accueil => Fromulaire de connexion - Si Validation OK => on ajoute les infos à la BDD + vue principale de l'app - Si Validation pas ok => on met un message d'erreur|
|La montre envoie sa localisation/rythme cardiaque/température à intervalle régulier|Collecte et envoi de la localisation GPS - Collecte et envoi du rythme cardiaque - Collecte et envoi de la temperature|GPS, puce 4G, sensor temperature et rythme cardiaque|le software collecte les donnes des differents sensors et les envoi à l'aide de la puce 4G au parent en continu|


## <span style='color:white'> Membres de l'équipe </span>

- Guenychionta TUO
- Alfonso TISCORNIA
- Hao LI
- Nour-Eddine DAHMAN
- Maxime PEREZ
