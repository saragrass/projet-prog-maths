# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
D'après un cours sur les coniques, effectuer un changement de repère en faisant une rotation autour de l'origine (point O) d'un angle spécifique rend l'équation de la conique plus simple : ax^2 + cy^2 + dx + ey + f = 0, où b devient nul. Ainsi, choisir 5 points permet d'obtenir 5 équations avec les 5 inconnues précédentes. Il y a ainsi autant d'inconnues que d'équations, on peut donc résoudre.

### 2.4 Coniques
On a :
x^T × C × x = 0
<br><=> x^T × C^T × x = 0 (comme C est symétrique, alors elle vérifie la propriété suivante : C = C^T)
<br><=> (C × x)^T × x = 0 (car x^T × C^T = (C × x)^T)
<br><=> (C × x)^T × Id × x = 0 (car la matrice Id est un élément neutre pour la multiplication)
<br><=> (C × x)^T × C^(-1) × C × x = 0 (en remplaçant Id par C^(-1) × C)
<br><=> l^T × C^(-1) × l = 0 (en posant : l = C × x)
