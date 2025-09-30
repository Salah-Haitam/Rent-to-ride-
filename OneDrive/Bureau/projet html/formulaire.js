// Ajoute un écouteur d'événement qui s'exécute lorsque le DOM est entièrement chargé
document.addEventListener('DOMContentLoaded', function () 
{
    // Récupère l'élément du formulaire par son ID 'mainForm'
    const form = document.getElementById('mainForm');

    // Ajoute un écouteur d'événement pour l'événement 'submit' du formulaire
    form.addEventListener('submit', function (event) 
    {
        // Initialise une variable pour vérifier la validité du formulaire
        let valid = true;

        // Validation du champ 'Nom'
        const nom = document.getElementById('nom').value.trim(); // Récupère et nettoie la valeur du champ 'nom'
        const errorNom = document.getElementById('error-nom'); // Récupère l'élément d'erreur pour le 'nom'
        if (nom === "") 
        { // Vérifie si le champ 'nom' est vide
            errorNom.textContent = "Le nom est requis."; // Définit le message d'erreur
            errorNom.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorNom.style.display = "none"; // Masque le message d'erreur si le champ est valide
        }

        // Validation du champ 'Prénom'
        const prenom = document.getElementById('prenom').value.trim(); // Récupère et nettoie la valeur du champ 'prenom'
        const errorPrenom = document.getElementById('error-prenom'); // Récupère l'élément d'erreur pour le 'prenom'
        if (prenom === "") { // Vérifie si le champ 'prenom' est vide
            errorPrenom.textContent = "Le prénom est requis."; // Définit le message d'erreur
            errorPrenom.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorPrenom.style.display = "none"; // Masque le message d'erreur si le champ est valide
        }

        // Validation du champ 'Sexe'
        const sexeMale = document.getElementById('male').checked; // Vérifie si l'option 'male' est sélectionnée
        const sexeFemale = document.getElementById('female').checked; // Vérifie si l'option 'female' est sélectionnée
        const errorSexe = document.getElementById('error-sexe'); // Récupère l'élément d'erreur pour le 'sexe'
        if (!sexeMale && !sexeFemale) { // Vérifie si aucune option n'est sélectionnée
            errorSexe.textContent = "Veuillez sélectionner votre sexe."; // Définit le message d'erreur
            errorSexe.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorSexe.style.display = "none"; // Masque le message d'erreur si une option est sélectionnée
        }

        // Validation du champ 'Âge'
        const age = document.getElementById('age').value; // Récupère la valeur du champ 'age'
        const errorAge = document.getElementById('error-age'); // Récupère l'élément d'erreur pour l'âge
        if (age < 18) { // Vérifie si l'âge est inférieur à 18 ans
            errorAge.textContent = "Vous devez avoir au moins 18 ans."; // Définit le message d'erreur
            errorAge.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorAge.style.display = "none"; // Masque le message d'erreur si l'âge est valide
        }

        // Validation du champ 'Email'
        const email = document.getElementById('email').value.trim(); // Récupère et nettoie la valeur du champ 'email'
        const errorEmail = document.getElementById('error-email'); // Récupère l'élément d'erreur pour l'email
        const emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/; // Déclare une expression régulière pour valider l'email
        if (!emailPattern.test(email)) { // Vérifie si l'email ne correspond pas au modèle
            errorEmail.textContent = "Veuillez entrer une adresse email valide."; // Définit le message d'erreur
            errorEmail.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorEmail.style.display = "none"; // Masque le message d'erreur si l'email est valide
        }

        // Validation du champ 'Mot de passe'
        const password = document.getElementById('password').value.trim(); // Récupère et nettoie la valeur du champ 'password'
        const errorPassword = document.getElementById('error-password'); // Récupère l'élément d'erreur pour le mot de passe
        if (password.length < 6) { // Vérifie si le mot de passe contient moins de 6 caractères
            errorPassword.textContent = "Le mot de passe doit contenir au moins 6 caractères."; // Définit le message d'erreur
            errorPassword.style.display = "block"; // Affiche le message d'erreur
            valid = false; // Marque le formulaire comme invalide
        } else {
            errorPassword.style.display = "none"; // Masque le message d'erreur si le mot de passe est valide
        }

        // Si le formulaire est invalide, empêche la soumission
        if (!valid) {
            event.preventDefault(); // Empêche la soumission du formulaire
        } else {
            alert("Formulaire soumis avec succès !"); // Affiche un message de succès si le formulaire est valide
        }
    });
});
