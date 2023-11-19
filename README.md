# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
D'après un cours sur les coniques, effectuer un changement de repère en faisant une rotation autour de l'origine (point O) d'un angle spécifique rend l'équation de la conique plus simple : ax^2 + cy^2 + dx + ey + f = 0, où b devient nul. Dans ce cas, choisir 5 points permet d'obtenir 5 équations avec les 5 inconnues précédentes. Il y a ainsi autant d'inconnues que d'équations, on peut donc résoudre.

### 2.4 Coniques
On a :
x^T × C × x = 0
<br><=> x^T × C^T × x = 0 (comme C est symétrique, alors elle vérifie la propriété suivante : C = C^T)
<br><=> (C × x)^T × x = 0 (car x^T × C^T = (C × x)^T)
<br><=> (C × x)^T × Id × x = 0 (car la matrice Id est un élément neutre pour la multiplication)
<br><=> (C × x)^T × C^(-1) × C × x = 0 (en remplaçant Id par C^(-1) × C)
<br><=> l^T × C^(-1) × l = 0 (en posant : l = C × x)

## 3. À réaliser

### 3.1 Mathématiques avancées

1) Les tangentes à une conique sont perpendiculaires au rayon passant par le centre. Avec cinq tangentes, on obtient cinq points d'intersection sur la conique. En déterminant le centre, les vecteurs du centre aux points d'intersection, perpendiculaires aux tangentes, sont formés. En créant des paires de tangentes, on trouve les points d'intersection correspondants. Ces points définissent la conique en résolvant le système d'équations adéquat.

2) Voir directement dans le code.

3) Une paire de droites est une parabole, spécifiquement lorsque b² − ac = 0 dans l'équation générale ax² + 2bxy + cy² + 2dx + 2ey + f = 0. Cela se simplifie à (ax + by + d)(cx + ey + f) = 0, représentant deux droites. Pour construire une paire de droites, il suffit ainsi de choisir les coefficients (a, b, c, d, e et f), écrire l'équation puis la factoriser et s'assurer que l'égalité b² − ac = 0 est bien vérifiée.

4) Quand une conique est un point, elle devient un cercle de rayon nul (r = 0), simplifiant l'équation du cercle (x - h)² + (y - k)² = r² à (x-h)² + (y-k)² = 0, représentant le point de coordonnées (h,k).
