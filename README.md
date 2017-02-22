*./moulinette.sh login-test.csv poule_d02 01 [cpp]*

moulinette will correct all exercice. It will compile the student code in /[NAME OF THE REPO]/[NAME OF THE STUDENT]/[EXERCICE] with the main in correction/[NAME OF THE REPO]/[EXERCICE]. It will compare the output with correction/[NAME OF THE REPO]/[EXERCICE]/output.

The binary and the output of student will be in res.
The correction will be in correction_[NAME OF THE REPO]_[EXERCICE].

The login-test.csv contains :

prenom.nom@epitech.eu;login_x

The [cpp] is just for compile cpp instead of c.


*./get_depot.sh login-test.csv poule_d03*

It will get the repo poule_d03 from students in login-test.csv