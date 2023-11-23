# projet-prog-maths

## 2. Section de conique
### 2.1 Conique et points de contrôle
Comme nous sommes en géométrie projective, les points peuvent être définis à un facteur près. Cela permet "d'éliminer" une composante (ici le $`w`$ qui vaudra alors $`1`$ ne sera plus une inconnue) et on se retrouve donc avec 5 inconnues pour 5 équations : $`ax^2 + cy^2 + dx + ey + f = 0`$.

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

1) D'après le <b>2.4 Coniques</b>, une droite $`l`$ est tangente à la conique $`C`$ ssi : $`l^TC^{-1}l = 0`$. Cette tangente passe par le point $`x \in C`$ : $`l = Cx`$ (avec $`x = (x, y, w)^T`$). On connait 5 tangentes à la conique, donc il y a 5 équations de ce type dont on connait les $`l_i`$ (avec $`i\in[1,5]`$) et il y a 5 points de contrôle connus (ici ce sont points de contact entre les différentes tangentes et la conique). De plus, comme on sait que les droites $`l_i`$ sont tangentes à la conique, elles vérifient : $`l_{i}^{T}C^{-1}l = 0`$. On remplace ensuite les $`l_{i}`$ par $`Cx_{i}`$. On a : $`(Cx_{i})^T \times C^{-1} \times Cx_{i} = 0`$. On a donc un système linéaire à 5 équations (une par tangente). On le résout avec la méthode des moindres carrés et on trouve les coefficients $`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$ permettant de tracer la conique : $`C = \begin{bmatrix} a & b/2 & d/2 \\ b/2 & c & e/2 \\ d/2 & e/2 & f \end{bmatrix}`$.
2) Voir directement dans le code.
3) Une paire de droites est une parabole, spécifiquement lorsque $`b^2 − ac = 0`$ dans l'équation générale $`ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0`$. Cela se simplifie à $`(ax + by + d)(cx + ey + f) = 0`$, représentant deux droites. Pour construire une paire de droites, il suffit ainsi de choisir les coefficients ($`a`$, $`b`$, $`c`$, $`d`$, $`e`$ et $`f`$), écrire l'équation puis la factoriser et s'assurer que l'égalité $`b^2 − ac = 0`$ est bien vérifiée.
4) Quand une conique est un point, elle devient un cercle de rayon nul ($`r = 0`$), simplifiant l'équation du cercle $`(x - h)^2 + (y - k)^2 = r^2`$ à $`(x-h)^2 + (y-k)^2 = 0`$, représentant le point de coordonnées ($`h`$,$`k`$).
