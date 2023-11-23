# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
D'après un cours sur les coniques, effectuer un changement de repère en faisant une rotation autour de l'origine (point $`O`$) d'un angle spécifique rend l'équation de la conique plus simple : $`ax^2 + cy^2 + dx + ey + f = 0`$, où $`b`$ devient nul. Dans ce cas, choisir 5 points permet d'obtenir 5 équations avec les 5 inconnues précédentes. Il y a ainsi autant d'inconnues que d'équations, on peut donc résoudre.

### 2.4 Coniques
On a :
$`x^T \times C \times x = 0`$
<br>$`\Leftrightarrow x^T \times C^T \times x = 0`$ (comme $`C`$ est symétrique, alors elle vérifie la propriété suivante : $`C = C^T`$)
<br>$`\Leftrightarrow (C \times x)^T \times x = 0`$ (car $`x^T × C^T = (C \times x)^T`$)
<br>$`\Leftrightarrow (C \times x)^T \times Id \times x = 0`$ (car la matrice $`Id`$ est un élément neutre pour la multiplication)
<br>$`\Leftrightarrow (C \times x)^T \times C^{-1} \times C \times x = 0`$ (en remplaçant $`Id`$ par $`C^{-1} \times C`$)
<br>$`\Leftrightarrow l^T \times C^{-1} \times l = 0`$ (en posant : $`l = C \times x`$)

## 3. À réaliser

### 3.1 Mathématiques avancées

1) D'après le <b>2.4 Coniques</b>, une droite $`l`$ est tangente à la conique $`C`$ ssi : $`l^TC^{-1}l = 0`$. Cette tangente passe par le point $`x\inC`$ : $`l = Cx`$ (avec $`x = (x, y, w)^T`$).
On connait 5 tangentes à la conique, donc il y a 5 équations de ce type dont on connait les $`l_i`$ (avec $`i\in[1,5]`$) et il y a 5 points de contrôle connus (ici ce sont points de contact entre les différentes tangentes et la conique).
De plus, comme on sait que les droites $`l_i`$ sont tangentes à la conique, elles vérifient : $`l_{i}^{T}C^{-1}l = 0`$. On remplace ensuite les $`l_{i}`$ par $`C*x_{i}`$.
On a : $`(Cx_{i})^T \times C^{-1} \times Cx_{i} = 0`$.
On a donc un système linéaire à 5 équations (une par tangente). On le résout avec la méthode des moindres carrés et on trouve les coefficients $`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$ permettant de tracer la conique :
$`C = \begin{bmatrix} a & b/2 & d/2 \\ b/2 & c & e/2 \\ d/2 & e/2 & f \end{bmatrix}`$.

3) Voir directement dans le code.

4) Une paire de droites est une parabole, spécifiquement lorsque $`b^2 − ac = 0`$ dans l'équation générale $`ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0`$. Cela se simplifie à $`(ax + by + d)(cx + ey + f) = 0`$, représentant deux droites. Pour construire une paire de droites, il suffit ainsi de choisir les coefficients ($`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$), écrire l'équation puis la factoriser et s'assurer que l'égalité $`b^2 − ac = 0`$ est bien vérifiée.

5) Quand une conique est un point, elle devient un cercle de rayon nul ($`r = 0`$), simplifiant l'équation du cercle $`(x - h)^2 + (y - k)^2 = r^2`$ à $`(x-h)^2 + (y-k)^2 = 0`$, représentant le point de coordonnées ($`h`$,$`k`$).
