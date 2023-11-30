# Arduino Coffre-fort

---

# Système de Sécurité avec Arduino

Ce projet Arduino crée un système de sécurité interactif utilisant un clavier, un servo-moteur, un écran LCD et un stepper motor. Le système permet à l'utilisateur d'entrer un mot de passe via un clavier numérique. Si le mot de passe est correct, le servo-moteur s'active pour débloquer un mécanisme (par exemple une porte). L'écran LCD affiche les instructions et les retours d'informations pour l'utilisateur.

## Composants

- Arduino UNO (ou similaire)
- Clavier numérique 4x4
- Servo-moteur
- Écran LCD avec interface I2C
- Stepper motor (non utilisé dans le code actuel mais prévu pour une extension future)
- Fils de connexion

## Configuration

Le clavier est connecté aux broches numériques 2-9 de l'Arduino. Le servo-moteur est connecté à la broche 13. L'écran LCD utilise une interface I2C connectée aux broches A4 (SDA) et A5 (SCL).

## Fonctionnalités

1. **Saisie du mot de passe** : L'utilisateur peut saisir un mot de passe à l'aide du clavier. Le mot de passe par défaut est "487".
   
2. **Validation du mot de passe** : En appuyant sur '*', le système vérifie le mot de passe. Si le mot de passe est correct, le servo-moteur s'active.

3. **Réinitialisation du mot de passe** : L'utilisateur peut appuyer sur '#' pour réinitialiser le mot de passe entré.

4. **Affichage LCD** : L'écran LCD guide l'utilisateur tout au long du processus, affichant les messages tels que "Entrer votre mot de passe", "Mot de passe incorrect", et d'autres retours d'informations.

## Extension

Ce code est conçu pour être facilement étendable. Par exemple, vous pourriez connecter un stepper motor pour réaliser des actions supplémentaires une fois le mot de passe validé.

---
